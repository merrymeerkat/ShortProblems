#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int Adrian[3] = {'A', 'B', 'C'};
    int Bruno[4] = {'B', 'A','B', 'C'};
    int Goran[6] = {'C', 'C', 'A', 'A', 'B', 'B'};

    int N; cin >> N;

    char letters[100];

    for (int i = 0; i < N; ++i){
        cin >> letters[i];
    }


    int correct_Ad = 0, correct_Br = 0, correct_Go = 0;

    for (int i = 0; i < N; ++i){
        if (letters[i] == Adrian[i%3])
            correct_Ad++;
        if (letters[i] == Bruno[i%4])
            correct_Br++;
        if (letters[i] == Goran[i%6])
            correct_Go++;
    }

    // This part can be optimised
    int max = 0;
    if (correct_Ad > max)
        max = correct_Ad;
    if (correct_Br > max)
        max = correct_Br;
    if (correct_Go > max)
        max = correct_Go;
    
    cout << max << "\n";

    if (correct_Ad == max)
        cout << "Adrian\n";
    if (correct_Br == max)
        cout << "Bruno\n";
    if (correct_Go == max)
        cout << "Goran\n"; 

}
