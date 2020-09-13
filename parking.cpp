#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC; cin >> TC;
    int min_dist[100]; // Array to store answers

    int n;

    for (int k = 0; k < TC; k++){

        cin >> n;

        int stores[n];

        for (int i = 0; i < n; ++i)
            cin >> stores[i];

        sort(stores, stores + n);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += stores[i];

        float mean = (float) sum / n; // The optimal parking spot

        float distance_walked = 0;
        float position = mean;
        for (int i = 0; i < n; i++){
            distance_walked += abs(position - stores[i]);
            position = stores[i];
        }

        // Adding the final distance (walking from the last shop back to the parking spot)
        distance_walked += abs(mean - position); 

        min_dist[k] = distance_walked;
    }

    for (int i = 0; i < TC; i++)
        cout << min_dist[i] << "\n";

}
