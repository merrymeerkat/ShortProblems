#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, P; cin >> N >> P;

    string description;
    for (int i = 0; i < N; ++i){
        cin >> description;
    }

    cout << P << "\n";
}
