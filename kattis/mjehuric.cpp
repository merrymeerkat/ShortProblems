#include <iostream>

using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    int numbers[5];

    for (int idx = 0; idx < 5; ++idx){
        cin >> numbers[idx];
    }

    bool swapped;
    for (int i = 0; i < 4; i++){
        swapped = false;
        for (int j = 0; j < 4-i; j++){
            if (numbers[j] > numbers[j + 1]){
                swap(numbers[j+1], numbers[j]);
                swapped = true;
                for (int k = 0; k < 5; k++)
                     cout << numbers[k] << ' ';
                cout << '\n'; 
                }    
        }
    
        if (!swapped)
            break;
    }

    return 0;
}
