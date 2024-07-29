clear all;%clear all variables
close all;%close all figures
clc; %clear command window
pkg load image;

input_image = imread('lab10.png');
if size(input_image, 3) == 3
  input_image = rgb2gray(input_image); % Convert to grayscale if the image is RGB
endif

% Define the Sobel kernels
sobel_x = [-1 0 1; -2 0 2; -1 0 1];
sobel_y = [-1 -2 -1; 0 0 0; 1 2 1];

% Apply the Sobel filters
gradient_x = imfilter(double(input_image), sobel_x);
gradient_y = imfilter(double(input_image), sobel_y);

% Compute the gradient magnitude
gradient_magnitude = sqrt(gradient_x.^2 + gradient_y.^2);

% Display the results
figure, imshow(input_image), title('Original Image');
figure, imshow(gradient_x, []), title('Gradient in X direction');
figure, imshow(gradient_y, []), title('Gradient in Y direction');
figure, imshow(gradient_magnitude, []), title('Gradient Magnitude');

