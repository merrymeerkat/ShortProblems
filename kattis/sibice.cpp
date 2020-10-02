#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    float W, H; cin >> W >> H;

    int match;
    while (N--){
        cin >> match;
        if (match > pow(pow(W, 2) + pow(H, 2), 0.5))
            cout << "NE\n";
        else
            cout << "DA\n";
    }
    return 0;
}

