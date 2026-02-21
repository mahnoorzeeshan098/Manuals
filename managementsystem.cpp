#include<iostream>
using namespace std;

int roomprice(int room_type);
void nightstay();
int print_final_bill(int room_value, int service_charges);
int show_service();
int get_service_price(int service_type);

int main()
{
    cout<< "--------------------------------------------------------------"<<endl;
    cout<<"               HOTEL MANAGEMENT SYSTEM                         "<<endl;
    cout<<" --------------------------------------------------------------"<<endl;
    cout<<" WELCOME TO OUR HOTEL "<<endl;
    cout<<" CHOOSE THE BEST ROOM FOR YOURSELF"<<endl;
    
    
    int room_type, nights;
    int room_value = 0;
    char more = 'y';
    int service_type;
    int service_charges = 0;

    
    cout<<endl<<"on fridays(5) ,saturdays(6) and sundays(7) total increases with 10%";
    cout<<endl<<"in month of november(11)and december(12)total increases by 20%";
    while(more=='y' || more=='Y')
    {
        nightstay();

        cout<<"Enter the type of room (1-3)"<<endl;
        cin>>room_type;

        
        if(room_type==1 || room_type==2 || room_type==3)
        {
            cout<<"Enter the nights you want to spend"<<endl;
            cin>>nights;

           
            int price = roomprice(room_type);
            room_value += price * nights;
        }
        else{
            cout<<"Invalid room"<<endl;
        }

        cout<<"Enter y if you want more rooms (y/n): ";
        cin>>more;
    }

    more = 'y'; // reset for services

    while(more=='y' || more=='Y')
    {
        show_service();

        cout<<"ENTER TYPE OF SERVICE YOU WANT TO AVAIL: ";
        cin>>service_type;

        if(service_type >= 1 && service_type <= 4)
        {
            int s_price = get_service_price(service_type);
            service_charges += s_price;
        }
        else{
            cout<<"Invalid service"<<endl;
        }

        cout<<"Type y if you want more services (y/n): ";
        cin>>more;
    }

    print_final_bill(room_value , service_charges);

    return 0;
}



void nightstay()
{
    cout<<"Choose a comfortable room for yourself"<<endl;
    cout<<"WE HAVE 3 CATEGORIES OF ROOMS"<<endl;
    cout<<"1 - Standard Room   - 5000 per night"<<endl;
    cout<<"2 - Deluxe Room     - 7000 per night"<<endl;
    cout<<"3 - Luxury Suite    - 15000 per night"<<endl;
}

int roomprice(int room_type)
{
    if(room_type==1) return 5000;
    if(room_type==2) return 7000;
    if(room_type==3) return 15000;
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
    // FIXED: corrected variable names
    if(service_type == 1) return 1200;
    else if(service_type == 2) return 500;
    else if(service_type == 3) return 300;
    else if(service_type == 4) return 1500;
    return 0;
}

int print_final_bill(int room_value, int service_charges)
{int day;
    int month;
     cout<<"Enter the day(1-7)";
    cin>>day;
    cout<<endl<<"Enter the month(1-12)";
    cin>>month;
    int total = room_value + service_charges;
    float gst = total * 0.1;
    float grand_total = total + gst;
    if(day==5||day==6||day==7)
    {
        grand_total=(10/100*grand_total)+grand_total;
    }
    else{
        if(month==11||month==12)
        grand_total=(20/100*grand_total)+grand_total;
    }


    cout<<"---------------------------------------"<<endl;
    cout<<"              FINAL BILL               "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Room Charges After Daily Increases = "<<total - service_charges<<endl;
    cout<<"Service Charges = "<<service_charges<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"              FINAL BILL               "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Room Charges = "<<room_value<<endl;
    cout<<"Service Charges = "<<service_charges<<endl;
    cout<<"GST (10%) = "<<gst<<endl;
    cout<<"The Grand Total is = "<<grand_total<<endl;

    return 0;
}
