#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Student
{
private:
    string Name;
    string ID;

public:
    int Present;
    int Absents;
    static int Total_Presents;
    static int Total_Absents;
    bool Fees_Paid;
    bool Is_Card_Active;
    string Stop;

    Student()
    {
        cout << "Enter your Name: ";
        getline(cin,Name);

        cout << "Enter your ID [NNK-NNNN; N is an integer]: ";
        getline(cin,ID);

        cout << "Are your Fees cleared [1 for Yes, 0 for No]: ";
        cin >> Fees_Paid;
        cin.ignore();

        if (Fees_Paid == true)
        {
            Is_Card_Active = true;
            cout << "Your Transport Card has been Activated." << endl;
        }
        else
        {
            Is_Card_Active = false;
            cout << "Your Transport Card has been Disabled." << endl;
        }
        
        cout << "Enter your Stop: ";
        getline(cin,Stop);

        Present = 0;
        Absents = 0;
    }

    void Set_Name()
    {
        cout << "Enter your New Name: ";
        getline(cin,Name);
    }

    string Get_Name()
    {
        return Name;
    }

    void Set_ID()
    {
        cout << "Enter your New ID [NNK-NNNN; N is an integer]: ";
        getline(cin,ID);
    }

    string Get_ID()
    {
        return ID;
    }

    void Paying_Fees()
    {
        if (Fees_Paid == true)
        {
            cout << "All your Fees has already been cleared: " << endl;
        }
        else
        {
            Fees_Paid = true;
            Is_Card_Active = true;
            cout << "Your Transport Card has been Activated." << endl;
        }
    }

    void Attendance()
    {
        int Option;

        cout << "Is Student Present [1 for Yes, 0 for No]: ";
        cin >> Option;
        cin.ignore();

        if (Option == 1)
        {
            ++Present;
            ++Total_Presents;
        }
        else
        {
            ++Absents;
            ++Total_Absents;
        }   
    }
};

int Student::Total_Presents = 0;
int Student::Total_Absents = 0;

class Transport
{
public:
    vector <string> Stops;

    Transport()
    {
        string S;

        cout << "Enter all the Stops [enter -1 to stop]: ";
        
        while (1)
        {
            getline(cin,S);

            if (S == "-1")
            {
                break;
            }
            else
            {
                Stops.push_back(S);
            }
        }
        
    }

    void Display_Routes()
    {
        cout << "Routes: " << endl;

        for (int i = 0; i < Stops.size(); i++)
        {
            cout << "Element Num: " << i << ". " << Stops[i] << endl;
        }
    }

    void Update_Routes()
    {
        int Option;

        cout << "Do wish to Add or Remove a stop [1 for Add, 2 for Remove, 0 for exit]: ";
        cin >> Option;
        cin.ignore();

        if (Option == 1)
        {
            string S;

            cout << "Enter your new Stop: ";
            getline(cin,S);

            Stops.push_back(S);
        }
        else if (Option == 2)
        {
            int Element;

            Display_Routes();

            cout << "Enter the Element Num: ";
            cin >> Element;
            cin.ignore();

            Stops.erase(Stops.begin() + Element);
        }
    }

    void Drop_Offs(Student &S)
    {
        for (int i = 0; i < Stops.size(); i++)
        {
            if (Stops[i] == S.Stop)
            {
                string ID;
                ID = S.Get_ID();

                cout << "Student: " << ID << " Dropped off at Stop: " << Stops[i] << endl;
            }
        }
    }

    void Pick_Ups(Student &S)
    {
        for (int i = 0; i < Stops.size(); i++)
        {
            if (Stops[i] == S.Stop)
            {
                string ID;
                ID = S.Get_ID();

                cout << "Student: " << ID << " Picked up at Stop: " << Stops[i] << endl;
            }
        }
    }
};

int main()
{
    cout << "Student Set Up" << endl;
    Student student1;

    cout << endl;

    cout << "Transport Set Up" << endl;
    Transport transport;
    
    cout << endl;
    transport.Display_Routes();
    
    cout << endl;
    transport.Update_Routes();
    
    cout << endl;
    student1.Attendance();
    
    cout << endl;
    int payOption;
    cout << "Do you wish to pay all your dues [1 for Yes, 0 for No]: ";
    cin >> payOption;
    cin.ignore();
    
    if (payOption == 1)
    {
        student1.Paying_Fees();
    }
    
    cout << endl;
    student1.Attendance();
    
    cout << endl;
    transport.Pick_Ups(student1);
    transport.Drop_Offs(student1);
    
    cout << endl;
    cout << "Total Presents: " << Student::Total_Presents << endl;
    cout << "Total Absents: " << Student::Total_Absents << endl;
    
    return 0;
}