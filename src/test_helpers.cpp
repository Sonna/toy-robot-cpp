#include "src/test_helpers.h"

#include <stdio.h>
#include <iostream>

// const char * capture_output(void (*block)()) {
const char * capture_output(std::function<void()> block) {
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
  block();

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

  return stdout_contents;
}

const char * capture_output(
    std::function<void(const std::string command, const std::string args)> block,
    // std::function<void()> block,
    const std::string command,
    const std::string args
) {
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
  block(command, args);

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

  return stdout_contents;
}
