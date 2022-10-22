// Converting a decimal number into binary in Java using while loop.
// By Soham Gupta (http://github.com/gupta-soham/) (https://www.linkedin.com/in/soham-gupta-in/)
import java.util.*;
public class Factorial {
    public static void main(String[] args) {
        int num;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a positive number: ");
        num = sc.nextInt();

        int fact = 1;
        for(int i=1; i<=num; i++) {
            fact *= i;
        }

        System.out.println("Factorial of " + num + " = " + fact);
    }
}