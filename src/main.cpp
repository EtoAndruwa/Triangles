#include "triangles.h"

int main(int argc, char** argv)
{
    triangle triangle1(0,0,0,2,0,0,0,0,2);
    triangle triangle2(0,0,1,2,0,0,2,0,2);
    simpl_triangle_inter(triangle1, triangle2);


    if((argc >= 2) && !strcmp("-Test", argv[1]))
    {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    else
    {
        return 0;
    }
}

