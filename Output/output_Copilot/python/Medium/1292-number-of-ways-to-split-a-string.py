#https://leetcode.com/problems/number-of-ways-to-split-a-string/
#Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.
#Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.
# 
#Example 1:
#Input: s = "10101"
#Output: 4
#Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
#"1|010|1"
#"1|01|01"
#"10|10|1"
#"10|1|01"
#Example 2:
#Input: s = "1001"
#Output: 0
#Example 3:
#Input: s = "0000"
#Output: 3
#Explanation: There are three ways to split s in 3 parts.
#"0|0|00"
#"0|00|0"
#"00|0|0"
# 
#Constraints:
#	3 <= s.length <= 105
#	s[i] is either '0' or '1'.
class Solution(object):
    def numWays(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Count the number of '1's in the string
        ones_count = s.count('1')
        
        # If the number of '1's is not divisible by 3, return 0
        if ones_count % 3 != 0:
            return 0
        
        # If there are no '1's, count the number of ways to split the string into three parts with '0's only
        if ones_count == 0:
            n = len(s)
            return ((n - 1) * (n - 2) // 2) % (10**9 + 7)
        
        # Calculate the number of ways to split the string based on the positions of '1's
        part_ones = ones_count // 3
        first_split = second_split = 0
        count = 0
        
        for i in range(len(s)):
            if s[i] == '1':
                if first_split < part_ones:
                    first_split += 1
                elif first_split == part_ones:
                    second_split += 1
        
        # The number of ways to split is the product of the number of ways to choose splits for the second and third parts
        return (second_split + 1) * (first_split + 1) % (10**9 + 7)        