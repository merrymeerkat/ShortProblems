#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.141592

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int h, v;

    cin >> h >> v;

    // Convert angle from degrees to radians
    float vr = v*PI/180;

    // Calculate length of ladder
    int ladLen = ceil(h/sin(vr));

    cout << ladLen << "\n";

}
