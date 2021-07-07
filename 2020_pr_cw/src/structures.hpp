#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>

#pragma pack (push, 1)
typedef struct
{
	unsigned short signature;
	unsigned int filesize;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct
{
	unsigned int headerSize;
	unsigned int width;
	unsigned int height;
	unsigned short planes;
	unsigned short bitsPerPixel;
	unsigned int compression;
	unsigned int imageSize;
	unsigned int xPixelsPerMeter;
	unsigned int yPixelsPerMeter;
	unsigned int colorsInColorTable;
	unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
} Rgb;

typedef struct
{
	char* filename;
	char* alternative;
	int* counts;
	int* start;
	int* end;
	int* to;
	int* old_color;
	int* new_color;
	char* actions;
    int action_counter;
} Params;

#pragma pack(pop)
