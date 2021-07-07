#pragma once

#include "structures.hpp"

int saveFile(const char* filename, Rgb** arr, BitmapFileHeader* bmfh_p, BitmapInfoHeader* bmih_p, int coordY, int coordX);