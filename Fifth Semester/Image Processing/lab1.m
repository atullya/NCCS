clc
close all
clear all
A=imread("lab1.png");
subplot(1,2,1);
imshow(A);
title("Color Image of Car")
B=rgb2gray(A);
#figure
subplot(1,2,2);
imshow(B)
title("Grayscale Image of Car");

