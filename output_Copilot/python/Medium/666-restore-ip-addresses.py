#https://leetcode.com/problems/restore-ip-addresses/
#A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
#	For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
#Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
# 
#Example 1:
#Input: s = "25525511135"
#Output: ["255.255.11.135","255.255.111.35"]
#Example 2:
#Input: s = "0000"
#Output: ["0.0.0.0"]
#Example 3:
#Input: s = "101023"
#Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
# 
#Constraints:
#	1 <= s.length <= 20
#	s consists of digits only.
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def is_valid(segment):
            # Check if the segment is a valid IP address segment
            if len(segment) > 1 and segment[0] == '0':
                return False    
            return 0 <= int(segment) <= 255
        def backtrack(start, path):
            # If we have 4 segments and we've used all characters, add to result
            if len(path) == 4 and start == len(s):
                result.append('.'.join(path))
                return
            # If we have 4 segments but haven't used all characters, return
            if len(path) == 4:
                return
            # Try all possible segment lengths (1 to 3 digits)
            for length in range(1, 4):
                if start + length <= len(s):
                    segment = s[start:start + length]
                    if is_valid(segment):
                        backtrack(start + length, path + [segment])
        result = []
        backtrack(0, [])
        return result       