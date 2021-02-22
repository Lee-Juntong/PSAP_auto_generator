#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

int MAX = 100;

string operation(int operation)
{
    switch (operation)
    {
    case 0:
        return "+";
    case 1:
        return "-";
    case 2:
        return "×";
    case 3:
        return "÷";
    }
    return NULL;
}

void randomGenerator(string *q, int num)
{
    srand((unsigned)time(NULL));
    int type;

    for (int i = 0; i < num; i++)
    {
        type = rand() % MAX % 6;

        switch (type)
        {
        case 0: //integer operations
            q[i] = std::to_string(rand() % MAX);
            q[i] += (operation(rand() % MAX % 4)) + std::to_string(rand() % MAX) + "=";
            break;
        case 1: //fraction operations
            q[i] = std::to_string(rand() % MAX);
            q[i] += "/" + std::to_string(rand() % MAX) + (operation(rand() % MAX % 4)) + std::to_string(rand() % MAX) + "/" + std::to_string(rand() % MAX) + "=";
        case 2: //decimal operations
            q[i] = std::to_string(rand() % MAX);
            q[i] += "." + std::to_string(rand() % MAX) + (operation(rand() % MAX % 4)) + std::to_string(rand() % MAX) + "." + std::to_string(rand() % MAX) + "=";
        case 3: //integer with fraction
            q[i] = std::to_string(rand() % MAX);
            q[i] += (operation(rand() % MAX % 4)) + std::to_string(rand() % MAX) + "/" + std::to_string(rand() % MAX) + "=";
        case 4: //integer with decimal
            q[i] = std::to_string(rand() % MAX);
            q[i] += (operation(rand() % MAX % 4)) + std::to_string(rand() % MAX) + "." + std::to_string(rand() % MAX) + "=";
        case 5: //decimal with fraction
            q[i] = std::to_string(rand() % MAX);
            q[i] += "." + std::to_string(rand() % MAX) + (operation(rand() % MAX % 4)) + std::to_string(rand() % MAX) + "/" + std::to_string(rand() % MAX) + "=";
        default:
            break;
        }
    }
    std::cout << "done generation" << endl;
}

int writeOnfile(string filetext)
{
    ofstream myfile;
    myfile.open("questions.txt", fstream::app);
    myfile << filetext << endl;
    myfile.close();
    return 0;
}

int main()
{
    std::cout << "Enter number of questions." << endl;
    int numberOfQuestions = 0;
    cin >> numberOfQuestions;
    while (numberOfQuestions <= 0)
    {
        std::cout << "try again. enter an integer larger than 0." << endl;
        cin >> numberOfQuestions;
    }
    string *questions = new string[numberOfQuestions];
    randomGenerator(questions, numberOfQuestions);

    for (int i = 0; i < numberOfQuestions; i++)
    {
        //cout<<questions[i]<<endl; for checking purposes
        writeOnfile(questions[i]);
    }
    return 0;
}