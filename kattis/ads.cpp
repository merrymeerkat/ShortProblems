#include <iostream>
#include <ctype.h>

using namespace std;

int H, W;

string page[200];
int visited[200][200];
int visited2[200][200];

int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};

int nr, nc; // neighbour row and column

//bool seen_border;

// finds if an cell is inside an image (i.e. surrounded by a border of '+'s)
bool in_image(int r, int c){

    visited2[r][c] = 1; // check

    bool answer;

    for (int i = 0; i < 8; i++){
        nr = r+dr[i]; nc = c + dc[i];
    
        if ((nr < 0) || (nr >= H) || (nc < 0) || (nc >= W)) continue;
        
        if (!visited2[nr][nc]){

            // if you reach a page border and this is not an image border, then
            // the cell is not in an image
            if ((nr == 0) || (nr == H-1) || (nc == 0) || (nc == W -1)){ 
                if (page[nr][nc] != '+'){
                    return false;
                }
            } 

                answer = answer || in_image(nr, nc);
                return answer;
        }
    }
    return true;
}

void flood_fill(int r, int c){

    
    // Mark as visited
    visited[r][c] = 1;
    page[r][c] = ' ';
   
    // Get 8 neighbours
    for (int i = 0; i < 8; i++){
        nr = r + dr[i]; nc = c + dc[i];

        // check for bounds
        if ((nr < 0) || (nr >= H) || (nc < 0) || (nc >= W)) continue;

        if (page[nr][nc] == '+'){
            page[nr][nc] = ' ';
            visited[nr][nc] = 1;
            continue;
        }
        //if (page[r][c] != ' '){
        //    flood_fill(nr,nc);
        //}

        if (!visited[nr][nc])
            flood_fill(nr, nc);
        
            //page[nr][nc] = ' ';
    }
}


int main(){
    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 200; j++){
             visited[i][j] = 0;
        }
    }
    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 200; j++){
             visited2[i][j] = 0;
        }
    }

    cin >> H >> W;

    //string row;
    char row[W];

    cin.get();
    for (int i = 0; i < H; ++i){
        getline(cin, page[i]);
        //cout << page[i] << endl;
        //cout << i << " ";
    }

    //string page_copy[200];

    for (int r = 0; r < H; ++r){
        for (int c = 0; c < W; ++c){
            if ((page[r][c] != '?') && (page[r][c] != '!') && (page[r][c] != ' ') && (page[r][c] != '+') && (page[r][c] != '.') && (page[r][c] != ',') && (!isalnum(page[r][c]))){
                //for (int i = 0; i < 200; i++){
                  //  for (int j = 0; j < 200; j++){
                    //    visited[i][j] = 0;
                    //}
                //}
                if (in_image(r,c)){
                   /* for (int i = 0; i < 200; i++){
                        for (int j = 0; j < 200; j++){
                            visited2[i][j] = 0;
                        }
                    }*/
                    flood_fill(r,c);    
               }
            }
        }
    }

    // Print out page without ads
    for (int r = 0; r < H; ++r){
        cout << page[r] << '\n';
    }

    return 0;

}


// THROW AWAY

/*for (int i = 0; i < H; i++){
                    page_copy[i] = page[i];
                }
               seen_border = false;
                flood_fill(r, c);
                if (!seen_border){
                    for (int i = 0; i < H; i++){
                        page_copy[i] = page[i];
*/  
