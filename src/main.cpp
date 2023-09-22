#include "triangles.h"

int main(int argc, char** argv)
{
    // triangle triangle1(0,0,0,2,0,0,0,0,2);
    // triangle triangle2(0,0,1,2,0,0,2,0,2);
    // simpl_triangle_inter(triangle1, triangle2);

    // vector vec1(0, 0, 0, 0, 0, 2);
    // vector vec2(1, 0, 4, 0, 0, 6);
    // printf("Is collinear %d\n", check_vec_collinear(vec1, vec2));

    // vector vec3(0, 0, 0, 0, 0, 1);
    // vector vec4(1, 0, 0, 0, 0, 0);
    // printf("Is perdenticular %d\n", check_vec_perpend(vec3, vec4));


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

