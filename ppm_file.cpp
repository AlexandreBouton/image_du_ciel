#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include "ppm_file.h"

using namespace std;
//ppm_file file;

//seed creation, based on date
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);

/* The random generator seems to works only with double or float
 *
 * To get unsigned int, we just take the round(abs()) value of this float number
 * */
normal_distribution<float> distri(0.0, 0.15);


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/**
 * @brief ppm_file::ppm_file
 * This constructor creates a ppm file with its header and run a body function
 * Be careful ! If the file already exists, he's deleted.
 * @date 04-16-2019
 * @author Alexandre Bouton
 */
ppm_file::ppm_file()
{
    //Creating the file
    this->open("my_ppm_file.ppm", ofstream::trunc);

    //Put the default width and height values to 100 pixels
    width = height = 100;
    max_level = 255;

    /**************************
     * PPM file structure:
     *
     * P3               <- for the type of Netpbm format (P1 = PBM, P2 = PGM, P3 = PPM). "P3" means this is a RGB color image in ASCII
     * x y              <- x is the width and y is the height
     * max              <- maximum color level
     *
     * The part under this header is the image
     **************************/
    *this << "P3\n";
    *this << width;
    *this << " ";
    *this << height;
    *this << "\n";
    *this << max_level;
    *this << "\n";

    //Close the file
    //ppm_image(name...
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/**
 * @brief ppm_file::ppm_file
 * This constructor creates a ppm file with its header and run a body function
 * Be careful ! If the file already exists, he's deleted.
 * @param name the name of the file
 * @param width
 * @param height
 * @param max_level the white level
 * @author Alexandre Bouton
 * @date 04-16-19
 */
ppm_file::ppm_file(const string& name, const unsigned int width, const unsigned int height, const unsigned int max_level)
{
    //Creating the file

    cout << "Creation du fichier..." << endl;
    cout << "Creationde l'en-tete..." << endl;
    this->open(name, ofstream::trunc);

    /**************************
     * PPM file structure:
     *
     * P3               <- for the type of Netpbm format (P1 = PBM, P2 = PGM, P3 = PPM). "P3" means this is a RGB color image in ASCII
     * x y              <- x is the width and y is the height
     * max              <- maximum color level
     *
     * The part under this header is the image
     **************************/
    *this << "P3\n";
    *this << width;
    *this << " ";
    *this << height;
    *this << "\n";
    *this << max_level;
    *this << "\n";


    cout << "En-tete cree !" << endl;
    ppm_image(width, height, max_level);
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/**
 * @brief ppm_file::ppm_image
 * This function creates the body of the ppm file
 * @author Alexandre Bouton
 * @date 04-16-19
 */
void ppm_file::ppm_image(unsigned int width, unsigned int height, unsigned int max_level)
{
    //Three colors arrays
    vector<vector<int>> R;
    vector<vector<int>> G;
    vector<vector<int>> B;


    //Writing the file
    cout << "Ecriture du fichier en cours ..." << endl;
    cout << "Generation des pixels ..." << endl;
    for(unsigned int i=0; i<height; i++)
    {
        for(unsigned int j=0; j<width; j++)
        {
            //R
            *this << get_int_value(max_level) << endl;
            *this << "\t";
            //V
            *this << get_int_value(max_level) << endl;
            *this << "\t";
            //B
            *this << get_int_value(max_level) << endl;
            *this << "\n";
        }
    }

    cout << "Generation terminee !" <<endl;
    close();
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/**
 * @brief ppm_file::get_int_value
 * This function normalizes the pixel value
 * @param max_level the max_level of the image
 * @return
 */

// I have a problem : max_level = 0 when I don't send it as an argument in the function. I don't understang
// why, because max_level is in the class ppm_file.
int ppm_file::get_int_value(unsigned int max_level)
{
    float raw_random_number = distri(generator);

    if (raw_random_number > 1)
        raw_random_number = 1;
    else if(raw_random_number < -1)
        raw_random_number = -1;

    float normalized_random_number = raw_random_number * max_level;

    int int_normalized_random_number = round(abs(normalized_random_number));

    return int_normalized_random_number;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void ppm_file::ppm_close()
{
    close();
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


//BIN !

//Initialization of the random generator
/*random_device dev;
mt19937 rng(dev());
uniform_int_distribution<std::mt19937::result_type> distr(0,max_level);
uniform_int_distribution<std::mt19937::result_type> distg(0,max_level);
uniform_int_distribution<std::mt19937::result_type> distb(0,max_level);*/

/*default_random_engine generator;
normal_distribution<unsigned int> distr(0, max_level);
normal_distribution<unsigned int> distg(0, max_level);
normal_distribution<unsigned int> distb(0, max_level);*/
