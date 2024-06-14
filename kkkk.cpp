

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
// for sleep
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

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
        cout << "\n"
                "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                "\t\t\t\t\t|                              Login Here                             |\n"
                "\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter Username: ";
        cin >> user;

        if (user != username)
        {
            cout << "\nInvalid Username!!!\n";
        }
        else
        {
            cout << "Enter Password: ";
            cin >> pass;
            if (pass == password)
            {
                cout << "\nLogin successfull! Please wait for 5 seconds...\n";
                // Platform-specific sleep
#ifdef _WIN32
                Sleep(5000); // 5000 milliseconds = 5 seconds
#else
                sleep(5); // 5 seconds
#endif
                return;
            }
            else
            {
                cout << "\nInvalid Password!!!\n";
            }
        }
        cout << "\n----------------------->  Invalid login attempt!!!  <---------------------------\n";
        cout << "\t\t\t      Attempt " << loginAttempt + 1 << " of 3\n";
        loginAttempt++;
        cout<<"Press enter to try again...";  
        cin.ignore();
        cin.get();
    }

    if (loginAttempt == 3)
    {
        cout << "\nToo many login attempts! The program will now terminate.\n\n\n";
        exit(0);
    }
}
// object is in vehicle details
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
    Amount() //default constructor
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
};

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
            cout << "\nAvailable Parking for Vehicles are:\n";
            cout << "1. Cycle \n2. Scooter \n3. Bike \n4. Auto-Rickshaw \n5. Car \n6. Bus\n";
            int vType;
            cout << "\nSelect Vehicle Type: ";
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
    static int serialNumber;

    VehicleType vType;

    Amount amt; // object of class Amount


public:
    VehicleDetails()
    {
        cPhone = 0;
        vmodelNumber = 0;
        cName = "default";
        cAddress = "default";
        vColor = "default";
        vCompanyName = "default";
        entryBy = "Hamjit";
        time_t lTime; // data type for representing the number of seconds since the Unix epoch (January 1, 1970).
        time(&lTime); //  variable and sets it to the current calendar time. to store current time in the variable.
        entryTime = asctime(localtime(&lTime)); //asctime function converts the tm structure to a human-readable. 
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
        cin.ignore();

        vType.readvehicleType(amt, hours);  // Read the vehicle type before entering the model number

        // Check for duplicate vehicle model number
        while (true)
        {
            cout << "Enter Vehicle Model Number: ";
            cin >> vmodelNumber;
            cin.ignore();

            if (!isDuplicateModelNumber(vmodelNumber))
            {
                break;
            }
            else
            {
                cout << "\nVehicle Model Number already exists! Please enter a different model number.\n\n";
            }
        }

        cout << "Enter Vehicle Color: ";
        getline(cin, vColor);

        cout << "Enter Vehicle Company Name: ";
        getline(cin, vCompanyName);

        entryBy = "Hamjit";
        time_t lTime;
        time(&lTime);
        entryTime = asctime(localtime(&lTime));
    }

    bool isDuplicateModelNumber(int modelNumber)
{
    ifstream vehicleFile("AvehicleData.txt");
    if (!vehicleFile)
    {
        return false; // If the file cannot be opened, assume no duplicate
    }

    string line;
    while (getline(vehicleFile, line))
    {
        if (line.find("Vehicle Model: " + to_string(modelNumber)) != string::npos)
        {
            return true; // If model number is found, return true (duplicate found)
        }
    }
    return false; // If model number is not found, return false (no duplicate)
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
        cout << "| Entry Time        : " << setw(30) << entryTime << " |\n";
        cout << "+-------------------------------------------------------+\n";
    }

    void displayAmount()
    {
        cout << "\n+------------------------------------------------------------------------+\n";
        cout << "|                      Vehicle Bills                                       |\n";
        cout << "+--------------------------------------------------------------------------+\n";
        amt.showtotalAmount();
        cout << "Vehicle details and amount details written successfully in file!!!\n"
             << endl;
        cout << "\n";
    }

      void writeVehicle()
    {
        ofstream obj;
        obj.open("AvehicleData.txt", ios_base::app); // Open file in append mode
        if (!obj)
        {
            cout << "Error opening file for writing vehicle details!\n\n"
                 << endl;
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
    }

    void writeAmount()
{
    ifstream serialFile("AearnedAmount.txt");
    int lastSerial = 0;
    string line;

    // Read the last serial number
    while (getline(serialFile, line))
    {
        if (line.find("S.N.: ") != string::npos)
        {
            lastSerial = stoi(line.substr(line.find("S.N.: ") + 6));
        }
    }
    serialFile.close();

    ofstream obj;
    obj.open("AearnedAmount.txt", ios_base::app); // Open file in append mode
    if (!obj)
    {
        cout << "Error opening file for writing amount details!" << endl;
        return;
    }

    // Write amount details with incremented serial number
    obj << "S.N.: " << ++lastSerial << endl;
    obj << "Customer Name: " << cName << endl;
    obj << "Hours Parked: " << hours << endl;
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
int VehicleDetails::serialNumber = 0;
void checkOutVehicle(bool &vehicleCheckedOut) {
    int deleteModelNumber;
    cout << "Enter Vehicle Model Number to delete: ";
    cin >> deleteModelNumber;

    ifstream inFile("AvehicleData.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;
    bool skipBlock = false;
    string checkoutDetails;
    string entryBy, entryTime, vehicleType;
    double totalAmount = 0; // Initialize totalAmount

    while (getline(inFile, line)) {
        if (line.find("Customer Name: ") != string::npos) {
            string customerBlock = line + "\n";
            for (int i = 0; i < 10; i++) {
                getline(inFile, line);
                customerBlock += line + "\n";

                if (line.find("Vehicle Model: " + to_string(deleteModelNumber)) != string::npos) {
                    found = true;
                    skipBlock = true;
                    checkoutDetails = customerBlock; // Store the block details
                }
                if (line.find("Vehicle Type: ") != string::npos) {
                    vehicleType = line; // Store vehicle type details
                }
                if (line.find("Entry By: ") != string::npos) {
                    entryBy = line; // Store entry by details
                }
                if (line.find("Entry Time: ") != string::npos) {
                    entryTime = line; // Store entry time details
                }
            }
            if (!skipBlock) {
                tempFile << customerBlock << "\n"; // Ensure a single newline between blocks
            }
            // Reset skipBlock here, at the end of the block
            skipBlock = false;
        }
    }

    if (!found) {
        cout << "\nVehicle with Model Number " << deleteModelNumber << " not found!" << endl;
        vehicleCheckedOut = false;

        // Prompt to press enter to display the menu
        cout << "\nPress Enter to return to the menu...";
        cin.ignore(); // To ignore the newline character left in the buffer
        cin.get(); // Wait for Enter key press
        clearScreen();
    } else {
        // Get the current time as exit time
        time_t now = time(0);
        char* dt = ctime(&now);

        // Append the exit time to the checkout details
        checkoutDetails += vehicleType + "\n";
        checkoutDetails += entryBy + "\n";
        checkoutDetails += entryTime + "\n";
        checkoutDetails += "Exit Time: " + string(dt);

        // Display the details of the vehicle being checked out
        cout << "\nVehicle with Model Number " << deleteModelNumber << " details deleted successfully!" << endl;
        cout << checkoutDetails << endl;
        vehicleCheckedOut = true;

        inFile.close();
        tempFile.close();

        // Remove the original file
        remove("AvehicleData.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "AvehicleData.txt");

        // Prompt to press enter to display payment rates and method
        cout << "\nPress Enter to display payment rates and method...";
        cin.ignore(); // To ignore the newline character left in the buffer
        cin.get(); // Wait for Enter key press
        clearScreen();
    }
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
            "\n|-------------------|\n"
            "|                   |\n"
            "|                   |\n"
            "|     SCAN HERE     |\n"
            "|                   |\n"
            "|                   |\n"
            "|-------------------|\n";

}
// Add this function to calculate the total amount from the file
void calculateTotalAmount()
{
    ifstream amountFile("AearnedAmount.txt");
    if (!amountFile)
    {
        cout << "Error opening file for reading amount details!" << endl;
        return;
    }

    string line;
    int totalAmount = 0;

    while (getline(amountFile, line))
    {
        if (line.find("Amount Earned: ") != string::npos)
        {
            int amount = stoi(line.substr(line.find("Amount Earned: ") + 15));
            totalAmount += amount;
        }
    }
    amountFile.close();

    // Display the total amount
    cout << "\nTotal Amount Earned from all vehicles: " << totalAmount << endl;
}


int menu()
{
    clearScreen(); // Clear the screen before displaying the menu
    int ch;
    cout << "\n1. Check-In";
    cout << "\n2. Read Vehicle Details";
    cout << "\n3. Read Amount Details";
    cout << "\n4. Check-Out";
    cout << "\n5. Total Amount Earned";
    cout << "\n6. Exit";
    cout << "\n\nEnter Your Choice: ";
    cin >> ch;
    cout << "\n";
    if (ch < 1 || ch > 5)
    {
        cout << "Invalid choice. Please try again." << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        return menu(); // Recursively call menu() to get a valid choice
    }
    else
    {
        // Clear the screen before returning for a valid choice
        clearScreen();
        return ch;
    }
}


int main()
{
    login();
    clearScreen();

    cout << "\n"
            "\t\t\t\t\t\t|--------------------------------------------------------------------|\n"
            "\t\t\t\t\t\t|          Welcome to the Vehicle Parking Management System          |\n"
            "\t\t\t\t\t\t|--------------------------------------------------------------------|\n";
    char select;
    bool displayMenu = true;
    bool vehicleCheckedOut = false;

    while (true)
    {
        if (displayMenu)
        {
            switch (menu())
            {
            case 1:
            {
                do
                {
                    VehicleDetails vehicle;  // object
                    vehicle.readDetails();
                    vehicle.displayvehicleDetails();

                    // Wait for 5 seconds
                    cout << "\nPress Enter to print bills...\n";
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

                    // cout << "Available Parking Capacity: " << PARKING_CAPACITY << endl;
                    cout << "Do you want to park another vehicle? (y/n): ";
                    cin >> select;
                    cin.ignore(); // Clear the input buffer
                    cout << endl;

                } while (select == 'Y' || select == 'y');

                cout<<"\nPress enter to display menu...";
                cin.ignore(); // To ignore the newline character left in the buffer
                // cin.get();
                clearScreen(); // Clear the screen before displaying the menu
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

                // Ask to display menu
                char displayMenuChoice;
                cout << "\nDo you want to display the menu again? (y/n): ";
                cin >> displayMenuChoice;
                if (displayMenuChoice != 'y' && displayMenuChoice != 'Y')
                {
                    cout << "\nExiting the program. Thank you!\n";
                    exit(0);
                }
                clearScreen(); // Clear the screen before displaying the menu
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

                // Ask to display menu
                char displayMenuChoice;
                cout << "\nDo you want to display the menu again? (y/n): ";
                cin >> displayMenuChoice;
                if (displayMenuChoice != 'y' && displayMenuChoice != 'Y')
                {
                    cout << "\nExiting the program. Thank you!\n";
                    exit(0);
                }
                clearScreen(); // Clear the screen before displaying the menu
            }
            break;

           case 4:

      checkOutVehicle(vehicleCheckedOut);
                if (vehicleCheckedOut)
                {
                    cout << "\n--- Payment ---\n";
                    cout << "Cycle: 10/hr\nScooter: 10/hr\nBike: 20/hr\nAuto Rickshaw: 20/hr\nCar: 50/hr\nBus: 100/hr\n";
                    displayPaymentMethods();
        int paymentChoice;
        cout << "\nEnter your payment method choice: ";
        cin >> paymentChoice;

        if (paymentChoice == 1) {
            cout << "\nPayment completed. Thank you!\n";
            cout << "\nPress Enter to display menu...";
            cin.ignore();
            cin.get();
            displayMenu = true;
            clearScreen();
        } else if (paymentChoice == 2) {
            displayQRCode();
            string scanned;
            cout << "\nDid you scan the QR code? (yes/no): ";
            cin >> scanned;

            if (scanned == "y" || scanned == "Y") {
                cout << "\nPlease wait for 5 seconds\n";

#ifdef _WIN32
                Sleep(5000); // 5000 milliseconds = 5 seconds
#else
                sleep(5); // 5 seconds
#endif

                cout << "\nPayment completed. Thank you!\n";
                cout << "\nPress Enter to display menu...";
                cin.ignore();
                cin.get();
                displayMenu = true;
                clearScreen();
            } else {
                cout << "\nThere is a technical issue in online payment. Would you like to pay in cash? (yes/no): ";
                string payInCashChoice;
                cin >> payInCashChoice;

                if (payInCashChoice == "y" || payInCashChoice == "Y") {
                    cout << "\nThank you for paying in cash!\n";
                    cout << "\nPress Enter to display menu...";
                    cin.ignore();
                    cin.get();
                    displayMenu = true;
                    clearScreen();
                } else {
                    cout << "\nThank you! Have a great day!\n";
                    cout << "\nPress Enter to display menu...";
                    cin.ignore();
                    cin.get();
                    displayMenu = true;
                    clearScreen();
                }
            }
        } else {
            cout << "\nInvalid payment method choice. Please try again.\n";
            clearScreen();
        }
    } 
    break;

    case 5:
{
    // Calculate total amount earned from all vehicles
    calculateTotalAmount();

   cout << "\nPress Enter to display menu...";
                    cin.ignore();
                    cin.get();
    clearScreen(); // Clear the screen before displaying the menu
}
break;
            case 6:
                cout << "\nThank you for using our parking management system!\n";
                cout << "Have a great day!\n";
                exit(0); // Exit the program

            default:
                cout << "Invalid choice. Please try again." << endl;
                clearScreen();
                break;
            }
        }
    }
    return 0;
}
