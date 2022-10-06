//Using map 
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
  {

    map<int, int> freq;
    for (int i = 0; i < n; i++)
      freq[arr1[i]]++;
    for (int i = 0; i < m; i++)
      freq[arr2[i]]++;

    vector<int> Union;
    for (auto &pair : freq)
      Union.push_back(pair.first);

    return Union;
  }

//map approach(explained)
#include <bits/stdc++.h>

using namespace std;
int main()
{
  // array elements
  int arr1[] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 3};
  int n = 10;
  int arr2[] = {7, 8, 8, 9, 10, 11, 12};
  int m = 7;

  // freq map to store frequency of 1st array elements
  map<int, int> freq;
  for (int i = 0; i < 10; i++)
    freq[arr1[i]]++;
  for (auto &pair : freq)
  {
    cout << pair.first << " " << pair.second << endl;
  }
  cout << endl;

  // same freq map to store frequency of 2nd array elements as well because 1 key points to one value only
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto &pair : freq)
  {
    cout << pair.first << " " << pair.second << endl;
  }
  cout << endl;

  // pushing all key values to union vector
  vector<int> Union;
  for (auto &pair : freq)
    Union.push_back(pair.first);

  // printing out the Union vector's elements
  for (auto &pair : Union)
  {
    cout << pair << endl;
  }
}



