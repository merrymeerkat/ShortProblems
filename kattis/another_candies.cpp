#include <iostream>

using namespace std;

int main(){

    int TC; cin >> TC;
    long long n;
    long long sum, candies;
    while (TC--){
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++){
            cin >> candies;
            sum += candies % n;
        }
        if (sum % n == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
