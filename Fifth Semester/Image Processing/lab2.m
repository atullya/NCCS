clear all;
close all;
clc;

% Import image package (only needed if using Octave, not required for MATLAB)
pkg load image;

% Read image
img = imread("lab2.png");

% Display original image
figure;
imshow(img);
title("Original Image");

% Convert image to grayscale
grayscale_img = rgb2gray(img);

% Show grayscale image
figure;
imshow(grayscale_img);
title("Grayscale Image");

% Save grayscale image
imwrite(grayscale_img, "lab2_grayscale.png");

% Calculate negative of the image
negative_img = 255 - grayscale_img;

% Show negative image
figure;
imshow(negative_img);
title("Negative Image");

% Save negative image
imwrite(negative_img, "lab2_negative.png");

