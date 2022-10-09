package com.deepanshu.dsamaths;

import java.util.Scanner;

public class prime_number_optimised{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        // ranged prime from 1 to n
        for(int i=1;i<=n;i++){
            System.out.println(i+" "+isPrime(i));
        }
    }
    static boolean isPrime(int n){
        if(n<=1) return false;
        int i=2;
        while(i*i<=n){
            if(n%i==0) return false;
            i++;
        }
        return true;
    }
}