#include "Cauchy_problem.hpp"
#include <iostream>
#include <vector>
#include <cmath>


int main(){
//    auto y = []( double t){ return exp(-t);};
    auto f = [](double y, double t){ return -t*exp(-y)*t;};
    double y_0 = 0;
    double T = 1;
    unsigned N = 1000;
    output res;
    res.u_n.reserve(N+1);
    res.t_n.reserve(N+1);
    // osk.u_n.push_back(3);

    mysolver(f,  y_0, T, N, res);
    for (unsigned i=0; i<res.t_n.size(); ++i){
        std::cout << res.u_n[i] << std::endl;
    }
    // std::cout << std::endl;
    // for (unsigned i=0; i<res.t_n.size(); ++i){
    //     std::cout << res.u_n[i] << std::endl;
    // }

    
    return 0;
}