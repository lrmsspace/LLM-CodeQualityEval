#https://leetcode.com/problems/duplicate-zeros/
#Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
#Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
# 
#Example 1:
#Input: arr = [1,0,2,3,0,4,5,0]
#Output: [1,0,0,2,3,0,0,4]
#Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
#Example 2:
#Input: arr = [1,2,3]
#Output: [1,2,3]
#Explanation: After calling your function, the input array is modified to: [1,2,3]
# 
#Constraints:
#	1 <= arr.length <= 104
#	0 <= arr[i] <= 9
class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        possibleDups = 0
        length_ = len(arr) - 1
        # Step 1: Count the zeros
        for i in range(length_ + 1):
            # Stop when left spots are not enough to copy zeros
            if i > length_ - possibleDups:
                break
            # Edge case: This zero can't be duplicated. We have no more space,
            # as indicated by possibleDups > 0
            if arr[i] == 0:
                # Edge case: This zero can't be duplicated. We have no more space,
                # as indicated by possibleDups > 0
                if i == length_ - possibleDups:
                    arr[length_] = 0
                    length_ -= 1
                    possibleDups -= 1
                else:
                    possibleDups += 1
        # Step 2: Start backwards and duplicate zero
        lastNonZeroFoundAt = length_
        for i in range(length_, -1, -1):
            if arr[i] != 0:
                lastNonZeroFoundAt -= 1
                arr[lastNonZeroFoundAt] = arr[i]
            else:
                arr[lastNonZeroFoundAt - 1] = arr[lastNonZeroFoundAt]
                lastNonZeroFoundAt -= 2

        return
