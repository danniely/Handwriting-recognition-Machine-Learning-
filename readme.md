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
With trainedData.txt file extracted from the part 1, posterior probabilty was calculated for each test images, then classified that specific test image using Naive Bayes classifier.\
<img width="466" alt="Screen Shot 2019-11-15 at 11 33 02 AM" src="https://user-images.githubusercontent.com/37637823/68963117-d13d4400-079b-11ea-99a3-0e51d8b48a12.png">

After the calculation of posterior probability of each class, pick the class with the highest probability, because that is what the classifier expects the hand written image to be, with the highest probability.
For example, assuming some unknown image was given,\
<img width="278" alt="Screen Shot 2019-11-15 at 11 35 50 AM" src="https://user-images.githubusercontent.com/37637823/68963246-1e211a80-079c-11ea-8b60-c488aece6e28.png">

we can expect this number to be 8, since the class '8' has the highest probability.

## Conclusion
After matching the expected values with their actual values, accuracy was calculated as below.\
Class 0: 75%\
Class 1: 68%\
Class 2: 83%\
Class 3: 87%\
Class 4: 77%\
Class 5: 79%\
Class 6: 85%\
Class 7: 84%\
Class 8: 82%\
Class 9: 88%
