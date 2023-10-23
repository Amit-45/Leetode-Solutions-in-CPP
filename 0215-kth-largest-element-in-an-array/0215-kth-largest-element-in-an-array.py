# ==============================================
# Solution 2: Using max heap and min heap concept
# ==============================================
# -1. Store the first K elements of the array into the min heap : if len(min_heap) < k: heapq.heappush(min_heap, el)
# -2. For the remaining elements of the array : 
#     - if the element of array is greater than topmost element of heap : if min_heap[0] < el:   
#         - Delete from the Heap (POP)   : heapq.heappop(min_heap)
#         - Insert this element into the heap : heapq.heappush(min_heap, el)
# -3.This way, in the end only the K - Largest elements of the array are stored in the heap
# -4.With the Kth smallest element being on the top as this is a MIN HEAP : return min_heap[0] 

#===============Time complexity====================
# TC: O(n logn) X O(n-k) log n 
# SC: O(k) 

import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
        min_heap = []
        for el in nums:
            if len(min_heap) < k:
                heapq.heappush(min_heap, el)
            else:
                if min_heap[0] < el:             
                    heapq.heappop(min_heap)
                    heapq.heappush(min_heap, el)
        return min_heap[0]





