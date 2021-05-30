#include <iostream>

using namespace std;

string wdw[110];

int main(){
    int R, C, S; cin >> R >> C >> S;
    for (int i = 0; i < R; i++)
        cin >> wdw[i];

    //int s = S - 2;
    pair <int, int> sol;
    int max_sum = -1e9;
    int sum;
    for (int col = 0; col <= C - S; col++){
        for (int row = 0; row <= R - S; row++){
            sum = 0;
            for (int c = col + 1; c < col + S - 1; c++){
                for (int r = row + 1; r < row + S - 1; r++){
                    if (wdw[r][c] == '*')
                        sum++;
                }
            }
            if (sum > max_sum){
                max_sum = sum;
                sol.first = row;
                sol.second = col;
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
