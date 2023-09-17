#include "triangles.h"

/*###############################################################################################*/

point::point() // OK
{
    #ifdef DEBUG
        std::cout << "POINT common constructor\n";
    #endif

    x = NAN;
    y = NAN;
    z = NAN;
}

point::point(const coords_type& x, const coords_type& y, const coords_type& z) // OK
{
    #ifdef DEBUG
        std::cout << "POINT constructor\n";
    #endif

    this->x = x;
    this->y = y;
    this->z = z;
}

point::~point() // OK
{
    #ifdef DEBUG
        std::cout << "POINT dectructor\n";
    #endif

    x = NAN;
    y = NAN;
    z = NAN;
}

coords_type point::get_x() const // OK
{
    return x;
}

coords_type point::get_y() const // OK
{
    return y;
}

coords_type point::get_z() const // OK
{
    return z;
}

void point::print_point() // OK
{
    std::cout << "x = " + std::to_string(get_x()) + " " + " y = "+ std::to_string(get_y()) + " " +" z = "+ std::to_string(get_z()) << std::endl;
}

/*###############################################################################################*/

vector::vector(const coords_type& x1, const coords_type& y1, const coords_type& z1, const coords_type& x2, const coords_type& y2, const coords_type& z2) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR constructor\n";
    #endif

    start.x = x1;
    start.y = y1;
    start.z = z1;

    end.x = x2;
    end.y = y2;
    end.z = z2;

    i = x2 - x1;
    j = y2 - y1;
    k = z2 - z1;

    calc_module();
}

vector::~vector() // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR dectructor\n";
    #endif

    start.x = NAN;
    start.y = NAN;
    start.z = NAN;

    end.x = NAN;
    end.y = NAN;
    end.z = NAN;

    i = NAN;
    j = NAN;
    k = NAN;
    module = NAN;
}

void vector::print_vector() // OK
{
    std::cout << "\nVector start x = " + std::to_string(start.get_x()) + " " + " y = "+ std::to_string(start.get_y()) + " " +" z = "+ std::to_string(start.get_z()) << std::endl;
    std::cout << "Vector end x = " + std::to_string(end.get_x()) + " " + " y = "+ std::to_string(end.get_y()) + " " +" z = "+ std::to_string(end.get_z()) << std::endl; 
    std::cout << "i = " + std::to_string(i) << std::endl;
    std::cout << "j = " + std::to_string(j) << std::endl;
    std::cout << "k = " + std::to_string(k) << std::endl;
    std::cout << "Vector module = " + std::to_string(module) << std::endl << std::endl;
}

void vector::get_start(coords_type& x1, coords_type& y1, coords_type& z1) const// OK
{
    #ifdef DEBUG
        std::cout << "VECTOR start getter\n";
    #endif

    x1 = start.get_x();
    y1 = start.get_y();
    z1 = start.get_z();
}

void vector::get_end(coords_type& x2, coords_type& y2, coords_type& z2) const// OK
{
    #ifdef DEBUG
        std::cout << "VECTOR end getter\n";
    #endif

    x2 = end.get_z();
    y2 = end.get_y();
    z2 = end.get_z();
}

double vector::get_module() const// OK
{
    #ifdef DEBUG
        std::cout << "VECTOR module getter\n";
    #endif

    return module;
}

void vector::calc_module() // OK
{
    if(isnan(i) || isnan(j) || isnan(k))
    {
        std::cout << "\nModule can't be calculated. Some components of the vector are NAN value\n";
        module = NAN;
    }
    else
    {
        module = sqrt(i * i + j * j + k * k);
    }
}

coords_type vector::get_i() const // OK
{
    return i;
}

coords_type vector::get_j() const // OK
{
    return j;
}

coords_type vector::get_k() const // OK
{
    return k;
}

/*###############################################################################################*/


// template <class T>
// void run_time(T func_ptr)
// {    
//     clock_t start = clock();
//     func_ptr();
//     clock_t end = clock();

//     printf("Function worked for = %lf\n", ((double) (end - start)) / CLOCKS_PER_SEC);
// }