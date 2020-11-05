#include <iostream>
#include <vector>

using namespace std;

int digit_product(int n);

int main(){

    int x; cin >> x;
    cout << digit_product(x) << '\n';
}

int digit_product(int n){

    int digit;
    vector <int> digits;

    // Partition
    while (n > 0){
        digit = n % 10;
        n /= 10;
        digits.push_back(digit);
    }

    // Multiply digits
    int product = 1;
    for (int dig : digits){
        if (dig){
            product *= dig;
        }
    }

    if (product > 9){
        return (digit_product(product));
    }
    else
        return product;  
}
