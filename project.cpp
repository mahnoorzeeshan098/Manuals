#include<iostream>
using namespace std;
int roomprice(int room_type);
void nightstay();
int print_final_bill(int total_bill,int service_charges);
int show_service();
int get_service_price(int service_type);
int main()
{

   cout<< "--------------------------------------------------------------"<<endl;
   cout<<"               HOTEL MANAGEMENT SYSTEM                         "<<endl;
   cout<<" --------------------------------------------------------------"<<endl;
   cout<<" WELCOME TO OUR HOTEL "<<endl;
   cout<<" CHOOSE THE BEST ROOM FOR YOUSELF"<<endl;

   int room_type,nights;
   int total_price=0;
   int room_value=0;
   char more='y';
   int serivce_type;
   int service_charges=0;
   while(more=='y'||more=='Y')
   nightstay();
   
   cout<<"Enter the type of room(1-3)"<<endl;
   cin>>room_type;
   if(room_type==1||room_type==2||room_type=3)
   {
   cout<<"Enter the nights you want to spend"<<endl;
   cin>>nights;
   int price=roomprice(int roomtype);
   room_value=price*nights;
   
   }
   else{
    cout<<" invalid room"<<endl;
   }
   cout<<"enter if you want more room(y for yes n for no)"<<endl;
   cin>>more;

while(more=='y'||more=='Y')
show_service();

     cout<<"ENTER TYPE OF SERVICES YOUWANT TO AVAIL"<<endl;
    if(serivce_type>1&&serivce_type<4){
  int s_price= get_service_price(int service_type);
  service_charges=service_charges+ s_price;
    }
  else{
    cout<<"invalid services"<<endl;
  }
  cout<<" type y if u want more services ifno then n"<<endl;
  cin>>more;
print_final_bill(int total_bill , int service_charges);
return 0;
}
void nightstay()
{
cout<<"choose a comfortable room for yourself"<<endl;
cout<<"WE HAVE 3 CATAGEROIES OF ROOM"<<endl<<"1-standard"<<endl<<"5000 per night"<<endl<<"2- deluxe room"<<endl<<"7000 per night"<<endl<<"3- Luxury suite"<<endl<<"15000 per night"<<endl;
}
int roomprice(int room_type)
{
if (room_type==1)
return 5000;
if(room_type==2)
return 7000;
if (room_type==3)
return 15000;
return 0;
}
int show_service()
{
 cout << "\nRoom Services:\n";
    cout << "1. Food Service     - Rs. 1200\n";
    cout << "2. Laundry Service  - Rs. 500\n";
    cout << "3. Room Cleaning    - Rs. 300\n";
    cout << "4. Spa Service      - Rs. 1500\n";
    return 0;
    }
    int get_service_price(int service_type)
    {
    if (service_Type == 1) return 1200;
    else if (serviceType == 2) return 500;
    else if (serviceType == 3) return 300;
    else if (serviceType == 4) return 1500;
    return 0;
}
    int print_final_bill(int total_bill,int service_charges)
{
    int total=room_value+service_charges;
    float gst=total*0.1;
    float grand_total= total+gst;
    cout<<"---------------------------------------"<<endl;
    cout<<"              FINAL BILL               "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"room charges="<<room_value;
    cout<<endl<<"service charges="<<service_charges;
    cout<<endl<<" total gst="<<gst<<endl;
    cout<<"The grand total is="<<grand_total;
}