#include <iostream>
using namespace std;

int factorial(int);
float calcU(float,float,float);
float calcP(int,float);

int main() {
    int n;
    cout<<"Enter no. of terms : ";
    cin>>n;
    float x, X[n], Y[n][n];
    cout<<"\nEnter values of X : \n\n";
    for (int i=0;i<n;i++) {
        cout<<"Enter X"<<i<<" : ";
        cin>>X[i];
    }
    cout<<"\nEnter values of Y : \n\n";
    for (int i=0;i<n;i++) {
        cout<<"Enter Y"<<i<<" : ";
        cin>>Y[i][0];
    }
    cout<<"\nEnter 'x' for which 'y' is to be calculated : ";
    cin>>x;
    for (int i=1;i<n;i++) {
        for (int j=n-1;j>=i;j--) {
            Y[j][i] = Y[j][i-1] - Y[j-1][i-1];
        }
    }
    cout<<"\nBackward Difference Table\n";
    for(int i=0;i<n;i++) {
        cout<<X[i]<<"\t";
        for (int j=0;j<=i;j++) {
            cout<<Y[i][j]<<"\t";
        }
        cout<<endl;
    }
    float u = calcU(x,X[n-1],X[n-2]);

    float summ = Y[n-1][0];
    for (int i=1;i<n;i++) {
        summ+=(calcP(i,u)*Y[n-1][i])/factorial(i);
        //Y[n-1][i] is the last row of difference table
    }

    cout<<"\nInterpolated value of Y at X="<<x<<" is "<<summ;
    cout<<endl;
    return 0;
}

int factorial(int n) {
    if (n<=1)
        return 1;
    return n*factorial(n-1);
}

float calcU(float x, float xn, float xn1) {
    return (x-xn)/(xn-xn1);
}

float calcP(int i, float u) {
    int j = 1;
    float t=u;
    while (j<i) {
        t=t*(u+j);
        j++;
    }
    return t;
}    