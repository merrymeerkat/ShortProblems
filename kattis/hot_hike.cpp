/* Taken from Kattis.

In order to pass time during your vacation, you decided to go on a hike to visit a scenic lake up in the mountains. Hiking to the lake will take you a full day, then you will stay there for a day to rest and enjoy the scenery, and then spend another day hiking home, for a total of three days. However, the accursed weather this summer is ridiculously warm and sunny, and since severe dehydration is not at the top of your priority list you want to schedule the three-day trip during some days where the two hiking days are the least warm. In particular you want to minimize the maximum temperature during the two hiking days.
Given the current forecast of daily maximum temperatures during your vacation, what are the best days for your trip?

Input
The first line of input contains an integer n (3≤n≤50), the length of your vacation in days. Then follows a line containing n integers t1,t2,…,tn (−20≤ti≤40), where ti is the temperature forecast for the i’th day of your vacation.

Output
Output two integers d and t, where d is the best day to start your trip, and t is the resulting maximum temperature during the two hiking days. If there are many choices of d that minimize the value of t, then output the smallest such d. */

#include <iostream>

using namespace std;

int main()
{
  int length;
  cin >> length;

  // Storing all temperatures in an array
  int temperatures[length];
  for (int i = 0; i < length; i++)
  {                                                  
    cin >> temperatures[i];
    // cout << "\n" << temperatures[i]; // (printing for checking purposes)
  }

 
  // Possible number of hike day pairs
  int options = length - 2;

  // Array to store temperature tuples (i.e. possible hike days)
  pair <int,int> hike_days[length -2];
  for (int i = 0; i < options; i ++)
  {
    hike_days[i] = make_pair(temperatures[i], temperatures[i+2]);
  }


  int min_temp = 41;
  int day;

// Iterate over temperature pairs to find the one with the smallest maximum temperature
  for (int i = 0; i < options; i ++)
  {
    int tuple_max = max(hike_days[i].first, hike_days[i].second);
    if (tuple_max < min_temp)
    {
      min_temp = tuple_max;
      day = i + 1; // Add 1 because array index starts at 0
    }
  }

  cout << day << " ";
  cout << min_temp;
}
