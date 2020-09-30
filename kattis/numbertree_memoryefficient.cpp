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
    // All we need is to know the value of the highest node (=size)


    // Step 2: Follow path!
    // Here, we suppose the tree is represented
    // as an array where index 1 is the root of the tree, and
    // the succeeding indices are occupied by the next elements in decreasing order.
    // In order to get the index of an element's left child, we
    // multiply the parent's index by 2. The right child is 1 index to the right of the left child.
    // Due to memory constraints, this array is "imaginary"
    int node_index = 1;
    for (auto c: path){
        if (c == 'R'){
            node_index *= 2;
            node_index++;
        }
        else 
            node_index *= 2;      
    }

    // Find the node value corresponding to this index
    // Since node_index 1 is the root, a simple subtraction allows us to find
    // any node_label given a node_index
    int node_label = size - node_index + 1;
    cout << node_label << '\n';
}
