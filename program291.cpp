#include<iostream>
using namespace std;
//Approach 1 using for loop
int SumDigits(int iNo)
{
    int iDigit=0;
    static int iSum=0;

    if(iNo!=0)
    {
        iDigit=iNo%10;
        iSum=iSum+iDigit;
        SumDigits(iNo/10);
    
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