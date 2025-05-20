#include<iostream>
using namespace std;
//Approach 1 using for loop
int SumDigits(int iNo)
{
    int Count=0,iSum=0,iDigit;

    while(iNo!=0)
    {
        iDigit=iNo%10;
        iSum=iSum+iDigit;
        iNo=iNo/10;
    
    }
    return iSum;
}

int main()
{
    int iValue=0,iRet=0;
    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet=SumDigits(iValue);

    cout<<"Sum of digits are: "<<iRet<<endl;

    return 0;
}