#ifndef UNIT_TESTS
#define UNIT_TESTS

#include "triangles.h"

/**#####################################################*/

TEST(vec_scal_mutp, scal_mutp_1)
{
    vector v1(1, 0, 0, 1, 0, 0);
    vector v2(2, 0, 0, 0, 1, 0);

    ASSERT_TRUE(v1*v2 == 0);
}

TEST(vec_scal_mutp, scal_mutp_2)
{
    vector v1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    vector v2(-1.0, 0.0, 1.0, 1.0, 2.0, -1.0);

    ASSERT_TRUE(v1*v2 == (v1.get_i() * v2.get_i() + v1.get_j() * v2.get_j()+ v1.get_k() * v2.get_k()));
}

TEST(vec_scal_mutp, scal_mutp_3)
{
    vector v1(2.0, 3.0, 4.0, 0.0, 0.0, 0.0);
    vector v2(5.0, 6.0, 7.0, 8.0, 9.0, 10.0);

    ASSERT_TRUE(v1*v2 == (v1.get_i() * v2.get_i() + v1.get_j() * v2.get_j()+ v1.get_k() * v2.get_k()));
}

TEST(vec_scal_mutp, scal_mutp_4)
{
    vector v1(1, 0, 4, 0, 1, 0);
    vector v2(2, 5, 0, 0, 1, 8);

    ASSERT_TRUE(v1*v2 == (v1.get_i() * v2.get_i() + v1.get_j() * v2.get_j()+ v1.get_k() * v2.get_k()));
}

/**#####################################################*/

TEST(vec_sum, vec_sum_1)
{
    vector v1(1, 0, 0, 0, 0, 0);
    vector v2(2, 0, 0, 0, 1, 0);
    vector v3(1, 0, 0, -2, 1, 0);

    #ifdef DEBUG_U
        vector v4 = v1 + v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1 + v2));
}

TEST(vec_sum, vec_sum_2)
{
    vector v1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    vector v2(-1.0, 0.0, 1.0, 1.0, 2.0, -1.0);
    vector v3(1.0, 2.0, 3.0, 6, 7, 4);

    #ifdef DEBUG_U
        vector v4 = v1 + v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    ASSERT_TRUE(v3 == (v1 + v2));
}

TEST(vec_sum, vec_sum_3)
{
    vector v1(2.0, 3.0, 4.0, 0.0, 0.0, 0.0);
    vector v2(5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
    vector v3(2.0, 3.0, 4.0, 3, 3, 3);

    #ifdef DEBUG_U
        vector v4 = v1 + v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    ASSERT_TRUE(v3 == (v1 + v2));
}

/**#####################################################*/

TEST(vec_eq, vec_eq_1)
{
    vector v1(1, 0, 0, 0, 0, 0);
    vector v2(2, 0, 0, 0, 1, 0);

    EXPECT_FALSE(v1 == v2);
}

TEST(vec_eq, vec_eq_2)
{
    vector v1(1, 0, 5, 0, 2, 0);
    vector v2(2, 0, -1, 0, 1, 0);

    EXPECT_FALSE(v1 == v2);
}

TEST(vec_eq, vec_eq_3)
{
    vector v1(1, 0, -1, 0, 2, 2);
    vector v2(1, 0, -1, 8, 2, 2);

    EXPECT_FALSE(v1 == v2);
}

TEST(vec_eq, vec_eq_4)
{
    vector v1(1, 0, -1, 8, 2, 2);
    vector v2(1, 0, -1, 8, 2, 2);

    EXPECT_TRUE(v1 == v2);
}

/**#####################################################*/


/**#####################################################*/



/**#####################################################*/

#endif
