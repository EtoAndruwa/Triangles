#include "triangles.h"

int main(int argc, char* argv[])
{
    // #ifdef DEBUG
        
    // #endif

    // point p;
    // p.print_point();

    // point p1(1.5,2,3);
    // p1.print_point();

    vector v1(1, 2, 3, 5, 6, 7);

    coords_type x1 = 0;
    coords_type y1 = 0;
    coords_type z1 = 0;

    coords_type x2 = 0;
    coords_type y2 = 0;
    coords_type z2 = 0;

    v1.print_vector();  

    printf("\n");
    v1.get_start(x1, y1, z1);
    printf("x1 = %lf, y1 = %lf, z1 = %lf\n", x1, y1, z1);
    v1.get_end(x2, y2, z2);
    printf("x2 = %lf, y2 = %lf, z2 = %lf\n\n", x2, y2, z2);

    
 
    return 0;
}

