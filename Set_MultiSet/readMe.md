----------------------SETS-------------------
=> Sets are implemented using a binary search tree.
=> A Set stores the elements in sorted order.
=> Set stores unique elements.
=> Elements can only be inserted and deleted but cannot be modified
within the set.(the values are immutable)
=> Sets are traversed using iterators (random access not possible)

upper_bound():
=> returns an iterator pointing to the immediate next element which is just greater than k
=> If the key passed in the parameter exceeds the maximum key in the container, then the iterator points to end()

lower_bound():
=> returns an iterator pointing to the element in the container which is equivalent to k passed
=> In case k is not present in the set container, the function returns an iterator pointing to the immediate next element which is just greater than k.
=> If the key passed in the parameter exceeds the maximum key in the container, then the iterator points to end()

(Complexities):
Insertion: log n
Deletion: log n
Lower/upper: log n

----------------------MULTISETS-------------------
=> MultiSets are implemented using a balanced binary search tree.
=> Can stores duplicate values
=> ...set

----------------------Unordered SETS-------------------

1.Unordered Set stores elements in an unsorted order
2.Unordered Set stores/acquire only unique values
3.Unordered Set uses Hash Tables for implementation
4.We can erase that element for which the iterator position is given

(Complexities)
Insertion: 1 avg
Deletion:  1 avg
