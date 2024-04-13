#pragma once
#include <cassert>
#include <iostream>
#define EASSERT(x, desc) { std::cout << "Asserting " << desc << std::endl; assert(x); }