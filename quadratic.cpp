//
// Created by Amir Nabiyev on 10/3/24.
//
#include "quadratic.h"
#include <cmath>
#include <iostream>
#include<cassert>

using namespace std;

//constructors
Quadratic::Quadratic(){
    for(int i = 0;i<3;i++){
        coeff[i] = 0;
    }
    //Post condition: Sets all the class values to 0
}
Quadratic::Quadratic(double a1, double b1, double c1) {
    coeff[0] = a1;
    coeff[1] = b1;
    coeff[2] = c1;
    //Post Condition: Sets all the values of the coefficients to the arguments passed
}
//member functions
 const double* Quadratic::getCoeffs() const{
    return coeff;
    //Post Condition: Returns the array of coefficients
}
void Quadratic::setCoeffs(double a1, double b1, double c1) {
    coeff[0] =a1;
    coeff[1] = b1;
    coeff[2] = c1;
    //Post Condition: Set the coefficients to the arguments passed
}
void Quadratic::setA(double a){
    coeff[0] = a;
    //Post Condition: Sets the A coefficient to the argument
}
void Quadratic::setB(double b){
    coeff[1] = b;
    //Post Condition: Sets the B coefficient to the argument
}
void Quadratic::setC(double c){
    coeff[2] = c;
    //Post Condition: Sets the C coefficient to the argument
}
double Quadratic::getA() const{
    return coeff[0];
    //Post Condition: Returns the A coefficient
}
double Quadratic::getB() const{
    return coeff[1];
    //Post Condition: Returns the B coefficient
}
double Quadratic::getC() const{
    return coeff[2];
    //Post Condition: Returns the C coefficient
}
double Quadratic::evaluate(double x) {
    return (coeff[0]* pow(x,2) + coeff[1]*x + coeff[2]);
    //Post Condition: Evaluates the quadratic at the given x through
    // plugging in and evaluating values
}
int Quadratic::numRoots() {
    double a = coeff[0];
    double b = coeff[1];
    double c = coeff[2];
    //define b^2
    double bSquare = pow(b,2);
    //define 4ac for easier use
    double ac4 = 4*a*c;

    //if the values of the coefficents are zero then, there is infinite roots, return 3
    if(a == 0 && b == 0 && c == 0 ){
        return 3;
    }
    if(a == 0 && b == 0 && c!=0){

        return 0;
    }
    if(a == 0 && b!=0){

        return 1;
    }
    if(a !=0){
        if(bSquare < ac4){

            return 0;
        }
        else if(bSquare == ac4){

            return 1;
        }
        else if(bSquare > ac4){

            return 2;
        }
    }
 return 0;
    //Post Condition: Returns the number of roots of the quadratic
    // depending on the values of the coefficients
}
double* Quadratic::qEquation(){

    double a = coeff[0], b = coeff[1], c = coeff[2];
    static double roots[2];
    double root1 , root2;
    assert(a!=0);
    assert(pow(b,2) >= 4*a*c);
    root1 = (b + sqrt(pow(b,2) - 4*a*c))/2*a;
    root2 = (b - sqrt(pow(b,2) - 4*a*c))/2*a;
    roots[0] = root1;
    roots[1] = root2;
    return roots;
    //Post Condition: Returns the array of the 2 roots using the quadratic equation
}
double* Quadratic::evaluateRoots(double numOfRoots){
    double a = coeff[0], b = coeff[1], c = coeff[2];
    if(numOfRoots == 2){
        static double* roots = qEquation();
        return roots;
    }
    if(numOfRoots == 1 ){
        if(a == 0 && b != 0) {
            static double root = -coeff[2] / coeff[1];
            return &root;
        }
        else if(a != 0 ){
            if(pow(b,2) == (4*a*c)){
                static double root = -b/2*a;
                return &root;
            }

        }
    }
    if(numOfRoots == 0){
        cout<<"This quadratic has no roots"<<endl;
        double* ptr = NULL;
        return ptr;

    }
    if(numOfRoots == 3){
        cout<<"This quadratic has infinite roots"<<endl;
        double* ptr = NULL;
        return ptr;
    }
    //Post Condition: Evaluates and returns the roots depending on how many roots there are
}


//OPERATORS
Quadratic operator+(const  Quadratic& poly1, const Quadratic& poly2){
    double aSum = poly1.getCoeffs()[0] + poly2.getCoeffs()[0];
    double bSum = poly1.getCoeffs()[1] + poly2.getCoeffs()[1];
    double cSum = poly1.getCoeffs()[2] + poly2.getCoeffs()[2];
    Quadratic sum  = Quadratic(aSum,bSum,cSum);
    return sum;
    //Post Condition: The return value of adding each respective coefficient between 2 quadratics
}
Quadratic operator*(const Quadratic& poly, double s){
    Quadratic product  = Quadratic(poly.getCoeffs()[0]*s,poly.getCoeffs()[1]*s,poly.getCoeffs()[2]*s);
    return product;
    //Post Condition: Returns the product of a scalar and a quadratic where that scalar was
    //distributed to each coefficient
}
bool operator==(const  Quadratic& poly1, const Quadratic& poly2){
    const double* p1 = poly1.getCoeffs();
    const double* p2 = poly2.getCoeffs();
    if(p1[0] == p2[0] && p1[1] == p2[1] && p1[2] == p2[2]){
        return true;
    }
    return false;
    //Post Condition: Returns boolean values by comparing each coefficient in quadratics
}
bool operator!=(const  Quadratic& poly1, const Quadratic& poly2){
    const double* p1 = poly1.getCoeffs();
    const double* p2 = poly2.getCoeffs();

    if(p1[0] != p2[0] || p1[1] != p2[1] || p1[2] != p2[2]){
        return true;
    }
    return false;
    //Post Condition: Returns boolean values by comparing each coefficient in quadratics
}
ostream& operator<<(ostream& outs, Quadratic const& poly){
    outs<< poly.coeff[0]<<"x^2 + "<<poly.coeff[1]<<"x + "<<poly.coeff[2];
    return outs;
    //Post Condition: Prints out quadratics in standard form
}
istream& operator>>(istream& ins, Quadratic& poly){
    cout<<"Enter a: ";
    ins>>poly.coeff[0];
    cout<<endl<<"Enter b: ";
    ins>>poly.coeff[1];
    cout<<endl<<"Enter c: ";
    ins>>poly.coeff[2];
    return ins;
    //Post Condition: Allows for input of values to be matched to coefficients in quadratic
}

