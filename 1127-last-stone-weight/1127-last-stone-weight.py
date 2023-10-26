#=====================================
# Using max heap and min heap concept
#=====================================
# We actually need a max heap as we need the largest two values
# But Python don't have max heap. So lets do it with a "min heap" and -ve numbers concept.It will convert the min heap to max heap :-
#       -Before push : x -> -x : 
#       -After pop : x -> -x
#- Before push: Converted all elements of the list to -ve : stones = [-s for s in stones]
#- Then i convert the list to a min heap :  heapq.heapify(stones)
#We have to stop when we have 1 or 0 stone : while len(stones) > 1:
#Then we pop X (first largest ):  first = heapq.heappop(stones)
#Then we pop Y (second largest ):  second = heapq.heappop(stones)
#--------------------------------
#If X> Y push X-Y to stones arr
#If Y> X push Y-X to stones arr :            
#Good way of writing it : if Y > X: heapq.heappush(stones, Y - X) 
#But we have to take -ve of this because we need max heap property . So -(Y-X) = X-Y)
#so we write : if Y > X: heapq.heappush(stones, X - Y) 
#-------------------------------

class Solution(object):
    def lastStoneWeight(self, stones):
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            first = heapq.heappop(stones)
            second = heapq.heappop(stones)
            if second > first:
                heapq.heappush(stones, first - second)

         # After the loop, there is at most one stone left
        if stones:
            return -stones[0]
        else:
            # No stones left
            return 0