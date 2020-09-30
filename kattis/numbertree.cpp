#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // Step 0: get input height and path
    int height; cin >> height;
    char direction; vector <char> path; 
    while (cin >> direction)
        path.push_back(direction);

    // Step 1: build tree
    int size = pow(2, (height+1)) - 1;
    int tree_arr[size + 1]; // leave 1 empty spot

    // Insert numbers into our perfect tree array
    // Index 0 will be empty (this allows us to find children by index more easily)
    int node_value = size;
    for (int i = 1; i <= size; i++){
        tree_arr[i] = node_value;
        node_value--;
    }

    // Step 2: Follow path!
    int node_index = 1;
    for (auto c: path){
        if (c == 'R'){
            node_index *= 2;
            node_index++;
        }
        else 
            node_index *= 2;      
    }

    cout << tree_arr[node_index] << '\n';
}
