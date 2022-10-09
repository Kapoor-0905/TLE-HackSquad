package com.deepanshu.dsamaths;

import java.util.Scanner;

public class gcd{
    public static void main(String[] args) {
        long x,y;
        Scanner sc=new Scanner(System.in);
        x=sc.nextLong();
        y=sc.nextLong();
        long ans=GCD(x,y);
        System.out.println(ans);
    }
    static long GCD(long a,long b){
        if(a==0) return b;
        return GCD(b%a,a);
    }
}