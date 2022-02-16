#include <gtest/gtest.h>
#include <iostream>
#include <Quaternion/quaternion.hpp>

TEST(tests, test0)
{  
    quaternion::Quaternion<int> q(0, 3, 0, -1);
    std::cout << (q * quaternion::Quaternion<int>(2, 0, 1, 1)).real() << std::endl;
}

TEST(arithmetic, multiplication)
{
    quaternion::Quaternion<int> q1(0, 3, 0, -1);
    quaternion::Quaternion<int> q2(2, 0, 1, 1);
    quaternion::Quaternion<int> expectedResult(1, 7, -3, 1);
    EXPECT_EQ(q1*q2, expectedResult);
}
