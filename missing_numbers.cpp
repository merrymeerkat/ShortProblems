

#include <iostream>
#include <string.h>
using namespace std;

int counting(int length, int *arr);

int main(){
  int n; cin >> n;

  // Create array for input numbers
  int numbers[n];
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }
  
  // Check for missing numbers
  counting(n, numbers);
  return 0;
}

int counting(int length, int *arr){
  
  int last_seen; last_seen = 0;

  bool correct = true;
  for (int i = 0; i < length; i++)
  { 
    // if the two numbers are not consecutive
    if (arr[i] > last_seen + 1)
    {
      // will not print "good job"
      correct = false;

      int difference = arr[i] - last_seen;

      // prints as many missing numbers as needed
      for (int i = 1; i < difference; i++)
      {
        cout << last_seen + i << "\n";
      }
    }
    // update last_seen
    last_seen = arr[i];
  }

  if (correct) {cout << "good job\n";}
  return 1;
}
