#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector <queue<string> > preferences;
vector <queue<string> > choices;
queue <string> ranking;
set <string> removed;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // n owners, k players/team
    int n, k; cin >> n >> k;

    preferences.assign(n, queue<string>());
    choices.assign(n, queue<string>());
    int size;
    string name;
    for (int i = 0; i < n; i++){
        cin >> size;
        while (size--){
            cin >> name;
            preferences[i].push(name);
        }
    }  

    // Get ranking
    cin >> size;
    while (size--){
        cin >> name;
        ranking.push(name);
    }
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            // Check owners preferences first
                // if their first pref has already been chosen, pop from preferences
                while(!preferences[j].empty() && removed.find(preferences[j].front()) != removed.end()){
                    preferences[j].pop();
                }
                
                if (!preferences[j].empty()){
                    name = preferences[j].front();
                    preferences[j].pop();
                }

                // If owners' pref is empty, check general ranking
                // Again, we first check if the front of the queue has alrd been chosen
                else {
                    while (removed.find(ranking.front()) != removed.end()){
                        ranking.pop();
                    }
                    name = ranking.front();
                    ranking.pop();
                }
                removed.insert(name);
                choices[j].push(name);
        }
    }

    // Print teams
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < k; j++){
            cout << choices[i].front() << ' ';
            choices[i].pop();
        }
        cout << '\n';
    }
}
