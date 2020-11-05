#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cout << "1n is " <<n << "yeah" << endl;
    string command;
    // string bits;
    char * bits = (char *) malloc(sizeof(char)*32);
    int i, j;
    while (true){
        
        cout << "2n is " << n << endl;
        if (n == 0)
            return 0;
        
        cout << "3n is " << n << endl;

        for (i = 0; i < 32; i++)
             bits[i] = '?'; // this causes a bug when bits is defined as str
            // bits += '?'; // this doesn't
        
        cout << (void *)&bits[0] << endl;
        cout << (void *)&bits[31] << endl;
        cout << (void *)&n << endl;
        cout << "4n is " << n << endl;
        for (i = 0; i < 32; i++){
            cout << bits[i];
        }

        cout << "5n is " << n << endl;

        for (int idx = 0; idx < n; idx++){
            cout << "n is " << n << endl;
            cin >> command;
            cout << "command is " << command << endl;

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
                if (bits[i] != '?' && bits[j] != '?'){
                    bits[i] = bits[i] | bits[j];
                }
            }
            else { // "AND"
                cin >> i >> j;
                if (bits[i] != '?' && bits[j] != '?'){
                    bits[i] = bits[i] & bits[j];
                }

            }
        }

        // Printing final result
      //  for (auto it = bits.begin(); it != bits.end(); it++){
      //      cout << *it << "oi";
      //  }
      //  cout << '\n';

        
        // bits.clear();
        //  rm part below for final progr
        for (int i =0 ; i<32; i++) {
            bits[i] = '?';
        }

        // Next input
        cin >> n;
    }
}
