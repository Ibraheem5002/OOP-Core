#include <iostream>
#include <utility>
using namespace std;

class Robot
{
private:
    string Name;
    int Hits;
public:
    Robot()
    {
        cout << "Enter Name of this Robot: ";
        getline(cin,Name);

        Hits = 0;
    }

    void HitBall(int &ballX, int &ballY, const string &direction)
    {
        if (direction == "U")
        {
            ballY++;
        }
        else if (direction == "D")
        {
            ballY--;
        }
        else if (direction == "L")
        {
            ballX++;
        }
        else if (direction == "R")
        {
            ballX--;
        }
        else
        {
            cout << "invalid input. the turn would be counted." << endl;
        }
        
        Hits++;
    }

    string getName()
    {
        return Name;
    }

    int getHits()
    {
        return Hits;
    }
};

class Ball
{
private:
    int X, Y;

public:
    Ball()
    {
        X = 0; Y = 0;
    }

    void setX(int ballX)
    {
        X = ballX;
    }

    void setY(int ballY)
    {
        Y = ballY;
    }

    int getX()
    {
        return X;
    }
    
    int getY()
    {
        return Y;
    }

    pair <int,int> getPosition()
    {
        return {X,Y};
    }
};

class Goal
{
public:
    int X = 3,Y = 3;

    bool isGoalReached(int ballX, int ballY)
    {
        if (ballX == X && ballY == Y)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class Team
{
private:
    string Name;
    Robot *robot;
public:
    Team(Robot *R)
    {
        cout << "Enter your Team Name: ";
        getline(cin,Name);

        robot = R;
    }

    string getTeamName()
    {
        return Name;
    }

    Robot *getRobot()
    {
        return robot;
    }
};

class Game
{
private:
    Robot Robot1, Robot2;  // Create two robots
    Team TeamA, TeamB;
    Ball Ball1;
    Goal GoalA;
    int HitsA, HitsB;

public:
    Game() : TeamA(&Robot1), TeamB(&Robot2)  // Initialize teams with robots
    {
        HitsA = 0;
        HitsB = 0;
    }


    int play(Team *team)
    {
        string direction;
        Ball1.setX(0); Ball1.setY(0);

        cout << "Goal's Position: (" << GoalA.X << "," << GoalA.Y << ")" << endl;
        cout << "Ball's Current Position: (" << Ball1.getPosition().first << "," << Ball1.getPosition().second << ")" << endl;
        cout << endl;

        cout << team->getTeamName() << "'s Turn.";
        cout << "Enter the direction you want to hit your ball" << endl;
        cout << "[U for Up, D for Down, L for Left, R for Right]" << endl;
        cin >> direction;

        int ballX = Ball1.getX(); int ballY = Ball1.getY();

        team->getRobot()->HitBall(ballX,ballY,direction);

        Ball1.setX(ballX); Ball1.setY(ballY);

        while (1)
        {
            cout << "Ball's Current Position: (" << Ball1.getPosition().first << "," << Ball1.getPosition().second << ")" << endl;
            cout << endl;

            cout << "Enter the direction you want to hit your ball" << endl;
            cout << "[U for Up, D for Down, L for Left, R for Right]" << endl;
            cin >> direction;

            int ballX = Ball1.getX(); int ballY = Ball1.getY();

            team->getRobot()->HitBall(ballX,ballY,direction);

            Ball1.setX(ballX); Ball1.setY(ballY);

            if (GoalA.isGoalReached(ballX,ballY) == 1)
            {
                cout << "GOOOOAL ?!" << endl;
                cout << "What a goal by " << team->getRobot()->getName() << endl;
                cout << endl;
                break;
            }
        }

        int Hits = team->getRobot()->getHits();
        return Hits;
    }  

    void declareWinner()
    {
        if (HitsA < HitsB)
        {
            cout << "Team: " << TeamA.getTeamName() << " is the Winner ?!" << endl;
            cout << "With " <<  HitsB-HitsA << " hits less then Team: " << TeamB.getTeamName() << endl;
        }
        else if (HitsA > HitsB)
        {
            cout << "Team: " << TeamB.getTeamName() << " is the Winner ?!" << endl;
            cout << "With " <<  HitsA-HitsB << " hits less then Team: " << TeamA.getTeamName() << endl;
        }
        else
        {
            cout << "tie." << endl;
            cout << "With both teams having equal hits of: " << HitsA;
        }    
    }

    void startGame(Team *team)
    {
        HitsA = play(&TeamA);
        HitsB = play(&TeamB);

        declareWinner();
    }

    
};

int main()
{
    Game game;
    game.startGame(nullptr);
    return 0;
}