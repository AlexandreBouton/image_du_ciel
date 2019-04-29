#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<new>
#include "ppm_file.h"
#include "general_noise.h"

using namespace std;
//ppm_file file;


/*
//seed creation, based on date
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);*/

/* The random generator seems to works only with double or float
 *
 * To get unsigned int, we just take the round(abs()) value of this float number
 * *
normal_distribution<float> distri(0.0, 0.15);
*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/**
 * @brief ppm_file::ppm_file
 * This constructor creates a ppm file with its header and run a body function. This is the default image : 100*100, max value = 255
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
    //Creating empty arrays

    for(unsigned int i=0; i<height; i++)
    {
        for(unsigned int j=0; j<width; j++)
        {
             R[i][j] = 0;
             G[i][j] = 0;
             B[i][j] = 0;
        }
    }
    cout << "Initialisation des valeurs terminee" << endl;

    //Creating a general_noise object
    general_noise noise;
    cout << "Generation terminee !" << endl;

    //Writing the file

    cout << "Ecriture du fichier en cours ..." << endl;
    for(unsigned int i=0; i<height; i++)
    {
        for(unsigned int j=0; j<width; j++)
        {
            //R
            *this << R[i][j] << endl;
            //G
            *this << G[i][j] << endl;
            //B
            *this << B[i][j] << endl;
        }
    }

    close();
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



//Siez of vectors
/*
R.resize(height);
G.resize(height);
B.resize(height);
for(unsigned int i=0; i<height; i++)
{
    R[i].resize(width);
    G[i].resize(width);
    B[i].resize(width);
    for(unsigned int j=0; j<width; j++)
    {
         R[i][j] = 0;
         G[i][j] = 0;
         B[i][j] = 0;
    }
}*/
