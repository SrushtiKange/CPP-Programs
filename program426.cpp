#include<iostream>
using namespace std;

template<class T>
T Add(T No1,T No2)
{
    T Ans=0;
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