#include<iostream>
using namespace std;
//Approach 1 using for loop
int Addition(int iNo)
{
    int iCnt=0;
    int iSum=0;

    while(iCnt<=iNo)
    {
        iSum=iSum+iCnt;
        iCnt++;
    }
 return iSum;
    
  
}

int main()
{
    int iValue=0,iRet=0;
    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet=Addition(iValue);

    cout<<"Addition is:"<<iRet<<endl;

    return 0;
}