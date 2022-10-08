----------------------------Brute Force(Using merge sort)--------------------------------------------------------------------------------------------------------------
O(NlogN) time complexity
O(1) space complexity 
 --------------------------Using count sort--------------------------------------------------------------------------------------------------------------------------- 
O(N)+O(N) time complexity 
O(1) space complexity 
--------------------------- DNF algo------------------------------------------------------------------------------------------------------------------------------------
//This algorithm is used to sort an array of 0s 1s and 2s without the use of extra space or sorting algorithms
//Most optimal solution
//O(n) time comlexity
//O(1) space complexity
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void sort012(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        switch (a[mid])
        {
        case 0:
            swap(a[low++], a[mid++]);
            continue;
        case 1:
            mid++;
            continue;
        case 2:
            swap(a[mid], a[high--]);
            continue;
        }
    }
}

int main()
{
    int t = 1;
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    //cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort012(a, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
}
