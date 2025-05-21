#include <gtest/gtest.h>
#include "sub.h"

TEST(SubTest, HandlesPositiveInput)
{
int resta = sub(5, 1);

EXPECT_EQ(resta, 4);
}
