// Competitive Arcade Basketball
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    short int p;
    cin >> n >> p >> m;
    unordered_map <string, int> scores;
    char player[20]; short int score;
    bool winner = false;
    while(n--){
        cin >> player;
        scores[player] = 0;
    }
    while (m--){
        cin >> player >> score;
        if (scores[player] == -1) continue;
        scores[player] += score;
        if (scores[player] < p) continue; // player has not won yet
        winner = true;
        scores[player] = -1; // if the player has won
        cout << player << " wins!\n";
    }

    if (!winner)
        cout << "No winner!\n";

    return 0;
}
