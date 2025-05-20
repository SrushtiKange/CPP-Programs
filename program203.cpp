#include<iostream>
using namespace std;

int SumFactors(int iNo)
{
    int iSum=0,iCnt=0;

    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        if(iNo%iCnt==0)
        {
            iSum=iSum+iCnt;
        }
    }
    return iSum;
}

int main()
{
    int iValue=0;
    int iRet=0;

    cout<<"Enter number\n";
    cin>>iValue;

    iRet=SumFactors(iValue);

    cout<<"Sum of factors is"<<iRet<<endl;

    return 0;
}