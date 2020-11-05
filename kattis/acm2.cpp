#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, p; cin >> n >> p;
    vector <int> times;

    int minutes = 300;
    int count = 0;
    int this_p, penalty;

    for (int i = 0; i < n; i++){
        cin >> this_p;
        times.push_back(this_p);
    }

    minutes -= times.at(p);
    penalty = 300 + times.at(p);
    times.erase(times.begin() + p);

    sort(times.begin(), times.end(), greater<int>());
    n -= 2;
    
    while (minutes >= 0 && (!times.empty()) && (n >= 0)){
        count++;
        minutes -= (times.at(n));
        times.pop_back();
        n--;
    }
    
    if (count == 0)
        penalty = 0;

    cout << count << ' '<< penalty << '\n';
    
}
