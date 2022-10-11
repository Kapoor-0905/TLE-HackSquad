class Solution {
    public int maxProfit(int[] prices) {
        int len=prices.length;
        int min=100000,ans=0,temp=0;
        for(int i=0;i<len;i++){
            if(min>prices[i]){
                min=prices[i];
            }
            temp=prices[i]-min;
            if(temp>ans){
                ans=temp;
            }
        }
        return ans;
    }
}