#Uncomment the 2 lines of code below to read in the image if you are on your local machine
#You do not need/want these lines when submitting your homework on Relate
#import matplotlib.image as mpimg
#img = mpimg.imread('illinois_bw.png')

#For each trial, you will need to generate a row and col location of the point
#Use the following lines to generate a row and col -- note they must be in this order
import numpy as np
import math
num_rows, num_cols = img.shape
i=0
count=0
while (i< math.pow(10,3)):
    col = np.random.random_integers(0, num_cols-1)
    row = np.random.random_integers(0, num_rows-1)
    if(img[row][col] == 1):
        count=count+1
    i=i+1
ratio=count/math.pow(10,3)
area=304*450*ratio

num=0
p=0
k=0
while (p< 540):
    while(k < 800):
        if(img[k][p] == 1):
            num=num+1
        k=k+1
    p=p+1
rel_error= abs(count-num)/(540*800)*304*450
