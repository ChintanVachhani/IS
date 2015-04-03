#include <iostream>
#include <math.h>

using namespace std;

unsigned long long int powMod(unsigned long long int a,int p,int n)
{
    unsigned long long int r,fr=1;
    int l3=p-(p%3),l2;
    l2=p-l3;
    l3/=3;
    for(int i=0;i<l3;i++)
    {
        r=a*a*a;
        r%=n;
        fr*=r;
    }
    if(l2==2)
    {
        r=a*a;
        r%=n;
        fr*=r;
    }
    if(l2==1)
    {
        r=a%n;
        fr*=r;
    }

    return fr;
}

int extendedEuclid(int m,int b)
{
    int Q,A[3]={1,0,m},B[3]={0,1,b},T[3];

    while(B[2]>=0)
    {

        if(B[2]==0)
            return -1;
        if(B[2]==1)
            return B[1];
        Q=A[2]/B[2];
        for(int i=0;i<3;i++)
        {
            T[i]=A[i]-Q*B[i];
            A[i]=B[i];
            B[i]=T[i];
        }
    }
}

int main()
{
    cout<<"--RSA ALGORITHM--"<<endl<<endl;

    int p,q,n,O,e,d,PU[2],PR[2];
    cout<<"Key Generation"<<endl;
    cout<<"\tEnter 2 different prime numbers : ";
    cin>>p>>q;
    n=p*q;
    cout<<"\tProduct of p & q ('n') : "<<n<<endl;
    O=(p-1)*(q-1);
    cout<<"\tValue of Totient Function of 'n' ('O') : "<<O<<endl;
    cout<<"\tEnter an integer 'e' [GCD(O,e)=1] : ";
    cin>>e;
    d=extendedEuclid(O,e);
    cout<<"\tMultiplicative Inverse of 'e mod O' : "<<d<<endl;
    PU[0]=e;
    PR[0]=d;
    PU[1]=PR[1]=n;
    cout<<"\tPublic Key : {"<<PU[0]<<","<<PU[1]<<"}"<<endl;
    cout<<"\tPrivate Key : {"<<PR[0]<<","<<PR[1]<<"}"<<endl<<endl;

    unsigned long long int M,C;
    cout<<"Encryption"<<endl;
    cout<<"\tEnter the Plain Text : ";
    cin>>M;
    C=powMod(M,e,n);
    C%=n;
    cout<<"\tCipher Text Generated is : "<<C<<endl<<endl;

    cout<<"Decryption"<<endl;
    cout<<"\tEnter the Cipher Text : ";
    cin>>C;
    M=powMod(C,d,n);
    M%=n;
    cout<<"\tPlain Text Generated is : "<<M<<endl<<endl;

    return 0;
}
