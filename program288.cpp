#include<iostream>
using namespace std;
//Approach 1 using for loop
int Count(int iNo)
{
    static int iCount=0;

    if(iNo!=0)
    {
        iCount++;
        iNo=iNo/10;
        Count(iNo);
    }
    return iCount;
}

int main()
{
    int iValue=0,iRet=0;
    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet=Count(iValue);

    cout<<"Number of digits are: "<<iRet<<endl;

    return 0;
}