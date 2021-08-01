#include <iostream>

using namespace std;

int query(int i);
int range_query(int i, int j);
void flip(int i, bool toZero);

// Fenwick tree (implemented as an array)
int ft[1000010] = { 0 };
int N, K;

// In this problem, we can store the cumulative frequency of bits in a fenwick tree. This allows for O(logN) updates and queries, where N is the number of bits in the memory (i.e., N)

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // Read in number of bits and queries
    cin >> N >> K;

    // Read each query
    while(K--){
        char op; cin >> op;
    
        // flip query
        if (op == 'F'){
            // get index
            int i; cin >> i;
            // see which direction of flip we want
            if (range_query(i, i) == 0)
               flip(i, false);
            else
               flip(i, true);
        }
        
        // Range query
        else {
            int i, j; cin >> i >> j;
            cout << range_query(i, j) << '\n';
        }
    }    
}

int LSOne(int i){
    return i & (-i);
}

void flip(int i, bool toZero){
    // we either increment a bit by 1 or decrement by 1
    int incr = toZero ? (-1) : 1;
    while (i <= N){
        ft[i] += incr;
        i += LSOne(i);
    }
}

// query range 0-i
int query(int i){
    if (i == 0) return 0;
    return ft[i] + query(i - LSOne(i));
}

//query range i-j
int range_query(int i, int j){
    return (query(j) - query(i-1));
}
