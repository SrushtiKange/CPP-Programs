#include<iostream>
using namespace std;

int CountCap(char *str)
{
    static int iCnt=0;
    if(*str!='\0')
    {
        if((*str>='A') && (*str<='Z'))
        {
            iCnt++;
        
        }
        str++;
        CountCap(str);
    }
    return iCnt;
}

int main()
{
   char Arr[30];
   int iRet=0;

   cout<<"Enter string\n";
   cin.getline(Arr,30);

   iRet=CountCap(Arr);

   cout<<"Cap character are: \n"<<iRet;
    
    return 0;
}