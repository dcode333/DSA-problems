 Searching:

 Binary Search:
   time Complexity => o(logn)
 Linear Search:  
   time Complexity => o(n)

Sorting:

 Selection Sort:
    Worst   => O(n2)
    Average => O(n2)
 Bubble Sort:
    O(n²) in the average and worst cases
    O(n) in the best case 
 Insersion Sort:
   Time Complexity is
        If the inversion count is O(n), 
        then the time complexity of insertion sort is O(n).

    Some Facts about insertion sort:
    2. Efficient for (quite) small data sets, much like other quadratic sorting algorithms
    3. More efficient in practice than most other simple quadratic (i.e., O(n2)) 
    algorithms such as selection sort or bubble sort
    4. Adaptive, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(kn)
    when each element in the input is no more than k places away from its sorted position
    5. Stable; i.e., does not change the relative order of elements with equal keys
    6. In-place; i.e., only requires a constant amount O(1) of additional memory space
    Online; i.e., can sort a list as it receives it   
 Merge Sort:
    => time complexity: nlogn (all cases)
    => explain: https://www.youtube.com/watch?v=4z9I6ZmeLOQ&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=46&t=107s
    => Merge sort can work well on any type of data sets irrespective of its size (either large or small)
 Quick Sort:
      => Time Complexity: 
            best: nlogn (if pivot point is the mid)
            worst: n^2 (if traversed n for pivot) 
      => Quick sort is more efficient and works faster than merge 
         sort in case of smaller array size or datasets.        
 Count Sort:
      => Time Complexity: 
            max(Ai,N)
      => This sorting technique is effective when the difference between different keys 
         are not so big, otherwise, it can increase the space complexity.
      => Counting sort is most efficient if the range of input values is not greater
         than the number of values to be sorted.  
 DNF Sort: 
    => Time Complexity: 0(n)        
    => for sorting array of only (0,1,2)
 Wave Sort:
    => Use to sort array in Wave manner like (big,small,big...)
    => Time Complexity: 0(n)     

Data Structures:

MultiSet: 
   Works like stack but can store the
   elems in descending or ascending order

TREES:
Max no of nodes at level L = 2^L
Max no of nodes at level height h = 2^h - 1
tree Indexing = 0 based indexing => left child(2 x i + 1) right child(2 x i + 2) 
