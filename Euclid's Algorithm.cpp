#include <iostream>

using namespace std;

int euclid(int a,int b)
{
    int A,B,R;
    if(b>a)
    {
        A=a;
        B=b;
    }
    else
    {
        A=b;
        B=a;
    }
    while(B>=0)
    {
        if(B==0)
            return A;
        R=A%B;
        A=B;
        B=R;
    }
}

int main()
{
    int a,b;
    cout<<"--EUCLID'S ALGORITHM--"<<endl<<endl;
    cout<<"Enter 2 numbers to find their GCD : ";
    cin>>a>>b;
    cout<<endl<<"The GCD is : "<<euclid(a,b)<<endl;
    return 0;
}
