#include <iostream>
#include <list>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    cin.ignore();

    string line;
    list <char> new_line;

    while(T--){

        getline(cin, line);
    
        new_line.clear();

        auto it = new_line.begin();

        for (auto c: line){
            switch(c){
                case '<':
                    if (it == new_line.begin())
                        break;
                    it--;
                    it = new_line.erase(it);
                    break;
                
                case ']':
                    it = new_line.end();
                    break;

                case '[':
                    it = new_line.begin();
                    break;

                default:
                    new_line.insert(it, c);
            }
        }

        // Printing output line
        for (auto it = new_line.begin(); it != new_line.end(); it++)
            cout << *it;
        cout << '\n';
    }
}
