#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // Storing user input
    int numbers[10];
    for (int i = 0; i < 10; i++)
        cin >> numbers[i];

    // Iterating over user input and counting modulo valuess
    // Each possible modulo value has its own "bucket" in the array
    int counting[42] = { 0 };
    int modulo;
    for (int i = 0; i < 10; i++){
        modulo = numbers[i] % 42;
        counting[modulo]++;
    }

    // Counting distinct values (i.e. the count of non-zero values in the array)
    int distinct_values = 0;
    for (int i = 0; i < 42; i++){
        if (counting[i] != 0)
            distinct_values++;
    }

    cout << distinct_values << "\n";
}
