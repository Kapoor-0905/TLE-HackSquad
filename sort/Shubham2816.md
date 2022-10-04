## Buuble Sort Algorithm:

begin BubbleSort(arr)  

   for all array elements  
   
      if arr[i] > arr[i+1]  
      
         swap(arr[i], arr[i+1])  
         
      end if  
      
   end for     
   
   return arr    
   
end BubbleSort  


## Selection Sort Algorithm:

Step 1 − Set MIN to location 0

Step 2 − Search the minimum element in the list

Step 3 − Swap with value at location MIN

Step 4 − Increment MIN to point to next element

Step 5 − Repeat until list is sorted


## Merge Sort Algorithm:

MERGE_SORT(arr, beg, end)  
  
if beg < end  

set mid = (beg + end)/2  

MERGE_SORT(arr, beg, mid)  

MERGE_SORT(arr, mid + 1, end) 

MERGE (arr, beg, mid, end)  

end of if  
  
END MERGE_SORT  
