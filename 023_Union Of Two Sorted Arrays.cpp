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
  for (int i = 0; i < n; i++)
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
//using set
class Solution
{
public:
  vector<int> findUnion(int arr1[], int arr2[], int n, int m)
  {

    set<int> s;
    vector<int> Union;
    for (int i = 0; i < n; i++)
      s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
      s.insert(arr2[i]);
    for (auto &it : s)
      Union.push_back(it);
    return Union;
  }
};

//Set approach(explained)
#include <bits/stdc++.h>

using namespace std;
int main()
{
  // array elements
  int arr1[] = {1, 2, 3, 4, 5};
  int n = 5;
  int arr2[] = {2, 3, 4, 4, 5, 10};
  int m = 6;

  // set to store  1st array elements
  set<int> s;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (auto &pair : s)
  {
    cout << pair << endl;
  }
  cout << endl;

  // set to store 2nd array elements (duplicates will not be stored)
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto &pair : s)
  {
    cout << pair << endl;
  }
  cout << endl;

  // pushing all key values to union vector
  vector<int> Union;
  for (auto &it : s)
    Union.push_back(it);

  // printing out the Union vector's elements
  for (auto &pair2 : Union)
  {
    cout << pair2 << endl;
  }
}


//Optimal approach(two pointer approach)
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i = 0, j = 0;
  vector<int> Union; // Union vector
  while (i < n && j < m)
  {
    if (arr1[i] < arr2[j]) // Case 1  i<j
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    }
    else if (arr1[i] == arr2[j]) // Case 2 i=j
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
      j++;
    }
    else // case 3 j<i
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  
  //returning the elements of the bigger array
  while (i < n) 
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) 
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
       
    }



};




