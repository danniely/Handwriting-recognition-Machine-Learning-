#include "validation.h"
#include "image.hpp"
#include "model.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <string>


void validation::countNumOfTrainingData() {

    std::ifstream loadingDatasetLabel;
    loadingDatasetLabel.open("../digitdata/traininglabels");
    int label;
    std::string row;

    while (std::getline(loadingDatasetLabel,row)) {
        label = row[0];
        if(trainingCount[label] != 0){
            trainingCount[label]++;
        }else{ trainingCount[label] = 1; }
    }
    loadingDatasetLabel.close();
}

void validation::loadTheTrainingData() {
    std::ifstream loadingDataset;
    std::ifstream loadingDatasetLabel;
    std::string labelRow;
    std::string dataRow;
    int imageNumber;

    loadingDataset.open("../digitdata/trainingimages");
    loadingDatasetLabel.open("../digitdata/traininglabels");

    while (std::getline(loadingDatasetLabel,labelRow)) {
        int predictedImageNumber;
        Image singleImage;
        char label;
        label = labelRow[0];
        imageNumber = (int)label - 48;

        int imageIndex = 0;
        std::string wholeImage;

        while(std::getline(loadingDataset, dataRow)){

            if(imageIndex >= IMAGE_SIZE)
                break;
            imageIndex++;
            wholeImage = wholeImage + dataRow;
        }

        std::stringstream ss(wholeImage);
        ss >> singleImage;

        std::vector< std::vector<int>> binaryImage = singleImage.getBinaryPixels();

        predictedImageNumber = calculateTheProb(binaryImage);

        if(predictedImageNumber == imageNumber){
            successOfImages[imageNumber]++;
        }
    }
}

int validation::calculateTheProb(std::vector<std::vector<int>> individualImage) {
    double probability=0;
    double k = 0.001;

    for(int class_index=0; class_index < NUM_CLASSES; class_index++){
        int numberOf1;
        double total_prob = 0;
        for(int j=0; j < IMAGE_SIZE; j++){
            for(int i = 0; i < IMAGE_SIZE; i++){
                std::pair<int, int> xyCord (i,j);
                numberOf1 = trainedData[class_index][xyCord];
                probability = (k + numberOf1)/(2*k+labelsCount[class_index]);

                total_prob = total_prob + log(probability);
            }
        }
        posterior_probability[class_index] = total_prob + log(labelsCount[class_index]/5000);
    }
    return findMaxProb(posterior_probability);
}

int validation::findMaxProb(std::map<int, double> Map){
    int maxValue = 0;
    int maxKey = 0;
    for(std::pair<int, double> iterator : Map){
        if (iterator.second > maxValue){
            maxKey = iterator.first;
        }
    }
    return maxKey;
}

void validation::accuracyCalculate(){
    for(int class_index=0; class_index < NUM_CLASSES; class_index++){
        accuracyTable[class_index] = (double)successOfImages[class_index]/trainingCount[class_index];
    }
}

void validation::printValidation(){
    for(std::pair<int,double> accuracy : accuracyTable){
        std::cout << "class " << accuracy.first << " has : " << accuracy.second << " success rate." << std::endl;
    }
}

void validation::run(){
    countNumOfTrainingData();
    std::cout << "Training data was recieved." << std::endl;
    loadTheTrainingData();
    std::cout << "training images has been read." << std::endl;
    accuracyCalculate();
    std::cout << "accuracy has been calculated" << std::endl;
    printValidation();
}

void validation::setModelClass(Model &model2) {
   labelsCount = model2.returnLabelCount();
    trainedData = model2.groupedImages;
}