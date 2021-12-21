#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout<<"\nEnter no. of data points : ";
    cin>>n;
    double dev,x,X[n],Y[n][n],h,u;
    cout<<"\nEnter values of X and corresponding value of Y : \n";
    for (int i=0;i<n;i++) {
        cin>>X[i];
        cin>>Y[i][0];
    }
    cout<<"\nEnter 'x' for which first derivative is to be calculated : ";
    cin>>x;
    h = X[1]-X[0];
    //u = x - X[n-1]/h;
    cout<<"\nh = "<<h<<endl;
    for (int i=1;i<n;i++) 
        for (int j=0;j<n-i;j++)
            Y[j][i] = Y[j+1][i-1] - Y[j][i-1];

    cout<<"\nForward Difference Table\n";
    for(int i=0;i<n;i++) {
        cout<<X[i]<<"\t";
        for (int j=0;j<n-i;j++) {
            cout<<Y[i][j]<<"\t";
        }
        cout<<endl;
    }
    double summ;
    cout<<summ;
    for (int i=1;i<n;i++) {
        summ+=pow(-1,i+1)*Y[0][i]/i;
    }

    dev = summ/h;
    cout<<"The first derivative is : "<<dev<<endl<<endl;
    return 0;
}