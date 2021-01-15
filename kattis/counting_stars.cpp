#include <iostream>
#include <vector>

using namespace std;

void flood_fill(int r, int c);
// vertical and horizontal neighbours only
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

vector <string> sky;
int n, m;

int main(){
    int stars;
    string row;
    int counter = 1;
    while (cin >> m >> n){
        
        sky.assign(m, "");
         
        // read input
        for (int r = 0; r < m; r++){
            cin >> row;
            sky[r] = row;
        }

        // count stars
        stars = 0;
        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++){
                if (sky[r][c] == '-'){ 
                    stars++;
                    flood_fill(r, c);
                }
            }
        }
        cout << "Case " << counter << ": " << stars << '\n';
        counter++;
        sky.clear();
    }
}

void flood_fill(int r, int c){
    // mark as visited
    sky[r][c] = '#';
    int nr, nc;
    for (int i = 0; i < 4; i++){
        nr = r + dr[i];
        nc = c + dc[i];
        if ((nc < 0) || (nr < 0) || (nc >= n) || (nr >= m)) continue;
        if (sky[nr][nc] == '#') continue;
        // if none of the cases above were caught, then cell is also a part of star
        flood_fill(nr, nc);
    }
    return;
}


