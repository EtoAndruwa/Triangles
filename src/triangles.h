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

        void setX(coords_type x);
        void setY(coords_type y);
        void setZ(coords_type z);

        coords_type getX();
        coords_type getY();
        coords_type getZ();

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

        void setStart(coords_type x1, coords_type y1, coords_type z1);
        void setEnd(coords_type x2, coords_type y2, coords_type z2);

        void getStart(coords_type& x1, coords_type& y1, coords_type& z1);
        void getEnd(coords_type& x2, coords_type& y2, coords_type& z2);

    private:
        point start;
        point end;
};


class triangle
{
    public:


    private:

};



#endif
