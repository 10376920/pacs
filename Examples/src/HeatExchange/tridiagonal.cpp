#include "tridiagonal.hpp"
#include <iostream>

tridiagonalMatrix::tridiagonalMatrix(int n,
                                     std::vector<double> b,
                                     std::vector<double> c,
                                     std::vector<double> a) {
    _n = n;
    if (n < 2) {
        std::cout << "Error: in a tridiagonal matrix n must be >= 2" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (b.size() != n) {
        std::cout << "Error: b.size() must be equal to n" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (c.size() != n-1) {
        std::cout << "Error: c.size() must be equal to n-1" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (a.size() != n-1) {
        std::cout << "Error: a.size() must be equal to n-1" << std::endl;
        exit(EXIT_FAILURE);
    }
    _n = n;
    _b = b;
    _c = c;
    _a = a;
}

void tridiagonalMatrix::thomasFactorize() {
    _cprime.reserve(_n-1);
    _cprime.clear();
    _cprime.push_back(_c[0]/_b[0]);
    for (int i=1; i<_n-1; ++i) {
        _cprime.push_back(_c[i]/(_b[i]-_a[i-1]*_cprime[i-1]));
    }
//    std::cout << "_cprime:\n";
//    for (auto it = _cprime.begin(); it != _cprime.end(); ++it) {
//        std::cout << *it << ", ";
//    }
    std::cout << std::endl;
}

std::vector<double> tridiagonalMatrix::thomasSolve(std::vector<double> d) {
    std::vector<double> dprime;
    dprime.reserve(_n);
    dprime.push_back(d[0]/_b[0]);
    for (int i=1; i<_n; ++i) {
        dprime.push_back((d[i] - _a[i-1]*dprime[i-1]) /
                        (_b[i] - _a[i-1]*_cprime[i-1]));
    }
//    std::cout << "dprime:\n";
//    for (auto it = dprime.begin(); it != dprime.end(); ++it) {
//        std::cout << *it << ", ";
//    }
//    std::cout << std::endl;
    std::vector<double> x(_n, 0.0);
    x[_n-1] = dprime[_n-1];
    for (int i = _n-2; i>=0; --i) {
        x[i] = dprime[i] - _cprime[i]*x[i+1];
    }
    return x;
}

void tridiagonalMatrix::print() {
    std::cout << "b =\n";
    for (auto it=_b.begin(); it != _b.end(); ++it) {
        std::cout << *it << "\n";
    }
    std::cout << "c =\n";
    for (auto it=_c.begin(); it != _c.end(); ++it) {
        std::cout << *it << "\n";
    }
    std::cout << "a =\n";
    for (auto it=_a.begin(); it != _a.end(); ++it) {
        std::cout << *it << "\n";
    }
}
