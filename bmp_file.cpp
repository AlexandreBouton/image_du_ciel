#include <iostream>
#include "bmp_file.h"

using namespace std;


//TODO !!

/**
 * @brief bmp_creator::bmp_creator
 * This constructor creates a bmp file with its header
 */
bmp_file::bmp_file()
{
    //Creating the file
    ofstream file;
    file.open("my_bmp_file.ppm", ofstream::trunc);


    file << "//\n"
            "// Header structure for the MS Windows 1.x Bitmap Format\n"
            "//    a BYTE is an unsigned char\n"
            "//    a WORD is an unsigned short int (16-bits)\n"
            "//\n"
            "typedef struct BMPFileHeader {\n"
            "uint16_t file_type{0x4D42};          // File type always BM which is 0x4D42\n"
            "uint32_t file_size{0};               // Size of the file (in bytes)\n"
            "uint16_t reserved1{0};               // Reserved, always 0\n"
            "uint16_t reserved2{0};               // Reserved, always 0\n"
            "uint32_t offset_data{0};             // Start position of pixel data (bytes from the beginning of the file)\n"
            "}";


    bmp_close();
}

void bmp_file::bmp_close()
{
    ofstream file;
    file.close();
}
