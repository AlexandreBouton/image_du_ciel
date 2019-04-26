#ifndef PPM_FILE_H
#define PPM_FILE_H
#include<fstream>
#include<string>
#include<random>

using namespace std;

class ppm_file : public ofstream
{
public:
    ppm_file();
    //Constructor with name, size and max level parameters
    ppm_file(const string& name, unsigned int width, unsigned int height, unsigned int max_level);

    void ppm_image(unsigned int width, unsigned int height, unsigned int max_level);
    void ppm_close();
    int get_int_value(unsigned int max_level);

    string name;

    unsigned int width; //largeur
    unsigned int height; //hauteur
    unsigned int max_level;
};

#endif // PPM_FILE_H
