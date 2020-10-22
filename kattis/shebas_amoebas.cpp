#include <iostream>

using namespace std;

// dish dimensions
int m, n;

// each row is a string
string dish[110];

int adj_row[8] = {-1,-1,0,1,1,1,0,-1}; // N, NE, ... W, NW
int adj_col[8] = {0,1,1,1,0,-1,-1,-1};

void flood_fill(int r, int c){

    // mark as visited
    dish[r][c] = '.';

    // find neighbours
    int n_row, n_col;
    for (int i = 0; i < 8; ++i){
        n_row = r + adj_row[i]; n_col = c + adj_col[i];
        
        // bound check
        if ((n_row < 0) || (n_row >= m) || (n_col < 0) || (n_col >= n)) continue;
    
        if (dish[n_row][n_col] == '#')
            flood_fill(n_row, n_col);
    }
}


int main(){

    cin >> m >> n; cin.get();
    for (int i = 0; i < m; i++){
        cin >> dish[i];
    }

    int components = 0;
    for (int r = 0; r < m; r++){
        for (int c = 0; c < n; c++){
            if (dish[r][c] == '#'){
                components++;
                flood_fill(r, c);
            }
        }
    }
    cout << components << '\n';
    return 0;
}
