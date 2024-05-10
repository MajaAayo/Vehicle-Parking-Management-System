#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

const int PARKING_CAPACITY = 2; // Define parking capacity

int numVehiclesParked = 0; // Track number of vehicles parked

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void login()
{
    string username = "admin";
    string password = "admin123";
    string user, pass;
    int loginAttempt = 0;

    while (loginAttempt < 3)
    {
        clearScreen();
             cout<<"\n"
                       "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                       "\t\t\t\t\t|                              Login Here                             |\n"
                       "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter Username: ";
        cin >> user;

        if (user != username)
        {
            cout << "\nInvalid Username!!!\n";
            cout << "\nPress Enter to try again...";
            cin.ignore();
            cin.get();
        }
        else
        {
            cout << "Enter Password: ";
            cin >> pass;
            if (pass == password)
            {
                cout << "\nLogin successful! Please wait for 5 seconds...\n";
                // Platform-specific sleep
#ifdef _WIN32
                Sleep(5000); // 5000 milliseconds = 5 seconds
#else
                sleep(5);    // 5 seconds
#endif
                return;
            }
            else
            {
                cout << "\nInvalid Password!!!\n";
                cout << "\nPress Enter to try again...";
                cin.ignore();
                cin.get();
            }
        }
        cout << "\n---------------------->  Invalid login attempt. Please try again.  <---------------------------\n";
        cout << "\t\t\t\t\tAttempt " << loginAttempt + 1 << " of 3\n";
        loginAttempt++;
    }

    if (loginAttempt == 3)
    {
        cout << "\nToo many login attempts! The program will now terminate.\n";
        cout << "Please try again after 5 seconds...\n";
        // Platform-specific sleep
#ifdef _WIN32
        Sleep(5000); // 5000 milliseconds = 5 seconds
#else
        sleep(5);    // 5 seconds
#endif
        exit(0);
    }
}

class Amount
{
    int cycle;
    int scooter;
    int bike;
    int autoRickshaw;
    int car;
    int bus;
    int total;

public:
    Amount()
    {
        cycle = 0;
        scooter = 0;
        bike = 0;
        autoRickshaw = 0;
        car = 0;
        bus = 0;
    }

    void gettotalAmount(int cycle, int scooter, int bike, int autoRickshaw, int car, int bus, int total, int hours)
    {
        this->cycle = cycle * hours;
        this->scooter = scooter * hours;
        this->bike = bike * hours;
        this->autoRickshaw = autoRickshaw * hours;
        this->car = car * hours;
        this->bus = bus * hours;
        this->total = total * hours;
    }

    void showtotalAmount()
    {
        cout << "+---------------+-------+" << endl;
        cout << "| Vehicle Type  | Total |" << endl;
        cout << "+---------------+-------+" << endl;
        cout << "| Cycle         | " << setw(5) << cycle << " |" << endl;
        cout << "| Scooter       | " << setw(5) << scooter << " |" << endl;
        cout << "| Bike          | " << setw(5) << bike << " |" << endl;
        cout << "| Auto Rickshaw | " << setw(5) << autoRickshaw << " |" << endl;
        cout << "| Car           | " << setw(5) << car << " |" << endl;
        cout << "| Bus           | " << setw(5) << bus << " |" << endl;
        cout << "+---------------+-------+" << endl;
        cout << "| Total         | " << setw(5) << total << " |" << endl;
        cout << "+---------------+-------+" << endl;
    }

    int getTotalAmount()
    {
        return total;
    }
    void writeearnedAmount();
};
void Amount::writeearnedAmount()
{
    ifstream fread;
    fread.open("AearnedAmount.txt", ios_base::in|ios_base::binary);
    fread.read((char*)this, sizeof(*this));
    if(!fread){
        cout<<"\nFile not found!!!\n";
    }
    else{
        fread.read((char*)this, sizeof(*this));
        this->showtotalAmount();
    }
}

class VehicleType
{
private:
    string vehicleTypeName;

public:
    VehicleType()
    {
        vehicleTypeName = "Vehicle";
    }

    void setvehicleType(string type)
    {
        vehicleTypeName = type;
    }
    string getvehicleType() const 
    {
        return vehicleTypeName;
    }
    void readvehicleType(Amount &amt, int hours)
    {
        while (true)
        {
            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Cycle \n2. Scooter \n3. Bike \n4. Auto-Rickshaw \n5. Car \n6. Bus\n";
            int vType;
            cout << "\nEnter Vehicle Type: ";
            cin >> vType;

            switch (vType)
            {
            case 1:
                setvehicleType("Cycle");
                amt.gettotalAmount(10, 0, 0, 0, 0, 0, 10, hours);
                break;
            case 2:
                setvehicleType("Scooter");
                amt.gettotalAmount(0, 10, 0, 0, 0, 0, 10, hours);
                break;
            case 3:
                setvehicleType("Bike");
                amt.gettotalAmount(0, 0, 20, 0, 0, 0, 20, hours);
                break;
            case 4:
                setvehicleType("Auto-Rickshaw");
                amt.gettotalAmount(0, 0, 20, 0, 0, 0, 20, hours);
                break;
            case 5:
                setvehicleType("Car");
                amt.gettotalAmount(0, 0, 0, 0, 50, 0, 50, hours);
                break;
            case 6:
                setvehicleType("Bus");
                amt.gettotalAmount(0, 0, 0, 0, 0, 100, 100, hours);
                break;
            default:
                cout << "\nInvalid Choice!!!\n";
                cout << "\nPress Enter to try again...";
                cin.ignore();
                cin.get();
                break;
            }
            if (vType >= 1 && vType <= 7)
            {
                break;
            }
        }
    }

    void displayVehicleType()
    {
        cout << vehicleTypeName << " ";
    }
};

class VehicleDetails : public VehicleType
{
private:
    long long cPhone;
    int vmodelNumber;
    int hours;
    string cName;
    string cAddress;
    string vColor;
    string vCompanyName;
    string entryBy;
    string entryTime;
    string updatedBy;
    string updatedTime;

    VehicleType vType;
    Amount amt;

public:
    VehicleDetails()
    {
        cPhone = 0;
        vmodelNumber = 0;
        cName = "default";
        cAddress = "default";
        vColor = "default";
        vCompanyName = "default";
        entryBy = "Kushal";
        time_t lTime;
        time(&lTime);
        entryTime = asctime(localtime(&lTime));
    }

    void setvehicleType()
    {
        vType.readvehicleType(amt, 1);
    }

    void readDetails()
    {
        cout << "Enter Customer Name: ";
        cin.ignore();
        getline(cin, cName);

        cout << "Enter Customer Address: ";
        getline(cin, cAddress);

        cout << "Enter Customer Phone Number: ";
        cin >> cPhone;
        cin.ignore();
        cout << "Enter Hours Parked: ";

        cin >> hours;
        vType.readvehicleType(amt, hours);

        cout << "Enter Vehicle Model Number: ";
        cin >> vmodelNumber;
        cin.ignore();

        cout << "Enter Vehicle Color: ";
        getline(cin, vColor);

        cout << "Enter Vehicle Company Name: ";
        getline(cin, vCompanyName);

        entryBy = "Kushal";
        time_t lTime;
        time(&lTime);
        entryTime = asctime(localtime(&lTime));
    }

    void displayvehicleDetails()
    {
        cout << "\n";
        cout << "+------------------------------------------------------------------------+\n";
        cout << "|                      Vehicle Details                                   |\n";
        cout << "+------------------------------------------------------------------------+\n";
        cout << "| Customer Name      : " << setw(30) << cName << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Customer Address   : " << setw(30) << cAddress << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Hours Parked       : " << setw(30) << hours << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Customer Phone     : " << setw(30) << cPhone << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Vehicle Model      : " << setw(30) << vmodelNumber << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Vehicle Type       : ";
        vType.displayVehicleType();
        cout << "|\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Vehicle Color      : " << setw(30) << vColor << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Vehicle Company    : " << setw(30) << vCompanyName << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Entry By           : " << setw(30) << entryBy << " |\n";
        cout << "+-------------------------------------------------------+\n";
        cout << "| Entry Date         : " << setw(30) << entryTime << "|"<<endl;
        cout << "+-------------------------------------------------------+\n";
        cout << "Vehicle details written successfully in file!!!" << endl;
    }

    void displayAmount()
    {
        cout << "\n+------------------------------------------------------------------------+\n";
        cout << "|                      Vehicle Bills                                   |\n";
        cout << "+------------------------------------------------------------------------+\n";
        amt.showtotalAmount();
        cout << "Amount details written successfully in file!!!" << endl;
        cout << "\n";
    }

    void writeVehicle()
    {
        ofstream obj;
        obj.open("AvehicleData.txt", ios_base::app); // Open file in append mode
        if (!obj)
        {
            cout << "Error opening file for writing vehicle details!" << endl;
            return;
        }

        // Write vehicle details
        obj << "Customer Name: " << cName << endl;
        obj << "Customer Address: " << cAddress << endl;
        obj << "Customer Phone: " << cPhone << endl;
        obj << "Hours Parked: " << hours << endl;
        obj << "Vehicle Model: " << vmodelNumber << endl;
        obj << "Vehicle Type: " << vType.getvehicleType() << endl;
        obj << "Vehicle Color: " << vColor << endl;
        obj << "Vehicle Company: " << vCompanyName << endl;
        obj << "Entry By: " << entryBy << endl;
        obj << "Entry Time: " << entryTime << endl;
        obj.close();

        // Check if parking is full
        if (numVehiclesParked >= PARKING_CAPACITY)
        {
            cout << "!!!!!!!!!!!!!!!!!! Parking is full. Cannot park more vehicles !!!!!!!!!!!!!!!!!!!" << endl;
            return;
        }

        // Increment number of vehicles parked
        numVehiclesParked++;
    }

    void writeAmount()
    {
        ofstream obj;
        obj.open("AearnedAmount.txt", ios_base::app); // Open file in append mode
        if (!obj)
        {
            cout << "Error opening file for writing amount details!" << endl;
            return;
        }

        // Write amount details
        obj << "Customer Name: " << cName << endl;
        obj << "Vehicle Model: " << vmodelNumber << endl;
        obj << "Vehicle Type: " << vType.getvehicleType() << endl;
        obj << "Vehicle Color: " << vColor << endl;
        obj << "Entry By: " << entryBy << endl;
        obj << "Entry Time: " << entryTime << endl;
        obj << "Total Amount Earned: " << amt.getTotalAmount() << endl;
        obj << "----------------------------------------" << endl; // Add a separator for each entry
        obj.close();
    }
};
int searchVehicle()
{
    int searchType;
    string searchTerm;
    cout << "\nSearch Vehicle by:\n";
    cout << "1. Customer Name\n";
    cout << "2. Vehicle ID\n";
    cout << "Enter choice: ";
    cin >> searchType;
    cin.ignore();

    cout << "Enter search term: ";
    getline(cin, searchTerm);

    ifstream vehicleFile("AvehicleData.txt");
    if (!vehicleFile)
    {
        cout << "\nUnable to open file\n";
        return -1;
    }

    bool found = false;
    string line;
    while (getline(vehicleFile, line))
    {
        if (line.find(searchTerm) != string::npos)
        {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching records found." << endl;
    }

    vehicleFile.close();
    return 0;
}
void checkOutVehicle()
{
    int checkoutModelNumber;
    cout << "Enter Vehicle Model Number to check-out: ";
    cin >> checkoutModelNumber;

    ifstream inFile("AvehicleData.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile)
    {
        cout << "Error opening file for reading or writing!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(inFile, line))
    {
        if (line.find("Vehicle Model: " + to_string(checkoutModelNumber)) != string::npos)
        {
            found = true;
            cout << "Vehicle with Model Number " << checkoutModelNumber << " checked out successfully!" << endl;
            numVehiclesParked--; // Decrease the number of vehicles parked
        }
        else
        {
            tempFile << line << endl;
        }
    }

    if (!found)
    {
        cout << "Vehicle with Model Number " << checkoutModelNumber << " not found!" << endl;
    }

    inFile.close();
    tempFile.close();

    remove("AvehicleData.txt");
    rename("temp.txt", "AvehicleData.txt");

    // Increase parking capacity
    int availableCapacity = PARKING_CAPACITY - numVehiclesParked;
    cout << "Available Parking Capacity: " << availableCapacity << endl;
}

void displayPaymentMethods()
{
    cout << "\nPayment Methods:\n";
    cout << "1. Cash\n";
    cout << "2. Online Payment\n";
}

void displayQRCode()
{
    cout << "\nQR Code: "
                       "|-------------------|\n"
                       "|                   |\n"
                       "|     SCAN HERE     |\n"
                       "|                   |\n";
                       "|-------------------|\n";

}

int menu()
{
    int ch;
    cout << "\n1. Check-In";
    cout << "\n2. Read Vehicle Details";
    cout << "\n3. Read Amount Details";
    cout << "\n4. Search vehicle";
    cout << "\n5. Check-Out";
    cout << "\n6. Display parking rate and payment method";
    cout << "\n7. Exit";
    cout << "\nEnter Your Choice: ";
    cin >> ch;
    return (ch);
}

int main()
{
    login();
 cout<<"\n"
                       "|--------------------------------------------------------------------|\n"
                       "|          Welcome to the Vehicle Parking Management System          |\n"
                       "|--------------------------------------------------------------------|\n";
    char select;
    bool displayMenu = true;

    while (true)
    {
        if (displayMenu)
        {
            switch (menu())
            {
            case 1:
            {
                cout << "Available Parking Capacity: " << PARKING_CAPACITY << endl;
                do
                {
                    VehicleDetails vehicle;
                    vehicle.readDetails();
                    vehicle.displayvehicleDetails();

                    // Wait for 5 seconds
                    cout << "\nPress Enter to print bills...\n";
                    cin.ignore();
                    cin.get();

                    cout << "Please wait for 5 seconds...\n";
                    #ifdef _WIN32
                    Sleep(5000); // 5000 milliseconds = 5 seconds
                    #else
                    sleep(5); // 5 seconds
                    #endif

                    vehicle.displayAmount();
                    vehicle.writeVehicle();
                    vehicle.writeAmount();

                    int availableCapacity = PARKING_CAPACITY - numVehiclesParked;
                    cout << "Available Parking Capacity: " << availableCapacity << endl;
                    if (numVehiclesParked >= PARKING_CAPACITY)
                    {
                        cout << "\nParking is full. Cannot park more vehicles." << endl;
                        break;
                    }

                    cout << "\nDo you want to enter details of another vehicle? (y/n): ";
                    cin >> select;
                    cin.ignore(); // Clear the input buffer
                    cout << endl;

                } while (select == 'Y' || select == 'y');
                // if(select == 'N' || select!= 'n')
                // {
                //     cout << "\nExiting the program. Thank you!\n\n";
                //     exit(0);
                // }

                // After exiting the loop
                if (numVehiclesParked >= PARKING_CAPACITY)
                {
                    char displayMenuChoice;
                    cout << "\nParking is full. Do you want to display the menu again? (y/n): ";
                    cin >> displayMenuChoice;
                    if (displayMenuChoice == 'y' || displayMenuChoice == 'Y')
                    {
                        cout << "\nDisplaying menu...\n";
                        displayMenu = true;
                    }
                    else
                    {
                        cout << "\nExiting the program. Thank you!\n";
                        exit(0);
                    }
                }
            }
            break;

              case 2:
            {
                // Read and display vehicle details
                ifstream vehicleFile("AvehicleData.txt");
                if (vehicleFile.is_open())
                {
                    cout << "\n--- Vehicle Details ---\n";
                    string line;
                    while (getline(vehicleFile, line))
                    {
                        cout << line << endl;
                    }
                    vehicleFile.close();
                }
                else
                {
                    cout << "\nUnable to open file\n";
                }
            }
            break;

            case 3:
            {
                // Read and display amount details
                ifstream amountFile("AearnedAmount.txt");
                if (amountFile.is_open())
                {
                    cout << "\n--- Amount Details ---\n";
                    string line;
                    while (getline(amountFile, line))
                    {
                        cout << line << endl;
                    }
                    amountFile.close();
                }
                else
                {
                    cout << "\nUnable to open file\n";
                }
            }
            break;
            
            case 4:
                    searchVehicle();
                    break;
                case 5:
                // Check-Out functionality
                // Remove vehicle details from file and increase parking capacity
                checkOutVehicle();
                 break;
//        case 6:
// {
//     displayPaymentMethods();
//     int paymentChoice;
//     cout << "\nEnter your payment method choice: ";
//     cin >> paymentChoice;

//     // Initialize paymentChoice before the switch statement
//     switch (paymentChoice)
//     {
//     case 1:
//         cout << "\nPayment completed. Thank you!\n";
//         break;
//     case 2:
//         displayQRCode();
//         string scanned;
//         cout << "\nDid you scan the QR code? (yes/no): ";
//         cin >> scanned;
//         if (scanned == "yes" || scanned == "Yes")
//         {
//             cout << "\nPayment completed. Thank you!\n";
//         }
//         else
//         {
//             cout << "\nThere is a technical issue in online payment. Please pay in cash.\n";
//         }
//         break;
//     default:
//         cout << "\nInvalid payment method choice. Please try again.\n";
//         break;
//     }
// }
// break;

            case 7:
    cout << "\nThank you for using our parking management system!\n";
    cout << "Have a great day!\n";
    exit(0); // Exit the program


            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        else
        {
            cout << "\nPress Enter to display menu...";
            cin.ignore();
            cin.get();
            displayMenu = true;
        }
    }


    return 0;
}
