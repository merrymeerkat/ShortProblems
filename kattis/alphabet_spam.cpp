#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string word; cin >> word;

    long long ws, lc, uc, sym;
    ws = 0; lc = 0; uc = 0; sym = 0;
    for (auto c : word){
        if (c == '_')
            ws++;
        else if (c > 96 && c < 123)
            lc++;
        else if (c > 64  && c < 91)
            uc++;
        else
            sym++;
    }

    float length = (float) (word.size());
    cout << setprecision(9);
    cout << (ws / length) << '\n';
    cout << (lc / length) << '\n';
    cout << (uc / length) << '\n';
    cout << (sym / length) << '\n';
}
