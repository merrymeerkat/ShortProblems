
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int one(int N, vector<int> numbers);
int unique(int N, vector<int> numbers); // Sorted
int frequent(int N, vector<int> numbers); // Sorted
int median(int N, vector<int> numbers); // Sorted
int range(int N, vector <int> numbers); // Sorted

int main(){

    int N, t; cin >> N >> t;

    vector<int> numbers;

    int number;
    for (int i = 0; i < N; ++i){
        cin >> number;
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end());
    
    switch(t){
        case 1:
            one(N, numbers);
            break;
        case 2:
            unique(N, numbers);
            break;
        case 3:
            frequent(N, numbers);
            break;
        case 4:
            median(N, numbers);
            break;
        case 5:
            range(N, numbers);
            break;
    }
    return 0;
}


int one(int N, vector<int> numbers){
    int a, b;
   
    // Keep track of two ends of the vector
    a = 0; b = N - 1;

    while(N--){
        int left = numbers.at(a); int right = numbers.at(b);
        
        if (a == b){break;} //we have traversed the entire vector and there is no solution
        
        if(left + right == 7777){
            cout << "Yes\n";
            return 0;
            }
         //technically we should also check whether x != y
         //but in reality we know that they are different, since
        // no two equal ints add up to an odd number
        if (left + right < 7777){
            ++a;
        }
        if (left + right > 7777){
            --b;
        }
    }
    cout << "No\n";
    return 0;
}


int unique(int N, vector<int> numbers){
    int last_seen = numbers.at(0);
    for (int i = 1; i < N; ++i){
        if (numbers.at(i) == last_seen){
            cout << "Contains duplicate\n";
            return 0;
        }
        last_seen = numbers.at(i);
    }
    cout << "Unique\n";
    return 0;
}

int frequent(int N, vector <int> numbers){
    int counter = 1;
    int last_seen = numbers.at(0);

    for (int i = 1; i < N; ++i){
        if (numbers.at(i) == last_seen){
            counter++;
        }

        if (counter > N/2){
            cout << numbers.at(i) << "\n";
            return 0;
        }
        last_seen = numbers.at(i);
    }
    
    cout << -1 << "\n";
    return 0;
}

int median(int N, vector <int> numbers){
    bool odd = true;
    if (N%2 == 0){
        odd = false;
    }
    int middle_ish = N/2;
    if (odd){
        cout << numbers.at(middle_ish) << "\n";
    }
    else{
        cout << numbers.at(middle_ish - 1) << " " << numbers.at(middle_ish) << "\n";
    }
    return 0;
}

int range(int N, vector <int> numbers){
    for (int i = 0; i < N; i++){
        if (numbers.at(i) >= 100 && numbers.at(i) <= 999){
            cout << numbers.at(i) << " ";
        }
    }
    return 0;
}
