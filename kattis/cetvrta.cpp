#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int xcoord[3];
    int ycoord[3];

    // Get user input
    for (int i = 0; i < 3; ++i){
        cin >> xcoord[i]; 
        cin >> ycoord[i];
    }

    // Finding "vertex"" (i.e. vertice that is already linked to two other vertices)
    int vertex;
    for (int i = 0; i < 3; ++i){
        if (((xcoord[i%3] == xcoord[(i+1)%3]) || (xcoord[i%3] == xcoord[(i+2)%3])) & ((ycoord[i%3] == ycoord[(i+1)%3]) || ycoord[i%3] == ycoord[(i+2)%3])){
           vertex = i;
        }
    }

    // Creating a list with the two non-vertex vertices
    vector<int> indexes = {0, 1, 2};
    for (int i = 0; i < 3; ++i){
        if ((indexes[i]) == vertex)
        indexes.erase(indexes.begin() + i);
    }

    int x_dist;
        if (abs(xcoord[vertex] - xcoord[indexes[0]]) > abs(xcoord[vertex] - xcoord[indexes[1]])){
                x_dist =  xcoord[indexes[0]] - xcoord[vertex];
                }
        else{
        x_dist =  xcoord[indexes[1]] - xcoord[vertex];
        }
    
    int y_dist;
    if (abs(ycoord[vertex] - ycoord[indexes[0]]) > abs(ycoord[vertex] - ycoord[indexes[1]])){
                y_dist =  ycoord[indexes[0]] - ycoord[vertex];
                }
        else{
        y_dist =  ycoord[indexes[1]] - ycoord[vertex];
        }
    
    // Computing fourth vertice coordinates    
    int new_x = xcoord[vertex] + x_dist;
    int new_y = ycoord[vertex] + y_dist;
   
    cout << new_x << " " << new_y << "\n";

}
