#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){

    float area; cin >> area;

    // pasture is square, so length side = sqrt(area)
    float perimeter = 4 * sqrt(area);

    cout << setprecision(7) << perimeter << '\n';
}

