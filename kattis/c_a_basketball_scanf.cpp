// Competitive Arcade Basketball
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, p, m; 
    if (!scanf("%d %d %d", &n, &p, &m)) return 0;
    unordered_map <string, int> scores;
    char player[20]; int score;
    bool winner = false;
    while(n--){
        cin >> player;
        scores[player] = 0;
    }
    while (m--){
        if (!scanf("%s %d", player, &score)) return 0;
        //cin >> player >> score;
        if (scores[player] == -1) continue;
        scores[player] += score;
        if (scores[player] < p) continue; // player has not won yet
        winner = true;
        scores[player] = -1; // if the player has won
        printf("%s wins!\n", player);
    }

    if (!winner)
        cout << "No winner!\n";

    return 0;
}
