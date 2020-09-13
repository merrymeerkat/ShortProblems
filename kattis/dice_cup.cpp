#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;

    // array to keep track of countings
    int buckets[41] = { 0 };

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            buckets[i + j]++;
        }
    }

    int max_values[20] = { 0 };
    int max_counter = 0;

    int max = 0;
    for (int i = 0; i < 41; ++i){
        max = (buckets[i] > max) ? buckets[i] : max;
    }

    for (int i = 0; i < 41; i++){
        if (buckets[i] == max){
            max_values[max_counter] = i;
            max_counter++;
        }
    }

    for (int i = 0; i < max_counter; i++)
        cout << max_values[i] << "\n";


}
