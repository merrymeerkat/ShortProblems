#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;

void count_sort(int initial[], int n, int place);
int count_digits(int n);
int get_max(int arr[], int n);
void radix_sort(int arr[], int n);

int sequence[1000000];
int output[1000000];
long long V[30] = { 0 };

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int TC; cin >> TC;

    for (int j = 0; j < TC; ++j){
        int N; cin >> N;

        long long A, B, C, X, Y;
        cin >> A >> B >> C >> X >> Y;
           
        sequence[0] = A;

        // Generating magic sequence
        for (int i = 1; i < N; ++i){
            sequence[i] = ((long long) sequence[i - 1] * B + A)% C;
        }

        // Sorting magic sequence
        radix_sort(sequence, N);

        // Hashing R
        V[j] = 0;
        for (int i = 0; i < N; ++i){
           V[j] = ((long long) V[j] * X + sequence[i])% Y;
        }
    }

    // Printing out results
    for (int i = 0; i < TC; ++i){
        cout << V[i] << "\n";
    }

    return 0;
}


void count_sort(int initial[], int output[], int n, int place){
    
    int count[31623] = { 0 };

    for (int i = 0; i < n; ++i){
        count[ (initial[i]/place) % 31623]++;
    }

    // Turn count into a running sum 
    for (int i = 1; i <  31623; ++i){
        count[i] += count[i-1];
    }

    int digit;
    // Based on the value in count for the relevant digit of each number,
    // we can insert the number in the output array at the desired position.
    // We iterate from right to left to maintain stability.
    for (int i = n - 1; i > -1; --i){
        digit = (initial[i]/place) % 31623;

        count[digit]--;

        output[count[digit]] = initial[i];
    }

}


void radix_sort(int arr[], int n){  
    //we only need two passes
    count_sort(arr, output, n, 1);
    count_sort(output, arr, n, 31623);
}
