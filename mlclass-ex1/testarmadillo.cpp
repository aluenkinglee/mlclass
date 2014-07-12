#include <armadillo>
using namespace std;
using namespace arma;


mat sigmoid(mat& z) {
    mat g(z.n_rows, z.n_cols,fill::zeros);
    g = 1 / (1 + exp(-z));
    return g;
}
int main()
{
    vec q = randu<vec>(10,1);
    cout<<q<<endl;
    cout << q.n_rows << endl;
    cout << q.n_elem << endl;
    mat a = randu<mat>(10,10);
    cout << a.size();
    double x = sum(q);
    cout<<x<<endl;
    
    //mat A = randu<mat>(10,10);
   // cout << A << endl;
    //A.save("A.dat", arma_ascii);
    mat data;
    data.load("lrdata2.txt",arma_ascii);
    cout<< "lrdata2 size:"<< data.size()<<endl;
    cout << data(2,2)<<endl;
    cout << data.n_rows<<endl;
    cout << data.n_cols<<endl;
    //data.load("data1.txt",arma_ascii);
    //cout << "read data from octave file:\n" <<data<<endl;
    //data.load("data2.txt",arma_ascii);
    //cout << "read data from octave file:\n" <<data<<endl;
   // cout << data.cols(0,2) << endl;
    
    //rowvec b = sum(A);
    //cout << b << endl;
    //double c = sum(sum(A));
    //cout << c << endl;
    
    mat A;
    A<< 1 << 1 << 1 <<endr
    << 2 << 2 << 2 <<endr
    << 3 << 3 << 3 <<endr;
    cout << A<<endl;
    
    cout <<1/A<<endl;
    
    cout << exp(A)<<endl;
    
    cout <<sigmoid(A)<<endl;
    

    a<<1<<2<<3<<endr;
    cout << a;
    mat b;
    b<<1<<endr<<2<<endr<<3<<endr;
    cout << b;
    cout << a*b<<endl;
    
    return 0;
}
