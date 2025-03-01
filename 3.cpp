#include <iostream>
#include <vector>
using namespace std;

// assuming that all the data entered would be appropiate.

class Vehicle
{
public:
    string Model;
    float Price_Per_Day;
    string Type;
    bool Learners;
    bool Is_Avaliable;
    
    Vehicle()
    {
        Model = "N/A";
        Price_Per_Day = 0.0;
        Type = "N/A";
        Learners = false;
        Is_Avaliable = false;
    }

    Vehicle(string M, float P, string T, bool L, bool A)
    {
        Model = M;
        Price_Per_Day = P;
        Type = T;
        Learners = L;
        Is_Avaliable = A;
    }

    void Display()
    {
        cout << "Model: " << Model << endl;
        cout << "Price Per Day: " << Price_Per_Day << endl;
        cout << "Type: " << Type << endl;
        cout << "Is Applicable for Learners: " << Learners << endl;
        cout << "Is Avaliable: " << Is_Avaliable << endl;
    }


};

class User
{
public:
    string Name;
    int Age;
    double Contact_Num;
    string License_Type;
    int ID;
    static int ID2;

    User()
    {
        ID = ID2++;

        cout << "Enter your details when prompt" << endl;

        cout << "Name: ";
        getline(cin,Name);

        cout << "Age: ";
        cin >> Age;
        cin.ignore();

        cout << "Contact Number [no space/dash]: ";
        cin >> Contact_Num;
        cin.ignore();

        cout << "License Type" << endl;
        cout << "[Types: Learners, MotorCar, MotorCycle, Truck, Bus]: ";
        getline(cin,License_Type);
    }

    void Update_Info()
    {
        int Option;

        cout << "What would you like to Update [1 for Name, 2 Age, 3 for Contact Num, 4 for License Type, 0 for Nothing]: ";
        cin >> Option;
        cin.ignore();

        if (Option == 1)
        {
            cout << "Enter New Name: ";
            getline(cin,Name);
        }
        else if (Option == 2)
        {
            cout << "Enter New Age: ";
            cin >> Age;
            cin.ignore();
        }
        else if (Option == 3)
        {
            cout << "Enter New Contact Number: ";
            cin >> Contact_Num;
            cin.ignore();
        }
        else if (Option == 4)
        {
            cout << "Enter your New License Type";
            cout << "[Types: Leaners, MotorCar, MotorCycle, Truck, Bus]: ";
            getline(cin,License_Type);
        } 
    }

    void RentingCar(Vehicle &V)
    {
        V.Display();

        if (V.Is_Avaliable == false)
        {
            cout << "Vehicle " << V.Model << " not avaliable." << endl;
            return;
        }
        else
        {
            if (License_Type == "Learners" && V.Learners == true)
            {
                cout << "Vehicle " << V.Model << " is Selected successfully." << endl;
                V.Is_Avaliable = false;
                return;
            }
            else if (License_Type == V.Type)
            {
                cout << "Vehicle " << V.Model << " is Selected successfully." << endl;
                V.Is_Avaliable = false;
                return;
            }
            else
            {
                cout << "Vehicle " << V.Model << " is not selected." << endl;
                return;
            }
        }
    }

};
int User::ID2 = 1;

int main()
{
    Vehicle *V1 = new Vehicle("Porsche Turbo S", 40.0, "MotorCar", true,true);
    Vehicle *V2 = new Vehicle("Yamaha R6",20.0,"MotorBike",true,false);
    Vehicle *V3 = new Vehicle("Mercedes Atego",60.0,"Truck",false,true);
    Vehicle *V4 = new Vehicle("Mercedes Tourismo",50.0,"Bus",false,true);

    vector <Vehicle*> Vehicles = {V1,V2,V3,V4}; 

    User U1;

    cout << "\nAvaliable Vehicles" << endl;
    for (int i = 0; i < Vehicles.size(); i++)
    {
        cout << "Element Num: " << i << endl;
        Vehicles[i] -> Display();
        cout << endl;
    }
    cout << endl;

    int Option;
    cout << "Enter the Element Number of your choosen vechicle: ";
    cin >> Option;
    cin.ignore();

    U1.RentingCar(*Vehicles[Option]);

    int Option1;
    cout << "\nDo you wish to update your information [1 for Yes, 0 for No]";
    cin >> Option1;
    cin.ignore();

    if (Option1 == 1)
    {
        U1.Update_Info();
    }

    delete V1;
    delete V2;
    delete V3;
    delete V4;
}