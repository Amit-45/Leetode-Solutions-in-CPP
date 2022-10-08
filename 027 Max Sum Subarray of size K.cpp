public:
long maximumSumSubarray(int K, vector<int> &Arr, int N)
{

  // sliding window approach

  // both pointers pointing to 0 index
  int i = 0;
  int j = 0;

  // max will store the maximum sum value
  long int maxi = INT_MIN;
  //sum taken to store sum array sum
  long int sum = 0;

  // Till j goess out of the array
  while (j < N)
  {
    // saare sum nikalte jaoo
    sum = sum + Arr[j];

    // size of window =j - i + 1
    //  sum tab matter karega when size of window == k hoga . Agar size of window chota hai  k sey ,  jst j ko increment karoo
    //  tab tak incremant karoo jab tak size of window ==k nhi ho jata
    if ((j - i + 1) < K)
    {
      j++;
    }

    // jab window ka size == k hoga
    // humko maximm sum store karna hai
    // phir iTH element ko delete karoo
    // phir window ko aage badhaoo (i++ and j++)
    else if ((j - i + 1) == K)
    {
      maxi = max(maxi, sum);
      sum = sum - Arr[i];
      i++;
      j++;
    }
  }
  return maxi;
}
}
;
