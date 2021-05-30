#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N; cin >> N;
    int num;
    vector <int> nums;
    for (int i = 0; i < N; i++){ // see while cin
        scanf("%d", &num);
        nums.push_back(num);
    }

    int max_height = 0, dist = 0, tmp_dist = 0;
    for (auto curr : nums){
        if (curr >= max_height){
            if (dist < tmp_dist)
                dist = tmp_dist;
            tmp_dist = 0;
            max_height = curr;
        }
        if (tmp_dist < max_height - curr)
            tmp_dist = max_height - curr;
    }
    max_height = 0; tmp_dist = 0;
    for (int i = N - 1; i >= 0; i--){
        int curr = nums[i];
        if (curr >= max_height){
            if (dist < tmp_dist)
                dist = tmp_dist;
            tmp_dist = 0;
            max_height = curr;
        }
        if (tmp_dist < max_height - curr)
            tmp_dist = max_height - curr;
    }

    cout << dist << '\n';
}
