#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N; cin >> N;
    for (int j = 1; j <= N; j++){
        vector <int> students;
        int size = 1; int counter = 0;
        int stu;
        cin >> stu; students.push_back(stu);
        for (int i = 0; i < 19; i++){
            cin >> stu;
            for (auto it = students.end()--; it >= students.begin(); it--){
                if (stu > *it){
                    students.insert(it, stu);
                    break;
                }
                counter++;
            }
        }
        for (auto c : students)
            cout << c << " ";
        cout << endl;
        cout << j << " " << counter << '\n';
    }
}
