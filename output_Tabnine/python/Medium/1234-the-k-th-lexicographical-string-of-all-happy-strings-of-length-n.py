#https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
#A happy string is a string that:
#	consists only of letters of the set ['a', 'b', 'c'].
#	s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
#For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
#Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
#Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
# 
#Example 1:
#Input: n = 1, k = 3
#Output: "c"
#Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
#Example 2:
#Input: n = 1, k = 4
#Output: ""
#Explanation: There are only 3 happy strings of length 1.
#Example 3:
#Input: n = 3, k = 9
#Output: "cab"
#Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
# 
#Constraints:
#	1 <= n <= 10
#	1 <= k <= 100
class Solution(object):
    def getHappyString(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        # Define the alphabet and the base case
        alphabet = ['a', 'b', 'c']
        if n == 1:
            return alphabet[k - 1]
        
        # Initialize the result string
        result = ''
        
        # Define the helper function to generate the next happy string
        def generate_happy_string(current_string, remaining_length):
            # If the remaining length is 0, return the current string
            if remaining_length == 0:
                return current_string
            
            # Iterate over the remaining characters
            for char in alphabet:
                # If the current string doesn't contain the same character as the next character, add it to the result
                if char!= current_string[-1]:
                    next_string = current_string + char
                    # If the result string is still valid and the kth string is found, return it
                    if len(result) == 0 or next_string < result:
                        result = generate_happy_string(next_string, remaining_length - 1)
                        if len(result) == k:
                            return result
        
        # Generate the kth happy string
        return generate_happy_string(result, n - 1)
        