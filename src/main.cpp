#include "triangles.h"

int main(int argc, char* argv[])
{
    vector v1(0,0,0, 1, 0, 0);
    vector v2(0, 0, 0, 0, 1, 0);


    v1.print_vector(); 
    v2.print_vector();   

    vector v3 = v1^v2;
    v3.print_vector();

    printf("Result %lf\n", v1*v2);

    
 
    return 0;
}

