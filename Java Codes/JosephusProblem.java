
/**
 * Josephus Problem is described as follows:
 * Suppose there are n people sitting in a circle numbered 1 to n
 * We start from 1 intially and kill every kth person and then we repeat this
 * process from the person next to the one killed
 * we do this until there is only 1 person left in the circle.
 * in the end we are required to return the intial position x such that person
 * sitting on the xth position in the beginning is the one that survives till
 * the end
 * 
 */

public class JosephusProblem {

    public static void main(String[] args) {
        // intially pass n: number of persons sitting in the person , and k: (such that
        // kth person is killed in every turn)
        System.out.println(josephus(7, 4));
    }

    private static int josephus(int n, int k) {
        // returns the reequired position
        if (n == 1)
            return 0;

        int death = (k - 1) % n;

        int nextStart = (death + 1) % n;

        int ans = josephus(n - 1, k);

        int res = (nextStart + ans) % n;

        return res;
    }

}
