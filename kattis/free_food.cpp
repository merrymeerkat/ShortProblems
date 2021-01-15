#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector <int> got_free_food;
    got_free_food.assign(365, 0);

    int E; cin >> E;
    int s, e;
    while (E--){
        cin >> s >> e;
        for (int i = s; i <= e; i++)
            got_free_food[i-1] = 1;
    }

    int total = accumulate(got_free_food.begin(), got_free_food.end(), 0);
    cout << total << '\n';
    return 0;
}
