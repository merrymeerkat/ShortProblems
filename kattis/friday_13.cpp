#include <iostream>
#include <vector>

using namespace std;

vector <int> days;

int main(){
    int TC; cin >> TC;
    int M, D, d, day_counter, fri_13s;

    while (TC--){
        cin >> D >> M;

        days.assign(D, 0);

        // Finding 13ths
        day_counter = 0;
        for (int i = 0; i < M; i++){
            cin >> d;
            if (d > 12)
                days.at(day_counter + 12)++;
            day_counter += d;
        }

        fri_13s = 0;
        //Finding Friday 13ths
        for (int idx = 5; idx < D; idx+=7){
            if (days.at(idx)){
                fri_13s++;
            }
        }

        cout << fri_13s << '\n';
    }
}
