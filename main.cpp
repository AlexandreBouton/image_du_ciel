#include <iostream>
#include <bmp_file.h>
#include <ppm_file.h>

using namespace std;

int main()
{
    cout << "Creation de l'image" << endl;
    ppm_file file("test.ppm", 500, 500, 255);
    return 0;
}
