#include "printInfoHelp.hpp"

void printInfo(BitmapFileHeader bmfh, BitmapInfoHeader bmih){
	printf("signature:\t%x (%hu)\n", bmfh.signature, bmfh.signature);
	printf("filesize:\t%x (%u)\n", bmfh.filesize, bmfh.filesize);
	printf("reserved1:\t%x (%hu)\n", bmfh.reserved1, bmfh.reserved1);
	printf("reserved2:\t%x (%hu)\n", bmfh.reserved2, bmfh.reserved2);
	printf("pixelArrOffset:\t%x (%u)\n", bmfh.pixelArrOffset, bmfh.pixelArrOffset);

	printf("headerSize:\t%x (%u)\n", bmih.headerSize, bmih.headerSize);
	printf("width:     \t%x (%u)\n", bmih.width, bmih.width);
	printf("height:    \t%x (%u)\n", bmih.height, bmih.height);
	printf("planes:    \t%x (%hu)\n", bmih.planes, bmih.planes);
	printf("bitsPerPixel:\t%x (%hu)\n", bmih.bitsPerPixel, bmih.bitsPerPixel);
	printf("compression:\t%x (%u)\n", bmih.compression, bmih.compression);
	printf("imageSize:\t%x (%u)\n", bmih.imageSize, bmih.imageSize);
	printf("xPixelsPerMeter:\t%x (%u)\n", bmih.xPixelsPerMeter, bmih.xPixelsPerMeter);
	printf("yPixelsPerMeter:\t%x (%u)\n", bmih.yPixelsPerMeter, bmih.yPixelsPerMeter);
	printf("colorsInColorTable:\t%x (%u)\n", bmih.colorsInColorTable, bmih.colorsInColorTable);
	printf("importantColorCount:\t%x (%u)\n", bmih.importantColorCount, bmih.importantColorCount);
}

void printHelp(){
	printf("\033[1;96m\nAbout:\033[0m\n");
	printf("\033[96m'bimped' utility is meant for BMP picture editing and only supports files with\n"
	"no compression, 24 bits per pixel, no colors in color table and 0 important color count.\033[0m\n");
    printf("\033[1m\nUsage:\033[0m\n");
    printf("  bimped <option> [argument]\n\n");
    printf("\033[1m\nOptions:\033[0m\n");
    printf("  -h, --help                \tShow help.\n");
    printf("  -f <path>, --file <path>  \tDefine original file. By default original file\n"
                                        "\t\t\t\tis the last argument.\n");
    printf("  -a <path>, --alter <path> \tUse this key to save to a different file.\n");
    printf("  -i <path>, --info <path>  \tShow information about the file.\n");
    printf("  -c, --copy-patch          \tCopies and pastes a rectangular fragment to a destination\n"
                                        "\t\t\t\tin the same picture.\n"
                                        "\t\t\t\tOnly used with \033[1m-s(--start)\033[0m and \033[1m-e(--end)\033[0m keys\n"
                                        "\t\t\t\tthe upper left (-s) and the bottom right (-e) corners\n"
                                        "\t\t\t\tof the fragment and \033[1m-t(--to)\033[0m key to define\n"
                                        "\t\t\t\tthe upper left corner of the destination.\n");
    printf("  -x, --reflect-x           \tReflects a fragment by X axis.\n"
                                        "\t\t\t\tOnly used with \033[1m-s(--start)\033[0m and \033[1m-e(--end)\033[0m keys to define\n"
                                        "\t\t\t\tthe upper left (-s) and the bottom right (-e) corners\n"
                                        "\t\t\t\tof the fragment.\n");
    printf("  -y, --reflect-y           \tReflects a fragment by Y axis.\n"
                                        "\t\t\t\tOnly used with \033[1m-s(--start)\033[0m and \033[1m-e(--end)\033[0m keys to define\n"
                                        "\t\t\t\tthe upper left (-s) and the bottom right (-e) corners\n"
                                        "\t\t\t\tof the fragment.\n");
    printf("  -r, --replace-color       \tReplaces old color and colors close to it with new color.\n"
                                        "\t\t\t\tOnly used with \033[1m-o(--old)\033[0m and \033[1m-n(--new)\033[0m keys to define\n"
                                        "\t\t\t\told and new colors using RGB palette.\n");
    printf("  -d, --divide <i> <j>      \tDivivdes a picture into i pieces by X axis and j pieces\n"
                                        "\t\t\t\tby Y axis. Stores all resulting fragments in the same\n"
                                        "\t\t\t\tdirectory if \033[1m-a(--alter)\033[0m key is not defined.\n");
    printf("  -s, --start <x> <y>       \tCoordinates of the upper left corner.\n"
                                        "\t\t\t\tDefault: 0, 0.\n");
    printf("  -e, --end   <x> <y>       \tCoordinates of the bottom right corner.\n"
                                        "\t\t\t\tDefault: 0, 0.\n");
    printf("  -t, --to   <x> <y>        \tCoordinates of the upper left corner.\n"
                                        "\t\t\t\tDefault: 0, 0.\n");
    printf("  -o, --old   <R> <G> <B>   \tColor to be replaced. Range 0-255.\n");
    printf("  -n, --new   <R> <G> <B>   \tNew color. Range 0-255.\n\n\n");
}