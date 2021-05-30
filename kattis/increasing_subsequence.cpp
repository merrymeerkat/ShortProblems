#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    while (n > 0){
        vector <int> nums;
        vector <int> dp;
        
        int num;
        for (int i = 0; i < n; i++){
            cin >> num;
            nums.push_back(num);
        }
        dp.assign(n, 1);

        // dp[i] is the longest increasing subsequence ending at index i
        int maxi = 1; // LIS for the whole array
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            if (dp[i] > maxi)
                maxi = dp[i];
        }   

        int idx = 0;
        vector <int> seq;
        int earliest;
        for (int i = 1; i <= maxi; i++){
            earliest = nums[idx];
            while (dp[idx] == i){
                idx++;
                if (nums[idx] < earliest)
                    earliest = nums[idx];
            }
            seq.push_back(earliest);
        }

        cout << maxi << ' ';
        for (auto n : seq)
            cout << n << ' ';
        cout << '\n';

        cin >> n;
    }
    return 0;
}
/*// Find first spot where dp[i] = LIS
        int mini;
        for (int i = 0; i < n; i++){
            if (dp[i] == maxi){
                mini = i;
                break;
            }
        }

        // Trace numbers
        // if dp[i] is less than dp[i+1], then nums[i] was included in the LIS
        vector <int> idxs;
        for (int i = 0; i < mini && i < n - 1; i++){
            if (dp[i] < dp[i+1])
                idxs.push_back(i);
        }

        cout << "TEST\n";
        for (int i = 0; i < n; i++)
            cout << dp[i] << ' ';
        cout << '\n';


        // output results
        cout << maxi << ' ';
        for (auto i : idxs){
            cout << nums[i] << ' ';
        }
        cout << nums[mini] << ' ';
        cout << '\n';*/


