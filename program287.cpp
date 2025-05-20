#include<iostream>
using namespace std;
//Approach 1 using for loop
int Count(int iNo)
{
    int Count=0;

    while(iNo!=0)
    {
       
        Count++;
        iNo=iNo/10;
    
    }
    return Count;
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