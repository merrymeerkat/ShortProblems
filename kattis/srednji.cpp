#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int N, B; cin >> N >> B;
    vector <int> nums;
    nums.assign(N, 0);
    int n;

    int Bidx; // B's position
    for (int i = 0; i < N; i++){
        cin >> n;
        if (n == B)
            Bidx = i;
        nums[i] = n;
    }

    map <int, int> mp;
    mp[0] = 1;
    int greater = 0;
    for (int idx = Bidx-1; idx >= 0; idx--){
        if (nums[idx] > B)
            greater++;
        else
            greater--;
        mp[greater]++;
    }

    ll answer = mp[0];
    greater = 0;
    for (int idx = Bidx + 1; idx < N; idx++){
        if (nums[idx] > B)
            greater++;
        else
            greater--;
        answer += mp[-greater];
    }

    cout << answer << '\n';
}
