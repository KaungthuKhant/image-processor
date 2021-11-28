/*
This is the header file for imgage tools module

Created by: Kaung Thu Khant
*/

struct Pixel{
	unsigned char red, green, blue;
};

struct Image{
	int width;
	int height;
	Pixel **pixels;
};


Image loadImage(FILE *imageFile);
Pixel** make2DArray(int numRows, int numCols);
void saveImage(Image img, FILE *imgFile);
void toGrayscale(Image img);
void flipImage(Image img, bool flipVertically);

