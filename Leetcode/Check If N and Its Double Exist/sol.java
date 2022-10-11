import java.util.HashSet;

class Solution {
    public boolean checkIfExist(int[] arr) {
        HashSet<Integer> set=new HashSet<>();
        for(int i:arr){
            if(set.contains(i*2)||(i%2==0 && set.contains(i/2))){
                return true;
            }
            set.add(i);
        }
        return false;
    }
}