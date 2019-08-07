#include <string>
#include <string_view>
#include <utility>
#include <gtest/gtest.h>
#include <equal/engine.hpp>

class HELPER_GUID : public testing::Test {
public:
  HELPER_GUID(){};
  ~HELPER_GUID(){};
};

TEST_F(HELPER_GUID, test) {
  EXPECT_NO_THROW(eq::GenerateUUID());
  std::string guid = eq::GenerateUUID();
  EXPECT_FALSE(guid.empty());
  EXPECT_EQ(guid.length(), 36);
}
