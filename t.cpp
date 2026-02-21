#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"enter the square matrix";
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            cout<<arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i][n-1-i];
    }
}