#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout<<"--DIFFIE-HELLMAN KEY EXCHANGE ALGORITHM--"<<endl<<endl;
    int a,p;
    cout<<"Enter the Prime Number 'P': ";
    cin>>p;
    cout<<"Enter a number 'a' (primitive root of P) : ";
    cin>>a;
    cout<<endl<<endl;

    long unsigned int xa,ya,xb,yb;
    cout<<"Key Generation - User A"<<endl;
    cout<<"\tEnter A's Private Key : ";
    cin>>xa;
    ya=pow(a,xa);
    ya%=p;
    cout<<"\tA's Public Key is : "<<ya<<endl<<endl;
    cout<<"Key Generation - User B"<<endl;
    cout<<"\tEnter B's Private Key : ";
    cin>>xb;
    yb=pow(a,xb);
    yb%=p;
    cout<<"\tB's Public Key is : "<<ya<<endl<<endl;

    long unsigned int k;
    cout<<"Secret Key Calculation "<<endl;
    k=pow(yb,xa);
    k%=p;
    cout<<"\tSecret Key Calculated by A : "<<k<<endl;
    k=pow(ya,xb);
    k%=p;
    cout<<"\tSecret Key Calculated by B : "<<k<<endl;

    return 0;
}
