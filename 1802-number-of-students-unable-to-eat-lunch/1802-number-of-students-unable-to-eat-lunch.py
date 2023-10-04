#Counter approach :-
#Create a counter for student (that will store sandwich type, no. of students) Ex: { 0:2, 1:2 } 
#Whenever same sandwich decrement the number of students corresponding to the key 
#A point will come when myCounter[sandwich]. At that point simply break 
#Other wise keep decrementing by 1 
#Finally return the sum of values in the counter 

from collections import Counter
class Solution(object):
    def countStudents(self, students, sandwiches):
        myCounter = Counter(students)
        for sandwich in sandwiches:
            if myCounter[sandwich] == 0:
                break
            else:
                myCounter[sandwich] -= 1
        return sum(myCounter.values())
