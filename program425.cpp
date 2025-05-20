#include<iostream>
using namespace std;

double Add(double No1,double No2)
{
    double Ans;
    Ans=No1+No2;
    return Ans;
}
int main()
{
    double iValue1=11.70,iValue2=10.10,Ret=0.0;

    Ret=Add(iValue1,iValue2);
    cout<<"Addition of numbers is"<<Ret<<"\n";

    return 0;
}