#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

template <typename MatrixExpression>
void stuff(MatrixExpression&& X)
{ 
    typedef typename std::remove_reference<decltype(X.derived())>::type Derived;
    static_assert( std::is_base_of< MatrixBase<Derived>, typename std::remove_reference<MatrixExpression>::type >::value, "Need a MatrixBase!");
    
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
    
    // This now works
    stuff(X.row(1));
    
    cout << endl << X << endl;
    
    return 0;
}
