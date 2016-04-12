#include "integration.hpp"

double int_cavalieri_simpson(double x1, double x2, double x3) {
    return (x1 + 4*x2 + x3)/6;
}
