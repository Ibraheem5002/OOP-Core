#include <iostream>
#include <vector>
using namespace std;

class Skill
{
public:
    int skillID;
    string skillName;
    string description;

    Skill(int id, string name, string desc)
    {
        skillID = id;
        skillName = name;
        description = desc;
    }

    void showSkillDetails()
    {
        cout << "Skill ID: " << skillID << ", Name: " << skillName << ", Description: " << description << endl;
    }

    void updateSkillDescription(string newDescription)
    {
        description = newDescription;
    }
};

class Sport
{
public:
    int sportID;
    string name;
    string description;
    vector<Skill> requiredSkills;

    Sport(int id, string n, string desc)
    {
        sportID = id;
        name = n;
        description = desc;
    }

    void addSkill(Skill s)
    {
        requiredSkills.push_back(s);
    }

    void removeSkill(int skillID)
    {
        for (auto it = requiredSkills.begin(); it != requiredSkills.end(); ++it)
        {
            if (it->skillID == skillID)
            {
                requiredSkills.erase(it);
                break;
            }
        }
    }
};

class Student
{
public:
    int studentID;
    string name;
    int age;
    vector<string> sportsInterests;
    class Mentor* mentorAssigned;

    Student(int id, string n, int a, vector<string> interests)
    {
        studentID = id;
        name = n;
        age = a;
        sportsInterests = interests;
        mentorAssigned = nullptr;
    }

    void registerForMentorship(class Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(string sport);
};

class Mentor
{
public:
    int mentorID;
    string name;
    vector<string> sportsExpertise;
    int maxLearners;
    vector<Student*> assignedLearners;

    Mentor(int id, string n, vector<string> expertise, int max)
    {
        mentorID = id;
        name = n;
        sportsExpertise = expertise;
        maxLearners = max;
    }

    bool assignLearner(Student* s)
    {
        if (assignedLearners.size() < maxLearners)
        {
            assignedLearners.push_back(s);
            return true;
        }
        return false;
    }

    void removeLearner(Student* s)
    {
        for (auto it = assignedLearners.begin(); it != assignedLearners.end(); ++it)
        {
            if (*it == s)
            {
                assignedLearners.erase(it);
                s->mentorAssigned = nullptr;
                break;
            }
        }
    }

    void viewLearners()
    {
        cout << "Mentor " << name << "'s Learners: " << endl;
        for (Student* s : assignedLearners)
        {
            cout << "- " << s->name << endl;
        }
    }

    void provideGuidance()
    {
        cout << "Mentor " << name << " is providing guidance." << endl;
    }
};

void Student::registerForMentorship(Mentor* m)
{
    if (m->assignLearner(this))
    {
        mentorAssigned = m;
        cout << name << " has been assigned to mentor " << m->name << endl;
    }
    else
    {
        cout << "Mentor " << m->name << " has reached the maximum capacity!" << endl;
    }
}

void Student::viewMentorDetails()
{
    if (mentorAssigned)
    {
        cout << "Mentor Name: " << mentorAssigned->name << endl;
    }
    else
    {
        cout << "No mentor assigned." << endl;
    }
}

void Student::updateSportsInterest(string sport)
{
    sportsInterests.push_back(sport);
}

int main()
{
    Mentor ali(1, "Ali", {"Tennis"}, 2);
    Student saad(101, "Saad", 20, {"Tennis"});
    Student ahmed(102, "Ahmed", 21, {"Tennis"});

    saad.registerForMentorship(&ali);
    ahmed.registerForMentorship(&ali);

    ali.viewLearners();

    ali.removeLearner(&saad);

    ali.viewLearners();
}