#include "image.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>


std::istream& operator>>(std::istream &input, Image &image){

    getline(input,image.rawPixel);

    int rawIndex = 0;

    std::vector<std::vector<int>> binaryPixels(IMAGE_SIZE,std::vector<int>(IMAGE_SIZE));

    for(int y_index = 0; y_index < IMAGE_SIZE; y_index++){
        for(int x_index = 0; x_index < IMAGE_SIZE; x_index++){
            if(image.rawPixel[rawIndex] == ' '){
                binaryPixels[y_index][x_index] = 0;
            }else if(image.rawPixel[rawIndex] == '+' || image.rawPixel[rawIndex] == '#'){
                binaryPixels[y_index][x_index] = 1;
            }
            rawIndex++;
        }
    }
    image.binaryPixels = binaryPixels;
    return input;
}

std::ostream& operator<<( std::ostream &output, const Image &image ) {
    for(int y_index = 0; y_index < IMAGE_SIZE; y_index++){
        for(int x_index = 0; x_index < IMAGE_SIZE; x_index++){
            auto s = std::to_string(image.binaryPixels[y_index][x_index]);
            output << s;
        }
        output << "\n";
    }
    return output;
}

std::vector<std::vector<int>> Image::getBinaryPixels() {return binaryPixels;}
