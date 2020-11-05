#include <iostream>

using namespace std;

string dance[2010];

int main(){

    int N; cin >> N;
    int M; cin >> M;

    // read dance move from user input
    for (int r = 0; r < N; ++r){
        cin >> dance[r];
    }
    
    // iterate through rows of each column to check for blank columns
    // number of moves = blank columns + 1
    int counter = 1;
    bool blank_c;
    for (int c = 0; c < M; ++c){
        blank_c = true;
        for (int r = 0; r < N; ++r){
            if (dance[r][c] == '$')
                blank_c = false;
        }
        if (blank_c)
            counter++;
    }

    // output number of moves
    cout << counter << '\n';
}
