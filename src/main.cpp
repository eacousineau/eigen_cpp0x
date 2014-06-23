#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

template<typename Derived>
void stuff(MatrixBase<Derived> &X)
{
    cout << "[" << X.size() << "] " << X << endl;
    if (X.size() > 0)
        X(0) = 5.;
}

int main()
{
    MatrixXd X(2, 1);
    X << 1, 2;
    
    // Just fine
    stuff(X);
    
    // This works
    MatrixXd::RowXpr row = X.row(1);
    stuff(row);
    
    // This does not
    // stuff(X.row(1));
    
    cout << endl << X << endl;
    
    return 0;
}
