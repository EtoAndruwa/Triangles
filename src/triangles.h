#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <iostream>
#include <math.h>
#include <string>
#include <time.h>   
#include <gtest/gtest.h>

// #define DEBUG // for code comments
#define EPS 1e-6

typedef float coords_type;  // types of coords (int/float)


enum return_codes
{
    IS_ZERO = 0,
    IS_POSITIVE = 1,
    IS_NEGATIVE = 2,
};

class point;
class vector;
class triangle;

class point // READY
{
    friend vector;
    friend triangle;

    public:
        point(); // common constructor
        point(const coords_type& x, const coords_type& y, const coords_type& z); // constructor

        ~point(); // destructor

        void print_point() const; // prints the coords of the point
        void set_point(const coords_type& x, const coords_type& y, const coords_type& z);

        coords_type get_x() const;
        coords_type get_y() const;
        coords_type get_z() const;

        bool operator == (const point& other) const// OK
        {
            return (fabs(this->get_x() - other.get_x()) <= EPS) && (fabs(this->get_y() - other.get_y()) <= EPS) 
                && (fabs(this->get_z() - other.get_z()) <= EPS);
        }

    private:
        coords_type x;
        coords_type y;
        coords_type z;
};

class vector: public point // READY
{
    friend triangle;

    public:
        vector();
        vector(const coords_type& x1, const coords_type& y1, const coords_type& z1, const coords_type& x2, const coords_type& y2, const coords_type& z2); // constructor

        ~vector(); //destructor
        
        void print_vector() const; // prints the coords of the start and the end of the point

        void get_start(coords_type& x1, coords_type& y1, coords_type& z1) const;
        void get_end(coords_type& x2, coords_type& y2, coords_type& z2) const;
        double get_module() const;
        coords_type get_i() const;
        coords_type get_j() const;
        coords_type get_k() const;

        void calc_module();
        void set_end(const coords_type& x2, const coords_type& y2, const coords_type& z2);
        void set_start(const coords_type& x1, const coords_type& y1, const coords_type& z1);

        bool operator == (const vector& other) const// OK
        {
            return (fabs(this->start.get_x() - other.start.get_x()) <= EPS) && (fabs(this->start.get_y() - other.start.get_y()) <= EPS) &&
                (fabs(this->start.get_z() - other.start.get_z()) <= EPS) && (fabs(this->end.get_x() - other.end.get_x()) <= EPS) && 
                    (fabs(this->end.get_y() - other.end.get_y()) <= EPS) && (fabs(this->end.get_z() - other.end.get_z()) <= EPS);
        }

        bool operator != (const vector& other) const // OK
        {
            return !((fabs(this->start.get_x() - other.start.get_x()) <= EPS) && (fabs(this->start.get_y() - other.start.get_y()) <= EPS) &&
                (fabs(this->start.get_z() - other.start.get_z()) <= EPS) && (fabs(this->end.get_x() - other.end.get_x()) <= EPS) && 
                    (fabs(this->end.get_y() - other.end.get_y()) <= EPS) && (fabs(this->end.get_z() - other.end.get_z()) <= EPS));
        }

        vector operator ^(const vector& other) const
        {
            if(isnan(this->get_module()) ||  isnan(other.get_module()))
            {
                printf("ERROR: cannot make cross multiplication. Some vectors have NAN coords\n");
                vector err_vec(NAN, NAN, NAN, NAN, NAN, NAN);
                return err_vec;
            }
            else
            {   
                const coords_type x1 = this->start.get_x();
                const coords_type y1 = this->start.get_y();
                const coords_type z1 = this->start.get_z();

                const coords_type i1 = this->get_i();
                const coords_type j1 = this->get_j();
                const coords_type k1 = this->get_k();

                const coords_type i2 = other.get_i();
                const coords_type j2 = other.get_j();
                const coords_type k2 = other.get_k();

                vector res_vec(x1, y1, z1, x1 + j1 * k2 - j2 * k1, y1 + i2 * k1 - i1 * k2, z1 + i1 * j2 - i2 * j1);
                return res_vec;
            }
        }

        double operator *(const vector& other) const// OK
        {
            if(isnan(this->get_module()) ||  isnan(other.get_module()))
            {
                printf("ERROR: cannot make dot multiplication. Some vectors have NAN coords\n");
                return NAN;
            }
            else
            {   
                return (this->get_i() * other.get_i() + this->get_j() * other.get_j() + this->get_k() * other.get_k());
            }
        }

        vector operator +(const vector& other) const // OK
        {
            const coords_type i3 = this->get_i() + other.get_i();
            const coords_type j3 = this->get_j() + other.get_j();
            const coords_type k3 = this->get_k() + other.get_k();

            const coords_type x1 = this->start.get_x();
            const coords_type y1 = this->start.get_y();
            const coords_type z1 = this->start.get_z();

            vector res_vec(x1, y1, z1, x1 + i3, y1 + j3, z1 + k3);
            return res_vec;
        }

        vector operator -(const vector& other) const// OK
        {
            const coords_type i3 = this->get_i() - other.get_i();
            const coords_type j3 = this->get_j() - other.get_j();
            const coords_type k3 = this->get_k() - other.get_k();

            const coords_type x1 = this->start.get_x();
            const coords_type y1 = this->start.get_y();
            const coords_type z1 = this->start.get_z();

            vector res_vec(x1, y1, z1, x1 + i3, y1 + j3, z1 + k3);
            return res_vec;
        }

        vector operator *(const double& multp_val) const// OK
        {
            const coords_type i3 = this->get_i() * multp_val;
            const coords_type j3 = this->get_j() * multp_val;
            const coords_type k3 = this->get_k() * multp_val;

            const coords_type x1 = this->start.get_x();
            const coords_type y1 = this->start.get_y();
            const coords_type z1 = this->start.get_z();

            vector res_vec(x1, y1, z1, x1 + i3, y1 + j3, z1 + k3);
            return res_vec;
        }

        vector operator /(const double& multp_val) const// OK
        {
            if(fabs(multp_val) <= EPS)
            {
                printf("Error: cannot div to zero\n");

                vector res_vec(NAN, NAN, NAN, NAN, NAN, NAN);
                return res_vec;
            }
            else
            {
                const coords_type i3 = this->get_i() / multp_val;
                const coords_type j3 = this->get_j() / multp_val;
                const coords_type k3 = this->get_k() / multp_val;

                const coords_type x1 = this->start.get_x();
                const coords_type y1 = this->start.get_y();
                const coords_type z1 = this->start.get_z();

                vector res_vec(x1, y1, z1, x1 + i3, y1 + j3, z1 + k3);
                return res_vec;
            }
        }

    private:
        point start;
        point end;
        coords_type i;
        coords_type j;
        coords_type k;
        double module;
};

class triangle // NOT READY
{
    friend bool check_top_inter(const point& point, const triangle triangl);
    friend bool simpl_triangle_inter(const triangle& triangle1, const triangle& triangle2);

    public:
        triangle(const coords_type& x1, const coords_type& y1, const coords_type& z1, const coords_type& x2, const coords_type& y2, const coords_type& z2, 
            const coords_type& x3, const coords_type& y3, const coords_type& z3);
        ~triangle();


        void calc_area();
        void print_triangle() const;
        float get_area() const;

    private:
        point A;
        point B;
        point C;
        vector AB;
        vector BC;
        vector CA;
        float area;
};

bool check_top_inter(const point& point, const triangle triangl);
bool triangle_inter(const triangle& triangle1, const triangle& triangle2);
bool check_vec_collinear(const vector& vector1, const vector& vector2);
bool check_vec_perpend(const vector& vector1, const vector& vector2);
bool check_on_one_line(const vector& v1, const vector& v2);
bool check_point_one_direct(const vector& v1, const vector& v2);


template <typename T>
int check_is_sign(const T& value) // OK
{
    return (fabs(value - fabs(value)) < EPS) && (fabs(value) > EPS)? IS_POSITIVE: 
        fabs(value) <= EPS? IS_ZERO: IS_NEGATIVE;
}

template <typename T>
bool check_val_in_interval(const T& a, const T& checked_val, const T& b) // OK
{
    return (check_is_sign(checked_val - a) == IS_ZERO) || check_is_sign(b - checked_val) == IS_ZERO || 
        ((checked_val - a) >= EPS && (b - checked_val) >= EPS)? true: false;
}

template <typename T>
bool check_three_eq(const T& a, const T& checked_val, const T& b) // OK
{
    return fabs(checked_val - a) <= EPS && fabs(b - checked_val) <= EPS? true: false;
}

#endif
