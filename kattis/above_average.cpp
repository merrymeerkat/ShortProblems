#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC; cin >> TC;

    int N; float average, above_average;

    while (TC--){
        cin >> N; 
        int scores[N];
        // Read scores from user
        for (int i = 0; i < N; i++)
            cin >> scores[i];

        // Find sum
        average = 0;
        for (int i = 0; i < N; i++)
            average += scores[i];
        
        // Find average
        average /= N;

        // Find those above average
        above_average = 0;
        for (int i = 0; i < N; i++)
            if (scores[i] > average)
                above_average++;

        // Find percentage of those above average
        above_average /= N;
        above_average *= 100;

        // Print percentage (3 decimal points)
        cout << fixed << setprecision(3) << above_average << "%\n";

    }
}
