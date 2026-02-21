#include<iostream>
using namespace std;
main()
{
    int number[5];
    cout<<"Enter 5 numbers";
    for(int i=0;i<5; i++)
{
    cin>>number[i];
}
    cout<<"The numbers are";
    for(int n=0;n<5;n++)
    {
        cout<<number[n];
    }

}