

#include <iostream>

using namespace std;

int main(){

    int n; // number of pairs of values in a set
    cin >> n;
    while (n != -1){

        int speed[n];
        int time[n];

        for (int i = 0; i < n; ++i){
            cin >> speed[i];
            cin >> time[i];
        }

        int adjusted_time[n];
        adjusted_time[0] = time[0];
        for (int i = 1; i < n; ++i){
            adjusted_time[i] = time[i] - time[i-1];
        }
        
        // calculating distance
        int distance = 0;
        for (int i = 0; i < n; ++i){
            distance += (speed[i] * adjusted_time[i]);
        }

        cout << distance << " miles\n";

        cin >> n;
    }
}
