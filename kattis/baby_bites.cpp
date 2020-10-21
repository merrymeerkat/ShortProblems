#include <iostream>
#include <string>

using namespace std;

int main(){

    int TC; cin >> TC;

    string word;
    for (int i = 1; i <= TC; ++i){
        cin >> word;
        if (word.compare("mumble") != 0 && stoi(word) != i){
            cout << "something is fishy" << '\n';
            return 0;
        }
    }
    cout << "makes sense" << '\n';
}
