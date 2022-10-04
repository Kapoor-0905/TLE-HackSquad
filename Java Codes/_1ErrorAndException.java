package _14ErrorAndException;

import java.util.Scanner;

public class _1ErrorAndException {
    public static void main(String[] args) {
        /*
            There are 3 type of error
            1. Syntax error
            2. Logical error
            3. Runtime error
        */

        // 1. Synatx error
        /*
        try {
            a = 10;
            int b = 4
            System.out.println(a+d);

        } catch (Exception e) {
            System.out.println(e);
        }
        */


        // 2.Logical error
        /*write a program to print all prime number between 1 and 10 but 9 is not prime,
        that means we implement wrong logic */

        /*
        System.out.println(2);
        for (int i = 1; i < 5; i++) {
            System.out.println(2 * i + 1);
        }
       */

        // 3. Runtime Error---> Exception error
        /* here a variable is must integer, if is not int then we will get runtime error
            so this type of error we can handle using try, catch and finally block
        */
        System.out.print("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();

        System.out.println("Calculation is " + 1000 / a);


    }
}
