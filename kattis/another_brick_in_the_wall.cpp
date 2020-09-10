
#include <iostream>
using namespace std;

int main(){

    int h, w, n; cin >> h >> w >> n;

    int bricks[n];
   
    // Getting and storing brick sizes
    for (int i = 0; i < n; ++i){
        cin >> bricks[i];
    }

    // Counters to keep track of current width and height of brick wall
    int width_counter = 0; 
    int height_counter = 0;
    
    // Iterating over the bricks
    for (int i = 0; i < n; ++i){

        width_counter += bricks[i];
        
        // If the next brick does not fit, Lars will give up
        if (width_counter > w){
            cout << "NO\n";
            return 0;
        }

        // Else if we reach the end of this layer, we move on to the next
        else if (width_counter == w){
            ++height_counter;
            width_counter = 0;
        }

        // If all layers are completed -> success!
        if (height_counter == h)
        {
            cout << "YES\n";
            return 0;
        }
    }
    
}
