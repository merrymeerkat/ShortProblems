#include <iostream>

using namespace std;

#define PI 3.1415653592898
#define TPI 6.28313071858

int main(){
    float A; cin >> A;
    float N; cin >> N;

    // Max area is a radius
    float radius = N / TPI;
    float max_A = PI * radius * radius;

    if (max_A >= A)
        cout << "Diablo is happy!" << '\n';
    else
        cout << "Need more materials!" << '\n';
}

