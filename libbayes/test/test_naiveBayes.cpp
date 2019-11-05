#include "catch.hpp"

#include "../src/image.hpp"
#include "../src/model.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

Image imageTest;
Model modelTest;

TEST_CASE("image.cpp >> operator test"){

    std::vector<std::vector<int>> binaryPixel;
    std::string testLine = "++++++";
    std::stringstream ss(testLine);
    ss >> imageTest;
    binaryPixel = imageTest.getBinaryPixels();
    REQUIRE(1 == binaryPixel[0][0]);
}

TEST_CASE("image.cpp << operator test"){

    std::ostringstream printBinaryPixels;
    printBinaryPixels << imageTest;
    REQUIRE("1111110000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
            "0000000000000000000000000000\n"
             == printBinaryPixels.str());
}

TEST_CASE("returning Binary Pixel method testing"){
    std::vector<std::vector<int>> testVector(28,std::vector<int>(28));
    testVector[0][0] = 1;
    testVector[0][1] = 1;
    testVector[0][2] = 1;
    testVector[0][3] = 1;
    testVector[0][4] = 1;
    testVector[0][5] = 1;

    REQUIRE(testVector == imageTest.getBinaryPixels());
}

TEST_CASE("File path check test"){
    REQUIRE("OK" == modelTest.filePathCheck());
}