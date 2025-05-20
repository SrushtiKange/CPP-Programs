#include<iostream>
using namespace std;

int main()
{
    char Arr[30];

    cout<<"Enter name:"<<endl;
    cin.getline(Arr,30);    //for string input

    cout<<"Hello "<<Arr<<endl;

    return 0;
}