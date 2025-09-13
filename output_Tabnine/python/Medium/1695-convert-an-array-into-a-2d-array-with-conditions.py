#https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
#You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
#	The 2D array should contain only the elements of the array nums.
#	Each row in the 2D array contains distinct integers.
#	The number of rows in the 2D array should be minimal.
#Return the resulting array. If there are multiple answers, return any of them.
#Note that the 2D array can have a different number of elements on each row.
# 
#Example 1:
#Input: nums = [1,3,4,1,2,3,1]
#Output: [[1,3,4,2],[1,3],[1]]
#Explanation: We can create a 2D array that contains the following rows:
#- 1,3,4,2
#- 1,3
#- 1
#All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
#It can be shown that we cannot have less than 3 rows in a valid array.
#Example 2:
#Input: nums = [1,2,3,4]
#Output: [[4,3,2,1]]
#Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
# 
#Constraints:
#	1 <= nums.length <= 200
#	1 <= nums[i] <= nums.length
class Solution(object):
    def findMatrix(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # Sort the numbers in ascending order
        nums.sort()
        
        # Initialize the 2D array with the first number
        matrix = [[nums[0]]]
        
        # Iterate through the remaining numbers
        for num in nums[1:]:
            # Check if the current number can be added to the last row of the matrix
            if matrix[-1][-1] < num:
                # If not, create a new row with the current number
                matrix.append([num])
            else:
                # If yes, find the last row with the smallest number greater than or equal to the current number
                for i in range(len(matrix) - 1, -1, -1):
                    if matrix[i][-1] >= num:
                        # Insert the current number in the found row
                        matrix[i].append(num)
                        break
        
        return matrix
        