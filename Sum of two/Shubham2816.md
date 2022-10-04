##### The two sum problem is a version of the subset sum problem and is a common programming question. 


- class Solution(object):
- def twoSum(self, nums, target):


-  for i in nums:
-     num1 = target - i
-     if num1 in nums[nums.index(i)+1::]:
-         return [nums.index(i), nums.index(num1,nums.index(i)+1,len(nums))]
