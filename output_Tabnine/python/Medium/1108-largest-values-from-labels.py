#https://leetcode.com/problems/largest-values-from-labels/
#You are given n item's value and label as two integer arrays values and labels. You are also given two integers numWanted and useLimit.
#Your task is to find a subset of items with the maximum sum of their values such that:
#	The number of items is at most numWanted.
#	The number of items with the same label is at most useLimit.
#Return the maximum sum.
# 
#Example 1:
#Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
#Output: 9
#Explanation:
#The subset chosen is the first, third, and fifth items with the sum of values 5 + 3 + 1.
#Example 2:
#Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
#Output: 12
#Explanation:
#The subset chosen is the first, second, and third items with the sum of values 5 + 4 + 3.
#Example 3:
#Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
#Output: 16
#Explanation:
#The subset chosen is the first and fourth items with the sum of values 9 + 7.
# 
#Constraints:
#	n == values.length == labels.length
#	1 <= n <= 2 * 104
#	0 <= values[i], labels[i] <= 2 * 104
#	1 <= numWanted, useLimit <= n
class Solution(object):
    def largestValsFromLabels(self, values, labels, numWanted, useLimit):
        """
        :type values: List[int]
        :type labels: List[int]
        :type numWanted: int
        :type useLimit: int
        :rtype: int
        """
        # Create a dictionary to store the count of each label
        label_count = {}
        for label in labels:
            label_count[label] = label_count.get(label, 0) + 1
        
        # Sort the items based on their values in descending order and labels in ascending order
        items = sorted([(value, label) for value, label in zip(values, labels)], reverse=True)
        
        # Initialize the maximum sum and the current sum
        max_sum = 0
        current_sum = 0
        
        # Iterate over the sorted items
        for value, label in items:
            # Check if the current label count is within the use limit
            if label_count[label] <= useLimit:
                # Add the value to the current sum and increment the label count
                current_sum += value
                label_count[label] += 1
                
                # Check if the current sum is greater than the maximum sum
                if current_sum > max_sum:
                    # Update the maximum sum if necessary
                    max_sum = current_sum
                    # Check if the number of wanted items is reached
                    if numWanted == 0:
                        break
        
        # Return the maximum sum
        return max_sum
        