#ifdef __APPLE__
    #include <sys/uio.h>
#else
    #include <sys/io.h>
#endif

#include <stdio.h>
#include <iostream>

#include "gtest/gtest.h"

#include "src/hello_world.c"

// TEST(test_case_name, test_name) {
TEST(HelloWorldTest, PrintHelloWorld) {
  char *stdout_contents;
  long temp_out_size;
  int stdout_dupfd;
  FILE *temp_out;
  size_t result;

  /* duplicate stdout */
  stdout_dupfd = dup(1);

  temp_out = fopen("tmp/test_output.txt", "w+");
  // freopen("redirected_filename.txt", "w", stdout);

  /* replace stdout with our output fd */
  dup2(fileno(temp_out), STDOUT_FILENO);

  /* output something... */
  // printf("Hello World\n");
  hello_world();

  /* flush output so it goes to our file */
  fflush(stdout);

  fseek(temp_out, 0, SEEK_END);
  temp_out_size = ftell(temp_out);
  rewind(temp_out);

  // stdout_contents = static_cast<char*>(malloc(temp_out_size * (sizeof(char))));
  stdout_contents = (char*) malloc(sizeof(char)* temp_out_size);
  if (stdout_contents == NULL) { fputs("Memory error\n", stderr); }

  // fread(stdout_contents, sizeof(char), temp_out_size, temp_out);
  result = fread(stdout_contents, sizeof(char), temp_out_size, temp_out);
  if (temp_out_size >= 0 && result != (size_t)temp_out_size) { fputs("Reading error\n", stderr); }

  fclose(temp_out);

  /* Now restore stdout */
  dup2(stdout_dupfd, STDOUT_FILENO);
  close(stdout_dupfd);

  const char* expected_output = "Hello World\n";
  EXPECT_EQ(0, strncmp(stdout_contents, expected_output, strlen(expected_output)));
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
