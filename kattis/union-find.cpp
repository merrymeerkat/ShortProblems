#include <iostream>

using namespace std;

int par[1000000];
int rnk[1000000];

int find_root(int a); // find root of a node
void check_elems(int a, int b); // check if two nodes are in the same set
void join(int a, int b); // join the sets to which a and b belong

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, Q; cin >> N >> Q;
    for (int i = 0; i < N; i++){
        par[i] = i;
        rnk[i] = 0;
    }

    // Read in operations
    char op; int a, b;
    for (int i = 0; i < Q; i++){
        cin >> op >> a >> b;
        if (op == '?')
            check_elems(a, b);
        else if (op == '=')
            join(a, b);
    }
}

// Recursively find representative ("root") node of a set, given an element that belongs to that set
int find_root(int a){
    if (a == par[a])
        return a;
    else{
        return par[a] = find_root(par[a]);
        //return par[a];
    }
}

// check if two elements are in the same set
void check_elems(int a, int b){
    if (find_root(a) == find_root(b))
        cout << "yes\n";
    else
        cout << "no\n";
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
        if (rnk[ra] == rnk[rb]) // if rank[ra] == rank[rb], the height of set ra increases by 1
            rnk[ra] += 1;
        return;
    }
}

