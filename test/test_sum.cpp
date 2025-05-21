#include <gtest/gtest.h>
#include "sum.h"

TEST(SumTest, HandlesPositiveInput)
{
int suma = sum(1, 5);

EXPECT_EQ(suma, 6);
}
