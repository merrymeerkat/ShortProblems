#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector <string> words;
    string word;
    while (cin >> word){
        words.push_back(word);
    }

    set <string> combos;
    for (auto it = words.begin(); it != words.end(); it++){
        for (auto it2 = words.begin(); it2 != words.end(); it2++){
            if (*it != *it2){
                combos.insert(*it + *it2);
            }
        }
    }

    for (auto it = combos.begin(); it != combos.end(); it++){
        cout << *it << '\n';
    }

}
