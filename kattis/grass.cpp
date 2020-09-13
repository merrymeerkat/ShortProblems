#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    float cost; cin >> cost;
    int lawns; cin >> lawns;

    double total_cost = 0.0;
    double w, l; 

    for (int i = 0; i < lawns; i++){
        cin >> w >> l;
        total_cost += (w * l) * cost;
    }

    cout << fixed << setprecision(7);
    cout << total_cost << "\n";
}
