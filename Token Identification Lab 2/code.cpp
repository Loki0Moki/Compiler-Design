#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <vector>


using namespace std;

bool Check(string str){

    if( (str[0] >= 'a' and str[0] <= 'z' ) or (str[0] >= 'A' and str[0] <= 'Z') or (str[0] == '_')){

        for(int i = 1; i < str.size(); i++){
            if(str[i] == '$'){
                return false;
            }
        }

        return true;
    }

    return false;

}

bool valid(string str){

    for(int i = 0; i < str.size(); i++){
        if(str[i] >= '0' and str[i] <= '9'){

        }else{
            return false;
        }
    }


    return true;

}

int main() {

    ifstream inputFile("input.txt");


    ifstream secondFile("keywords.txt");

    ifstream thirdFile("Operators.txt");

    ifstream fourthFile("Punctuation.txt");


    set<string> wordSetSecond;
    set<string> wordSetThird;
    set<string> punctuationSet;
    set<string>Key;
    set<string>Op;
    set<string>punction;
    set<string>digit;
    set<string>Var;

    string line;


    while (getline(secondFile, line)) {
        istringstream iss(line);
        string character;
        while (iss >> character) {
            wordSetSecond.insert(character);
        }
    }


    while (getline(thirdFile, line)) {
        istringstream iss(line);
        string character;
        while (iss >> character) {
            wordSetThird.insert(character);
        }
    }


    while (getline(fourthFile, line)) {
        istringstream iss(line);
        string character;
        while (iss >> character) {
            punctuationSet.insert(character);
        }
    }


    while (getline(inputFile, line)) {
        istringstream iss(line);
        string character;
        while (iss >> character) {
            if (wordSetSecond.find(character) != wordSetSecond.end()) {

               Key.insert(character);

                iss >> character;
                if(Check(character)){
                    Var.insert(character);
                }

            } else if (wordSetThird.find(character) != wordSetThird.end()) {

                Op.insert(character);
            }else if(punctuationSet.find(character) != punctuationSet.end()){


                punction.insert(character);
            }
            else{
                if(Check(character)){


                   Var.insert(character);
                }else if(valid(character)){
                    digit.insert(character);
           }

                else{

                    cout << "Error : \n" << character <<'\n';
                }
            }
        }
    }

    cout << "Keyword :\n";
    for(auto x : Key){
        cout << x << ' ';
    }cout << '\n';

    cout << "Operator :\n";
    for(auto x : Op){
        cout << x << ' ';
    }cout << '\n';

    cout << "Punctuation :\n";
    for(auto x : punction){
        cout << x << ' ';
    }cout << '\n';

    cout << "Digit :\n";
    for(auto x : digit){
        cout << x << ' ';
    }cout << '\n';

    cout << "Identifier :\n";
    for(auto x : Var){
        cout << x << ' ';
    }cout << '\n';

    inputFile.close();
    secondFile.close();
    thirdFile.close();
    fourthFile.close();

    return 0;
}
