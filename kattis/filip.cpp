#include <iostream>

using namespace std;

int reverse_int(int n);

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, B; cin >> A >> B;

    A = reverse_int(A); B = reverse_int(B);

    if (A > B)
        cout << A << '\n';
    else
        cout << B << '\n';
}

int reverse_int(int n){
    int output = 0;
    while (n > 0){
        output *= 10;
        output += n % 10;
        n /= 10;
    }
    return output;
}
