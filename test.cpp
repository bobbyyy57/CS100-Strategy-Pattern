#include "spreadsheet.hpp"
#include "not.hpp"
#include "and.hpp" 
#include "contains.hpp"
#include "select.hpp"
#include "or.hpp"

#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
