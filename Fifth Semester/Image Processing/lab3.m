clear all;
close all;
clc;

% Read image
a = imread('lab3.png');

% Display original image
subplot(2, 2, 1);
imshow(a);
title('Original Image');

% Convert image to double precision
b = im2double(a);

% Apply log transformation with c=1
s1 = 1 * log(1 + b);
s1 = uint8(s1 * 255 / max(s1(:))); % Proper scaling
subplot(2, 2, 2);
imshow(s1);
title('c=1');

% Apply log transformation with c=10
s2 = 10 * log(1 + b);
s2 = uint8(s2 * 255 / max(s2(:))); % Proper scaling
subplot(2, 2, 3);
imshow(s2);
title('c=12');

% Apply log transformation with c=200
s3 = 200 * log(1 + b);
s3 = uint8(s3 * 255 / max(s3(:))); % Proper scaling
subplot(2, 2, 4);
imshow(s3);
title('c=201');

