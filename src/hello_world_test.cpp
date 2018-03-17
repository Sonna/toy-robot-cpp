#include "src/test_helpers.h"

#include "src/hello_world.c"

// TEST(test_case_name, test_name) {
TEST(HelloWorldTest, PrintHelloWorld) {
  const char* stdout_contents = capture_output(hello_world);
  const char* expected_output = "Hello World\n";

  ASSERT_STREQ(stdout_contents, expected_output);
}

TEST(StrcmpTest, strcmp) {
  std::string str1 ("green apple");
  std::string str2 ("green apple");

  EXPECT_EQ(0, str1.compare(str2));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
