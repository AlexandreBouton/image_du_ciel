#ifndef GENERAL_NOISE_H
#define GENERAL_NOISE_H
#include<random>
#include<iostream>
#include<chrono>
#include<vector>
#include"ppm_file.h"


class general_noise : public ppm_file
{
public:
    general_noise();

    void add_general_noise(unsigned int width, unsigned int height);
    int get_int_value(unsigned int gain);

};

#endif // GENERAL_NOISE_H
