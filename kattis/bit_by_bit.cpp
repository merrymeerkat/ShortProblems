#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    string command;
    //char * bits = (char *) malloc(sizeof(char)*32);
    vector <int> bits;
    int i, j;
    int idx;
    while (true){
        
        if (n == 0)
            return 0;

        for (idx = 0; idx < 32; idx++)
            bits.push_back(2); 
        
        for (idx = 0; idx < n; idx++){
            cin >> command;

            if (command.compare("SET") == 0){
                cin >> i;
                bits[i] = 1;
            }
            else if (command == "CLEAR"){
                cin >> i;
                bits[i] = 0;
            }
            else if (command == "OR"){
                cin >> i >> j;
                if (bits[i] == 1 || bits[j] == 1)
                    bits[i] = 1;
                else if (bits[i] == 2 || bits[j] == 2)
                    bits[i] = 2;
                else if (bits[i] == 0 && bits[j] == 0)
                    bits[i] = 0;
            }
            else { // "AND"
                cin >> i >> j; 
                if (bits[i] == 0 || bits[j] == 0)
                    bits[i] = 0;
                else if (bits[i] == 2 || bits[j] == 2)
                    bits[i] = 2;
                else if (bits[i] == 1 && bits[j] == 1){
                    bits[i] = 1;
                }

            }
        }

        // Printing final result
    for (auto it = bits.end() - 1; it >= bits.begin(); it--){
        if (*it == 2)
            cout << '?';
        else
            cout << *it;
    }
    cout << '\n';
        
    bits.clear();

    // Next input
    cin >> n;
    }
}
