#include "triangles.h"

int main(int argc, char* argv[])
{
    vector v1(1, 2, 3, 5, 6, 7);
    // v1.set_end(1, 2, 3);

    v1.calc_module();
    v1.print_vector();  
    
 
    return 0;
}

