#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int N;
int memo[2000][2000];
int wt[2000] = { 0 };
int val[2000] = { 0 };        
set <int> choices;


// takes in item id and remaining weight, and see what's the best we can do!
int dp(int id, int remW){
    if (id == N || remW == -1) return 0;
    int &ans = memo[id][remW-1]; // cool way of writing this
    if (ans != -1) return ans;
    if (remW < wt[id]) return ans = dp(id+1, remW); // skip; item too heavy
    return ans = max(dp(id+1,remW), val[id] + dp(id+1,remW-wt[id]));
}

// get choices: if dp[id][w] == dp[id+1][w-wt[id]] + val[id] => id was chosen! Else it was not
void get_choices(int C, int best){
    int remW = C;
    for (int id = 0; id < N - 1; id++){
       if (dp(id,remW) - val[id] == (dp(id+1, remW-wt[id]))){
            remW -= wt[id];
            choices.insert(id);
        }
    }
    if (dp(N-1,remW) > 0)
        choices.insert(N-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int C;
    while(cin >> C){
        cin >> N;
        choices.clear();

        // Fill memo with dummy values
        for (int i = 0; i < N; i++){
            for (int j = 0; j < C; j++)
                memo[i][j] = -1;
        }
        for (int i = 0; i< N; i++){
            cin >> val[i];
            cin >> wt[i];
        }
        
        // Carry out dp and print out choices
        int best = dp(0,C);
        get_choices(C, best);
        cout << choices.size() << endl;
        for (auto c: choices)
            cout << c << ' ';
        cout << endl;
    }
}
