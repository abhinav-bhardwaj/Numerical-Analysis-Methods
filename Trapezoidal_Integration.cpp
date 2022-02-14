/*Numerical integration using Trapezoidal rule*/
#include <iostream>
#include <math.h>
using namespace std;

double func(float);

int main () {
    float h, inter, lower, upper, integ,k;
    cout<<"Enter lower limit of integration : ";
    cin>>lower;
    cout<<"Enter upper limit of integration : ";
    cin>>upper;
    cout<<"Enter number of sub intervals : ";
    cin>>inter;
    h = (upper - lower)/inter;
    integ = func(upper) + func(lower);
    for (int i=1;i<inter;i++) {
        k = lower + i*h;
        integ = integ+ 2*(func(k));
    }
    integ*=h/2;
    cout<<"\nDefinite Integral of function is : "<<integ<<endl;
    return 0;
}

double func(float x) {
    double f = pow(x,3);
    return f;
}