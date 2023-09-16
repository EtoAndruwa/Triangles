#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <iostream>
#include <math.h>
#include <string>

#define DEBUG

typedef float coords_type;  // types of coords (int/float)

class vector
{
    public:


    private:

};


class point
{
    public:
        point()
        {
            this->x = NAN;
            this->y = NAN;
            this->z = NAN;
        }
        
        point(coords_type x, coords_type y, coords_type z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        ~point()
        {
            this->x = NAN;
            this->y = NAN;
            this->z = NAN;
        }

        void print_coords()
        {
            std::cout << "x = " + std::to_string(this->x) + " " + " y = "+ std::to_string(this->y) + " " +" z = "+ std::to_string(this->z)<< std::endl;
        }

    private:
        coords_type x;
        coords_type y;
        coords_type z;
};


class triangle
{
    public:


    private:

};


#endif