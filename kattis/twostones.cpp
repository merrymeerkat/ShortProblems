#include <iostream>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int stones; cin >> stones;

    if (stones % 2 == 0)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}
