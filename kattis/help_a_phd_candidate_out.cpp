#include <iostream>
#include <string>

using namespace std;

int main(){

    int N; cin >> N;

    string problem;

    while(N--){
        cin >> problem;

        int a = 0; int b = 0;
        int num = a;
        int digit;
        bool NP = false;
        for (auto c : problem){
            if (c == 'P'){
                cout << "skipped\n";
                NP = true;
                break;
            }
            if (c == '+'){
                a = num;
                num = b;
            }
            else {
                num *= 10;
                digit = c - '0';
                num += digit;
            }
        }

        if (!NP){
            cout << a + num << '\n';
        }
    }
}

