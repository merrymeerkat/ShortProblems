#include <iostream>
#include <string>

using namespace std;

int main(){

    int n; cin >> n;

    int length;
    string fst, snd, diff;
    while(n--){
        cin >> fst >> snd;

        length = fst.size();
        for (int i = 0; i < length; i++){
            if (fst[i] == snd[i])
                diff += '.';
            else
                diff += '*';
        }

        cout << fst << '\n' << snd << '\n' << diff << '\n' << '\n'; 
        
        diff.clear();
    }

    return 0;
}
