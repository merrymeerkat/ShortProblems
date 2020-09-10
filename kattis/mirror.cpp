
#include <iostream>
#include <string>
using namespace std;

int main(){

    // Number of test cases
    int t; cin >> t;

    // Arrays to store number of rows and columns for each test case
    int r[t], c[t];
    
    // Each image can have up to 20 rows and up to 20 columns
    char image[t][20][20];
   
    // For each test case
    for (int k = 0; k < t; k++){

        cin >> r[k]; // Get and store number of rows
        cin >> c[k]; // Get and store  number of columns
        
        // Get and store image
        for (int i = 0; i < r[k]; ++i){
             for (int j = 0; j < c[k]; ++j){
                 cin >> image[k][i][j];
             }
         } 
    }


    // Print mirrored image
    for (int k = 0; k < t; k ++){
        cout << "Test " << k + 1 << "\n";
        for (int i = r[k] - 1; i >= 0; --i) {
            for (int j = c[k] - 1; j >= 0; --j)
            {
                cout << image[k][i][j];
            }
            cout << "\n";
         }
     }    
    return 0;
}
