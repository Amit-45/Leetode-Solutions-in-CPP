#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int index = 0; index < n; index++)
    {
        cin >> arr[index];
    }
    vector<int> cum_arr(n, 0);
    cum_arr[0] = arr[0];
    for (int index = 1; index < n; index++)
    {
        cum_arr[index] = cum_arr[index - 1] + arr[index];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int start, end;
        cin >> start;
        cin >> end;
        if (start == 0)
        {
            cout << cum_arr[end] << endl;
        }
        else
            cout << cum_arr[end] - cum_arr[start - 1];
    }
}
