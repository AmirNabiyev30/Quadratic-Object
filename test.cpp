#include <iostream>
#include "quadratic.h"
using namespace std;

int main() {
    //Constructing example polynomials
    Quadratic poly1  = Quadratic();
    Quadratic poly2  = Quadratic(2,8,4);
    //setting and getting coeffs
    poly1.setCoeffs(1,2,-3);
    const double* poly1Coeffs = poly1.getCoeffs();
    cout<<"The B coefficient of poly2 "<<poly2.getB()<<endl;
    poly2.setB(4);
    cout<<"The new B coefficient of poly2 is "<<poly2.getB()<<endl<<endl;
    cout<<"The coefficient of polynomial 1 are ";
    for(int i = 0; i<3;i++){
        cout<< poly1Coeffs[i]<<" ";
    }
    cout<<endl<<endl;
    //evaluating quadratics
    cout<<"Evaluated at x = 1: " <<poly1.evaluate(1)<<endl;
    if(poly1 == poly2){
        cout<<"The quadratics are equal"<<endl;

    }
    else if(poly1 != poly2){
        cout<<"Quadratic 1 is not equal to Quadratic 2"<<endl;
    }

    //adding and multiplying quadratics
//    Quadratic poly3 = poly1 + poly2;
//    cout<<"Poly 1 + Poly 2 = "<<poly3<<endl;
//    poly3  = poly1*3;
//    cout<<"Poly 1 *3 = "<<poly3<<endl;

    //Printing and inputting quadratics
//    Quadratic poly4;
//    cin>>poly4;
//    cout<<poly4<<endl;

//    Finding the roots of quadratics
    //2 Root Quadratic
    cout<<"The number of roots in quadratic 1 is : "<<poly1.numRoots()<<endl;
    double* poly1Roots = poly1.evaluateRoots(poly1.numRoots());
    cout<<"The roots of poly 1 are "<<poly1Roots[0] <<" and "<<poly1Roots[1]<<endl<<endl;

    //1 Root Quadratics
    Quadratic poly4 = Quadratic(0,3,4);
    cout<<"The number of roots in quadratic 4 is "<<poly4.numRoots()<<endl;
    double* poly4Roots = poly4.evaluateRoots(poly4.numRoots());
    cout<<"The roots of poly4 is "<< *poly4Roots<<endl<<endl;

    Quadratic poly5 = Quadratic(1,4,4);
    cout<<"The number of roots in quadratic 5 is "<<poly5.numRoots()<<endl;
    double* poly5Roots = poly5.evaluateRoots(poly5.numRoots());
    cout<<"The roots in poly 5 is "<< *poly5Roots<<endl<<endl;

    //0 Root Quadratic
    Quadratic poly6 = Quadratic();
    cout<<"The number of roots in quadratic 6 is "<<poly6.numRoots()<<endl;
    double* poly6Roots = poly6.evaluateRoots(poly6.numRoots());


    return 0;
}
