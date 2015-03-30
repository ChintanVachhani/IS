#include <iostream>
#include <stdio.h>
#include <string.h>
#include <alphaindex.h>

using namespace std;

int main()
{
    char *p=new char[50],*c=new char[50];
    int k,j=0;

    cout<<"CAESAR CIPHER\n\n";

    cout<<"--Encryption--\n"<<endl;
    cout<<"Enter the Plain Text [Use Capital Letters] : ";
    gets(p);
    cout<<"Enter the Key : ";
    cin>>k;
    for(int i=0;p[i]!='\0';i++)
    {
        if(isalpha(p[i])!=0)
        {
            int t=alphaToIndex(p[i]);
            c[j]=indexToAlpha(t+k);
            j++;
        }
    }
    cout<<"\nThe Cipher Text Generated : "<<c<<endl<<endl;
    int n=strlen(c);
    j=0;
    char *pt=new char[n];
    cout<<"--Decryption--\n"<<endl;
    cout<<"Enter the Key : ";
    cin>>k;
    for(int i=0;i<n;i++)
    {
            int t=alphaToIndex(c[i]);
            pt[i]=indexToAlpha(t-k);
    }
    cout<<"\nThe Plain Text Generated : "<<pt<<endl<<endl;

    return 0;
}
