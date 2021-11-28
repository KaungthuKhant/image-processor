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


Image loadImg(FILE *imageFile);
Pixel** make2DArray(int numRows, int numCols);
void saveImg(Image img, FILE *imgFile);
void grayImg(Image img);
void flipImg(Image img, bool flipVertically);

