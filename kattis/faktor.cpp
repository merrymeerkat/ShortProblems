#include <iostream>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, I; cin >> A >> I;

    // Starting value for citations
    int starting = A * I;

    while((ceil((float) starting / A)) >= I)
        starting--;
   
    // Add 1 because above there's an extra -- operation
    cout << starting + 1 << '\n';
    
}
