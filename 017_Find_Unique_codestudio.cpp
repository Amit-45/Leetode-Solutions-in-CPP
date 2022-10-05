Link -https://www.codingninjas.com/codestudio/problems/find-unique_625159?leftPanelTab=1
//Optimesed approach
int findUnique(int *arr, int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
      //Xoring all the elements
        ans=ans^arr[i];  
    }
    return ans;
}
