https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest


class Solution
  {
  public:
    int print2largest(int arr[], int n)
    {

      int max = INT_MIN;
      int secondMax = -1; //dont take this as INT_MIN

      for (int i = 0; i < n; i++)
      {
        if (max < arr[i])
          max = arr[i];
      }

      for (int i = 0; i < n; i++)
      {
        if (arr[i] > secondMax && arr[i] != max)
        {
          if (secondMax < arr[i])
            secondMax = arr[i];
        }
      }
      return secondMax;
    }
