// Count occurence of each number
// Go through list again
// First, go through these two scenarios:
// D U -> leave unique up 
// U U -> any
// And decrease, accordingly, the count of each of the numbers NOT left up
//
// Then go through the case
// D D -> leave the one with fewer counts up
//
#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef pair<int,int> ii;

int main(){
    int N; cin >> N;
    int a, b;
    vector <ii> cards;
    while(N--){
        cin >> a >> b;
        cards.push_back({a,b});
    }
    
    map <int, int> count;
    for (auto [a, b] : cards){
        count[a]++;
        count[b]++;
    }

    int unique = 0;
    for (auto it = count.begin(); it != count.end(); it++){
        if ((*it).second == 1)
            unique++;
    }

    set <int> picked;

    // put all unique cards up while you can
    long long ans = 0;
    while (unique > 0){
        for (int i = 0; i < cards.size(); i++){
            a = cards[i].first;
            b = cards[i].second;
            if (count[a] == 1){ // if a is unique, choose a
                ans++;
                count[a] = 0;
                //picked.insert(a);
                cards.erase(cards.begin()+i);
                unique--;
                count[b]--;
                if (count[b] == 1)
                    unique++;
            }
            else if (count[b] == 1){ // if a was not unique but b is, choose b
                ans++;
                count[b] = 0;
                //picked.insert(b);
                cards.erase(cards.begin()+i);
                unique--;
                count[a]--;
                    if (count[a] == 1)
                        unique++;
            }
        }
    }

    while(!cards.empty()){
        for (int i = 0; i < cards.size(); i++){
            a = cards[i].first;
            b = cards[i].second;
            if (count[a] <= count[b]){// pick a
                ans++;
                count[b]--;
                cards.erase(cards.begin()+i);
            }
            else{
                ans++;
                count[a]--;
                cards.erase(cards.begin()+1);
            }

        }
    }

    cout << ans << '\n';
}
