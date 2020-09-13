#include <iostream>

using namespace std;

int main (){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;

    int temp; int counter = 0;

    for (int i = 0; i < N; i++){
        cin >> temp;
        if (temp < 0)
            counter ++;
    }

    cout << counter << "\n";
}
