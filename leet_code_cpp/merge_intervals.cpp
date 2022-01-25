#include <iostream>
#include <vector>
using namespace std;

int main(){

    // tuples
    //int N; cin >> N;
    vector <int> nums[1000000];
    int counter = 1;
    for (auto [f, l] : tuples ){
        nums[f].push_back(counter);
        nums[l].push_back(counter);
        counter++;
    }

    vector <pair <int, int> > output;
    set <int> interval;
    int first = -1;
    int last = -1;
    int idx = 0;
    for (auto v : nums){
        for (auto n : v){
            if (n == 0) continue;
            if (interval.empty())
                first = idx;
            if (interval.find(n) != interval.end())
                interval.erase(n);
            else
                interval.insert(n);
            if (interval.empty()){
                last = idx;
                output.push_back({first, last});
            }
        }
        idx++;
    }



}
