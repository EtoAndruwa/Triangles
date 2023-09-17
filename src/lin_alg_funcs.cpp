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

    // CHECK for nans??

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

void point::set_point(const coords_type& x, const coords_type& y, const coords_type& z)
{
    // #ifdef DEBUG
    //     std::cout << "POINT setter\n";
    // #endif

    // CHECK for nans??

    this->x = x;
    this->y = y;
    this->z = z;
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

void point::print_point() const // OK
{
    std::cout << "x = " + std::to_string(get_x()) + " " + " y = "+ std::to_string(get_y()) + " " +" z = "+ std::to_string(get_z()) << std::endl;
}

/*###############################################################################################*/

vector::vector(const coords_type& x1, const coords_type& y1, const coords_type& z1, const coords_type& x2, const coords_type& y2, const coords_type& z2)
{
    #ifdef DEBUG
        std::cout << "VECTOR constructor\n";
    #endif

    // CODE MUST BE CHANGED
    // CHECK for nans??

    start.set_point(x1, y1, z1);
    end.set_point(x2, y2, z2);

    i = x2 - x1;
    j = y2 - y1;
    k = z2 - z1;

    calc_module();
}

vector::vector() 
{
    #ifdef DEBUG
        std::cout << "VECTOR common constructor\n";
    #endif

    // CODE MUST BE CHANGED

    start.set_point(NAN, NAN, NAN);
    end.set_point(NAN, NAN, NAN);

    i = NAN;
    j = NAN;
    k = NAN;

    module = NAN;
}

vector::~vector() 
{
    #ifdef DEBUG
        std::cout << "VECTOR dectructor\n";
    #endif

    // CODE MUST BE CHANGED

    start.set_point(NAN, NAN, NAN);
    end.set_point(NAN, NAN, NAN);

    i = NAN;
    j = NAN;
    k = NAN;
    module = NAN;
}

void vector::print_vector() const// OK
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

void vector::set_end(const coords_type& x2, const coords_type& y2, const coords_type& z2) // OK
{
    end.set_point(x2, y2, z2);
}

void vector::set_start(const coords_type& x1, const coords_type& y1, const coords_type& z1) // OK
{
    start.set_point(x1, y1, z1);
}

/*###############################################################################################*/

triangle::triangle(const coords_type& x1, const coords_type& y1, const coords_type& z1, const coords_type& x2, const coords_type& y2, const coords_type& z2, 
            const coords_type& x3, const coords_type& y3, const coords_type& z3) // OK
{
    #ifdef DEBUG
        std::cout << "TRIANGLE constructor\n";
    #endif

    // CODE MUST BE CHANGED

    A.set_point(x1, y1, z1);
    B.set_point(x2, y2, z2);
    C.set_point(x3, y3, z3);

    AB.set_start(x1, y1, z1);
    AB.set_end(x2, y2, z2);
    AB.i = x2 - x1;
    AB.j = y2 - y1;
    AB.k = z2 - z1; 
    AB.calc_module();

    BC.set_start(x2, y2, z2);
    BC.set_end(x3, y3, z3);
    BC.i = x3 - x2;
    BC.j = y3 - y2;
    BC.k = z3 - z2; 
    BC.calc_module();

    CA.set_start(x3, y3, z3);
    CA.set_end(x1, y1, z1);
    CA.i = x1 - x3;
    CA.j = y1 - y3;
    CA.k = z1 - z3; 
    CA.calc_module();

    calc_area();
}   

triangle::~triangle() 
{
    #ifdef DEBUG
        std::cout << "TRIANGLE dectructor\n";
    #endif

    // CODE MUST BE CHANGED

    A.set_point(NAN, NAN, NAN);
    B.set_point(NAN, NAN, NAN);
    C.set_point(NAN, NAN, NAN);

    AB.set_start(NAN, NAN, NAN);
    AB.set_end(NAN, NAN, NAN);
    AB.i = NAN;
    AB.j = NAN;
    AB.k = NAN; 
    AB.module = NAN;

    BC.set_start(NAN, NAN, NAN);
    BC.set_end(NAN, NAN, NAN);
    BC.i = NAN;
    BC.j = NAN;
    BC.k = NAN; 
    BC.module = NAN;

    CA.set_start(NAN, NAN, NAN);
    CA.set_end(NAN, NAN, NAN);
    CA.i = NAN;
    CA.j = NAN;
    CA.k = NAN; 
    CA.module = NAN;

    area = NAN;
}

void triangle::print_triangle() const
{
    printf("\n###############################################################\n");
    printf("Point A(%lf, %lf, %lf)\n", A.get_x(), A.get_y(), A.get_z());
    printf("Point B(%lf, %lf, %lf)\n", B.get_x(), B.get_y(), B.get_z());
    printf("Point C(%lf, %lf, %lf)\n", C.get_x(), C.get_y(), C.get_z());
    printf("Vector AB(%lf, %lf, %lf)\n", AB.get_i(), AB.get_j(), AB.get_k());
    printf("Vector BC(%lf, %lf, %lf)\n", BC.get_i(), BC.get_j(), BC.get_k());
    printf("Vector CA(%lf, %lf, %lf)\n", CA.get_i(), CA.get_j(), CA.get_k());
    printf("Area = %lf\n", area);
    printf("###############################################################\n\n");
}

void triangle::calc_area()
{
    area = (AB ^ (CA * (-1))).get_module() / 2;
}

float triangle::get_area() const
{
    return area;
}

/*###############################################################################################*/

bool simpl_triangle_inter(const triangle& triangle1, const triangle& triangle2)
{
    if(check_top_inter(triangle1.A, triangle2))
    {
        printf("Intersection in peek A\n");
        // triangle1.print_triangle();
        // triangle2.print_triangle();
        return true;
    }
    else if(check_top_inter(triangle1.B, triangle2))
    {
        printf("Intersection in peek B\n");
        // triangle1.print_triangle();
        // triangle2.print_triangle();
        return true;
    }
    else if(check_top_inter(triangle1.C, triangle2))
    {
        printf("Intersection in peek B\n");
        // triangle1.print_triangle();
        // triangle2.print_triangle();
        return true;
    }
    return false;
}

bool check_top_inter(const point& point, const triangle triangl)
{
    return point == triangl.A ||  point == triangl.B || point == triangl.C;
}

