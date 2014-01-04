#include "featureNormalize.h"

namespace mlclass{
namespace ex1{
    // returns a normalized version of X where
    // the mean value of each feature is 0 and the standard deviationis 1. 
    mat featureNormalize(const mat& X, mat& mu, mat& sigma){
        // X is a matrix where each column is a feature and 
        // each row is an example.
        
        mat X_norm = X;
        
        // find a particular statistic for each column (dim=0)
        mu = mean(X, 0);
        // using norm_type=1 performs normalisation using N,
        sigma = stddev(X, 1);
        
        zscore(X_norm, mu, sigma);
        
        return X_norm;
    }
    // Z-score :removes the mean and normalizes the data 
    void zscore(mat& X,const mat& mu, const mat& sigma){
        // instance numbers;
        long m = X.n_rows;
        for (long i = 0 ; i < m ; i++){
            X.row(i) = (X.row(i) - mu) / sigma;
        }
    }
}
} 
