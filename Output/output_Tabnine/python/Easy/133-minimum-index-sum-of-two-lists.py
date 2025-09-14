#https://leetcode.com/problems/minimum-index-sum-of-two-lists/
#Given two arrays of strings list1 and list2, find the common strings with the least index sum.
#A common string is a string that appeared in both list1 and list2.
#A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.
#Return all the common strings with the least index sum. Return the answer in any order.
# 
#Example 1:
#Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
#Output: ["Shogun"]
#Explanation: The only common string is "Shogun".
#Example 2:
#Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
#Output: ["Shogun"]
#Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
#Example 3:
#Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
#Output: ["sad","happy"]
#Explanation: There are three common strings:
#"happy" with index sum = (0 + 1) = 1.
#"sad" with index sum = (1 + 0) = 1.
#"good" with index sum = (2 + 2) = 4.
#The strings with the least index sum are "sad" and "happy".
# 
#Constraints:
#	1 <= list1.length, list2.length <= 1000
#	1 <= list1[i].length, list2[i].length <= 30
#	list1[i] and list2[i] consist of spaces ' ' and English letters.
#	All the strings of list1 are unique.
#	All the strings of list2 are unique.
#	There is at least a common string between list1 and list2.
class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        # Create a dictionary to store the index of each string in list1
        index_dict = {word: i for i, word in enumerate(list1)}
        
        # Initialize the minimum index sum and the result list
        min_sum = float('inf')
        result = []
        
        # Iterate through list2 and check if each string is common to list1
        for i, word in enumerate(list2):
            # If the string is common and its index sum is less than the current minimum
            if word in index_dict and index_dict[word] + i < min_sum:
                # Update the minimum index sum and the result list
                min_sum = index_dict[word] + i
                result = [word]
            # If the string is common and its index sum is equal to the current minimum
            elif word in index_dict and index_dict[word] + i == min_sum:
                # Add the string to the result list
                result.append(word)
        
        return result
        
        