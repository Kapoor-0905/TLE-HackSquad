class Solution {
    public int addDigits(int n) {
        int sum=n;
        while(sum>9){
            sum=0;
            while(n!=0){
                sum+=n%10;
                n/=10;
            }
            n=sum;
        }
        return sum;
    }
}