#include <gtest/gtest.h>
#include "class.hh"
#include "dep_mock.hh"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
TEST(SquareTwo, TestSquareTwo)
{
    MainClass obj;
}

TEST(MainClass, ThrowIfNoDependency)
{
    MainClass obj;

    EXPECT_THROW(obj.squareTwoDep(), std::exception);
}

TEST(MainClass, TestDependency)
{
    DepMock dep_mock;

    MainClass obj(&dep_mock);

    EXPECT_CALL(dep_mock, get()).WillOnce(::testing::Return(5.0f));
    float res = obj.squareTwoDep();

    EXPECT_NEAR(res, 25.0, 1e-8);
}