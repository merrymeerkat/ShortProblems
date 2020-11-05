#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

int main(){

    int TC; cin >> TC;

    cin.get();
    string line;
    vector <string> words;
    set <string> deleted;
    while (TC--){

        // Get sounds of the forest
        getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word){
            words.push_back(word);
        }

        // get sounds of the other animals
        while(getline(cin, line)){
            stringstream ss(line);
            ss >> word; 
            if (word.compare("what") == 0)
                break;
            ss >> word; ss >> word;
            // third word is animal sound
            deleted.insert(word);
        }

        for (auto it = words.begin(); it!= words.end(); it++){
            if (deleted.find(*it) == deleted.end())
                cout << *it << " ";
        }
        cout << '\n';

        deleted.clear();
        words.clear();
    }
}
// iistream??
//
