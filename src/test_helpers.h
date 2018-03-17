#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#ifdef __APPLE__
    #include <sys/uio.h>
#else
    #include <sys/io.h>
#endif

#include <functional>
#include <string>

#include "gtest/gtest.h"

const char * capture_output(std::function<void()> block);
// const char * capture_output(void (*block)());

#endif
