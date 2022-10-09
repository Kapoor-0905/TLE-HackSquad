package com.deepanshu.sortingalgo;

import java.util.Arrays;

public class insertion_sort {
    public static void main(String[] args) {
        int[] arr=new int[]{10,9,8,7,6,5,4,3,2,1};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }

    private static void sort(int[] arr) {
        int key=0,i=0;
        for(int j=1;j<arr.length;j++){
            key=arr[j];
            i=j-1;
            while(i>=0 && arr[i]>key){
                arr[i+1]=arr[i];
                i=i-1;
            }
            arr[i+1]=key;
        }
    }
}
