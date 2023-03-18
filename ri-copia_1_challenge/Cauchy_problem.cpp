#include "Cauchy_problem.hpp"
//#include "basicZeroFun.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

// to compile:
// g++ Cauchy_problem.cpp -o  Cauchy_problem -I/home/pietr/pacs_directory/pacs-examples/Examples/src/LinearAlgebraUtil -I/home/pietr/pacs_directory/pacs-examples/Examples/include -I/home/pietr/pacs_directory/pacs-examples/Examples/src/Utilitie



const auto solver(force_type &f, double y_0, double T, unsigned N){
    output osk;
    double h=T/N;
    for(size_t i=0; i<=N; ++i){
        osk.t_n.push_back(0+T/N*i);
    }
    auto F = [=](double x,double t_1,double t_2,double u_n){
        return x-h/2*(f(t_1, u_n)+f(t_2, u_n))-u_n;
    };
    osk.u_n.push_back(y_0);

    for(size_t i=1; i<=N; ++i){
        auto F_x = [=](double x){
            return F(x, osk.t_n[i-1], osk.t_n[i], osk.u_n[i-1]);
        };
        //std::tuple<double, bool>    secant(Function const &F, double a, double b);
    }

    return osk;
}

// constexpr int func( int , int ){return 1;};

// int main(){

//  // a function
// struct F2{ // a function object
// int operator ()( int , int ) const {return 0;} ;};
// // a vector of functions
// std::vector<std::function< int ( int , int )>> tasks ;
// tasks.push_back(func );// wraps a function
// tasks.push_back(F2{});// wraps a functor
// tasks.push_back([]( int x, int y){ return x*y;});// a lambda
// for ( auto i : tasks) std::cout<<i(3,4)<<std::endl ;

