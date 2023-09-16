#include "triangles.h"

/*###############################################################################################*/

point::point() // OK
{
    #ifdef DEBUG
        std::cout << "POINT common constructor\n";
    #endif

    setX(NAN);
    setY(NAN);
    setZ(NAN);
}

point::point(coords_type x, coords_type y, coords_type z) // OK
{
    #ifdef DEBUG
        std::cout << "POINT constructor\n";
    #endif

    setX(x);
    setY(y);
    setZ(z);
}

point::~point() // OK
{
    #ifdef DEBUG
        std::cout << "POINT dectructor\n";
    #endif

    setX(NAN);
    setY(NAN);
    setZ(NAN);
}

void point::setX(coords_type x) // Ok
{
    this->x = x;
}

void point::setY(coords_type y) // OK
{
    this->y = y;
}

void point::setZ(coords_type z) // OK
{
    this->z = z;
}

coords_type point::getX() // OK
{
    return x;
}

coords_type point::getY() // OK
{
    return y;
}

coords_type point::getZ() // OK
{
    return z;
}

void point::print_point() // OK
{
    std::cout << "x = " + std::to_string(getX()) + " " + " y = "+ std::to_string(getY()) + " " +" z = "+ std::to_string(getZ()) << std::endl;
}

/*###############################################################################################*/

vector::vector() // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR common constructor\n";
    #endif
    
    setStart(NAN, NAN, NAN);
    setEnd(NAN, NAN, NAN);
}

vector::vector(coords_type x1, coords_type y1, coords_type z1, coords_type x2, coords_type y2, coords_type z2) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR constructor\n";
    #endif

    setStart(x1, y1, z1);
    setEnd(x2, y2, z2);
}

vector::~vector() // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR dectructor\n";
    #endif

    setStart(NAN, NAN, NAN);
    setEnd(NAN, NAN, NAN);
}

void vector::setStart(coords_type x1, coords_type y1, coords_type z1) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR start setter\n";
    #endif

    start.setX(x1);
    start.setY(y1);
    start.setZ(z1);
}

void vector::setEnd(coords_type x2, coords_type y2, coords_type z2) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR end setter\n";
    #endif

    end.setX(x2);
    end.setY(y2);
    end.setZ(z2);
}

void vector::print_vector() // OK
{
    std::cout << "Vector start x = " + std::to_string(start.getX()) + " " + " y = "+ std::to_string(start.getY()) + " " +" z = "+ std::to_string(start.getZ()) << std::endl;
    std::cout << "Vector end x = " + std::to_string(end.getX()) + " " + " y = "+ std::to_string(end.getY()) + " " +" z = "+ std::to_string(end.getZ()) << std::endl;
}

void vector::getStart(coords_type& x1, coords_type& y1, coords_type& z1) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR start getter\n";
    #endif

    x1 = start.getX();
    y1 = start.getY();
    z1 = start.getZ();
}

void vector::getEnd(coords_type& x2, coords_type& y2, coords_type& z2) // OK
{
    #ifdef DEBUG
        std::cout << "VECTOR end getter\n";
    #endif

    x2 = end.getX();
    y2 = end.getY();
    z2 = end.getZ();
}
/*###############################################################################################*/