'''
Python Implementation of Selection Sort
Time Complexity: O(n^2)
Author: D1Dayer 99
'''
import random

class Selection_Sort:
    '''
    1. Set minimum value at index 0
    2. Traverse the array, if an element is smaller than the minimum index, swap
    3. Increment minimum index
    '''
    def __init__(self):
        self.random_array = self.gen_array()
        self.sorted_array = self.sort_array()

    def gen_array(self) -> list:
        #Randomly generate 10 integers between 0 and 1000
        self.arr = []
        for i in range (10):
            self.arr.append(random.randint(0,1000))
        return self.arr

    def sort_array(self):
        #Nested loops performing the steps mentioned above
        for i in range(len(self.random_array)):
            min_idx = i
            for j in range(i+1,len(self.random_array)):
                if self.random_array[min_idx] > self.random_array[j]:
                    self.random_array[min_idx], self.random_array[j] = self.random_array[j], self.random_array[min_idx]
        print(self.random_array)

arr1 = Selection_Sort()
