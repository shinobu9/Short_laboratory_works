#include "checker.hpp"

int typeCheck(BitmapFileHeader* bmfh, BitmapInfoHeader* bmih){
    if((bmfh->signature == 19778) && (bmih->bitsPerPixel == 24) && (bmih->compression == 0) && 
        (bmih->colorsInColorTable == 0) && (bmih->importantColorCount == 0)){
        return 1;
    }else{
        return 0;
    }
}

int operandCheck(int flag, BitmapInfoHeader* bmih, int* start, int* end, int* to, int* old_color, int* new_color){
    switch (flag){
        case 'c':
            if(start[0] < 0 || start[0] >= bmih->width || end[0] < 0 || end[0] >= bmih->width || to[0] < 0 || to[0] >= bmih->width)
                return 0;
            if(start[1] < 0 || start[1] >= bmih->height || end[1] < 0 || end[1] >= bmih->height || to[1] < 0 || to[1] >= bmih->height)
                return 0;
        break;

        case 'x':
            if(start[0] < 0 || start[0] >= bmih->width || end[0] < 0 || end[0] >= bmih->width)
                return 0;
            if(start[1] < 0 || start[1] >= bmih->height || end[1] < 0 || end[1] >= bmih->height)
                return 0;
        break;

        case 'y':
            if(start[0] < 0 || start[0] >= bmih->width || end[0] < 0 || end[0] >= bmih->width)
                return 0;
            if(start[1] < 0 || start[1] >= bmih->height || end[1] < 0 || end[1] >= bmih->height)
                return 0;
        break;

        case 'r':
            for(int i=0; i<3; i++){
                 if(old_color[i] < 0 || old_color[i] > 255 || new_color[i] < 0 || new_color[i] > 255)
                    return 0;
            }
        break;
    }
    return 1;
}