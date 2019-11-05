#ifndef NAIVEBAYES_VALIDATION_H
#define NAIVEBAYES_VALIDATION_H

#include "image.hpp"
#include <map>
#include <fstream>
#include <iostream>
#include "model.hpp"

class validation {
public:
    Model model1;

    void setModelClass(Model&);
    std::map<char, int> labelsCount;
    void readTheTrainedFile();
    int calculateTheProb(std::vector<std::vector<int>>);
    void loadTheTrainingData();
    int findMaxProb(std::map<int, double>);
    void countNumOfTrainingData();
    void accuracyCalculate();
    void printValidation();
    void run();
    std::map<int, int> trainingCount;
    std::map<int, double> accuracyTable;



    std::map<int, std::map<std::pair<int,int>,int>> trainedData;

    std::map<int, double> posterior_probability;
    std::map<int, int> successOfImages;
    Model model;


};


#endif //NAIVEBAYES_VALIDATION_H
