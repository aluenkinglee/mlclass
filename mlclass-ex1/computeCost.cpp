#include "computeCost.h"
namespace mlclass{
namespace ex1{
    double computeCost(mat X, rowvec y, mat theta){
        long m = y.n_elem;
        double J = 0;
        rowvec hypothesis = X * theta;
        
        J = sum(square(hypothesis - y)) / 2 /m;
        return J;
    }
    
    double computeCost(mat X, colvec y, mat theta){
        long m = y.n_elem;
        double J = 0;
        colvec hypothesis = X * theta;
        
        J = sum(square(hypothesis - y)) / 2 /m;
        return J;
    }
   
    double computeCost(mat X, mat y, mat theta){
        long m = y.n_elem;
        double J = 0;
        mat hypothesis = X * theta;
        
        J = accu(square(hypothesis - y)) / 2 /m;
        return J;
    }

}
}
