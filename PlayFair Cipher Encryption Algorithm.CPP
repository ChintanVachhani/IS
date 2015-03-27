#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

int checkAlpha(int n,char ch,char *t)
{
 for(int i=n-1;i>=0;i--)
 {
  if(ch==t[i] || ((ch=='i'||ch=='j'||ch=='I'||ch=='J')&&(t[i]=='i'||t[i]=='j'||t[i]=='I'||t[i]=='J')))
   return 0;
 }
 return 1;
}

int main()
{
 char pm[5][5];
 char *k,*p,*t,*c,xx[2],ch,_0i,_0j,_1i,_1j;
 int a=0,lk,lp,x,y;

 clrscr();

 printf("Enter the Plain Text : ");
 gets(p);
 lp=strlen(p);

 printf("Enter the Key : ");
 gets(k);
 lk=strlen(k);

 //PLAYFAIR MATRIX MODULE START
 if(k[0]>='a')
  ch='a';
 else
  ch='A';

 for(int i=0;i<5;i++)
 {
  for(int j=0;j<5;j++)
  {
   if(a<=lk)
   {
    if(k[a]!=' ' && checkAlpha(a,k[a],k)==1)
     pm[i][j]=k[a];
    else
     --j;
    a++;
    if(a==lk+1)
     j--;
   }
   else if(a==lk+1)
    {

     if(checkAlpha(lk+1,ch,k)==1)
      pm[i][j]=ch;
     else
      --j;
     ch++;
     if(ch=='j'|| ch=='J')
      ch++;
    }
   else
    break;
  }
 }
 printf("\n\nPlayFair Matrix :- \n");
 for(int m=0;m<5;m++)
 {
  for(int n=0;n<5;n++)
  {
   printf("%c ",pm[m][n]);
  }
  printf("\n");
 }
 //PLAYFAIR MATRIX MODULE END

 //BREAK PLAIN TEXT MODULE START
 for(int u=0;u<=lp-1;u=u+2)
 {
  xx[0]=p[u];
  xx[1]=p[u+1];

  if(xx[0]==xx[1])
  {
   for(int j=lp;j>=u+1;j--)
   {
    p[j+1]=p[j];
   }
   if(k[0]>='a')
   {
     p[u+1]='x';
     lp++;
   }
    else
    {
     p[u+1]='X';
     lp++;
    }
  }
 }
 printf("\n\nIntermediate Plain Text :- ");
 for(u=0;u<=lp-1;u++)
 {
  printf("%c",p[u]);
 }
 //BREAK PLAIN TEXT MODULE END

 //CIPHER TEXT MODULE START

 for(u=0;u<=lp-1;u=u+2)
 {
  xx[0]=p[u];
  xx[1]=p[u+1];

  for(i=0;i<5;i++)
  {
   for(int j=0;j<5;j++)
   {
    if(xx[0]==pm[i][j])
    {
     _0j=j;
     _0i=i;
    }
    if(xx[1]==pm[i][j])
    {
     _1j=j;
     _1i=i;
    }
   }
  }
  if(_0i==_1i)
  {
   if(_0j+1>=5)
    _0j=-1;
   if(_1j+1>=5)
    _1j=-1;
   c[u]=pm[_0i][_0j+1];
   c[u+1]=pm[_1i][_1j+1];
  }
  else if(_0j==_1j)
  {
   if(_0i+1>=5)
    _0i=-1;
   if(_1i+1>=5)
    _1i=-1;
   c[u]=pm[_0i+1][_0j];
   c[u+1]=pm[_1i+1][_1j];
  }
  else
  {
   c[u]=pm[_0i][_1j];
   c[u+1]=pm[_1i][_0j];
  }
 }
 printf("\n\nCipher Text :- ");
 for(u=0;u<=lp-1;u++)
 {
  printf("%c",c[u]);
 }
 //CIPHER TEXT MODULE END
 getch();
 return 0;
}
