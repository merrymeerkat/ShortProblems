#include <iostream>

using namespace std;

typedef long long ll;

int LSOne(int i);
ll query(int i);
void insert(int i, int j);

long long ft[5000010] = { 0 };
int N, Q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    while(Q--){
        char bop;
        cin >> bop;
        if (bop == '+'){
            int i, k; cin >> i >> k;
            insert(i+1, k);
        }
        else{
            int i; cin >> i;
            cout << query(i) << '\n';
        }
    } 
    return 0;
}

// LSOne => gets the least significant 1 of a number's binary representation
int LSOne(int i){
    return ((i) & -(i));
}

ll query(int i){
    if (i <= 0) return 0;
    return ft[i] + query(i - LSOne(i));
}

void insert(int i, int k){
    if (i >= N + 1) return;
    // increment this index and all of the others affected by this
    ft[i] += k;
    return insert(i+LSOne(i), k);
}
// our array starts at index 1 (so add 1 to each query/insertion index)
// let our fenwick tree (array) be called ft

// RANGE QUERY
// Sum of range(1, j) = ft[j] + ft[j'] + ft[j''] + ... + ft[0]
// where ft[0] = 0
// and j' = j - LSOne(j)
//
// To get the sum of the range(i,j), we can use an exclusion principle
// sum_range(i,j) = sum_range(j) - sum_range(i-1)


// INSERTION
// When adding k to the value at index i,
// we set ft[i] += k and do the same for i*, i**, ..., until i**... >= m
// where i* = i + LSOne(i)

