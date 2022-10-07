//Optimal approach
//Start traversing from the first occurrence index of Zero 
//Tak 2 variables (i,j), i will be at the first occurrence of zero and j is at i+1 
 //If element at j index is not zero then swap elements at i,j and increment i,j
//If the element at j index is zero then only increment j.

void zerosToEnd(int arr[], int n)
{

  // finding first zero occurrence
  int k = 0;
  while (k < n)
  {
    if (arr[k] == 0)
    {

      break;
    }
    else
    {
      k = k + 1;
    }
  }

  int i = k, j = k + 1;

  while (i < n && j < n)
  {
    // if non zero element swap , then increment i,incerment j
    if (arr[j] != 0)
    {
      swap(arr[i], arr[j]);
      i++;
    }

    j++;
  }
  for (i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}
