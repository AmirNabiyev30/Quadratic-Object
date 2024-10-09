//
// Created by Amir Nabiyev on 10/3/24.
//

#ifndef PROJECT_1_CS212_QUADRATIC_H
#define PROJECT_1_CS212_QUADRATIC_H
#include <iostream>
using namespace std;
class Quadratic{
private:
    double coeff[3]{};
    double root;

public:
    Quadratic();
    Quadratic(double a1,double b1,double c1);
    const double* getCoeffs() const;
    void setCoeffs(double a1,double b1,double c1);
    void setA(double a);
    void setB(double b);
    void setC(double c);
    double getA() const;
    double getB() const;
    double getC() const;
    double evaluate(double x);
    int numRoots();
    friend ostream& operator<<(ostream& outs, Quadratic const& poly);
    friend istream& operator>>(istream& ins, Quadratic& poly);
    double* qEquation ();
    double* evaluateRoots(double numOfRoots);

};
//operators
Quadratic operator+(Quadratic const& poly1, Quadratic const& poly2);
Quadratic operator*(Quadratic const& poly, double s);
bool operator==(Quadratic const& poly1, Quadratic const& poly2);
bool operator!=(Quadratic const& poly1, Quadratic const& poly2);




#endif //PROJECT_1_CS212_QUADRATIC_H
