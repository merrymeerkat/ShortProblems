// plan
// get string
// iterate through characters of the string
// if int(char) > 96 && int(char) < 123, put char in set
// output size of char set
//
#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int main(){

    int N; cin >> N;
    string frase;
    set <char> letters; // set to store unique letters
    cin.get();
    while(N--){
        getline(cin, frase);
        for (auto c: frase){
            c = tolower(c);
            if ((int(c) > 96) && (int(c) < 123)){
                letters.insert(int(c));
            }
        }
        if (letters.size() == 26){
            cout << "pangram\n";
        }
        else{
            cout << "missing ";
            for (int i = 97; i < 123; i++){
                if (letters.find(i) == letters.end()){
                    cout << char(i);
                }
            }
            cout << '\n';
        }
        letters.clear();
    }
}
