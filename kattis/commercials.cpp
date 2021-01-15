#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, P; cin >> N >> P;
    int num, sum; int max_sum = -1e9; int last_sum = -1e9;
    // Kadane's algo
    while (N--){
        cin >> num;
        num -= P; // subtract cost of ad from # of students watching (1 student = 1 krone)
        sum = max(num, last_sum + num);
        if (sum > max_sum)
            max_sum = sum;
        last_sum = sum;
    }
    cout << max_sum << '\n';
}

