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

struct force{
  double operator()(double tn1, double tn2, force_type f,){return 0;};

};




 class Cproblem {
    public:
     Cproblem(force &f, double &y0, double &T) : forcing_term(f), init(y0), final_t(T) {};
     
     const auto solver(unsigned int N);

    private:
     force forcing_term;
     double final_t;
     double init;

 };



double
Newton(Function const &f, Dfunction const & df, double a, double tol = 1e-4,
       double tola = 1.e-10, unsigned int maxIt = 150);



#endif