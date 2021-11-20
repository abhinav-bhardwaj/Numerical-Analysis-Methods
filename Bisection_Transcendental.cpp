#include <iostream>
#include <math.h>
using namespace std;

double func(double x) {
    return x*exp(x)-1;
}
double find_root(double, double, double, int);

int main() {
    int maxc,valid=1;
    double a,b,root,prec;
    do {
        cout<<"\nEnter starting interval : ";
        cin>>a;
        cout<<"\nEnter ending interval : ";
        cin>>b;
        if (func(a)*func(b)>=0)
            cout<<"\nWrong assumption!\nTry again";
        else
            valid = 0;
    }while(valid==1);
    cout<<"\nEnter precision : ";
    cin>>prec;
    cout<<"\nEnter Max no. of iterations : ";
    cin>>maxc;
    root = find_root(a,b,prec,maxc);
    cout<<"\nRoot of equation is : "<<root;
    cout<<endl;
    return 0;
}

double find_root(double a, double b, double prec, int maxc) {
    int c=1, root;
    double m=0;
    cout<<"\nIteration\tRoot";
    while (c<=maxc && (b-a)>=prec) {
        m = (a+b)/2;
        if (func(m)==0.00)
            root = m;
        if ((func(m)>0 && func(b)<0) || (func(m)<0 && func(b)>0)) {
            a = m;
        }
        else {
            b = m;
        }
        cout<<"\n"<<c<<"\t\t"<<m;
        c++;
    }
    return root;
}