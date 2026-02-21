#include <iostream>
#include <fstream>
#include<windows.h>
#include<string>
using namespace std;

int roomprice(int room_type);
void nightstay();
void show_service();
int get_service_price(int service_type);
void print_final_bill(int room_value, int service_charges);
void customers(string &customerName, string &phone, string &cnic, int &roomtype, int &nights);
bool isroomavailable(int roomtype);
int bookroom(int room_type);
int assignroom(int room_type);


void sign_up(string user_name[10], string password[10], string roles[10], int &user_count);
void user_login(string user_name[10], string password[10], string roles[10], int &user_count, string &role);

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(h,4);
cout << "******************************************************************************" << endl;
cout << "******************************************************************************" << endl;
               SetConsoleTextAttribute(h,9);
cout << "**              II        II  II        II                                  **" << endl;
cout << "**              II II  II II    II    II                                    **" << endl;
cout << "**              II   II   II       II                                       **" << endl;
cout << "**              II        II       II                                       **" << endl;
cout << "**                                                                          **" << endl;
cout << "**          II  II      II  II      IIIIIIII  IIIIIII   II                  **" << endl;
cout << "**          II  II    II      II       II     II        II                  **" << endl;
cout << "**          IIIIII   II        II      II     IIIIIII   II                  **" << endl;
cout << "**          II  II    II      II       II     II        II                  **" << endl;
cout << "**          II  II      II II          II     IIIIIII   IIIIIIII            **" << endl;
 SetConsoleTextAttribute(h,4);
cout << "*******************************************************************************" << endl;
cout << "*******************************************************************************" << endl;

        
       int choice = 1;

    string user_name[10];
    string password[10];
    string roles[10];
    int user_count = 0;
    int room_type, nights;
        int room_value = 0;
        int service_type;
        int service_charges = 0;
        char more = 'y';
        string role;
        string customrName;
        string phone;
        string cnic;
        int night;

    while (choice)     //code entry
    {
          SetConsoleTextAttribute(h,13);
        cout << "--------Enter Option--------" << endl;
        cout << "1- Sign Up" << endl;
        cout << "2- Login" << endl;
        cout << "0- Exit" << endl;
        cin >> choice;

         if (choice == 1)
        {
            sign_up(user_name, password, roles, user_count);
            user_login(user_name, password, roles, user_count, role);
        }
        else if (choice == 2)
        {
            user_login(user_name, password, roles, user_count, role);
        }
        else if (choice == 0)
        {
            SetConsoleTextAttribute(h,3);
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            SetConsoleTextAttribute(h,3);
            cout << "Invalid option." << endl;
        }  

         // Ask for customer info after successful login
         customers(customrName, phone, cnic, room_type, night);
 
        void customers(string customrName, string phone, string cnic, int roomtype, int night);    

        int room_type, nights;   //for night stays and rooms
        int room_value = 0;
        int service_type;
        int service_charges = 0;
        char more = 'y';

        while (more == 'y' || more == 'Y')
        {
            nightstay();
             SetConsoleTextAttribute(h,15);
            cout << "Enter room type (1-3): ";
            cin >> room_type;

            if (room_type >= 1 && room_type <= 3)
            {
                cout << "Enter number of nights: ";
                cin >> nights;

                int price = roomprice(room_type);
                room_value += price * nights;

                // Now actually book the room
               bookroom(room_type);
               
               // assign specific room number

               assignroom(room_type); 
            }
            else
            {
                cout << "Invalid room type!" << endl;
            }
                 SetConsoleTextAttribute(h,15);
            cout << "Book another room? (y/n): ";
            cin >> more;
        }
            bool isroomavailable(room_type);     //to check the availability of room
            int bookroom(room_type);
            int assignroom(room_type);

            
            //for serivices we need

        more = 'y';

        while (more == 'y' || more == 'Y')
        {
            show_service();
            SetConsoleTextAttribute(h,7);

            cout << "Enter service type (1-4): ";
            cin >> service_type;

            if (service_type >= 1 && service_type <= 4)
            {
                int s_price = get_service_price(service_type);
                service_charges += s_price;
            }
            else
            {
                cout << "Invalid service!" << endl;
            }

            cout << "Add more services? (y/n): ";
            cin >> more;
        }

        print_final_bill(room_value, service_charges);
    }

    return 0;
}

// Rooms
void nightstay()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,13);
    cout << "Choose a comfortable room:" << endl;
    cout << "1. Standard Room - 5000 per night\n";
    cout << "2. Deluxe Room   - 7000 per night\n";
    cout << "3. Luxury Suite  - 15000 per night\n";
}

int roomprice(int room_type)
{
    if (room_type == 1) return 5000;
    if (room_type == 2) return 7000;
    if (room_type == 3) return 15000;
    return 0;
}

void show_service()
{
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,12);
    cout << "\nRoom Services:\n";
    cout << "1. Food Service     - 1200\n";
    cout << "2. Laundry Service  - 500\n";
    cout << "3. Room Cleaning    - 300\n";
    cout << "4. Spa Service      - 1500\n";
}

int get_service_price(int service_type)
{
    if (service_type == 1) return 1200;
    if (service_type == 2) return 500;
    if (service_type == 3) return 300;
    if (service_type == 4) return 1500;
    return 0;
}

void print_final_bill(int room_value, int service_charges)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int total = room_value + service_charges;
    float gst = total * 0.10;
    float grand_total = total + gst;
       
             SetConsoleTextAttribute(h,7);       

    cout << "-------------------------------------------------------------\n";

                    SetConsoleTextAttribute(h,4); 

    cout << "      IIIII                                                  \n";
    cout << "      II      IIIIII  II       II     II     II              \n";
    cout << "      IIIII     II    II  II   II    II II   II              \n";
    cout << "      II        II    II    II II   IIIIIII  II              \n";
    cout << "      II      IIIIII  II       II  II     II IIIIIIII        \n";
    cout << "                                                             \n";
    cout << "      II  II                                                 \n";
    cout << "      II    II                                               \n";
    cout << "      II I II    IIIIII  II      II                          \n";          
    cout << "      II  II       II    II      II                          \n";
    cout << "      II    II     II    II      II                          \n";
    cout << "      II I II    IIIIII  IIIIIII IIIIII                      \n";
               
               SetConsoleTextAttribute(h,7); 

    cout << "-------------------------------------------------------------\n";

     SetConsoleTextAttribute(h,7); 
    cout << "Room Charges:      " << room_value << endl;
    cout << "Service Charges:   " << service_charges << endl;
    cout << "GST (10%):         " << gst << endl;
    cout << "---------------------------------------\n";
    cout << "Grand Total:       " << grand_total << endl;
}

// Signup
void sign_up(string user_name[10], string password[10], string roles[10], int &user_count)
{ 
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

      SetConsoleTextAttribute(h,8); 
    cout << "---------------SIGN UP---------------" << endl;

    if (user_count >= 10)
    { 
           SetConsoleTextAttribute(h,8); 
        cout << "User limit reached!" << endl;
        return;
    }


          SetConsoleTextAttribute(h,9); 

    cout << "Enter username: ";
    cin >> user_name[user_count];
       while( true)                                     //for password validation
       {

    cout << "Enter password:    (minimum 8 chracters)";
    cin >> password[user_count];
    if(password[user_count].length()>=8)
    {
        break;     //bcz password is valid
    }
    else 
    {
    SetConsoleTextAttribute(h, 2);
    cout<<" the password is invalid try again";
    }
}


    cout << "Enter role (manager/receptionist): ";
    cin >> roles[user_count];

    // File handling part
    
    ofstream file("users.txt", ios::app); 
    if (file.is_open())
    {
        file << user_name[user_count] << " "
             << password[user_count] << " "
             << roles[user_count] << endl;
        file.close();
    }
    else
    {
            SetConsoleTextAttribute(h,7); 
        cout << "Error opening file!" << endl;
        return;
    }
              SetConsoleTextAttribute(h,7); 
    cout << "Account created successfully!" << endl;
    user_count++;
}

// Login function

void user_login(string user_name[10], string password[10], string roles[10], int &user_count, string &role)
{

          HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,7); 

    cout << "------------------LOGIN----------------" << endl;

    // file handling

    ifstream file("users.txt");
    user_count = 0;
    while(file >> user_name[user_count] >> password[user_count] >> roles[user_count])
    {
        user_count++;
        if (user_count >= 10) break; // avoid overflow
    }
    file.close();

    string username, pass;
    int attempts = 0;
  
       SetConsoleTextAttribute(h,9); 


    cout << "Enter username: ";
    cin >> username;

    while(attempts < 3)
    {
        cout << "Enter password: ";
        cin >> pass;

        bool found = false;
        for (int i = 0; i < user_count; i++)
        {
            if (user_name[i] == username && password[i] == pass)
            {
                role = roles[i];
                cout << "Login successful! Logged in as: " << role << endl;
                return; // login successful
            }
        }

        attempts++;

            SetConsoleTextAttribute(h,7); 
        cout << "Wrong password! Attempts left: " << (3 - attempts) << endl;
    }

    // After 3 failed attempts
       SetConsoleTextAttribute(h,7); 
    cout << "Too many failed attempts! You must sign up again.\n";

    sign_up(user_name, password, roles, user_count);

    // Immediately login again after signup
    user_login(user_name, password, roles, user_count, role);
}
//for having customers detail
void customers(string &customerName, string &phone, string &cnic, int &roomtype, int &nights);
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
    
    cout<<"Enter the name of customer:";
    cin>>customrName[100];
    cout<<endl<<"enter phone number:";
    cin>>phone[11000];
    cout<<endl<<"enter cnic:";
    cin>>cnic[1000];
    cout<<endl<<"Enter the room type:";
    cin>>roomtype;
    cout<<endl<<" number of nights staying:";
    cin>>night;
}
    bool isroomavailable(int room_type)
    {

        
          int totalStandard = 40;
          int totalDeluxe   = 20;
          int totalLuxury  = 12;

    
         int bookedStandard = 0;
         int bookedDeluxe   = 0;
         int bookedLuxury  = 0;

    if (room_type == 1)
    {
        if (bookedStandard < totalStandard)
        {
            cout << "ROOM AVAILABLE\n";
            return true;
        }
    }
    else if (room_type == 2)
    {
        if (bookedDeluxe < totalDeluxe)
        {
            cout << "ROOM AVAILABLE\n";
            return true;
        }
    }
    else if (room_type == 3)
    {
        if (bookedLuxury < totalLuxury)
        {
            cout << "ROOM AVAILABLE\n";
            return true;
        }
    }

    cout << "ROOM NOT AVAILABLE\n";
    return false;
}

}
      //for assigning room number
      int assignroomnum(int room_type)
      {
         int standardroom[40]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
        int deluxeroom[20]={31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
        int luxuryroom[12]={51,52,53,54,55,56,57,58,50,60,61,62};
        int totalstandardroom=40;
        int totaldeluxeroom=20;
        int totalluxuryroom=12;
        int standard_index = 0;
        int deluxe_index   = 0;
        int luxury_index   = 0;
         int assignroomnum(int room_type);
         {
       int assignroom(int room_type)
{
    if (room_type == 1)
    {
     cout << "Room number assigned: " << standardRooms[standardIndex - 1] << endl;
    }
    else if (room_type == 2)
     {
    cout << "Room number assigned: " << deluxeRooms[deluxeIndex - 1] << endl;
     }
    else if (room_type == 3) 
    {
        cout << "Room number assigned: " << luxuryRooms[luxuryIndex - 1] << endl;
    }
    return 0;
}












      }

