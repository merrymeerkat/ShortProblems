#include <iostream>
#include <string>

using namespace std;

int main(){

    string line;
    cin >> line;

    string new_line;

    for (auto i: line){
        switch(i){
        case '<':
            new_line.pop_back();
            break;
        default:
            new_line.push_back(i);   
        }
    }

    cout << new_line;
}

