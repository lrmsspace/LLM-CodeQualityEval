#https://leetcode.com/problems/group-anagrams/
#Given an array of strings strs, group the anagrams together. You can return the answer in any order.
# 
#Example 1:
#Input: strs = ["eat","tea","tan","ate","nat","bat"]
#Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
#Explanation:
#	There is no string in strs that can be rearranged to form "bat".
#	The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
#	The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
#Example 2:
#Input: strs = [""]
#Output: [[""]]
#Example 3:
#Input: strs = ["a"]
#Output: [["a"]]
# 
#Constraints:
#	1 <= strs.length <= 104
#	0 <= strs[i].length <= 100
#	strs[i] consists of lowercase English letters.
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        # Create an empty dictionary to store the groups of anagrams
        anagram_groups = {}
        
        # Iterate over each string in the input list
        for string in strs:
            # Sort the characters in the string to create anagrams
            sorted_string = ''.join(sorted(string))
            
            # If the sorted string is already a key in the dictionary, append the current string to its value
            if sorted_string in anagram_groups:
                anagram_groups[sorted_string].append(string)
            # If the sorted string is not a key in the dictionary, create a new list with the current string
            else:
                anagram_groups[sorted_string] = [string]
        
        # Convert the dictionary values (which are lists of anagrams) to a list of lists and return it
        return list(anagram_groups.values())
        