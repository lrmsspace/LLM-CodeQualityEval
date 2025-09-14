#https://leetcode.com/problems/sum-of-k-mirror-numbers/
#A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
#	For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
#	On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
#Given the base k and the number n, return the sum of the n smallest k-mirror numbers.
# 
#Example 1:
#Input: k = 2, n = 5
#Output: 25
#Explanation:
#The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
#  base-10    base-2
#    1          1
#    3          11
#    5          101
#    7          111
#    9          1001
#Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
#Example 2:
#Input: k = 3, n = 7
#Output: 499
#Explanation:
#The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
#  base-10    base-3
#    1          1
#    2          2
#    4          11
#    8          22
#    121        11111
#    151        12121
#    212        21212
#Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
#Example 3:
#Input: k = 7, n = 17
#Output: 20379000
#Explanation: The 17 smallest 7-mirror numbers are:
#1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
# 
#Constraints:
#	2 <= k <= 9
#	1 <= n <= 30
class Solution(object):
    def kMirror(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: int
        """
        def is_mirror(num):
            s = str(num)
            return s == s[::-1]
        def convert_base(num, base):
            return int(str(num), base)
        def dfs(num, base, count):
            if count == n:
                return num
            for i in range(9, 1, -1):
                if base == 10 or i < base:
                    new_num = num * 10 + i
                    if is_mirror(new_num):
                        res = dfs(new_num, base, count + 1)
                        if res is not None:
                            return res
        res = 0
        for i in range(1, 9):
            if is_mirror(i):
                res = dfs(i, k, 1)
                if res is not None:
                    return res
        return res

