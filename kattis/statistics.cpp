#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector <int> maxArr; vector <int> minArr; vector <int> rangeArr;

    int n; cin >> n;
    
    while (cin >> n){
    
        vector <int> numbers;
        
        int j;
        for (int i = 0; i < n; ++i){
            cin >> j;
            numbers.push_back(j);
        }

        int siz = numbers.size();

        // Find max
        int max = numbers.at(0);
        for (int i = 1; i < siz; ++i){
            if (numbers.at(i) > max){
                max = numbers.at(i);
            }
        }
        maxArr.push_back(max);

        
        // Find min
        int min = numbers.at(0);
        for (int i = 1; i < siz; ++i){
            if (numbers.at(i) < min){
                min = numbers.at(i);
            }
        }
        minArr.push_back(min);

        // Find range
        int range = max - min;
        rangeArr.push_back(range);
    
        cin >> n;
    }

    // printing out results
    int test_cases = maxArr.size();

    for (int i = 0; i < test_cases; ++i){
        cout << "Case " << i + 1 << ": ";
        cout << minArr.at(i) << " " << maxArr.at(i) << " " << rangeArr.at(i) << "\n";
    }
}
