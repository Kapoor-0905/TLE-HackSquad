package com.deepanshu.dsamaths;

import java.util.Scanner;

public class lcm {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        System.out.println(LCM(a,b));
    }
    static long GCD(long a,long b){
        if(a==0) return b;
        return GCD(b%a,a);
    }
    static long LCM(long a,long b){
        return a*b/GCD(a, b);
    }
}
