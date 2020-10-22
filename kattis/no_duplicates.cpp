#include <iostream>
#include <set>
#include <string>

using namespace std;

set <string> words;

int main(){
    string word;
    while (cin >> word){
        if (words.find(word) != words.end()){
            cout << "no\n";
            return 0;
        }
        else {
            words.insert(word);
        }
    }
    
    cout << "yes\n";
    
}

