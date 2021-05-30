#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(){
    int TC; cin >> TC;
    while(TC--){
        int n, t;
        cin >> n >> t;
        int time;
        set <int> buttons;
        while(n--){
            cin >> time;
            buttons.insert(time);
        }
        queue <pair <int, int> > q;
        int closest = 1e9;
        int length; // how many presses you need
        q.push({0,0});
        while (!q.empty()){
            auto [num, presses] = q.front(); q.pop();
            if (num == t){
                closest = t;
                length = presses;
                break;
            }
            if (num >= t && num < closest){
                closest = num;
                length = presses;
            }

            for (auto it = buttons.begin(); it != buttons.end(); it++){
                if (num + *it <= 3600)
                    q.push({num + *it, presses + 1});
            }
        }
        cout << length << ' ' << closest - t << '\n';
    }
    return 0;
}
