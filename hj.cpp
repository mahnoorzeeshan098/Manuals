#include<iostream>
using namespace std;
int large();
main()
{
    int large();
}
int large()
{
    int n;
    int largest;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cout<<array[i];
        int largest=array[i];
    }
    for(int j=0;j<n;j++)
    if(array[j]>largest)
    largest=array[j];
    
    
}