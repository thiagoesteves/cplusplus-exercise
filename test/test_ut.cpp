#include "gtest/gtest.h"
#include "exe1.h"

using namespace ::cplusplus_exercise;

/**
 * @brief This class is empty, you can create a test here
 */
class EmptyClass : public ::testing::Test {
 public:
  EmptyClass() {}
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

/**
 * @brief This is an empty test.
 */
TEST(EmptyClass, Test) {

}
