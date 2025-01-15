# Binary Search Algorithm

Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

*Time Complexity of Binary Search Algorithm is `O(log(n))`.*

## How Binary Search Works

1. **Initial Setup**: Start with two pointers, one at the beginning (`low`) and one at the end (`high`) of the list.
2. **Middle Element**: Find the middle element of the list.
3. **Comparison**:
   - If the middle element is equal to the target value, you've found the item.
   - If the middle element is greater than the target value, repeat the search on the left half of the list.
   - If the middle element is less than the target value, repeat the search on the right half of the list.
4. **Repeat**: Continue the process until the `low` pointer exceeds the `high` pointer, which means the target value is not in the list.

![Two Pointer Algorithm](BinarySearch.png)