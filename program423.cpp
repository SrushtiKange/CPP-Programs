#include<iostream>
using namespace std;

int Add(int No1,int No2)
{
    int Ans=0;
    Ans=No1+No2;
    return Ans;
}
int main()
{
    int iValue1=11,iValue2=10,iRet=0;

    iRet=Add(iValue1,iValue2);
    cout<<"Addition of numbers is"<<iRet<<"\n";


    return 0;
}