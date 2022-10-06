//Brute force(Using a visited array)
#include<bits/stdc++.h>

using namespace std;

int main() {
  vector < int > A {1,2,3,3,4,5,6,7};
  vector < int > B {3,3,4,4,5,8};

  vector < int > ans;
  vector < int > visited(B.size(), 0); // to maintain visited 
  int i = 0, j = 0;
  for (i = 0; i < A.size(); i++) {
    for (j = 0; j < B.size(); j++) {

      if (A[i] == B[j] && visited[j] == 0) { 
      //if element matches and has not been matched with any other before
        ans.push_back(B[j]);
        visited[j] = 1;

        break;
      } else if (B[j] > A[i]) break; 
        //because array is sorted , element will not be beyond this
    }
  }
  cout<<"The elements are: ";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

//Optimised Approach (Two pointer)
//Using vectors
#include<bits/stdc++.h>

using namespace std;

int main() {
  vector < int > A {1,2,3,3,4,5,6,7};
  vector < int > B {3,3,4,4,5,8};

   vector < int > ans;

  int i = 0, j = 0; // to traverse the arrays

  while (i < A.size() && j < B.size()) {
    if (A[i] < B[j]) { //if current element in i is smaller
      i++;
    } else if (B[j] < A[i]) {
      j++;
    } else {
      ans.push_back(A[i]); //both elements are equal
      i++;
      j++;
    }
  }
  cout<<"The elements are: ";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

//Optimised Approach (Two pointer)
//Using arrays
#include <bits/stdc++.h>
using namespace std;

int printIntersection(int a1[], int a2[], int m, int n)
{
    int i = 0;
    int j = 0;
    while (i < m && j < n)

    {
        if (a1[i] < a2[j])
            i++;
        else if (a1[i] > a2[j])
            j++;
        else
        {
            cout << a2[j++] << endl;
            i++;
        }
    }
}

int main()
{
    int a1[] = {1, 2, 4, 5, 6};
    int a2[] = {2, 3, 5, 7};

    int m = sizeof(a1) / sizeof(a1[0]);
    int n = sizeof(a2) / sizeof(a2[0]);

    printIntersection(a1, a2, m, n);
}
