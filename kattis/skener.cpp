
#include <iostream>
#include <string>

using namespace std;

int main(){

    int R, C, ZR, ZC; cin >> R >> C >> ZR >> ZC;

    cin.ignore();

    string row;

    while(R--){
        getline(cin, row);

        for(int j = 0; j < ZR; ++j){
            for(char c: row){
                for(int k = 0; k < ZC; ++k){
                     cout << c;
                }
           }
        cout << "\n";
       } 
    }
}
