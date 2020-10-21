#include <iostream>
#include <string>

using namespace std;

int main(){

    string output;

    char previous = getchar();
    output += previous;
    char c = getchar();
    while (c != '\n'){
        if (c != previous){
            output += c;
        }
        previous = c;
        c = getchar();
    }

    cout << output << '\n';
}


/*
int main(){
    
    string name; cin >> name;
    string new_name;
    new_name += name[0];
    char previous = name[0];

    for (auto it = name.begin()++; it != name.end(); it++){
        if (previous != (*it))
            new_name += *it;
        previous = *it;
    }

    cout << new_name << '\n';
}*/
