# Handwriting recognition
## Introduction
Handwriting recognition is the ability of a computer to interpret hand written text as the characters. The goal of this project is to recognize numbers from images using a Naive Bayes classifier.

Naive Bayes classifiers are a family of probabilistic classifiers that are based on Bayes’ theorem. These algorithms work by combining the probabilities that an instance belongs to a class based on the value of a set of features. In this case, we will be testing if an image belongs to the class of the digits 0 to 9 based on the state of the pixels in the images.


## Part 1. Training images
We set a single hand written image size as 28x28 pixels. Below is one of the hand written images used to train the model.\
<img width="359" alt="Screen Shot 2019-11-13 at 4 02 35 AM" src="https://user-images.githubusercontent.com/37637823/68753493-c2536780-05ca-11ea-8f50-061ca2a10b51.png">

For the simplicity, types of characters are categorized as shaded or not shaded as below.\
blank space: 0\
#: 1\
+: 1\
After going through every single pixels in a 28x28 image, the number of characters in pixels were counted and stored into a 2d vector of the class '8'. This same procedure was repeated with all the other remaining images.
Below is the dataset of shaded characters counts of class '0'.\
<img width="651" alt="Screen Shot 2019-11-15 at 11 20 19 AM" src="https://user-images.githubusercontent.com/37637823/68962373-047ed380-079a-11ea-9c60-360777847f24.png">

## Part 2. Testing images
With trainedData.txt file extracted from the part 1, posterior probabilty was calculated for each test images, then classified that specific test image using Naive Bayes classifier.
