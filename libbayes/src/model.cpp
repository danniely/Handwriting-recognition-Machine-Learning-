#include "image.hpp"
#include "model.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

void Model::countLabels() {

    char label;
    labelFile.open(labels);

    while (std::getline(labelFile,line)) {
        label = line[0];
        if(labelCount[label] != 0){
            labelCount[label]++;
        }else{ labelCount[label] = 1; }
    }
    labelFile.close();
}

void Model::groupingImages(){
    std::string labelRow;
    std::string imageRow;

    char label;
    int imageNumber;

    imageFile.open(trainingData);
    labelFile.open(labels);

    int progress_indicator = 0;

    while (std::getline(labelFile,labelRow)) {
        Image singleImage;
        label = labelRow[0];
        imageNumber = (int)label - 48;

        int imageIndex = 0;
        std::string wholeImage;

        while(std::getline(imageFile, imageRow)){

            if(imageIndex >= IMAGE_SIZE)
                break;

            imageIndex++;

            wholeImage = wholeImage + imageRow;
        }

        std::stringstream ss(wholeImage);
        ss >> singleImage;

        std::vector< std::vector<int>> binaryImage = singleImage.getBinaryPixels();

        if(groupedImages[imageNumber].empty()){
            for(int j=0; j < IMAGE_SIZE; j++) {
                for (int i = 0; i < IMAGE_SIZE; i++) {
                    std::pair<int, int> xyCord(i, j);
                    if (binaryImage[j][i] == 1) {
                        groupedImages[imageNumber][xyCord] = 1;
                    }
                }
            }
        }else if(!groupedImages[imageNumber].empty()){

            for(int j=0; j < IMAGE_SIZE; j++) {
                for (int i = 0; i < IMAGE_SIZE; i++) {
                    if(binaryImage[j][i] == 1){
                        std::pair<int, int> xyCord(i, j);
                        if(groupedImages[imageNumber][xyCord] != 0){
                            groupedImages[imageNumber][xyCord]++;
                        }else if(groupedImages[imageNumber][xyCord] == 0){
                            groupedImages[imageNumber][xyCord] = 1;
                        }
                    }
                }
            }
        }

        progress_indicator++;
        if(progress_indicator % 100 == 0){
            std::cout << progress_indicator << std::endl;
        }
    }
    labelFile.close();
    imageFile.close();
}

std::map<char,int> Model::returnLabelCount(){
    return labelCount;
};

void Model::printTrainingDataSize(){
    for(std::pair<char,int> eachClass : labelCount) {
        std::cout << "class " << eachClass.first << ": " << eachClass.second << std::endl;
        classSizeCount.push_back(eachClass.second);
    }
}

std::string Model::filePathCheck(){
    labelFile.open(labels);
    imageFile.open(trainingData);

    if(labelFile.is_open() && imageFile.is_open()){
        std::cout << "label file is found" << std::endl;
        return "OK";
    }else{
        std::cout << "image file has not been found" << std::endl;
        return "BAD";
    }
}

void Model::saveTheFile() {
    std::ofstream outfile("../libbayes/src/trainedData.txt");
    for(int imageNum = 0; imageNum < 10; imageNum++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            for (int i = 0; i < IMAGE_SIZE; i++) {
                std::pair<int, int> xyCord(i, j);
                outfile << groupedImages[imageNum][xyCord] << " ";
            }
            outfile << std::endl;
        }
//
//        char index = imageNum + '0';
//        int temp = labelCount[index];
//        std::string numberAsString = std::to_string(temp);
//        outfile << numberAsString << std::endl;
    }
    outfile.close();
}

void Model::countNumOfTrainingData() {

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

void Model::loadTheTrainingData() {
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

int Model::calculateTheProb(std::vector<std::vector<int>> individualImage) {
    double probability=0;
    double k = 0.001;

    for(int class_index=0; class_index < NUM_CLASSES; class_index++){
        int numberOf1;
        double total_prob = 0;
        for(int j=0; j < IMAGE_SIZE; j++){
            for(int i = 0; i < IMAGE_SIZE; i++){
                std::pair<int, int> xyCord (i,j);
                numberOf1 = groupedImages[class_index][xyCord];

                probability = (k + numberOf1)/(2*k+labelCountCopy[class_index]);

                total_prob = total_prob + log(probability);
            }
        }
        posterior_probability[class_index] = total_prob;
    }
    int i = 0;
    for(std::pair<char,int> eachClass : labelCount){
        posterior_probability[i] = posterior_probability[i] + log(eachClass.second);
        i++;
    }

    return findMaxProb(posterior_probability);
}

int Model::findMaxProb(std::map<int, double> Map){
    int maxValue = 0;
    int maxKey = 0;
    for(std::pair<int, double> iterator : Map){
        if (iterator.second > maxValue){
            maxValue = iterator.second;
            maxKey = iterator.first;
        }
    }
    return maxKey;
}

void Model::accuracyCalculate(){
    for(std::pair<int, int> eachClass : successOfImages){
        accuracyTable[eachClass.first] = (double)eachClass.second/classSizeCount[eachClass.first];
        std::cout << "class of " << eachClass.first << " has successes of  " << eachClass.second << std::endl;
    }
}

void Model::printValidation(){
    for(std::pair<int,double> accuracy : accuracyTable){
        std::cout << "class " << accuracy.first << " has : " << accuracy.second << " success rate." << std::endl;
    }
}


void Model::run(){
    countLabels();
    std::cout << "Counting labels has finished" << std::endl;
    groupingImages();
    std::cout << "goruping Images has finished" << std::endl;
    printTrainingDataSize();
    std::cout << "Training Data has been read." << std::endl;
    countNumOfTrainingData();
    loadTheTrainingData();
    std::cout << "Training data has been stored." << std::endl;
    accuracyCalculate();
    printValidation();
}
