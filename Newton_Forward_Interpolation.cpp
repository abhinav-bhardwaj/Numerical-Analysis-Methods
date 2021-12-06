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
        for (int j=0;j<n-i;j++) {
            Y[j][i] = Y[j+1][i-1] - Y[j][i-1];
        }
    }
    cout<<"\nForward Difference Table\n";
    for(int i=0;i<n;i++) {
        cout<<X[i]<<"\t";
        for (int j=0;j<n-i;j++) {
            cout<<Y[i][j]<<"\t";
        }
        cout<<endl;
    }
    float u = calcU(x,X[0],X[1]);
    float summ = Y[0][0];
    for (int i=1;i<n;i++) {
        summ+=(calcP(i,u)*Y[0][i])/factorial(i);
        //Y[0][i] is the first row of difference table
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

float calcU(float x, float x0, float x1) {
    return (x-x0)/(x1-x0);
}

float calcP(int i, float u) {
    int j = 1;
    float t=u;
    while (j<i) {
        t=t*(u-j);
        j++;
    }
    return t;
}    