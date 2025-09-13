#https://leetcode.com/problems/three-equal-parts/
#You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
#If it is possible, return any [i, j] with i + 1 < j, such that:
#	arr[0], arr[1], ..., arr[i] is the first part,
#	arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
#	arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
#	All three parts have equal binary values.
#If it is not possible, return [-1, -1].
#Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
# 
#Example 1:
#Input: arr = [1,0,1,0,1]
#Output: [0,3]
#Example 2:
#Input: arr = [1,1,0,1,1]
#Output: [-1,-1]
#Example 3:
#Input: arr = [1,1,0,0,1]
#Output: [0,2]
# 
#Constraints:
#	3 <= arr.length <= 3 * 104
#	arr[i] is 0 or 1
class Solution(object):
    def threeEqualParts(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        # Count the number of 1's in the array
        count_ones = sum(arr)
        
        # If the number of 1's is not divisible by 3, return [-1, -1]
        if count_ones % 3 != 0:
            return [-1, -1]
        
        # If there are no 1's, return [0, len(arr) - 1]
        if count_ones == 0:
            return [0, len(arr) - 1]
        
        # Calculate the number of 1's in each part
        ones_per_part = count_ones // 3
        
        # Find the starting indices of each part
        first_part_start = second_part_start = third_part_start = None
        current_ones_count = 0
        
        for i in range(len(arr)):
            if arr[i] == 1:
                current_ones_count += 1
                if current_ones_count == 1:
                    first_part_start = i
                elif current_ones_count == ones_per_part + 1:
                    second_part_start = i
                elif current_ones_count == 2 * ones_per_part + 1:
                    third_part_start = i
        
        # Compare the three parts to check if they are equal
        while third_part_start < len(arr) and arr[first_part_start] == arr[second_part_start] == arr[third_part_start]:
            first_part_start += 1
            second_part_start += 1
            third_part_start += 1
        
        # If we reached the end of the array, return the indices of the last elements of the first two parts
        if third_part_start == len(arr):
            return [first_part_start - 1, second_part_start]
        
        return [-1, -1]        