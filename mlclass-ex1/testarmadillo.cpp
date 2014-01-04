#include <armadillo>
using namespace std;
using namespace arma;

int main()
{
    vec q = randu<vec>(10,1);
    cout<<q<<endl;
    cout << q.n_rows << endl;
    cout << q.n_elem << endl;
    mat a = q;
    double x = sum(q);
    cout<<x<<endl;
    
    mat A = randu<mat>(10,10);
    cout << A << endl;
    A.save("A.dat", arma_ascii);
    mat data;
    data.load("data1.txt",arma_ascii);
    cout << "read data from octave file:\n" <<data<<endl;
    data.load("data2.txt",arma_ascii);
    cout << "read data from octave file:\n" <<data<<endl;
    cout << data.n_rows << endl;
    
    rowvec b = sum(A);
    cout << b << endl;
    double c = sum(sum(A));
    cout << c << endl;

    return 0;
}
