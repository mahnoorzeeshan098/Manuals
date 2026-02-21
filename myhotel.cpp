#include <iostream>
#include<fstream>
using namespace std;

int roomprice(int room_type);
void nightstay();
void show_service();
int get_service_price(int service_type);
void print_final_bill(int room_value, int service_charges);

 
void sign_up(string user_name[10], string password[10], string roles[10], int &user_count);
void user_login(string user_name[10], string password[10], string roles[10], int user_count, string &role);

int main()
{
    int choice = 1;

    string user_name[10];
    string password[10];
    string roles[10];
    int user_count = 0;

    while (choice)
    {
        cout << "--------enter option--------" << endl;
        cout << "1- sign up" << endl;
        cout << "2- login  " << endl;
        cout << "0- exit   " << endl;
        cin >> choice;

        string role;

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
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid option." << endl;
        }

        cout << "\n--------------------------------------------------------------" << endl;
        cout << "               HOTEL MANAGEMENT SYSTEM                         " << endl;
        cout << " --------------------------------------------------------------" << endl;

        int room_type, nights;
        int room_value = 0;
        int service_type;
        int service_charges = 0;
        char more = 'y';

        while (more == 'y' || more == 'Y')
        {
            nightstay();

            cout << "Enter room type (1-3): ";
            cin >> room_type;

            if (room_type >= 1 && room_type <= 3)
            {
                cout << "Enter number of nights: ";
                cin >> nights;

                int price = roomprice(room_type);
                room_value += price * nights;
            }
            else
            {
                cout << "Invalid room type!" << endl;
            }

            cout << "Book another room? (y/n): ";
            cin >> more;
        }

        more = 'y';

        while (more == 'y' || more == 'Y')
        {
            show_service();

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

//rooms

void nightstay()
{
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
    int total = room_value + service_charges;
    float gst = total * 0.10;
    float grand_total = total + gst;

    cout << "---------------------------------------\n";
    cout << "              FINAL BILL               \n";
    cout << "---------------------------------------\n";
    cout << "Room Charges:      " << room_value << endl;
    cout << "Service Charges:   " << service_charges << endl;
    cout << "GST (10%):         " << gst << endl;
    cout << "---------------------------------------\n";
    cout << "Grand Total:       " << grand_total << endl;
}

//signup
void sign_up(string user_name[10], string password[10], string roles[10], int &user_count)
{
    cout << "---------------SIGN UP---------------" << endl;

    if (user_count >= 10)
    {
        cout << "User limit reached!" << endl;
        return;
    }

    cout << "Enter username: ";
    cin >> user_name[user_count];

    cout << "Enter password: ";
    cin >> password[user_count];

    cout << "Enter role (manager/receptionist): ";
    cin >> roles[user_count];

    // File handling part
    ofstream file;
    file.open("users.txt", ios::app);   // append mode

    if (file.is_open())
    {
        file << user_name[user_count] << " "
             << password[user_count] << " "
             << roles[user_count] << endl;
        file.close();
    }
    else
    {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "Account created successfully!" << endl;
    user_count++;
}



 
//login function

void user_login(string user_name[10], string password[10], string roles[10], int &user_count, string &role)
{
    cout << "------------------LOGIN----------------" << endl;

    // Load users from file
    ifstream file("users.txt");
    user_count = 0;
    while(file >> user_name[user_count] >> password[user_count] >> roles[user_count])
    {
        user_count++;
    }
    file.close();

    string username, pass;
    int attempts = 0;

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
        cout << "Wrong password! Attempts left: " << (3 - attempts) << endl;
    }

    // After 3 failed attempts
    cout << "Too many failed attempts! You must sign up again.\n";
    sign_up(user_name, password, roles, user_count);

    // Immediately login again after signup
    user_login(user_name, password, roles, user_count, role);
}
