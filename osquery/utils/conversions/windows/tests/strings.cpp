/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed in accordance with the terms specified in
 *  the LICENSE file found in the root directory of this source tree.
 */

#include <string>

#include <gtest/gtest.h>

#include <osquery/utils/conversions/windows/strings.h>

namespace osquery {

class ConversionsTests : public testing::Test {};

TEST_F(ConversionsTests, test_string_to_wstring) {
  std::string narrowString{"The quick brown fox jumps over the lazy dog"};
  auto wideString = stringToWstring(narrowString.c_str());
  std::wstring expected{L"The quick brown fox jumps over the lazy dog"};
  EXPECT_EQ(wideString, expected);
}

TEST_F(ConversionsTests, test_wstring_to_string) {
  std::wstring wideString{L"The quick brown fox jumps over the lazy dog"};
  auto narrowString = wstringToString(wideString.c_str());
  std::string expected{"The quick brown fox jumps over the lazy dog"};
  EXPECT_EQ(narrowString, expected);
}

TEST_F(ConversionsTests, test_string_to_wstring_extended) {
  std::string narrowString{"fr\xc3\xb8tz-jorn"};
  auto wideString = stringToWstring(narrowString.c_str());
  std::wstring expected{L"fr\x00f8tz-jorn"};
  EXPECT_EQ(wideString, expected);
}

TEST_F(ConversionsTests, test_wstring_to_string_extended) {
  std::wstring wideString{L"fr\x00f8tz-jorn"};
  auto narrowString = wstringToString(wideString.c_str());
  std::string expected{"fr\xc3\xb8tz-jorn"};
  EXPECT_EQ(narrowString, expected);
}

} // namespace osquery
