#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    int n, m, a, b, trips;
    set <int> cities;

    while (tc--){
        cin >> n >> m;
        
        while (m--){
            cin >> a >> b;
        }

        // short cut: in this specific problem, the answer is always the number of
        // edges (i.e. number of cities - 1)
        cout << n - 1 << '\n';

        /*trips = 0;
        int i = 0;
        for ( ; i < m; i++){
            cin >> a >> b;
            cities.insert(a); cities.insert(b);
            trips++;
            if (cities.size() == n){
                cout << trips << '\n';
                break;
            }
        }
        for (int j = i + 1; j < m; j++){
            cin >> a >> b;
        }
        cities.clear(); */
        

        /*// Adjacency list
        vector<int> adl[n];

        while(m--){
            cin >> a >> b;
            adl[a - 1].push_back(b);
        }

        // Check if any city is not connected
        for (int i = 0; i < n; ++i){
            if (adl[i].empty())
                return
        }
        */
    }
}
