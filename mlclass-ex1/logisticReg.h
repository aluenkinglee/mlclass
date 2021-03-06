#ifndef LOGISTIC_REGRESSION_H
#define LOGISTIC_REGRESSION_H

#include <string>

#include "armadillo"
#include "featureNormalize.h"

using namespace arma;
using namespace std;

namespace net.wecash{
namespace algorithm{
    
    class LogisticRegression {
    private:
        mat theta;
        mat data;
        mat X;
        mat y;
        mat mu,sigma;
        long m;
        long n;
        double alpha;
        long num_iters;
        double lamda;
        
    public:
        LogisticRegression() {
        }
        
        LogisticRegression(double alpha, long num_iters) {
            this->alpha = alpha;
            this->num_iters = num_iters;
        }
        
        LogisticRegression(string filename, double alpha, long num_iters) {
            this->alpha = alpha;
            this->num_iters = num_iters;
            loadData(filename);
        }
        
        void loadTheta(string thetafile) {
            theta.load(thetafile);
        }
        
        void loadData(string datafile) {
            data.load(datafile,arma_ascii);
            m = data.n_rows;
            n = data.n_cols;
            X = data.cols(0,n-2);
            y = data.col(n-1); 
        }
        
        void setAlpha(double alpha) {
            this->alpha = alpha;
        }
        
        void setIter(long num_iters) {
            this->num_iters = num_iters;
        }
        
        void setLamda(double lamda) {
            this->lamda = lamda;
        }
        
        void noralize(const mat& X, mat & mu, mat& sigma) {
            X = featureNormalize(X, mu, sigma);
            X = join_rows(ones<mat>(m, 1), X);
        }
        
        double predict(const mat& instance) {
            return sigmoid(instace * theta);
        }
        
        void train(){
            
        }
        
    private:
       
        mat sigmoid(mat& z) {
            mat g(z.n_rows, z.n_cols,fill::zeros);
            g = 1 / (1 + exp(-z));
            return g;
        }
        
        double computeCost(mat& theta, mat& X, mat& y, double lamda) {
            double J = 0;
            mat hopythesis = sigmoid(X*theta);
            //第一个theta=0；
            theta(0)=0;
            
            J = -accu(y % log(hopythesis)+(1-y) %(log(1-hopythesis))/m + lamda/(2*m)*accu(pow(theta,2) );
            grad = X.t()*(hopythesis-y)/m + lamda/m % theta;
        }
        
        mat gradientDescent(mat& X, mat& y, mat& theta) {
            mat hopythesis;
            for(int i =0; i<num_iters; i++) {
                hopythesis = X * theta;
                theta = theta - alpha /m *(X.t() *(hopythesis -y));
            }
            return theta;
        }
        
        
    }
}
}

int main()
{
    LogisticRegression lr;
    lr.setAlpha(0.1);
    lr.setIter(100);
    lr.load("lrdata2.txt",arma_ascii);
}
#endif 
 