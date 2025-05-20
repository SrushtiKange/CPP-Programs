#include<iostream>
#include<string.h>
using namespace std;




int main()
{
    char Arr[30]="Hello world";
    char Brr[30]="India";

   
    strcat(Brr,Arr)

    cout<<"Destination string : "<<Brr<<endl;

    return 0;
}