#include <iostream>
#include "algebraClass.hh"

int main() {
    AlgebraClass alg;
    auto sqr = alg.squareTwo(5);

    std::cout << "Result: " << sqr << std::endl;
    return 0;
}