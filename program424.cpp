#include<iostream>
using namespace std;

float Add(float No1,float No2)
{
    float Ans=0;
    Ans=No1+No2;
    return Ans;
}
int main()
{
    float iValue1=11.7,iValue2=10.1,Ret=0.0;

    Ret=Add(iValue1,iValue2);
    cout<<"Addition of numbers is"<<Ret<<"\n";


    return 0;
}