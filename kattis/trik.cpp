#include <iostream>

using namespace std;

void swap(char* a, char* b);

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    char moves[50];

    char k; int idx = 0;
    
    cin >> noskipws;

    // Store user input in array of moves
    while(cin >> k && k != '\n'){
        moves[idx] = k;
        idx++;
    }

    // Initial position (1 == ball)
    int cups[3] = {1, 0, 0};

    // Iterate through moves array, making the corresponding cup swaps
    for (int i = 0; i < idx; i++){
        switch(moves[i]){
            case('A'):
                swap(cups[0], cups[1]);
                break;
            case('B'):
                swap(cups[1], cups[2]);
                break;
            default:
                swap(cups[0], cups[2]);
        }
    }

    // Output correct location of ball
    for (int i = 0; i <= idx; i++){
        if (cups[i] == 1){
            cout << i + 1 << "\n";
            return 0;
        }
    } 
}

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
