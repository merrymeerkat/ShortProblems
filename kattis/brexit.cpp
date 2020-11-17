#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;

vector <vi> AL;
vi leftt;
vi num_partners;
vi num_partners_post;
queue <int> leaving;

int main(){

    int C, P, X, L; cin >> C >> P >> X >> L;

    AL.assign(C + 1, vi());
    leftt.assign(C + 1, 0);
    num_partners.assign(C + 1, 0);
    num_partners_post.assign(C + 1, 0);

    int u, v;
    while (P--){
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    // get number of partners
    //for (auto it = AL.begin(); it != AL.end(); it++){
    for (int idx = 1; idx <= C; idx++){
        num_partners[idx] = (AL[idx]).size();
        num_partners_post[idx] = (AL[idx].size());
    }  

    leaving.push(L);
    leftt[L] = 1;

    //change
    int country, partners_gone;
    while(!leaving.empty()){
        country = leaving.front(); leaving.pop();

        for (auto it = AL[country].begin(); it != AL[country].end(); it++){
            if (!leftt[*it]){
                num_partners_post[*it]--;
                if ((long long)num_partners_post[*it] <= ((long long) num_partners[*it] / 2)){
                    leaving.push(*it);
                    leftt[*it] = 1;
                }
            }
        }
    }

   /* for (int i = 1; i < C; i++){
        cout << leftt[i] << endl;
    }*/

    if (leftt[X])
        cout << "leave\n";
    else
        cout << "stay\n";

    return 0;
    

}
