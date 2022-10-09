package com.deepanshu.dsamaths;

import java.util.Scanner;

public class sieve {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        boolean[] primes=new boolean[n+1];
        seive(n,primes);
        for(int i=2;i<=n;i++){
            if(!primes[i]) System.out.print(i+" ");
        }
    }
    // false in array means number is prime, make the multiple of prime equal to true
    static void seive(int n, boolean[] primes){
        for(int i=2;i*i<=n;i++){
            if(!primes[i]){
                for(int j=i*2;j<=n;j+=i){
                    primes[j]=true;
                }
            }
        }    
    }
}
