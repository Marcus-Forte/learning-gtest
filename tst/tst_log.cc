#include <gtest/gtest.h>
#include "algebraClass.hh"
#include "logger_mock.hh"
using namespace testing;
TEST(AlgebraClass, testLongOpLogging)
{
    MockLogger mock_logger;

    AlgebraClass obj;

    obj.setLogger(&mock_logger);

    EXPECT_CALL(mock_logger, info(StrEq("Long operationg starting...")));
    EXPECT_CALL(mock_logger, info(StrEq("Long operation over...")));

    auto ret = obj.longOperation(10.0);

    EXPECT_NEAR(ret, 100.0, 1e-8);
}