#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>

/*
 * We've given you a starter class to represent an image.
 * You are totally allowed to delete, change, move, rename, etc. this class
 * however you like! In fact, we encourage it! It only exists as a starting
 * point of reference.
 *
 * You can delete this comment once you're done with it.
 */

constexpr size_t IMAGE_SIZE = 28;

class Image {
private:

public:
    friend std::ostream &operator<<(std::ostream &output, const Image &D);
    friend std::istream &operator>>(std::istream &input, Image &D);
    std::string getRawPixcel();
    void transferPixcel();
    void setUp();
    std::string rawPixel;
    std::vector<std::vector<int>> getBinaryPixels();
    std::vector<std::vector<char>> pixels;
    std::vector<std::vector<int>> binaryPixels;


};
