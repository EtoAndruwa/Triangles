#ifndef UNIT_TESTS
#define UNIT_TESTS

#include "triangles.h"

// #define DEBUG_U // for unit test comments

/**#####################################################*/

/*Unit tests for scalar multiplication of two vectors*/

TEST(vec_scal_mutp, scal_mult_1)
{
    vector v1(1, 0, 0, 1, 0, 0);
    vector v2(2, 0, 0, 0, 1, 0);

    ASSERT_TRUE(v1*v2 == 0);
}

TEST(vec_scal_mutp, scal_mult_2)
{
    vector v1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    vector v2(-1.0, 0.0, 1.0, 1.0, 2.0, -1.0);

    ASSERT_TRUE(v1*v2 == (v1.get_i() * v2.get_i() + v1.get_j() * v2.get_j()+ v1.get_k() * v2.get_k()));
}

TEST(vec_scal_mutp, scal_mult_3)
{
    vector v1(2.0, 3.0, 4.0, 0.0, 0.0, 0.0);
    vector v2(5.0, 6.0, 7.0, 8.0, 9.0, 10.0);

    ASSERT_TRUE(v1*v2 == (v1.get_i() * v2.get_i() + v1.get_j() * v2.get_j()+ v1.get_k() * v2.get_k()));
}

TEST(vec_scal_mutp, scal_mult_4)
{
    vector v1(1, 0, 4, 0, 1, 0);
    vector v2(2, 5, 0, 0, 1, 8);

    ASSERT_TRUE(v1*v2 == (v1.get_i() * v2.get_i() + v1.get_j() * v2.get_j()+ v1.get_k() * v2.get_k()));
}

/**#####################################################*/

/*Unit tests for sum of two vectors*/

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

TEST(vec_sum, vec_sum_4)
{
    vector v1(2.5, 3.1, 4.2, 0.0, 0.8, 0.2);
    vector v2(5.6, 6.0, 7.9, 8.4, 9.0, 10.1);
    vector v3(2.5, 3.1, 4.2, 2.8, 3.8, 5.9);

    #ifdef DEBUG_U
        vector v4 = v1 + v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    ASSERT_FALSE(v3 == (v1 + v2));
}

// TEST(vec_sum, vec_sum_5)
// {
//     vector v1(0, 0, 0, 0, 0, 0);
//     vector v2(0, 0, 0, 0, 0, 0);
//     vector v3(0, 0, 0, 0, 0, 0);

//     #ifdef DEBUG_U
//         vector v4 = v1 + v2;
//         v4.print_vector();
//         v3.print_vector();
//     #endif

//     EXPECT_TRUE(v3 == (v1 + v2));
// }

/**#####################################################*/

/*Unit tests for two vectors being equal*/

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

/*Unit tests of multiplication vector by scalar*/

TEST(vec_mult_by_scal, mult_by_scal_1)
{
    vector v1(1, 0, 0, 1, 0, 0);
    vector v2(1, 0, 0, 2, 0, 0);

    ASSERT_TRUE(v1 * 2 != v2);
}

TEST(vec_mult_by_scal, mult_by_scal_2)
{
    vector v1(1, 2, 0, -1, 0, 10);
    vector v2(1, 2, 0, -3, -2, 20);

    #ifdef DEBUG_U
        vector v4 = v1 * 2;
        v4.print_vector();
        v2.print_vector();
    #endif

    ASSERT_TRUE(v1 * 2 == v2);
}

TEST(vec_mult_by_scal, mult_by_scal_3)
{
    vector v1(1, 0, 0, 2, 0, 0);
    vector v2(1, 0, 0, 3, 0, 0);

    #ifdef DEBUG_U
        vector v4 = v1 * 2;
        v4.print_vector();
        v2.print_vector();
    #endif

    ASSERT_TRUE(v1 * 2 == v2);
}

// TEST(vec_mult_by_scal, mult_by_scal_4)
// {
//     vector v1(1, 0, 0, 1, 0, 0);
//     vector v2(1, 0, 0, 1, 0, 0);

//     #ifdef DEBUG_U
//         vector v4 = v1 * 2;
//         v4.print_vector();
//         v2.print_vector();
//     #endif

//     ASSERT_TRUE(v1 * 2 == v2);
// }

/**#####################################################*/

/*Unit tests for sub of two vectors*/

TEST(vec_sub, vec_sub_1)
{
    vector v1(1, 0, 0, 1, 1, 0);
    vector v2(1, 0, 0, 2, 0, 0);
    vector v3(1, 0, 0, 0, 1, 0);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1 - v2));
}

TEST(vec_sub, vec_sub_2)
{
    vector v1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    vector v2(-1.0, 0.0, 1.0, 1.0, 2.0, -1.0);
    vector v3(1.0, 2.0, 3.0, 2, 3, 8);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1 - v2));
}

TEST(vec_sub, vec_sub_3)
{
    vector v1(2.0, 3.0, 4.0, 0.0, 0.0, 0.0);
    vector v2(5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
    vector v3(2.0, 3.0, 4.0, -3, -3, -3);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1 - v2));
}

TEST(vec_sub, vec_sub_4)
{
    vector v1(2.5, 3.1, 4.2, 0.0, 0.8, 0.2);
    vector v2(5.6, 6.0, 7.9, 8.4, 9.0, 10.1);
    vector v3(2.5, 3.1, 4.2, -2.8, -2.2, -2);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1 - v2));
}

/**#####################################################*/

/*Unit tests for vector multiplication of two vectors*/

TEST(vec_mult, vec_mult_1)
{
    vector v1(0, 0, 0, 1, 0, 0);
    vector v2(0, 0, 0, 0, 1, 0);
    vector v3(0, 0, 0, 0, 0, 1);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1^v2));
}

TEST(vec_mult, vec_mult_2)
{
    vector v1(0, 0, 0, 0, 0, 1);
    vector v2(0, 0, 0, 1, 0, 0);
    vector v3(0, 0, 0, 0, 1, 0);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1^v2));
}

TEST(vec_mult, vec_mult_3)
{
    vector v1(0, 0, 0, 0, 1, 0);
    vector v2(0, 0, 0, 0, 0, 1);
    vector v3(0, 0, 0, 1, 0, 0);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1^v2));
}

TEST(vec_mult, vec_mult_4)
{
    vector v1(0, 0, 0, 0, 0, 1);
    vector v2(0, 0, 0, 0, 1, 0);
    vector v3(0, 0, 0, -1, 0, 0);

    #ifdef DEBUG_U
        vector v4 = v1 - v2;
        v4.print_vector();
        v3.print_vector();
    #endif

    EXPECT_TRUE(v3 == (v1^v2));
}

/**#####################################################*/

/*Unit tests for the triangle's area calcultaion*/

TEST(vec_area, vec_area_1)
{
    triangle ABC(0, 0, 0, 2, 0, 0, 0, 0, 2);
    EXPECT_FLOAT_EQ(ABC.get_area(), 2);
}

TEST(vec_area, vec_area_2)
{
    triangle ABC(0, 0, 0, 0, 0, 0, 0, 0, 0);
    EXPECT_FLOAT_EQ(ABC.get_area(), 0);
}

TEST(vec_area, vec_area_3)
{
    triangle ABC(0, 0, 0, 1, 0, 0, 0, 0, 1);
    EXPECT_FLOAT_EQ(ABC.get_area(), 0.5);
}

/**#####################################################*/

//UNIT TEST FOR COLLINEAR

/**#####################################################*/

//UNIT TEST FOR PERPENDICULAR

/**#####################################################*/

//UNIT TEST FOR check_on_one_line

// TEST(check_on_one_line, test_1)
// {
//     vector v1(0, 0, 0, 1, 0, 0);
//     vector v2(0, 0, 0, 2, 0, 0);

//     EXPECT_TRUE(check_on_one_line(v1, v2));
// }

/**#####################################################*/

TEST(check_is_zero, test_1)
{
    EXPECT_EQ(check_is_sign(0), IS_ZERO);
}

TEST(check_is_zero, test_2)
{
    EXPECT_EQ(check_is_sign(EPS), IS_ZERO);
}

TEST(check_is_zero, test_3)
{
    EXPECT_EQ(check_is_sign(0.0), IS_ZERO);
}

/**#####################################################*/

TEST(check_val_in_interval, test_1)
{
    EXPECT_TRUE(check_val_in_interval(1, 2, 3));
}

TEST(check_val_in_interval, test_2)
{
    EXPECT_TRUE(check_val_in_interval(-1, 0, 10));
}

TEST(check_val_in_interval, test_3)
{
    EXPECT_TRUE(check_val_in_interval(-2.0, 0.0, 3.0));
}

TEST(check_val_in_interval, test_4)
{
    EXPECT_FALSE(check_val_in_interval(-2, -4, 3));
}

/**#####################################################*/

TEST(check_three_eq, test_1)
{
    EXPECT_TRUE(check_three_eq(0, 0, 0));
}

TEST(check_three_eq, test_2)
{
    EXPECT_FALSE(check_three_eq(-1, 0, 0));
}

TEST(check_three_eq, test_3)
{
    EXPECT_FALSE(check_three_eq(-2, -2, 3));
}

TEST(check_three_eq, test_4)
{
    EXPECT_TRUE(check_three_eq(-2.0, -2.0, -2.0));
}

/**#####################################################*/

TEST(check_point_one_direct, test_1)
{
    vector v1(0, 0, 0, 1, 0, 0);
    vector v2(0, 0, 0, 1, 1, 0);

    EXPECT_TRUE(check_point_one_direct(v1, v2));
}

TEST(check_point_one_direct, test_2)
{
    vector v1(0, 0, 0, 1, 0, 0);
    vector v2(0, 0, 0, 0, -1, 0);

    EXPECT_TRUE(check_point_one_direct(v1, v2));
}

TEST(check_point_one_direct, test_3)
{
    vector v1(0, 0, 0, 1, 2, 3);
    vector v2(0, 0, 0, 2, 4, 6);

    EXPECT_TRUE(check_point_one_direct(v1, v2));
}

TEST(check_point_one_direct, test_4)
{
    vector v1(0, 0, 0, 1, 2, 3);
    vector v2(1, 2, 3, 0, 2, 3);

    EXPECT_FALSE(check_point_one_direct(v1, v2));
}

TEST(check_point_one_direct, test_5)
{
    vector v1(0, 0, 0, 1, 1, 0);
    vector v2(0, 0, 0, 0, -1, 0);

    EXPECT_FALSE(check_point_one_direct(v1, v2));
}

/**#####################################################*/

TEST(check_on_one_line, test_1)
{
    vector v1(0, 0, 0, 1, 1, 1);
    vector v2(0, 0, 0, 1, 1, 1);

    EXPECT_TRUE(check_on_one_line(v1, v2));
}

TEST(check_on_one_line, test_2)
{
    vector v1(0, 0, 0, 1, 1, 1);
    vector v2(0, 0, 0, 2, 2, 2);

    EXPECT_TRUE(check_on_one_line(v1, v2));
}

TEST(check_on_one_line, test_3)
{
    vector v1(0, 0, 0, 1, 1, 1);
    vector v2(0, 0, 0, -2, -2, -5);

    EXPECT_FALSE(check_on_one_line(v1, v2));
}


/**#####################################################*/

#endif
