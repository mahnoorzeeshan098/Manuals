#include<iostream>
#include<math.h>
using namespace std;
main()
{
    int n1,n2,n3;
    cout<<" enter first nember:"<<endl;
    cin>>n1;
    cout<<" enter second number:"<<endl;
    cin>>n2;
    cout<<"Enter third number:"<<endl;
    cin>>n3;
    int avg;
    avg=(n1+n2+n3)/3;
    cout<<" the average is"<<avg<<endl;
    if(avg>50)
    
    cout<<"Above average"<<endl;
    
    if (avg<50)
    
        cout<<"below average"<<endl;
    

}