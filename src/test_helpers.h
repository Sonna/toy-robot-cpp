#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#ifdef __APPLE__
    #include <sys/uio.h>
#else
    #include <sys/io.h>
#endif

#include <string>

#include "gtest/gtest.h"

const char * capture_output(void (*block)());

#endif
