clear all;
close all;
clc;
pkg load image;
  i=imread('lab7.png');
  i=i(:,:,1);subplot(2,2,1);imshow(i);title('Original Image');
  a=[0.001 0.001 0.001;0.001 0.001 0.001;0.001 0.001 0.001];
  r=conv2(a,i);
  subplot(2,2,2);imshow(r);title('filtered image');
  b=[0.005 0.005 0.005;0.005 0.005 0.005;0.005 0.005 0.005];
  r1=conv2(b,i);
  subplot(2,2,3);imshow(r1);title('filtered image2');

