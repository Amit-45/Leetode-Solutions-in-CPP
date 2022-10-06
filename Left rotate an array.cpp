void leftRotate(int arr[], int n, int d) {
       reverse(arr,0,d-1); // Reverse last d elements
       reverse(arr,d,n-1); // Reverse first n-d elements
       reverse(arr,0,n-1); // Reverse whole array
    }
    
     void rightRotate(int arr[], int n, int d) {
          reverse(arr,0,n-d-1); // Reverse first n-d elements
          reverse(arr,n-d,n-1); // Reverse last d elements
          reverse(arr,0,d-1); // Reverse whole array
     }
     
     
    
    int reverse(int arr[], int low, int high)
    {  
        while (low < high)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
     }
     
     void rightRotateLeetcode(vector<int>& nums, int k) 
     {
      int n=nums.size();       //size of nums array 
      vector<int> temp(n);    //temp vector created to prevent any type of over writes
         
      //using the % formula(remember we are performing operations in nums array but storing in temp)
        for(int i=0;i<n;i++)
        {
            temp[(i+k)%n]=nums[i];
        }
        nums=temp;  //finally copying all the temp array elements into the nums array 

        
    }
