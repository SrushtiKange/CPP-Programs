#include<iostream>
using namespace std;

int strlenX(char *str)
{
    int count=0;

    while(*str!='0')
    {
        count++;
        str++;
    }
    return count;

}


int main()
{
    char Arr[30];
    int iRet=0;

    cout<<"Enter name:"<<endl;
    cin.getline(Arr,30);    //for string input

    iRet=strlenX(Arr);

    cout<<"string length is : "<<iRet<<endl;

    return 0;
}