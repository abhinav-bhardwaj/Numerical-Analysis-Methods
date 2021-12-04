#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double func(double x) {
    return pow(x,3)-5*pow(x,1)+1;
}
double find_root(double, double, int);

int main() {
    int maxc;
    double a,b,root,prec;
    cout << "\nEnter starting interval : ";
    cin >> a;
    cout << "\nEnter ending interval : ";
    cin >> b;
    cout<<"\nEnter Max no. of iterations : ";
    cin>>maxc;
    root = find_root(a,b,maxc);
    cout<<"\nRoot of equation is : "<<root;
    cout<<endl;
    return 0;
}

double find_root(double a, double b, int maxc) {
    double c;
    int i=1;
    cout<<"\nIterations\tRoot";
    while (i<=maxc) {
        c = b - ((a-b)/(func(a)-func(b)))*func(b);
        cout<<"\n"<<i<<"\t\t"<<c;
        i++;
        a=b;
        b=c;
    }
    return c;
}