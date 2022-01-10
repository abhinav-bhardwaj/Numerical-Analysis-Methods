/*backward Difference First Derivative*/
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cout<<"\nEnter no. of data points : ";
    cin>>n;
    double x,X[n],Y[n][n],dev;
    cout<<"\nEnter values of X and corresponding value of Y : \n";
    for (int i=0;i<n;i++) {
        cin>>X[i];
        cin>>Y[i][0];
    }
    cout<<"\nEnter 'x' for which first derivative is to be calculated : ";
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
    float h = X[1]-X[0];
    cout<<"\nh = "<<h<<endl;
    double summ;
    for (int i=1;i<n;i++) {
        summ+=Y[n-1][i]/i;
    }
    dev = summ/h;
    cout<<"The first derivative is : "<<dev<<endl<<endl;
    return 0;
}
