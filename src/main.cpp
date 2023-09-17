#include "triangles.h"

int main(int argc, char** argv)
{
    triangle ABC(0,0,0,2,0,0,0,0,2);
    ABC.print_triangle();

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

