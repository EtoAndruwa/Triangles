#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <iostream>
#include <math.h>
#include <string>
#include <time.h>

// #define DEBUG

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
        point(const coords_type& x, const coords_type& y, const coords_type& z); // constructor

        ~point(); // destructor

        void print_point(); // prints the coords of the point

        void set_x(const coords_type& x);
        void set_y(const coords_type& y);
        void set_z(const coords_type& z);

        const coords_type get_x() const;
        const coords_type get_y() const;
        const coords_type get_z() const;

    private:
        coords_type x;
        coords_type y;
        coords_type z;
};

class vector
{
    public:
        vector(); // common constructor 
        vector(const coords_type& x1, const coords_type& y1, const coords_type& z1, const coords_type& x2, const coords_type& y2, const coords_type& z2); // constructor

        ~vector(); //destructor
        
        void print_vector(); // prints the coords of the start and the end of the point

        void set_start(const coords_type& x1, const coords_type& y1, const coords_type& z1);
        void set_end(const coords_type& x2, const coords_type& y2, const coords_type& z2);
        void set_module(const double& module_val);

        void get_start(coords_type& x1, coords_type& y1, coords_type& z1) const;
        void get_end(coords_type& x2, coords_type& y2, coords_type& z2) const;
        void get_module(double& module_val) const;

        void calc_module();

        bool operator == (const vector& other) // OK
        {
            return this->start.x == other.start.x && this->start.y == other.start.y && this->start.z == other.start.z && 
                this->end.x == other.end.x && this->end.y == other.end.y && this->end.z == other.end.z;
        }

        bool operator != (const vector& other) // OK
        {
            return !(this->start.x == other.start.x && this->start.y == other.start.y && this->start.z == other.start.z && 
                this->end.x == other.end.x && this->end.y == other.end.y && this->end.z == other.end.z);
        }

        vector operator +(const vector& other)
        {
            vector res_vec;
    
            res_vec.set_start(start.get_x(), start.get_y(), start.get_z());
            res_vec.set_end(other.end.get_x(), other.end.get_y(), other.end.get_z());
            res_vec.set_module(NAN);
            res_vec.calc_module();

            return res_vec;
        }

        vector operator ^(const vector& other)
        {
            vector res_vec;
    
            res_vec.set_start(start.get_x(), start.get_y(), start.get_z());
            res_vec.set_end(other.end.get_x(), other.end.get_y(), other.end.get_z());
            res_vec.set_module(NAN);
            res_vec.calc_module();

            return res_vec;
        }

        vector operator +(const vector& other)
        {
            vector res_vec;
    
            res_vec.set_start(start.get_x(), start.get_y(), start.get_z());
            res_vec.set_end(other.end.get_x(), other.end.get_y(), other.end.get_z());
            res_vec.set_module(NAN);
            res_vec.calc_module();

            return res_vec;
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

// template <class T>
// void run_time(T func_ptr);

#endif
