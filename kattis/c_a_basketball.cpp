// Competitive Arcade Basketball
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, p, m; cin >> n >> p >> m;
    unordered_map <string, int> scores;
    string player; int score;
    set <string> has_won;
    while(n--){
        cin >> u;
    }
    while (m--){
        cin >> player >> score;
        if (has_won.find(player) != has_won.end()) continue;
        scores[player] += score;
        if (scores[player] < p) continue;
        has_won.insert(player);
        cout << player << " wins!\n";
    }

    if (!has_won.size())
        cout << "No winner!\n";

    return 0;
}
