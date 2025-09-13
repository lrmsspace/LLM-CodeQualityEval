#https://leetcode.com/problems/check-if-n-and-its-double-exist/
#Given an array arr of integers, check if there exist two indices i and j such that :
#	i != j
#	0 <= i, j < arr.length
#	arr[i] == 2 * arr[j]
# 
#Example 1:
#Input: arr = [10,2,5,3]
#Output: true
#Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
#Example 2:
#Input: arr = [3,1,7,11]
#Output: false
#Explanation: There is no i and j that satisfy the conditions.
# 
#Constraints:
#	2 <= arr.length <= 500
#	-103 <= arr[i] <= 103
class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        # Create a dictionary to store the frequency of each number
        freq_dict = {}
        
        # Iterate over the array and update the frequency dictionary
        for num in arr:
            freq_dict[num] = freq_dict.get(num, 0) + 1
        
        # Iterate over the array again
        for num in arr:
            # Check if the number is twice the other number
            if 2 * num in freq_dict:
                # If the frequency of the doubled number is greater than 1, return True
                if freq_dict[2 * num] > 1:
                    return True
        
        # If no pair of numbers satisfies the condition, return False
        return False
        