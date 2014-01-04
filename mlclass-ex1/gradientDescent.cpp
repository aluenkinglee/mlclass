#include "gradientDescent.h"
#include "computeCost.h"
using namespace mlclass::ex1;
namespace mlclass{
namespace ex1{
    //Performs gradient descent to learn theta
    mat gradientDescent(mat X, vec y, mat& theta, double alpah,long num_inters){
        //number of training examples
        long m = y.n_rows;
        
        mat J_history = zeros<mat>(num_inters,1);
        long i = 0;
        for (;i < num_inters; i++){
            theta = theta - alpah/m* (X.t()* (X*theta - y));
            J_history(i) = computeCost(X, y, theta);    
        }
        return J_history;
    }
}
}