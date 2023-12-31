#include <bits/stdc++.h>
using namespace std;


void Identify(const string& bar, unordered_set<string>& functionNames)
{
    long long int pos = bar.find("(");
    if (pos != string::npos)
    {
        long long int start = bar.rfind(" ", pos);
        if (start != string::npos)
        {
            string functionName = bar.substr(start + 1, pos - start - 1);
            functionNames.insert(functionName);
        }
    }
}

void Operators(const string& bar, unordered_set<string>& operators)
{
    unordered_set<string> operatorNames = {"plus", "minus", "multiply", "divide", "modulus", "assign", "greater", "less", "not", "bitwise_and", "bitwise_or", "bitwise_xor"};

    string operatorSymbols = "+-*/%=><!&|^";
    long long int lineSize = bar.size();

    for (long long int i = 0; i < lineSize; ++i)
    {
        char currentChar = bar[i];

        if (operatorSymbols.find(currentChar) != string::npos)
        {
            string operatorStr;

            if (i + 1 < lineSize && operatorSymbols.find(bar[i + 1]) != string::npos)
            {
                operatorStr = bar.substr(i, 2);
                i++;
            }
            else
            {
                operatorStr = bar.substr(i, 1);
            }

            operators.insert(operatorStr);
        }
    }
}
int main()
{
    ifstream file("Program.cpp");

    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    unordered_set<string> functionNames;
    unordered_set<string> operators;
    string line;
    while (getline(file, line))
    {
        Identify(line, functionNames);
        Operators(line, operators);
    }
        file.close();
    cout << "Number of Unique User-Defined Functions: " << functionNames.size() << endl;
    cout << "Identify:" << endl;
    for (const string& functionName : functionNames)
    {
        cout << functionName << endl;
    }
       cout << "\nOperators:" << endl;
    for (const string& op : operators)
    {
        cout << "Operator: " << op << ", Name: ";
        if (op == "+") cout << "plus";

        else if (op == "/") cout << "divide";
        else if (op == "-") cout << "minus";
        else if (op == "*") cout << "multiply";
        else if (op == "%") cout << "modulus";
        else if (op == "=") cout << "assign";
        else if (op == ">") cout << "greater";
        else if (op == "<") cout << "less";
        else if (op == "!") cout << "not";
        else if (op == "&") cout << "bitwise_and";
        else if (op == "|") cout << "bitwise_or";
        else if (op == "^") cout << "bitwise_xor";
        cout << endl;
        }
return 0;
}


