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
    int iValue1=11.7,iValue2=10.1,iRet=0.0;
    float fValue1=11.7,fValue2=10.1,fRet=0.0;
    double dValue1=11.7,dValue2=10.1,dRet=0.0;

    iRet=Add(iValue1,iValue2);
    cout<<"Addition of int is"<<iRet<<"\n";

     fRet=Add(fValue1,fValue2);
    cout<<"Addition of float is"<<fRet<<"\n";

     dRet=Add(dValue1,dValue2);
    cout<<"Addition of doduble is"<<dRet<<"\n";


    return 0;
}