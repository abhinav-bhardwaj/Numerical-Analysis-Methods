#include <iostream>
#include <math.h>
using namespace std;

double func (double);
double gunc (double);

int main () {
    int maxi;
    int flag;
    double x,err;
    int i=1;
    cout<<"Enter initial guess : ";
    cin>>x;
    cout<<"Enter tolerable error : ";
    cin>>err;
    cout<<"Enter Max no. of iterations : ";
    cin>>maxi;
    if (gunc(x)==0) {
        cout<<"\nMathematical Error";
        return 0;
    }
    else {
        double x1;
        do {
            flag=0;
            x1 = x - (func(x)/gunc(x));
            i++;
            if (i>=maxi) {
                cout<<"\nNot Convergent";
                return 0;
            }  
            if (abs(func(x1))>err) {
                x = x1;
                flag=1;
            }
        }while(flag==1);
        cout<<"\nRoot : "<<x1;
        cout<<endl;
    }
    return 0;
}

double func (double x) {
    return 3*pow(x,2)-6*x+3;
}

double gunc (double x) {
    return 6*x-6;
}

