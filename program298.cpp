#include<iostream>
using namespace std;

int Factors(int iNo)
{
    static int i=1;
    static int Fsum=0;

    if(i<=iNo/2)
    {
        if((iNo%i)==0)
        {
            Fsum=Fsum+i;    
        }                                              
        i++;
        Factors(iNo);

    }
    return Fsum;
}

int main()
{
    int iValue=0,iRet=0;
    cout<<"Enter the number"<<endl;
    cin>>iValue;

    iRet=Factors(iValue);

    cout<<"Sum of factors is "<<iRet<<endl;

    return 0;
}