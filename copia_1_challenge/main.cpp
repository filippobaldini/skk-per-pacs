#include "Cauchy_problem.cpp"
#include <iostream>
#include <vector>
#include <cmath>


int main(){
//    auto y = []( double t){ return exp(-t);};
    auto f = [](double y, double t){ return -t*exp(-y)*t;};
    double y_0 = 0;
    double T = 1;
    unsigned N = 10;
    output osk;
    osk.u_n.push_back(3);

    output res = solver(f,  y_0, T, N);
    std::cout << res.u_n[0] << std::endl;
    return 0;
}