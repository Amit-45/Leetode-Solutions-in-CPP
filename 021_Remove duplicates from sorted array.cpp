//Brute force(using set)
class Solution
{
public:
  int remove_duplicate(int a[], int n)
  {
    set<int> set;
    for (int i = 0; i < n; i++)
    {
      set.insert(a[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set)
    {
      a[j++] = x;
    }
    return k;
  }
};

//Optimal approach(two pointer)
class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int i = 0;
    int n = nums.size();
    for (int j = 1; j < n; j++)
    {
      if (nums[i] != nums[j])
      {
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};
