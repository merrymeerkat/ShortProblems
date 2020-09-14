#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int candidate;
    for (int i = 0; i < N; i++){
        cin >> candidate;

        if (candidate % 2 == 0)
            cout << candidate << " is even\n";
        else
            cout << candidate << " is odd \n";

    }


}
