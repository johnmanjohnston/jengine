#pragma once
#include <cassert>
#include <iostream>
#define EASSERT(x, desc) { std::cout << "Asserting " << desc << std::endl; assert(x); }

#define WIDTH 640
#define HEIGHT 640