#include <iostream>
#include <stack>
#include <string>

using namespace std;

char match_bracket(char bracket);

int main() {

    stack <char> opening;

    int N; cin >> N;
    cin.ignore();
    
    // Read string of brackets
    string input; getline(cin, input);

    int counter = -1;

    for(auto c: input){
        counter++;
        
        // If it is an opening bracket, push it to our stack
        if (c == '[' || c == '(' || c == '{'){
            opening.push(c);
        }

        // If it is a closing bracket
        else if (c == ')' || c == ']' || c == '}'){
            
            // If the stack is empty, we already know the string is "faulty" and we can return
            if (opening.empty()){
                cout << c << ' ' << counter << "\n";
                return 0;
            }

            // Else check whether the first element of the stack is equivalent to the current closing bracket            
             if (match_bracket(c) != opening.top()){
                cout << c << ' ' << counter << "\n";
                return 0;
            }

            // Then we pop the used opening bracket
            opening.pop();
        }
    }

    // No errors found
    cout << "ok so far\n";

}


// Given a closing bracket, outputs the matching opening bracket
char match_bracket(char bracket){
    char match;
    if (bracket == ')')
        match = '(';
    else if (bracket == ']')
        match = '[';
    else
        match = '{';
    
    return match;
}
