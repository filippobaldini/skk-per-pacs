#ifndef __CAUCHY_PROBLEM_HPP__
#define __CAUCHY_PROBLEM_HPP__
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <iostream>

// Write a function that takes in input a function wrapper that defines f, the initial condition,
// the final time T, the number of steps N (and any other data you deem appropriate) and
// returns an array with the vectors containing tn and un for all n.

using scalar_f = std::function<double(double)>;
using force_type = std::function<double(double, double)>;


struct output{
std::vector<double> u_n;
std::vector<double> t_n;
};
// struct output{
//     double u_n;
//     double t_n;
// };


void mysolver(force_type f, double y_0, double T, unsigned N, output & osk);

// class problem {
//     public:

//     private:

// }

double computing_L_inf_error(std::vector<double> & u_n, std::vector<double> & t_n, std::function<double(double)> u_ex);


#endif