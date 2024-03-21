#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "algebraClass.hh"
#include "noise_mock.hh"
#include "logger_mock.hh"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(AlgebraClass, SquareTwo) {
    AlgebraClass alg;
    

    auto expect = alg.squareTwo(5);
    EXPECT_NEAR(expect, 25.0, 1e-7);
    EXPECT_NEAR(alg.squareTwo(25), 625.0, 1e-7);
}

TEST(AlgebraClass, SquareTwoNoiseThrow) {
    AlgebraClass alg;
    
    EXPECT_THROW(alg.squareTwoNoise(1.0), std::exception);
}

TEST(AlgebraClass, SquareTwoNoise) {
    MockNoise mock_noise;
    AlgebraClass alg(&mock_noise);

    EXPECT_CALL(mock_noise, addNoise).WillOnce(testing::Return(1.0));

    auto res = alg.squareTwoNoise(5);

    EXPECT_NEAR(res, 26.0, 1e-7);
}

TEST(AlgebraClass, testLongOpLogging)
{
    MockLogger mock_logger;

    AlgebraClass obj;

    obj.setLogger(&mock_logger);

    EXPECT_CALL(mock_logger, info(testing::StrEq("Long operationg starting...")));
    EXPECT_CALL(mock_logger, info(testing::StrEq("Long operation over...")));

    auto ret = obj.longOperation(10.0);

    EXPECT_NEAR(ret, 100.0, 1e-8);
}