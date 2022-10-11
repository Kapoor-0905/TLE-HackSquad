class Solution {
    public int search(int[] nums, int target) {
        return BS(nums,0,nums.length-1,target);
    }
    public int BS(int[] nums,int s,int e,int target){
        if(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(target>nums[mid]){
                return BS(nums,mid+1,e,target);
            }else{
                return BS(nums,s,mid-1,target);
            }
        }else{
            return -1;
        }
    }
}