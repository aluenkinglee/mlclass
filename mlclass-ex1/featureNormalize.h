#ifndef FEATURE_NORMALIZE_H
#define FEATURE_NORMALIZE_H

#include "armadillo"

using namespace arma;
using namespace std;

namespace mlclass{
namespace ex1{
    mat featureNormalize(const mat& X, mat& mu, mat& sigma);
    void zscore(mat& X,const mat& mu, const mat& sigma);
}
}

#endif 
