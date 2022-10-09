package com.deepanshu.sortingalgo;

import java.util.Arrays;

public class SelectionSort {
    public static void main(String[] args) {
        int[] arr= new int[]{10, 9, 8, 7, 6};
        sort(arr,arr.length,0,0);
        System.out.println(Arrays.toString(arr));
    }
    //    Selection Sort using com.deepanshu.practice.recursion, max is used here as index
    static void sort(int[] arr,int len,int index,int max){
        if(len==0) return;
        if(index<len){
            if(arr[index]>arr[max]){
                sort(arr,len,index+1,index);
            }else{
                sort(arr,len,index+1,max);
            }
        }else{
            int temp=arr[max];
            arr[max]=arr[index-1];
            arr[index-1]=temp;
            sort(arr,len-1,0,0);
        }
    }
}
