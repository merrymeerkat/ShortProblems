#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC, N, number, median, sum;
    vector <int> numbers; bool inserted;

    cin >> TC;
    while (TC--){
        sum = 0;
        cin >> N;
        cin >> number; numbers.push_back(number);
        sum += number;
        for (int i = 1; i < N; i++){
            cin >> number;
            
            inserted = false;
            // Insert at correct position
            for (auto it = numbers.begin(); it != numbers.end(); it++){
                if (*it > number){
                    numbers.insert(it, number);
                    inserted = true;
                    break;    
                    }
                }
            if (!inserted) {
                numbers.push_back(number);
            }

            if (i % 2 == 0){
                median = ((long long) numbers.at(i/2) + numbers.at((i/2) + 1))/2;
            }
            else{
                median = numbers.at(i/2);
            }
            sum += median;
        }
        cout << sum << '\n';
        
        numbers.clear();
    }
}
