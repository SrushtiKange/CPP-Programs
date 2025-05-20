#include<iostream>
using namespace std;
//Approach 3 using recursion
void Display(int iNo)
{
    static int iCnt=1;//why we have used static here

    if(iCnt<=iNo)
    {
        cout<<"*"<<endl;
        iCnt++;
        Display(iNo);
    }
    cout<<"End of display"<<endl;
}

int main()
{
    int iValue=0;

    cout<<"Enter number :"<<endl;
    cin>>iValue;

    Display(iValue);

    cout<<"End of application"<<endl;
    return 0;
}