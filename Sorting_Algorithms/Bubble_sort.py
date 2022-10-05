'''
Python Implementation of Bubble Sort
Time Complexity: O(n^2)
Author: D1Dayer99
'''
import random

class Bubble_Sort:
    '''
    1. Run a nested for loop to traverse the input array using two variables i and j
    2. If arr[j] is greater than arr[j+1], then swap the adjacent elements, else nothing
    '''
    def __init__(self):
        self.random_array = self.gen_array()
        self.sorted_array = self.sort_array()
    
    def gen_array(self) -> list:
        self.arr = []
        #Randomly generating 10 integers between 0 and 1000
        for i in range (10):
            self.arr.append(random.randint(0,1000))
        return self.arr

    def sort_array(self):
        #Nested loops performing the steps described above
        for i in range(len(self.random_array)**2):
            for j in range (len(self.random_array)-1):
                if self.random_array[j] > self.random_array[j+1]:
                    self.random_array[j],self.random_array[j+1] = self.random_array[j+1],self.random_array[j]
        print(self.random_array)

arr1 = Bubble_Sort()
