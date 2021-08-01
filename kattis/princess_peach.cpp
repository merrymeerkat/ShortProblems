#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; int Y;
    // Read in total number of obstacles and number of obstacles Mario saw
    cin >> N >> Y;

    // Make list of obstacles
    vector<int> obstacles;
    obstacles.assign(N, 1);

    // Mark obstacles Mario saw
    int seen;
    for (int i = 0; i < Y; i++){
        cin >> seen;
        obstacles[seen] = 0;
    }

    // Print out obstacles Mario missed!
    int missed = 0;
    for (int i = 0; i < N; i++){
        if (obstacles[i]) {
            cout << i << '\n';
            missed++;    
        }
    }

    cout << "Mario got " << N - missed << " of the dangerous obstacles.\n";

}
