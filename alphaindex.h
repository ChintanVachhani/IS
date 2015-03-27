#include <iostream>
#include <string.h>

using namespace std;

char const alphabets[2][27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ","abcdefghijklmnopqrstuvwxyz"};

int alphaToIndex(char str)    //Accepts a character and returns the index of the corresponding character
{
    int r,c,ascii;
    int index;

        ascii=str;
        if(isalpha(str)!=0)
        {
            if(isupper(str)==1)
                r=0;
            else
                r=1;

            if(r==0)
                index=ascii-65;
            else

                index=ascii-97;
        }
        else
            index='*';

    return index;
}

char indexToAlpha(int index)  //Accepts an index and returns the corresponding character
{
    char str;
    index%=26;

    return alphabets[0][index];
}
