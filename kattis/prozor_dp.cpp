#include <iostream>

using namespace std;

string wdw[110];

int main(){
    int R, C, S; cin >> R >> C >> S;
    for (int i = 0; i < R; i++)
        cin >> wdw[i];

    // running sum on each row
    int run_sum[110][110] = { 0 };
    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            if (c != 0) run_sum[r][c] += run_sum[r][c-1];
            if (wdw[r][c] == '*') run_sum[r][c]++;
        }
    }

    //int s = S - 2;
    // pensar melhor na estrategia
    pair <int, int> sol;
    int max_sum = -1e9;
    int sum;
    int partial_sum[110][110];
    for (int row = 0; row <= R - S; row++){
        for (int col = 0; col <= C - S; col++){
            partial_sum[row][col] += run_sum[row][col+S-1];
            partial_sum[row][col] -= run_sum[row][col]; //border
            if (row != 0){
                partial_sum[row][col] += partial_sum[row-1][col];
                
            }
        }
    }

    cout << max_sum << endl;
    wdw[sol.first][sol.second] = '+';
    for (int r = sol.first + 1; r < sol.first + S - 1; r++){
        wdw[r][sol.second] = '|';
        wdw[r][sol.second + S - 1] = '|';
    }
    for (int c = sol.second + 1; c < sol.second + S - 1; c++){
        wdw[sol.first + S - 1][c] = '-';
        wdw[sol.first][c] = '-'; 
    }
    wdw[sol.first + S-1][sol.second] = '+';
    wdw[sol.first][sol.second + S-1] = '+';
    wdw[sol.first + S-1][sol.second + S-1] = '+';

    for (int i = 0 ; i < R; i++)
        cout << wdw[i] << '\n';

}
