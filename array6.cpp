#include<iostream>
using namespace std;
main()
{
    int array[10],i,n;
    int flag=0;
    for(i=0; i<10;i++)
    {
        cout<<"Enter value=";
        cin>>array[i];

    }
    cout<<" enter value you want to find";
    cin>>n;
    for(i=0;i<10;i++)
    {
        if(array[i]==n)
        {
            flag=1;
            break;
        }

    }
    if(flag==1)
    cout<<n<<"value  found";
    else
    cout<<n<<"Value not found";


}