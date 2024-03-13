#include <gtest/gtest.h>
#include "algebraClass.hh"
#include "noise_mock.hh"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(AlgebraClass, testSquareTwo)
{
    AlgebraClass obj;

    EXPECT_NEAR(25.0, obj.squareTwo(5.0), 1e-9);
    EXPECT_NEAR(9.0, obj.squareTwo(3.0), 1e-9);
    EXPECT_NEAR(900.0, obj.squareTwo(30.0), 1e-9);
}

TEST(AlgebraClass, testSquareTwoNoiseThrow)
{
    AlgebraClass obj;
    
    EXPECT_THROW(obj.squareTwoNoise(5.0), std::exception);

    try {
        obj.squareTwoNoise(5.0); 
    } catch (std::exception ex) {
        EXPECT_STREQ(ex.what(), "No noise object found!");
    }
}

TEST(AlgebraClass, testSquareTwoNoise) {
    MockNoise noise;

    AlgebraClass obj(&noise);

    EXPECT_CALL(noise, addNoise);
    obj.squareTwoNoise(5.0);
}

TEST(AlgebraClass, testSquareTwoNoiseAddition) {
    MockNoise noise;

    AlgebraClass obj(&noise);

    EXPECT_CALL(noise, addNoise).WillOnce(testing::Return(1.0));
    float square_plus_noise = obj.squareTwoNoise(5.0);
    EXPECT_NEAR(square_plus_noise, 26.0, 1e-9);
}
