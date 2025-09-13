#https://leetcode.com/problems/longest-duplicate-substring/
#Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
#Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
# 
#Example 1:
#Input: s = "banana"
#Output: "ana"
#Example 2:
#Input: s = "abcd"
#Output: ""
# 
#Constraints:
#	2 <= s.length <= 3 * 104
#	s consists of lowercase English letters.
class Solution(object):
    def longestDupSubstring(self, s):
        """
        :type s: str
        :rtype: str
        """
        def check(length):
            hash_value = 0
            prime = 101  # a prime number
            base = 256  # ASCII value of 'a'
            
            # Create a hash value for the substring of length 'length'
            for i in range(length):
                hash_value = (base * hash_value + ord(s[i])) % prime
            
            # Set to store the starting indices of all substrings of length 'length'
            indices = set([0])
            
            # Hash value of the substring ending at index 'i'
            hash_value_i = hash_value
            
            # Check for potential duplicates
            for i in range(1, len(s) - length + 1):
                # Update the hash value for the next substring
                hash_value_i = (base * (hash_value_i - ord(s[i - 1]) * pow(base, length - 1, prime)) + ord(s[i + length - 1])) % prime
                
                # If the hash value is the same as any of the previously stored hash values,
                # then the substring of length 'length' starting at index 'i' is a duplicate
                if hash_value_i in indices:
                    return s[i:i + length]
                
                # Add the new starting index to the set
                indices.add(i)
        
        # Binary search to find the longest possible duplicate substring
        left = 1
        right = len(s)
        
        while left < right:
            mid = (left + right) // 2
            duplicate = check(mid)
            
            if duplicate:
                left = mid + 1
            else:
                right = mid
        
        return check(left - 1)
        