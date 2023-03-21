#include "Cauchy_problem.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>



int main(){
//    auto y = []( double t){ return exp(-t);};

    auto exact_sol = [](double t) {return log(-std::pow(t, 3)/3+1);};
    auto f = [](double t, double y){ return -t*exp(-y)*t;};
    double y_0 = 0;
    double T = 1;
    unsigned N = 10000;
    output res;
    res.u_n.reserve(N+1);
    res.t_n.reserve(N+1);
    // osk.u_n.push_back(3);

    mysolver(f,  y_0, T, N, res);
    // for (unsigned i=0; i<res.t_n.size(); ++i){
    //     std::cout << res.u_n[i] << std::endl;
    // }
    // std::cout << std::endl;
    // for (unsigned i=0; i<res.t_n.size(); ++i){
    //     std::cout << res.u_n[i] << std::endl;
    // }

    std::ofstream o_filesk("results.dat");
    for (unsigned i=0; i<res.t_n.size(); ++i){
        o_filesk.setf(std::ios::left, std::ios::adjustfield);
        o_filesk << res.t_n[i] << "\t\t" << res.u_n[i] << "\n";
    }

    int myNs[6] = {64, 128, 256, 512, 1024, 2048};

    for(int N1:myNs){
        output res_conv;
        res_conv.u_n.reserve(N1+1);
        res_conv.t_n.reserve(N1+1);

        mysolver(f,  y_0, T, N1, res_conv);

        double prova = computing_L_inf_error(res_conv.u_n, res_conv.t_n, exact_sol);
        std::cout << std::endl << prova << std::endl;
    }



    
    return 0;
}