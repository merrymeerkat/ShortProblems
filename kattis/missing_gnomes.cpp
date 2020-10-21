#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector <int> incomplete;
set <int> missing;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;

    int gn;
    for (int i = 0; i < m; i++){
        cin >> gn;
        incomplete.push_back(gn);
    }

    // originally, missing has everything
    for (int i = 1; i <= n; i++){
        missing.insert(i);
    }

    // delete from missing what's not missing
    // mb try lazy deletion instead
    for (auto it = incomplete.begin(); it != incomplete.end(); ++it){
        missing.erase(*it);
    }

    int gn2;
    auto it = incomplete.begin();
    while(n--){
        if (it >= incomplete.end()){
            cout << *missing.begin() << '\n';
            missing.erase(*missing.begin());
        }
        else if (missing.empty()){
            cout << *it << '\n';
            it++;
        }
        else {
            gn = *it;
            gn2 = *missing.begin();
        
            if (gn <= gn2){
                cout << gn << '\n';
                it++;
            }
            else {
                cout << gn2 << '\n';
                missing.erase(gn2);
            }   
        }
    }
}
