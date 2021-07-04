#include <iostream>
#include <iostream>
#include <map>

using namespace std;

int par[1000000];
int rnk[1000000];
int siz[1000000];
map <string, int> mp;


int find_root(int a); // find root of a node
void join(int a, int b); // join the sets to which a and b belong

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int TC; cin >> TC;
    while(TC--){
        int F; cin >> F;
        int count = 0;
        mp.clear();
        for (int i = 0; i < F + 1; i++){
            par[i] = i;
            rnk[i] = 0;
            siz[i] = 1;
        }
        
        while (F--){
            string a, b; cin >> a >> b;
            if (mp.find(a) == mp.end()){    
                mp[a] = count;
                count++;
            }
            if (mp.find(b) == mp.end()){
                mp[b] = count;
                count++;
            }
            int ra = find_root(mp[a]);
            int rb = find_root(mp[b]);
            join(ra, rb); // join the two sets at the root
            if (rnk[ra] >= rnk[rb])
                cout << siz[ra] << '\n';
            else
                cout << siz[rb] << '\n';
        }
    }
}


// Recursively find representative ("root") node of a set, given an element that belongs to that set
int find_root(int a){
    if (a == par[a])
        return a;
    else{
        par[a] = find_root(par[a]);
        return par[a];
    }
}


void join(int a, int b){
    int ra = find_root(a);
    int rb = find_root(b);
    // if the elemnts are already in the same set, do nothing
    if (ra == rb)
        return;
    // we assume a has higher rank
    if (rnk[ra] < rnk[rb])
        join(b, a);
    else{ // rank[a] >= rank[b] -> we join to a
        par[rb] = ra;
        siz[ra] += siz[rb]; // increment size of set ra
        if (rnk[ra] == rnk[rb]) // if rank[ra] == rank[rb], the height of set ra increases by 1
            rnk[ra] += 1;
        return;
    }
}

