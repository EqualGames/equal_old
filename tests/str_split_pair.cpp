#include <equal/engine.hpp>
#include <gtest/gtest.h>
#include <string>
#include <string_view>
#include <utility>

using str_pair = std::pair<std::string, std::string>;

class STR_SPLIT_PAIR : public testing::Test {
public:
  STR_SPLIT_PAIR(){};
  ~STR_SPLIT_PAIR(){};
};

TEST_F(STR_SPLIT_PAIR, perfect) {
  str_pair e("Button", "Play");
  str_pair p = eq::str::split_pair("Button#Play", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, spaces_and_without_delimiter) {
  str_pair e("Container", "");
  str_pair p = eq::str::split_pair("  Container  ", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, spaces_with_delimiter) {
  str_pair e("Button", "Play");
  str_pair p = eq::str::split_pair("  Button#Play   ", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, start_space) {
  str_pair e("Button", "Play");
  str_pair p = eq::str::split_pair("  Button#Play", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, end_space) {
  str_pair e("Button", "Play");
  str_pair p = eq::str::split_pair("Button#Play  ", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, space_between) {
  str_pair e("Button", "Play");
  str_pair p = eq::str::split_pair("Button # Play", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, space_between_start) {
  str_pair e("Button", "Play");
  str_pair p = eq::str::split_pair("Button #Play", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, space_between_end) {
  str_pair e("Button", "Play");
  str_pair p = eq::str::split_pair("Button# Play", '#');

  EXPECT_EQ(p, e);
}

TEST_F(STR_SPLIT_PAIR, parse_attr) {
  str_pair e("position", "0 0");
  str_pair p = eq::str::split_pair("position: 0 0", ':');

  EXPECT_EQ(p, e);
}
