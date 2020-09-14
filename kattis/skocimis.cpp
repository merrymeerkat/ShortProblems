#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int positions[3]; cin >> positions[0] >> positions[1] >> positions[2];

    int largest_difference = ((positions[1] - positions[0]) > (positions[2] - positions[1])) ? (positions[1] - positions[0]) : (positions[2] - positions[1]);
            
    cout << largest_difference - 1 << '\n';

}
