#include <iostream>
#include <bmp_file.h>
#include <ppm_file.h>

using namespace std;

int main()
{
    //cout << "Creation de l'image" << endl;
    //For the moment, create a 1000*1500 image
    //Dynamic size for a futur update
    ppm_file file("test", 100, 100, 255);

    return 0;
}
