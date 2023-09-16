#include "triangles.h"

/*###############################################################################################*/

point::point() // OK
{
    #ifdef DEBUG
        std::cout << "POINT common constructor\n";
    #endif

    set_x(NAN);
    set_y(NAN);
    set_z(NAN);
}

point::point(coords_type x, coords_type y, coords_type z) // OK
{
    #ifdef DEBUG
        std::cout << "POINT constructor\n";
    #endif

    set_x(x);
    set_y(y);
    set_z(z);
}

point::~point() // OK
{
    #ifdef DEBUG
        std::cout << "POINT dectructor\n";
    #endif

    set_x(NAN);
    set_y(NAN);
    set_z(NAN);
}

void point::set_x(coords_type x) // Ok
{
    this->x = x;
}

void point::set_y(coords_type y) // OK
{
    this->y = y;
}

void point::set_z(coords_type z) // OK
{
    this->z = z;
}

coords_type point::get_x() // OK
{
    return x;
}

coords_type point::get_y() // OK
{
    return y;
}

coords_type point::get_z() // OK
{
    return z;
}

void point::print_point() // OK
{
    std::cout << "x = " + std::to_string(get_x()) + " " + " y = "+ std::to_string(get_y()) + " " +" z = "+ std::to_string(get_z()) << std::endl;
}

/*###############################################################################################*/

vector::vector() // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR common constructor\n";
    #endif
    
    set_start(NAN, NAN, NAN);
    set_end(NAN, NAN, NAN);
}

vector::vector(coords_type x1, coords_type y1, coords_type z1, coords_type x2, coords_type y2, coords_type z2) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR constructor\n";
    #endif

    set_start(x1, y1, z1);
    set_end(x2, y2, z2);
}

vector::~vector() // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR dectructor\n";
    #endif

    set_start(NAN, NAN, NAN);
    set_end(NAN, NAN, NAN);
}

void vector::set_start(coords_type x1, coords_type y1, coords_type z1) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR start set_ter\n";
    #endif

    start.set_x(x1);
    start.set_y(y1);
    start.set_z(z1);
}

void vector::set_end(coords_type x2, coords_type y2, coords_type z2) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR end set_ter\n";
    #endif

    end.set_x(x2);
    end.set_y(y2);
    end.set_z(z2);
}

void vector::print_vector() // OK
{
    std::cout << "Vector start x = " + std::to_string(start.get_x()) + " " + " y = "+ std::to_string(start.get_y()) + " " +" z = "+ std::to_string(start.get_z()) << std::endl;
    std::cout << "Vector end x = " + std::to_string(end.get_x()) + " " + " y = "+ std::to_string(end.get_y()) + " " +" z = "+ std::to_string(end.get_z()) << std::endl;
}

void vector::get_start(coords_type& x1, coords_type& y1, coords_type& z1) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR start get_ter\n";
    #endif

    x1 = start.get_x();
    y1 = start.get_y();
    z1 = start.get_z();
}

void vector::get_end(coords_type& x2, coords_type& y2, coords_type& z2) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR end get_ter\n";
    #endif

    x2 = end.get_z();
    y2 = end.get_y();
    z2 = end.get_z();
}

void vector::set_module(double& module_val) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR module get_ter\n";
    #endif

    module = module_val;
}

void vector::get_module(double& module_val) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR module get_ter\n";
    #endif

    module_val = module;
}



/*###############################################################################################*/