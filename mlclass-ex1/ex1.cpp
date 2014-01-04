#include <cstdio>
#include <iostream>

#include <armadillo>

#include "computeCost.h"
#include "gradientDescent.h"
//#include "gradientDescentMulti.h"
#include "featureNormalize.h"
#include "normalEqn.h"

using namespace std;
using namespace mlclass::ex1;

int main(){
    mat data;
    data.load("data1.txt",arma_ascii);
    
    mat X = data.col(0);
    colvec y = data.col(1);
    
    long m = y.n_rows;
    
    //horizontal concatenation
    X = join_rows(ones<mat>(m, 1), X);
    //cout << X.n_rows << " " << X.n_cols;
    //initialize fitting parameters
    mat theta = zeros<mat>(2,1);
    
    long num_iters = 1500;
    double alpha = 0.01;

    cout << "Initial cost: " << computeCost(X, y, theta) << endl;
    
    //run gradient descent
    gradientDescent(X, y, theta, alpha, num_iters);
    cout << "Theta found by gradient descent:" << endl;
    cout << theta(0) << " " << theta(1) << endl;
    
    //predict values
    mat instance1(1,2);
    double predict;
    
    instance1<<1<<3.5<<endr;
    predict = accu(instance1*theta);
    printf("For population = 35,000, we predict a profit of %f\n", predict*10000);
    
    instance1<<1<<7<<endr;
    predict = accu(instance1*theta);
    printf("For population = 70,000, we predict a profit of %f\n", predict*10000);

    ///
    data.load("data2.txt",arma_ascii);
    
    X = data.cols(0,1);
    y = data.col(2);
    m = y.n_rows;
    
    mat mu,sigma;
    // 注意正规化的作用阿！！！要不然就会溢出！！！
    X = featureNormalize(X, mu, sigma);
    //horizontal concatenation
    X = join_rows(ones<mat>(m, 1), X);

    alpha = 1;
    num_iters = 400;
    theta = zeros(3, 1);

    // 向量化或者矩阵化实现的函数，当然不需要因为dimensions不同而特别写.
    //gradientDescentMulti(X, y, theta, alpha, num_iters);
    gradientDescent(X, y, theta, alpha, num_iters);
    printf("Theta computed from gradient descent with alpha = 0.01: \n");
    cout << theta;
    
    instance1<<1650<<3<<endr;
    instance1 = (instance1 - mu) / sigma;
    instance1 = join_rows(ones<mat>(1, 1), instance1);
    predict = accu(instance1*theta);
    printf("Predicted price of a 1650 sq-ft, 3 br house (using gradient descent):\n $%f\n", predict);
    
    X = data.cols(0,1);
    y = data.col(2);
    m = y.n_rows;
    X = join_rows(ones<mat>(m, 1), X);
    theta = normalEqn(X, y);
    
    printf("Theta computed from the normal equations: \n");
    cout << theta << endl;
    
    instance1<<1<<1650<<3<<endr;
    predict = accu(instance1*theta);
    printf("Predicted price of a 1650 sq-ft, 3 br house (using normalEqn ):\n $%f\n", predict);
    
    return 0;
}
