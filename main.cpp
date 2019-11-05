#include "../src/image.hpp"
#include "../src/model.hpp"
#include "../src/validation.h"
#include <iostream>
#include <map>

int main() {

    Model beta_model;

    beta_model.run();

    std::map<char, int> labelCounts = beta_model.returnLabelCount();

    std::cout << "beta model label count of class 0 is " << labelCounts[0] << std::endl;


    return 0;
}