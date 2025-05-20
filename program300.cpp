#include<iostream>
using namespace std;

int strlenX(char *str)
{
    int iCnt=0;
    while(*str!='\0')
    {
        iCnt++;
        str++;
    }
    return iCnt;
}

int main()
{
   char Arr[30];
   int iRet=0;

   cout<<"Enter string\n";
   cin.getline(Arr,30);

   iRet=strlenX(Arr);

   cout<<"str length is : \n"<<iRet;
    
    return 0;
}