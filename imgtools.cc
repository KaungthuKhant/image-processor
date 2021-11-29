/*
This an image toolkit that provides tools for manipulating and filtering digital
images.

Created by: Kaung Thu Khant

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imgtools.h"
#include <math.h>


// Loads a “P3” PPM formatted image from a previously opened text file. 
// The image will be returned as Image 
Image loadImg(FILE *imgFile)
{
	Image img;
	int maxRGB;
	
	// scan inportant informations
	fscanf(imgFile, "%d", &img.width);
	fscanf(imgFile, "%d", &img.height);
	fscanf(imgFile, "%d", &maxRGB);

	// make 2d array using the width and height recorded
	img.pixels = make2DArray(img.height, img.width);
	
	int red;
	int green;
	int blue;
	
	// put in rgb values to the array
	for (int i = 0; i < img.height; i++)
	{
		for (int j = 0; j < img.width; j++)
		{
			fscanf(imgFile, "%d", &red);
			fscanf(imgFile, "%d", &green);
			fscanf(imgFile, "%d", &blue);
			
			if (red > maxRGB || green > maxRGB || blue > maxRGB){
				fprintf(stderr, "RGB value more than 255\n");
			}
			img.pixels[i][j].red = red;
			img.pixels[i][j].green = green;
			img.pixels[i][j].blue = blue;
		}
	}
	// return the image
	return img;
	
}

// this function will make an array with numRows and numCols
Pixel** make2DArray(int numRows, int numCols)
{
	// buid the structure
	Pixel **theRows;
	theRows = (Pixel**) malloc(numRows * sizeof(Pixel*));
	for (int i = 0; i < numRows; i++)
	{
		theRows[i] = (Pixel *) malloc(numCols * sizeof(Pixel));
	}
	return theRows;
}

//Saves an image to a previously opened text file as a “P3” PPM formatted image
void saveImg(Image img, FILE *imgFile)
{
	// input important info
	int num = 3;
	int max = 255;
	fprintf(imgFile, "P%d\n", num);
	fprintf(imgFile, "%d %d\n", img.width, img.height);
	fprintf(imgFile, "%d\n", max);
	
	// save each pixels
	for (int i = 0; i < img.height; i++)
	{
		for (int j = 0; j < img.width; j++)
		{
			fprintf(imgFile, "%4d", img.pixels[i][j].red);
			fprintf(imgFile, "%4d", img.pixels[i][j].green);
			fprintf(imgFile, "%4d", img.pixels[i][j].blue);
		}
		
	}
}

// turn the image that is passed into a gray scale
void grayImg(Image img)
{
	int gray;
	for (int i = 0; i < img.height; i++)
	{
		for (int j = 0; j < img.width; j++)
			{
				int red = img.pixels[i][j].red;
				int green = img.pixels[i][j].green;
				int blue = img.pixels[i][j].blue;
				
				// calculate the gray scale using the rgb values
				gray = round(0.299*red + 0.587 * green + 0.114 * blue);
				
				img.pixels[i][j].red = gray;
				img.pixels[i][j].green = gray;
				img.pixels[i][j].blue = gray;
			}
	}
}

// this funciton will flip the image vertically if boolean value passed is true
// else, flip horizontally
void flipImg(Image img, bool flipVertically)
{
	int width = img.width;
	int height = img.height;
	int index; 
	
	// for each column, flip the column
	if(flipVertically == true){
		//int mid = height/2;
		Pixel temp;
		for (int i = 0; i < height/2; i++){
			index = height - 1 - i;
			for (int j = 0; j < width; j++){
				temp = img.pixels[i][j];
				img.pixels[i][j] = img.pixels[index][j];
				img.pixels[index][j] = temp;
			}
		}
	}
	// for each row, flip the row
	else{
		Pixel temp;
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width/2; j++){
				index = width - 1 - j;
				temp = img.pixels[i][j];
				img.pixels[i][j] = img.pixels[i][index];
				img.pixels[i][index] = temp;
			}
		}
	}
}

void ratate(Image img, bool left)
{
	int width = img.width;
	int height = img.height;
	//int index;

	if(left == true)
	{
		Image newImg;
		newImg.pixels = img.pixels;
		for (int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				printf("testing %d", img.pixels[i][j].red);
				printf("testing %d", img.pixels[i][j].green);
				printf("testing %d", img.pixels[i][j].blue);
			}
		}
	}
	else
	{

	}
}
