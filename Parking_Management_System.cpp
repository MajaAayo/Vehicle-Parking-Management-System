
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
    void readearnedAmount();
};
void Amount::readearnedAmount()
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
            cout<<"Amount details written successfully in file!!!"<<endl;
            cout << "\n";

        }

    void writeVehicle()
{
    ofstream obj;
    obj.open("AvehicleData.txt", ios_base::app);
    obj << "Customer Name: " << cName <<endl;
    obj << "Customer Address: " << cAddress <<endl;
    obj << "Customer Phone: " << cPhone <<endl;
    obj << "Hours Parked: " << hours <<endl;
    obj << "Vehicle Model: " << vmodelNumber <<endl;
    obj << "Vehicle Type: " << vType.getvehicleType() <<endl;
    obj << "Vehicle Color: " << vColor <<endl;
    obj << "Vehicle Company: " << vCompanyName <<endl;
    obj << "Entry By: " << entryBy <<endl;
    obj << "Entry Time: " << entryTime <<endl;
    // obj << "Total Amount Earned: " << amt.getTotalAmount()<<endl;
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
    obj.open("AearnedAmount.txt", ios_base::app);
    obj << "Customer Name: " << cName <<endl;
    obj << "Vehicle Model: " << vmodelNumber <<endl;
    obj << "Vehicle Type: " << vType.getvehicleType() <<endl;
    obj << "Vehicle Color: " << vColor <<endl;
    obj << "Entry By: " << entryBy <<endl;
    obj << "Entry Time: " << entryTime <<endl;
    obj << "Total Amount Earned: " << amt.getTotalAmount()<<endl;
    obj.close();
}

};
int menu()
{
    int ch;
    cout << "\n1. Check-In";
    cout << "\n3. Display vehicle details";
    cout << "\n4. Display earned amount";
    cout << "\n5. Search vehicle";
    cout << "\n2. Check-Out";
    cout << "\n6. Display parking rate and payment method";
    cout << "\n7. Exit";
    cout << "\nEnter Your Choice: ";
    cin >> ch;
    return (ch);
}int main()
{
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

                        // W                ait for 5 seconds
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

                    } while (select == 'y' || select == 'Y');

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
                        Amount amount;
                        cout << "\nReading earned amounts...\n";
                        amount.readearnedAmount();

                        VehicleDetails vehicleDetails;
                        cout << "\nReading vehicle details...\n";
                        // vehicleDetails.readVehicleDetails(); // This function is missing
                    }
                    break;

                case 7:
                    exit(0); // Exit the program

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        }
        else
        {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            displayMenu = true;
        }
    }

    return 0;
}
