'''
Python implementation of Merge Sort
Time Complexity: O(nlog(n))
Author: D1Dayer99
'''

nums = [5,26,2,42,563,25,46,3,19]

def merge_sort(nums) -> list:
    '''
    Recursive implementation of Merge Sort
    1. Divide the unsorted list into n (length of the list) sublists, each containing one element
    2. Repeatedly merge the sublists
    '''
    if len(nums) ==1:
        return

    mid = len(nums)//2
    left = nums[:mid]
    right = nums[mid:]
    
    #Recursively dividing the list into sublists
    merge_sort(left)
    merge_sort(right)

    l_idx = 0
    r_idx = 0

    main_idx = 0

    #Compre the values of the left and right sublists
    while l_idx < len(left) and r_idx<len(right):
        if left[l_idx]<=right[r_idx]:
            nums[main_idx] = left[l_idx]
            l_idx+=1
        else:
            nums[main_idx] = right[r_idx]
            r_idx+=1
        
        main_idx+=1
    
    #If the left or right sublists is empty
    while r_idx<len(right):
        nums[main_idx] = right[r_idx]
        r_idx+=1
        main_idx+=1
        
    while l_idx<len(left):
        nums[main_idx] = left[l_idx]
        l_idx+=1
        main_idx+=1

    return nums

res= merge_sort(nums)
print(res)

