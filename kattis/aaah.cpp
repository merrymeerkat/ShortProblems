#include <iostream>
#include <string>

using namespace std;

int main() {

    string Jon, doctor;

    cin >> Jon >> doctor;

    if (doctor.length() > Jon.length()){
        cout << "no\n";
    }
    else {
        cout << "go\n";
    }
    return 0;
}

