#include "saveFile.hpp"

int saveFile(const char* filename, Rgb** arr, BitmapFileHeader* bmfh_p, BitmapInfoHeader* bmih_p, int coordY, int coordX){
    FILE *ff = fopen(filename, "wb");
    if(ff==NULL){
    	printf("Trouble with creating output file.\n");
        return 0;
    }
    unsigned int w = bmih_p->width * sizeof(Rgb);
    unsigned int w_buff = (w*3)%4;
    char arr_buff[3] = {0,0,0};

    fwrite(bmfh_p, 1, sizeof(BitmapFileHeader),ff);
    fwrite(bmih_p, 1, sizeof(BitmapInfoHeader),ff);

    for(int i=coordY; i < coordY + bmih_p->height; i++){
        fwrite(arr[i]+coordX,1,w,ff);
        fwrite(arr_buff,1,w_buff,ff);
    }

    fclose(ff);
    return 1;
}