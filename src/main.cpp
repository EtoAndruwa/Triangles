#include "triangles.h"

int main(int argc, char* argv[])
{
    vector v1(1, 2, 3, 5, 6, 7);
    vector v2(5, 6, 7, 11, 12, 13);

    v1.print_vector(); 
    v2.print_vector();   

    vector v3 = v1 + v2;
    v3.print_vector();   
    
 
    return 0;
}

