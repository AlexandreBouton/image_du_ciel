#ifndef PPM_FILE_H
#define PPM_FILE_H
#include<fstream>
#include<string>
#include<random>


using namespace std;

class ppm_file
        : public ofstream
{
public:
    ppm_file();
    //Constructor with name, size and max level parameters
    ppm_file(const string& name, unsigned int width, unsigned int height, unsigned int max_level);

    void ppm_image(unsigned int width, unsigned int height, unsigned int max_level);
    void ppm_close();

    string name;

    unsigned int width; //largeur
    unsigned int height; //hauteur
    unsigned int max_level;

    //Three colors arrays

    vector<vector<int>> R;
    vector<vector<int>> G;
    vector<vector<int>> B;


};

#endif // PPM_FILE_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*                      Help for 2D vectors
 *
 *  Assign linear value (1,2,3,4,5...) :
 *
 *  R.resize(height);
 *  for(unsigned int i=0; i<height; i++)
 *  {
 *      R[i].resize(width);
 *      for(unsigned int j=0; j<width; j++)
 *      {
 *           R[i][j] = i * height + j;
 *      }
 *  }
 *
 *
 *
 *
 *
 *
 * */


