#ifndef COMPUTECOST_H
#define COMPUTECOST_H

#include "armadillo"

using namespace arma;
using namespace std;

namespace mlclass{
namespace ex1{
  double computeCost(mat X, rowvec y, mat theta);
  double computeCost(mat X, colvec y, mat theta);
  double computeCost(mat X, mat y, mat theta);
}
}

#endif