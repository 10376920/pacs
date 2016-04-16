#ifndef TRIDIAGONAL_HPP
#define TRIDIAGONAL_HPP

#include <vector>

class tridiagonalMatrix {
  private:
    int _n;
    std::vector<double> _b;
    std::vector<double> _c;
    std::vector<double> _a;
    std::vector<double> _cprime;
  public:
    tridiagonalMatrix(): _n(2), _b(2,1.0), _c(1,0.0), _a(1,0.0) {}
    tridiagonalMatrix(int n,
                      std::vector<double> diag,
                      std::vector<double> up,
                      std::vector<double> down);
    void thomasFactorize();
    std::vector<double> thomasSolve(std::vector<double> f);
    void print();
};
#endif
