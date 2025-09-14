#https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
#Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
# 
#Example 1:
#Input: s = "eleetminicoworoep"
#Output: 13
#Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
#Example 2:
#Input: s = "leetcodeisgreat"
#Output: 5
#Explanation: The longest substring is "leetc" which contains two e's.
#Example 3:
#Input: s = "bcbcbc"
#Output: 6
#Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
# 
#Constraints:
#	1 <= s.length <= 5 x 10^5
#	s contains only lowercase English letters.
class Solution(object):
    def findTheLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize a dictionary to store the last seen index of each vowel
        last_seen = {'a': -1, 'e': -1, 'i': -1, 'o': -1, 'u': -1}
        # Initialize a variable to keep track of the current state of vowels
        state = 0
        # Initialize a variable to keep track of the maximum length of the substring found so far
        max_length = 0
        
        # Iterate through the string and update the state based on the vowels encountered
        for i, char in enumerate(s):
            if char in last_seen:
                # Toggle the bit corresponding to the vowel encountered
                state ^= (1 << (ord(char) - ord('a')))
                # Update the last seen index for this vowel
                last_seen[char] = i

            # Check if the current state has been seen before
            if state in last_seen.values():
                # Calculate the length of the substring from the last seen index to the current index
                max_length = max(max_length, i - min(last_seen.values()))
        
        return max_length        