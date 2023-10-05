#Merge sort TC(nlogn) SC(n)
#Summary : Divide the array, Check for base case =1 Other wise call MergeSort for left and right part, Then call merge to merge these two,Return arr, At last return the mergeSort for whole array 
#Main merge function approach: Create copies of l and r, figure out which is smaller, Push it into main array and update pointers accordingly, At last if any of the subarray left with elements push into the main array , Again update pointers
# -----------------------------------------------------------------------
#We know merge sort is recursive algorithm
#So we create a function called merge sort with param(array, left and right index to determine what portion of subarray are we running merge sort on)
#Now we need to keep dividing this and to do it inplace we can use pointers
#Main base case is that what if size of array is 1? In that case return array directly : if l==r return arr
#If base case does not satisy we will do the recursion
#So we will run merge sort for the left and right part of the array .How to do that ? We have to supply the array and we also have to supply left and right boundaries that defines the sub array.
#The right boundary of the left sub array will be somewhere between the left and right boundary and we can calculate by m =(l+r//2)
#mergeSort(arr,l,m)
#Then we call merge sort to the right part of the array 
#The left boundary of the right sub array will be somewhere between the left and right
#mergeSort(arr,m+1, r)
# ---------------------------------------------------------------
#After merge sort on the left and right part there comes the tricky part 
#Now lets create a merge function that is going to merge these two subarray parts merge(arr,l,m,r)
#Then we return the arr
#At last return the mergeSort(nums,0,lenght()-1) : Merge sort on the whole array 
#--------------------merge function------------------------------
#Now our task is to complete the mergeSort function that merges the two sub arrays using 2 pointers
#Now first steps first lets create copies of left and right pointers
#left, right = arr[L: M+1], right=[M+1: R+1]. (left subarray starts form l till mid ) (right subarray starts from mid+1 till end of array)
#Now we will keep the 3 pointers i,j and k 
#i,j,k = L,0,0 (i ponter acts as the 3rd pointer that points to the main array) (j,k pointer act as 1st and 2nd pointer that points to the first element of each subarray)

#For the actual merge part 
#First use a while loop and check that j and k always stay within array : while j<len(left) and k<len(right):
#Now figure out which one has the smaller value and insert that value into input array 
#So if left[j]<=right[k]: 
#Then the left value goes into the array  : arr[i]=left[j]
#Also we increase the j pointer as it is already used (refer notes): j+=1
#Also we need to increase the i pointer but we will do that depending on the if statement that which is smaller l or r 
#Similarly if the right value is smaller value then insert that value into the input array
#else : (basicaly it checks for the condition right[k]<=left[j])
#Then the right value goes into the array  : arr[i]=right[k]
#Also we increase the k pointer as it is already used (refer notes): k+=1
#At last as we said we will increment i depending on which of the if statement satisfies that which is smaller l or r : i+=1

# ----------Finally if any of the pointer gets out of bound and if either the left or the right part has some value left -------------------
#Put the remaining elements into the main array 
#Lets first assume left part has some values remaining  : while j<len(left)
#Then add these values from the left subarray to the main array : arr[i] = left[j]
#Similarly if we assume right part  has some values remaining : while j<len(right)
#Then add these values from the right subarray to the main array : nums[i]= right[k]
#At last increment i and j for both the cases after we add into the array : For each while loop add : j+=1 and i+=1


class Solution(object):
    def sortArray(self, nums):
        def merge(arr, L, M, R):
            left, right = arr[L:M+1], arr[M+1:R+1]
            i, j, k = L, 0, 0
            while j < len(left) and k < len(right):
                if left[j] <= right[k]:
                    arr[i] = left[j]
                    j += 1
                else:
                    arr[i] = right[k]
                    k += 1
                i += 1
            while j < len(left):
                arr[i] = left[j]
                j += 1
                i += 1
            while k < len(right):
                arr[i] = right[k]
                k += 1
                i += 1

        def mergeSort(arr, l, r):
            if l == r:
                return arr
            m = (l + r) // 2
            mergeSort(arr, l, m)
            mergeSort(arr, m + 1, r)
            merge(arr, l, m, r)
            return arr
        
        return mergeSort(nums, 0, len(nums) - 1)
        