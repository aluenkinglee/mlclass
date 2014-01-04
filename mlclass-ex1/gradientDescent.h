#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include "armadillo"

using namespace arma;
using namespace std;

namespace mlclass{
namespace ex1{
    mat gradientDescent(mat X, vec y, mat& theta, double alpah,long num_inters);
}
}

#endif 
