#https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
#Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
#The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
#Any two characters may be swapped, even if they are not adjacent.
# 
#Example 1:
#Input: s = "111000"
#Output: 1
#Explanation: Swap positions 1 and 4: "111000" -> "101010"
#The string is now alternating.
#Example 2:
#Input: s = "010"
#Output: 0
#Explanation: The string is already alternating, no swaps are needed.
#Example 3:
#Input: s = "1110"
#Output: -1
# 
#Constraints:
#	1 <= s.length <= 1000
#	s[i] is either '0' or '1'.
class Solution(object):
    def minSwaps(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Count the number of 0s and 1s
        count_0 = s.count('0')
        count_1 = s.count('1')
        
        # If the count of 0s and 1s are not equal, it's impossible to make the string alternating
        if count_0!= count_1:
            return -1
        
        # Initialize the minimum number of swaps
        min_swaps = 0
        
        # Iterate through the string, looking for pairs of adjacent 0s or 1s
        for i in range(len(s) - 1):
            # If the current pair is not alternating, find the next pair that is alternating
            if s[i]!= s[i + 1]:
                # Find the next 0 or 1 in the string that is adjacent to the current pair
                next_0 = next((j for j in range(i + 1, len(s)) if s[j] == '0'), len(s))
                next_1 = next((j for j in range(i + 1, len(s)) if s[j] == '1'), len(s))
                
                # Swap the positions of the next 0 or 1 with the current pair
                s = s[:i] + s[next_0] + s[i + 1:next_1] + s[i] + s[next_1 + 1:]
                
                # Increment the minimum number of swaps
                min_swaps += 1
        
        return min_swaps
        