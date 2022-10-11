class Solution {
    public int search(int[] nums, int target) {
        int l=0;
        int u=nums.length-1;
        while(l<=u){
            int mid=l+(u-l)/2;
            if(nums[mid]>target){
                u=mid-1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
}