#include <iostream>
#include "class.h"

Time::Time(int x, int y) { first = x; second = y; }

Time::double minutes() { return second = second + (first * 60); }
