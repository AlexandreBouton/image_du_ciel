#include "general_noise.h"


using namespace std;
/**
 * @brief general_noise::general_noise
 * This class generates noise to add a real dimension to the image
 *
 * @author Alexandre Bouton
 * @date 04-24-2019
 */

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
 * @brief general_noise::general_noise
 * While the method "add_general_noise" is not
 * called, nothing is added to the image
 */
general_noise::general_noise()
{
    cout << "Creation d'un general_noise..." << endl;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


void general_noise::add_general_noise(unsigned int width, unsigned int height)
{
    cout << "Ajout de valeurs de bruit a l'image..." << endl;
    for(unsigned int i=0; i<width; i++)
    {
        for(unsigned int j=0; j<height; j++)
        {
            int test = get_int_value(10);
            //cout << test << endl;
            R[i][j] = test;
            G[i][j] = test;
            B[i][j] = test;
            cout << B[i][j] << endl;
        }
    }

    cout << "Ajout des valeurs terminee !" << endl;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


int general_noise::get_int_value(unsigned int gain)
{
    float raw_random_number = distri(generator);
    if (raw_random_number > 1)
        raw_random_number = 1;
    else if(raw_random_number < -1)
        raw_random_number = -1;

    float normalized_random_number = raw_random_number * gain;

    int int_normalized_random_number = round(abs(normalized_random_number));
    //cout << int_normalized_random_number << endl;
    return int_normalized_random_number;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


//BIN !!


/*for(unsigned int i=0; i<height; i++)
{
    for(unsigned int j=0; j<width; j++)
    {

        //TODO : regarder pourquoi il est impossible d'acceder aux valeurs d'un vecteur 2D

        cout << R[1][1] << endl;    //MARCHE PAS

        cout << "Entree en boucle" << endl;
        //R[i][j] = R[i][j] + get_int_value(max_level);
        cout << R[i][j] << endl;
        //G[i][j] = G[i][j] + get_int_value(max_level);
        //B[i][j] = B[i][j] + get_int_value(max_level);
    }
}*/
