#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <iostream>
#include <math.h>
#include <string>

#define DEBUG

typedef float coords_type;  // types of coords (int/float)

class point;
class vector;
class triangle;

class point
{
    friend vector;
    friend triangle;

    public:
        point(); // common constructor
        point(coords_type x, coords_type y, coords_type z); // constructor

        ~point(); // destructor

        void print_point(); // prints the coords of the point

        void set_x(coords_type x);
        void set_y(coords_type y);
        void set_z(coords_type z);

        coords_type get_x();
        coords_type get_y();
        coords_type get_z();

    private:
        coords_type x;
        coords_type y;
        coords_type z;
};

class vector
{
    public:
        vector(); // common constructor 
        vector(coords_type x1, coords_type y1, coords_type z1, coords_type x2, coords_type y2, coords_type z2); // constructor

        ~vector(); //destructor
        
        void print_vector(); // prints the coords of the start and the end of the point

        void set_start(coords_type x1, coords_type y1, coords_type z1);
        void set_end(coords_type x2, coords_type y2, coords_type z2);
        void set_module(double& module_val);

        void get_start(coords_type& x1, coords_type& y1, coords_type& z1);
        void get_end(coords_type& x2, coords_type& y2, coords_type& z2);
        void get_module(double& module_val);

        void calc_module()
        {

        }

    private:
        point start;
        point end;
        double module;
};


class triangle
{
    public:


    private:

};



#endif
