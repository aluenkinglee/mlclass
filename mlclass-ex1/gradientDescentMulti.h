#ifndef GRADIENT_DESCENT_MULTI_H
#define GRADIENT_DESCENT_MULTI_H

#include "armadillo"

using namespace arma;
using namespace std;

namespace mlclass{
namespace ex1{
    mat gradientDescentMulti(const mat& X, const vec& y, mat& theta, double alpah,long num_inters);
}
}

#endif 
 
