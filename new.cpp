#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

// ---------------- FUNCTION DECLARATIONS ----------------
int roomprice(int room_type);
void nightstay();
void show_service();
int get_service_price(int service_type);
void print_final_bill(int room_value, int service_charges, int nights);
float apply_discount(float total, int nights);
void customers(string &customerName, string &phone, string &cnic);
bool is_username_exists(string user_name[100], int user_count, string username);
bool isroomavailable(int roomtype, int bookedStandard, int bookedDeluxe, int bookedLuxury);
bool bookroom(int room_type, int &bookedStandard, int &bookedDeluxe, int &bookedLuxury);
int assignroom(int room_type, int &standard, int &deluxe, int &luxury);
void add_employee(int &roomCleaningStaff,int &spaStaff,int &kitchenStaff,int &receptionStaff);
void show_employees(int roomCleaningStaff, int spaStaff, int kitchenStaff, int receptionStaff);
void showavailablerooms(int bookedStandard, int bookedDeluxe, int bookedLuxury);
void store_bill(string customerName, string phone, string cnic, int room_value, int service_charges, int nights, float gst, float grandtotal);
void show_employee_records();
void manager_menu(int &bookedStandard, int &bookedDeluxe, int &bookedLuxury,int &roomCleaningStaff, int &spaStaff, int &kitchenStaff, int &receptionStaff);
void receptionist_menu(int &bookedStandard, int &bookedDeluxe, int &bookedLuxury, int &roomNumStandard, int &roomNumDeluxe, int &roomNumLuxury);

void sign_up(string user_name[100], string password[100], string roles[100], int &user_count);
bool user_login(string user_name[100], string password[100], string roles[100], int &user_count, string &role);


// ---------------- MAIN ----------------
int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, 12); 
    cout << "************************************************************\n";
    cout << "************************************************************\n";

    SetConsoleTextAttribute(h, 11); 
    cout << "\n                    WELCOME TO\n";

    SetConsoleTextAttribute(h, 14); 
    cout << "\n                HOTEL MANAGEMENT SYSTEM\n";

    SetConsoleTextAttribute(h, 10); // Green
    cout << "\n          Manage Rooms, Services, Employees Easily\n";

    SetConsoleTextAttribute(h, 12); 
    cout << "\n************************************************************\n";
    cout << "************************************************************\n\n";

    // ---------------- VARIABLES ----------------
    
    int bookedStandard=0, bookedDeluxe=0, bookedLuxury=0;
    int roomNumStandard=1, roomNumDeluxe=31, roomNumLuxury=51;
    int roomCleaningStaff=0, spaStaff=0, kitchenStaff=0, receptionStaff=0;

    string user_name[100], password[100], roles[100];
    int user_count = 0;
    string role;

    char choice;
    bool isLoggedIn = false;

    // ---------------- LOGIN / SIGNUP LOOP ----------------
    while(true)
    {
        SetConsoleTextAttribute(h, 11); // Cyan
        cout << "\n1 - Sign Up\n2 - Login\n3 - Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        if(choice == '1')
        {
            sign_up(user_name, password, roles, user_count);

            // login immediately after signup
            if(!user_login(user_name, password, roles, user_count, role))
            {
                cout << "Login failed after signup. Exiting...\n";
                return 0;
            }
            else
            {
                cout << "Login successful! Role: " << role << "\n";
                break;
            }
        }
        else if(choice == '2')
        {
            if(user_login(user_name, password, roles, user_count, role))
            {
                cout << "Login successful! Role: " << role << "\n";
                break;
            }
            else
            {
                cout << "Login failed! Try again.\n";
            }
        }
        else if(choice == '3')
        {
            cout << "Exiting program...\n";
            return 0;
        }
        else
        {
            cout << "Invalid choice! Press Enter to continue...";
            cin.get();
        }
    }

    // ---------------- CALL MENU BASED ON ROLE ----------------
    if(role == "manager")
    {
        manager_menu(bookedStandard, bookedDeluxe, bookedLuxury,
                     roomCleaningStaff, spaStaff, kitchenStaff, receptionStaff);
    }
    else if(role == "receptionist")
    {
        receptionist_menu(bookedStandard, bookedDeluxe, bookedLuxury,
                          roomNumStandard, roomNumDeluxe, roomNumLuxury);
    }
    else
    {
        cout << "Invalid role. Exiting...\n";
        return 0;
    }

    return 0;
}

// ================= FUNCTIONS =================


//----------------signup func--------------

void sign_up(string user_name[100], string password[100], string roles[100], int &user_count)
{
    if (user_count >= 100)
    {
        cout << "User limit reached!\n";
        return;
    }

    cout << endl<<"-----------------------------------------------";
    cout<<endl;
    cout<<"                        SIGN UP                        ";
    cout<<endl;
    cout<<" -------------------------------------------------"<<endl;

    cout << endl<<"Enter username: "<<endl;
    cin >> user_name[user_count];
    if (is_username_exists(user_name, user_count, user_name[user_count]))
{
    cout << "Username already exists! Try another."<<endl;
    return;
}

    while (true)
    {
        cout << "Enter password (min 8 chars): ";
        cin >> password[user_count];

        if (password[user_count].length() >= 8)
            break;

        cout << "Password too short! Try again.\n";
    }

    cout << "Enter role (manager/receptionist): ";
    cin >> roles[user_count];

// Keep asking until input is correct
while (roles[user_count] != "manager" && roles[user_count] != "receptionist") 
{
    cout << "Invalid role! Please enter 'manager' or 'receptionist': ";
    cin >> roles[user_count];
}

cout << "Role accepted: " << roles[user_count] << endl;

    ofstream file("users.txt", ios::app);
    file << user_name[user_count] << " "
         << password[user_count] << " "
         << roles[user_count] << endl;
    file.close();

    cout << "Account created successfully!\n";
    user_count++;
}

//----------------duplicate username----------------------


bool is_username_exists(string user_name[100], int user_count, string username)
{
    for (int i = 0; i < user_count; i++)
    {
        if (user_name[i] == username)
        {
            return true;   // username already exists
        }
    }
    return false;          // username not found
}



//-------------------login function------------------------


bool user_login(string user_name[100], string password[100], string roles[100], int &user_count, string &role)
{
    ifstream file("users.txt");
    user_count = 0;

    while (file >> user_name[user_count] >> password[user_count] >> roles[user_count])
    {
        user_count++;
        if (user_count >= 100) break;
    }
    file.close();

    string username, pass;
    cout << endl<<"-----------------------------------------";
    cout<<endl;
    cout<<        "              LOGIN                      ";
    cout<<endl;
    cout<<       " -----------------------------------------"<<endl;
    cout << "Enter username: ";
    cin >> username;

    int index = -1;
    for (int i = 0; i < user_count; i++)
    {
        if (user_name[i] == username)
        {
            index = i;
            break;
        }
    }

    // Username not found it must sign up
    if (index == -1)
    {
        cout << "User not found. Please sign up first.\n";
        return false;
    }

    // Password attempts
    for (int attempts = 1; attempts <= 3; attempts++)
    {
        cout << "Enter password: ";
        cin >> pass;

        if (pass == password[index])
        {
            role = roles[index];
            cout << "Login successful! Logged in as: " << role << endl;
            return true;
        }

        cout << "Wrong password! Attempts left: " << (3 - attempts) << endl;
    }

    cout << "Too many failed attempts! Please sign up again.\n";
    return false;
}

//------------------managers role-------------------------

void manager_menu(int &bookedStandard, int &bookedDeluxe, int &bookedLuxury,int &roomCleaningStaff, int &spaStaff,int &kitchenStaff, int &receptionStaff)

 {
    char more = 'y';
    while(more == 'y' || more == 'Y')
     {
        string choice = "";

        
        while (true) 
        {
            cout << "\n----------------------------------------------";
            cout<<endl;
            cout<<  "                 MANAGER MENU                  ";
            cout<<endl;
            cout<< "------------------------------------------------"<<endl;

            cout << "1. Add Employee\n";
            cout << "2. Show Employees\n";
            cout << "3. View Booked Rooms / Customer Details\n";
            cout << "4. Show Available Rooms\n";
            cout << "5. View All Bills\n";
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore(); 

           if(choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5")

            {
                break; // valid choice
            } 
            else 
            {
                cout << "Invalid choice! Please select again from the menu.\n";
            }
        }

        // Execute the selected choice
        if(choice == "1")
         {
            add_employee(roomCleaningStaff, spaStaff, kitchenStaff, receptionStaff);
         }
        
        else if(choice == "2")
         {
            show_employees(roomCleaningStaff, spaStaff, kitchenStaff, receptionStaff);

             
        }
        else if(choice == "3") 
        {
            ifstream file("bills.txt");
            string line;
            cout << "\n--- Booked Rooms / Customer Details ---\n";
            while(getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else if(choice == "4")
         {
            showavailablerooms(bookedStandard, bookedDeluxe, bookedLuxury);
        }
        else if(choice == "5") 
        {
            ifstream file("bills.txt");
            string line;
            cout << "\n--- All Bills ---\n";
            while(getline(file, line)) 
            {
                cout << line << endl;
            }
            file.close();
        }

        cout << "\nDo you want to continue in Manager Menu? (y/n): ";
        cin >> more;
        cin.ignore();
    }
}
    

    //----------- check customers details-----------------

void customers(string &customerName, string &phone, string &cnic)
{
    // Customer Name
    while(true)
    {
        cout << "Enter customer name: ";
        // cin.ignore(); removed double ignore
        getline(cin, customerName);

        bool valid = true;
        for(int i = 0; i < customerName.length(); i++)
        {
            if(!isalpha(customerName[i]) && customerName[i] != ' ')
            {
                valid = false;
                break;
            }
        }

        if(valid && customerName.length() > 0)
        {
            cout << "Name verified.\n";
            break;
        }
        else
            cout << "Invalid name! Only letters and spaces allowed.\n";
    }

    // Phone validation
    while (true)
    {
        cout << "Enter phone number: ";
        cin >> phone;

        bool valid = true;

        if (phone.length() < 10 || phone.length() > 12)
        {
            valid = false;
            cout << "Phone number must be between 10 and 12 digits.\n";
        }

        for (int i = 0; i < phone.length(); i++)
        {
            if (!isdigit(phone[i]))
            {
                valid = false;
                cout << "Phone number should contain only digits!\n";
                break;
            }
        }

        if(valid)
        {
            cout << "Phone number verified.\n";
            break;
        }
    }

    // CNIC validation
    while (true)
    {
        cout << "Enter CNIC (13 digits): ";
        cin >> cnic;

        if(cnic.length() != 13)
        {
            cout << "Invalid CNIC length! Must be 13 digits.\n";
            continue;
        }

        bool valid = true;
        for(int i = 0; i < cnic.length(); i++)
        {
            if(!isdigit(cnic[i]))
            {
                valid = false;
                break;
            }
        }

        if(valid)
        {
            cout << "CNIC verified: " << cnic << endl;
            break;
        }
        else
        {
            cout << "Invalid CNIC! Only numbers are allowed.\n";
        }
    }
}


void nightstay()
{
    cout << "\n1. Standard Room - 5000\n";
    cout << "2. Deluxe Room   - 7000\n";
    cout << "3. Luxury Room   - 15000\n";
}

//------------------return room price------------------------

int roomprice(int room_type)
{
    if (room_type == 1) 
    return 5000;
    if (room_type == 2) 
    return 7000;
    if (room_type == 3)
    return 15000;
    else
    return 0;
}

//--------------check availability of rooms-----------------------

bool isroomavailable(int roomtype, int bookedStandard, int bookedDeluxe, int bookedLuxury)
{
    if(roomtype==1 && bookedStandard<40)
     return true;
    if(roomtype==2 && bookedDeluxe<20) 
    return true;
    if(roomtype==3 && bookedLuxury<12) 
    return true;
    else
    return false;
}


//--------------------available rooms-----------------------------

void showavailablerooms(int bookedStandard, int bookedDeluxe, int bookedLuxury)
 {
    cout << "\n--- Available Rooms ---\n";

    cout << "Standard Rooms: ";
    for (int i = 1; i <= 40; i++) {
        if (i > bookedStandard)               // If the room number is higher than booked count
            cout << i << " ";                 //prints number that are higher than booked count
    }
    cout << endl;

    cout << "Deluxe Rooms: ";
    for (int i = 31; i <= 50; i++)
     {
        if (i - 30 > bookedDeluxe)  
            cout << i << " ";
    }
    cout << endl;

    cout << "Luxury Rooms: ";
    for (int i = 51; i <= 62; i++) 
    {
        if (i - 50 > bookedLuxury) 
            cout << i << " ";
    }
    cout << endl;
}

//-------------------book rooms------------------------------------

bool bookroom(int room_type, int &bookedStandard, int &bookedDeluxe, int &bookedLuxury)
{
    if(room_type==1)
    { 
        bookedStandard++; cout<<"Standard room booked\n"; return true; 
    }
    if(room_type==2) 
    {
         bookedDeluxe++; cout<<"Deluxe room booked\n"; return true; 
    }
    if(room_type==3) 
    { 
        bookedLuxury++; cout<<"Luxury room booked\n"; return true;
    }
    return false;
}


//-----------------assign room num---------------------------


int assignroom(int room_type, int &standard, int &deluxe, int &luxury)
{
    if(room_type==1) 
    { 
        cout<<"Room Number: "<<standard<<endl; return standard++; 
    }
    if(room_type==2) 
    { 
        cout<<"Room Number: "<<deluxe<<endl; return deluxe++; 
    }
    if(room_type==3)
     { 
        cout<<"Room Number: "<<luxury<<endl; return luxury++; 
    }
    return 0;
}
                            

     
//------------------- to show services provided-------------------
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

//------------------for service prices------------------------------


int get_service_price(int service_type)
{
    if (service_type == 1) 
    {
        return 1200;
    }
    if (service_type == 2)
    {
         return 500;
    }
    if (service_type == 3) 
    {
        return 300;
    }
    if (service_type == 4) 
    {
        return 1500;
    }
    return 0;
}


//------------------workers------------------------------------

void add_employee(int &roomCleaningStaff,
                  int &spaStaff,
                  int &kitchenStaff,
                  int &receptionStaff)
{
    char more = 'y';

    while (more == 'y' || more == 'Y')
    {
        string name, department;
        int choice;
        bool validChoice = false;

        cout << "\n------------------------------------------\n";
        cout << "              ADD WORKERS\n";
        cout << "------------------------------------------\n";

        while (!validChoice)
        {
            cout << "Select Department:\n";
            cout << "1. Room Cleaning\n2. Spa\n3. Kitchen\n4. Reception\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            cin.ignore(); // clear newline

            if (choice >= 1 && choice <= 4)
                validChoice = true;
            else
            {
                cout << "Invalid choice! Press Enter to try again...";
                cin.get();
            }
        }

        cout << "Enter employee name: ";
        getline(cin, name);

        if (choice == 1)
         {
            roomCleaningStaff++;
            department = "Room Cleaning";
        }
        else if (choice == 2) 
        {
            spaStaff++;
            department = "Spa";
        }
        else if (choice == 3) 
        {
            kitchenStaff++;
            department = "Kitchen";
        }
        else if (choice == 4)
         {
            if (receptionStaff >= 8) 
            {
                cout << "Cannot add more receptionists!\n";
                continue;
            }
            receptionStaff++;
            department = "Reception";
        }

        ofstream file("employees.txt", ios::app);
        if (file.is_open())
            file << "Name: " << name << ", Department: " << department << endl;
        file.close();

        cout << "Added " << name << " to " << department << " department.\n";

        cout << "Do you want to add more employees? (y/n): ";
        cin >> more;
        cin.ignore();
    }
}

        

       

//---------------show the employeess----------------------------

void show_employees(int roomCleaningStaff, int spaStaff, int kitchenStaff, int receptionStaff)
{
    cout<<"\nRoom Cleaning: "<<roomCleaningStaff
        <<"\nSpa: "<<spaStaff
        <<"\nKitchen: "<<kitchenStaff
        <<"\nReception: "<<receptionStaff<<endl;
}



//--------------------------discounts----------------------------

float apply_discount(float total, int nights)
{
    if (nights > 10)
    {
        total = total - (total * 0.15);   // 15% discount
    }
    else if (nights > 5)
    {
        total = total - (total * 0.10);   // 10% discount
    }

    return total;
}

//----------------------final bill----------------------


void print_final_bill(int room_value, int service_charges, int nights)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    float total = room_value + service_charges;
    total = apply_discount(total, nights);  // use local nights
    float gst = total * 0.10;
    float grandtotal = total + gst;

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

    cout << "-----------------------------------------------------------------";

    cout << "Room Charges: " << room_value << endl;
    cout << "Service Charges: " << service_charges << endl;
    cout << "GST: " << gst << endl;
    cout << "Grand Total: " << grandtotal << endl;
}

//-----------------STORING BILL---------------------------------------

void store_bill(string customerName, string phone, string cnic, int room_value, int service_charges, int nights, float gst, float grandtotal)
 {
    ofstream file("bills.txt", ios::app);
    file << "------------------------------------------------\n";
    file << "Customer Name: " << customerName << endl;
    file << "Phone: " << phone << endl;
    file << "CNIC: " << cnic << endl;
    file << "Room Charges: " << room_value << endl;
    file << "Service Charges: " << service_charges << endl;
    file << "Nights Stayed: " << nights << endl;
    file << "GST: " << gst << endl;
    file << "Grand Total: " << grandtotal << endl;
    file << "------------------------------------------------\n\n";
    file.close();
}

//-----------------RECORDS OF EMPLOYEES--------------------------
void show_employee_records()
 {
    ifstream file("employees.txt");                 // open file for reading
    if (!file.is_open()) 
    {
        cout << "No employee records found.\n";
        return;
    }

    cout << "\n------------------------------------------------";
    cout<<endl;
    cout<<  "               EMPLOYEES RECORD                   ";
    cout<<endl;
    cout<<"    ------------------------------------------------";

    string line;
    bool hasData = false;
    while (getline(file, line))
     {  // read file line by line
        cout << line << endl;
        hasData = true;
    }

    if (!hasData)
    {
        cout << "No employee records found.\n";
    }

    file.close();
}

//-------------------receptionist menu---------------------------------

void receptionist_menu(int &bookedStandard, int &bookedDeluxe, int &bookedLuxury,int &roomNumStandard, int &roomNumDeluxe, int &roomNumLuxury) 
 {

    char more = 'y';
    while (more == 'y' || more == 'Y') 
    {
        string choice;

        // for validation of choice

        while (true) 
        {
            cout << "\n-----------------------------------------------";
            cout<<endl;
            cout<<  "                RECEPTION MENU                   ";
            cout<<endl;
            cout<<  " ------------------------------------------------";

            cout << "1. Book Room for Customer\n";
            cout << "2. Show Available Rooms\n";
            cout << "3. Add Services for Customer\n";
            cout << "4. View Customer Details / Bills\n";
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore(); // clear newline


           if (choice != "1" && choice != "2" && choice != "3" && choice != "4")
            {
                 cout << "Invalid choice! Please select 1-4.\n";
            }
            else
            {
                break;
            }
        }

        if (choice == "1") 
        {
            string customerName, phone, cnic;
            int room_type, nights = 0, room_value = 0;
            customers(customerName, phone, cnic); // enter customer details

            char addMoreRooms = 'y';
            while (addMoreRooms == 'y' || addMoreRooms == 'Y') 
            {
                nightstay();

                // Validate room type
                while (true)
                 {
                    cout << "Enter room type (1-3): ";
                    cin >> room_type;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input! Please enter a number.\n";
                        continue;
                    }
                    if (room_type >= 1 && room_type <= 3) 
                    {
                        break;
                    }
                    cout << "Invalid room type! Please enter 1, 2, or 3.\n";
                }

                if (isroomavailable(room_type, bookedStandard, bookedDeluxe, bookedLuxury)) 
                {
                    cout << "Enter number of nights: ";
                    cin >> nights;
                    room_value += roomprice(room_type) * nights;
                    bookroom(room_type, bookedStandard, bookedDeluxe, bookedLuxury);
                    assignroom(room_type, roomNumStandard, roomNumDeluxe, roomNumLuxury);
                }
                 else
                {
                    cout << "Room not available!\n";
                }

                cout << "Book another room for this customer? (y/n): ";
                cin >> addMoreRooms;
            }

            // Services
            int service_charges = 0;
            char addMoreServices;
            
            cout << "Do you want to add services? (y/n): ";
            cin >> addMoreServices;

            while (addMoreServices == 'y' || addMoreServices == 'Y')
             {
                show_service();

                int service_type;
                // Validate service type
                while (true) 
                {
                    cout << "Enter service type (1-4): ";
                    cin >> service_type;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input! Please enter a number.\n";
                        continue;
                    }
                    if (service_type >= 1 && service_type <= 4) break;
                    cout << "Invalid service! Enter 1-4.\n";
                }

                service_charges += get_service_price(service_type);

                cout << "Add more services? (y/n): ";
                cin >> addMoreServices;
            }

            print_final_bill(room_value, service_charges, nights);
            
             // Calculate totals and store bill
            float total = room_value + service_charges;
            total = apply_discount(total, nights);
            float gst = total * 0.10;
            float grandtotal = total + gst;

            store_bill(customerName, phone, cnic, room_value, service_charges, nights, gst, grandtotal);
        }
        else if (choice == "2") 
        {
            showavailablerooms(bookedStandard, bookedDeluxe, bookedLuxury);
        }
        else if (choice == "3") 
        {
            cout << "To add services, please book a room first in option 1.\n";
        }
        else if (choice == "4") 
        {
            ifstream file("bills.txt");
            string line;
            cout << "\n-------------------------------------------------------";
            cout<<endl;
            cout<<  "               CUSTOMERS DETAIL                          "<<endl;
            cout<<  "                     BILL                                "<<endl;
            cout<<endl;
            cout<<  "---------------------------------------------------------";
            while (getline(file, line))
             {
                cout << line << endl;
            }
            file.close();
        }

        cout << "\nDo you want to continue in Receptionist Menu? (y/n): ";
        cin >> more;
        cin.ignore();
    }
}