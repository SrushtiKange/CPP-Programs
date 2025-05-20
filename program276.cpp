#include<iostream>
using namespace std;
//Approach 1 using for loop
void Display(int iNo)
{
    int iCnt=1;

    while(iCnt<=iNo)
    {
        cout<<iCnt<<endl;
        iCnt++;
    }


}

int main()
{
    int iValue=0;
    cout<<"Enter the number"<<endl;
    cin>>iValue;

    Display(iValue);

    return 0;
}