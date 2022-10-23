import java.util.*;
public class Fibonacci
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n1=0;
        int n2=1;
        int n3;
        System.out.println("Enter Count :");
        int count=sc.nextInt();
        System.out.println(n1+" "+n2);
        for(int i=2;i<=count;i++)
        {
            n3=n1+n2;
            System.out.print(" "+n3);
            n1=n2;
            n2=n3;
        }
    }
}
