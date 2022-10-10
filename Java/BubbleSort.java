package com.deepanshu.sortingalgo;

import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arr= new int[]{10, 9, 8, 7, 6};
        sort(arr,arr.length-1,0);
        System.out.println(Arrays.toString(arr));
    }
//    Bubble Sort using com.deepanshu.practice.recursion
    static void sort(int[] arr,int len,int index){
        if(len==0) return;
        if(index<len){
            if(arr[index]>arr[index+1]){
                int temp=arr[index];
                arr[index]=arr[index+1];
                arr[index+1]=temp;
            }
            sort(arr,len,index+1);
        }else{
            sort(arr,len-1,0);
        }
    }
}
