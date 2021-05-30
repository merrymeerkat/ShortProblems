#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int num;
    vector <int> nums;
    while(N--){ // see while cin
        cin >>  num; 
        nums.push_back(num);
    }

    int max_height = 0, dist = 0, tmp_dist = 0;
    for (auto curr : nums){
        if (curr >= max_height){
            dist = max(dist, tmp_dist);
            tmp_dist = 0;
            max_height = curr;
        }
        tmp_dist = max(max_height - curr, tmp_dist);
        //cout << "tmp is " << tmp_dist << endl;
    }
    //cout << dist << endl; 
    reverse(nums.begin(), nums.end());
    max_height = 0; tmp_dist = 0;
    for (auto curr : nums){
        if (curr >= max_height){
            dist = max(dist, tmp_dist);
            tmp_dist = 0;
            max_height = curr;
        }
        tmp_dist = max(max_height - curr, tmp_dist);
    }

    cout << dist << '\n';
}
