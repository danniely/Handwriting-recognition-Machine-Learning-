#pragma once

#include "image.hpp"
#include <map>
#include <fstream>

/*
 * We've given you a starter struct to represent the model.
 * You are totally allowed to delete, change, move, rename, etc. this struct
 * however you like! In fact, we encourage it! It only exists as a starting
 * point of reference.
 *
 * In our probabilities array we have a final dimension [2], which represents
 * the individual probabilities that a pixel for a class is either shaded or
 * not shaded. Since the probability that a pixel is shaded is just
 * (1 - probability not shaded), we COULD have deleted that final dimension
 * (and you can do so if you want to), but we left it in so that you could
 * see how the model would need to change if we were to keep track of the
 * probability that a pixel is white vs. gray vs. dark gray vs. black.
 *
 * You can delete this comment once you're done with it.
 */

constexpr size_t NUM_CLASSES = 10;  // 0-9 inclusive

/**
 * Represents a Naive Bayes classification model for determining the
 * likelihood that an individual pixel for an individual class is
 * white or black.
 */
struct Model {

    // The individual probabilities for each pixel for each class for
    // whether it's shaded or not.
    //
    // Examples:
    // probs[2][10][7][0] is the computed probability that a pixel at
    // [2][10] for class 7 is not shaded.
    //
    // probs[0][0][0][1] is the computed probability that a pixel at
    // [0][0] for class 0 is shaded.
public:
    std::map<char, int> labelCount;
    std::map<int , int> labelCountCopy;
    double probs[IMAGE_SIZE][IMAGE_SIZE][NUM_CLASSES][2];
    int numOfClass;
    void countLabels();
    void countProb();
    void run();
    void printTheProb();
    void printTrainingDataSize();
    void saveTheFile();

    std::map<char, int> returnLabelCount();
    void groupingImages();
    int calculateTheProb(std::vector<std::vector<int>>);
    void loadTheTrainingData();
    int findMaxProb(std::map<int, double>);
    void countNumOfTrainingData();
    void accuracyCalculate();
    void printValidation();
    std::map<int, int> trainingCount;

    std::map<int, int> successOfImages;
    std::map<int, double> accuracyTable;
    std::string filePathCheck();
    std::map<int, std::map<std::pair<int,int>,int>> groupedImages;
    std::map<std::pair<int,int>,int> coordinateCheck;
    std::map<int, double> posterior_probability;

    std::ifstream labelFile;
    std::ifstream imageFile;
    std::string line;
    std::string labels = "/Users/user/Desktop/UIUC/naive-numbers-danniely/digitdata/traininglabels";
    std::string trainingData = "/Users/user/Desktop/UIUC/naive-numbers-danniely/digitdata/trainingimages";

    std::vector<int> classSizeCount;

//    std::string labels = "/Users/user/Desktop/UIUC/naive-numbers-danniely/digitdata/testlabels";
//    std::string trainingData = "/Users/user/Desktop/UIUC/naive-numbers-danniely/digitdata/testimages";

};