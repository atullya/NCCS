clear all;
close all;
clc;
pkg load image;

% Read the image
a = imread('lab4.png');
subplot(2, 2, 1);
imshow(a);
title('Original Image');

% Convert the image to double precision
b = im2double(a);

% Manually set the values for a and gamma
a1 = 1; % Enter the value for a1 here
gamma1 = 0.5; % Enter the value for gamma1 here

a2 = 2; % Enter the value for a2 here
gamma2 = 1; % Enter the value for gamma2 here

a3 = 3; % Enter the value for a3 here
gamma3 = 1.5; % Enter the value for gamma3 here

% Apply gamma correction for the first set of values
s1 = (a1 * (b .^ gamma1)) * 256;
s1 = uint8(s1);
subplot(2, 2, 2);
imshow(s1);
title('Image 1');

% Apply gamma correction for the second set of values
s2 = (a2 * (b .^ gamma2)) * 256;
s2 = uint8(s2);
subplot(2, 2, 3);
imshow(s2);
title('Image 2');

% Apply gamma correction for the third set of values
s3 = (a3 * (b .^ gamma3)) * 256;
s3 = uint8(s3);
subplot(2, 2, 4);
imshow(s3);
title('Image 3');

