/*To fit an exponential function to a given set of data values*/

#include <iostream>
#include <math.h>
using namespace std;

struct para {
    double slope;
    double intercept;
}; //End of para Structure

//findeq() function declaration
para findeq(double[],double[],int);

int main() {
    int n;
    cout<<"\nEnter no. of data points : ";
    cin>>n;
    double X[n],Y[n],logY[n];
    cout<<"\nEnter values of X and corresponding value of Y : \n";
    for (int i=0;i<n;i++) {
        cin>>X[i];
        cin>>Y[i];
        logY[i] = log(Y[i]);
    }
    cout<<"\nTABLE\n";
    cout<<"\nX\tY\tlogY";
    for (int i=0;i<n;i++) {
        cout<<"\n"<<X[i]<<"\t"<<Y[i]<<"\t"<<logY[i];
    }
    para p = findeq(X,logY,n);
    double a  = exp(p.intercept);
    double b = p.slope;
    cout<<"\n\nIntercept = "<<p.intercept;
    cout<<"\nExp(Intercept) = "<<a;
    cout<<"\nSlope = "<<b;
    cout<<"\n\nThe exponential fit equation\ny = "<<a<<"e^("<<b<<")x\n";
    return 0;
} // End of main() function

//findeq() function body to return slope and intercept
para findeq(double X[], double logY[], int n) {
    double XX=0,XY=0, meanXX=0, meanXY=0;
    double meanX=0, meanY=0;
    for (int i=0;i<n;i++) {
        meanX = meanX+X[i];
        meanY = meanY+logY[i];
        XX = XX+X[i]*X[i];
        XY = XY+X[i]*logY[i];
    }
    meanY = meanY/n;
    meanX = meanX/n;
    meanXX = XX/n;
    meanXY = XY/n;
    para p;
    p.slope = (meanXY-meanX*meanY)/(meanXX - meanX*meanX);
    p.intercept = (meanXX*meanY - meanXY*meanX)/(meanXX-meanX*meanX);
    return p;
} // End of findeq() function

// End of Program