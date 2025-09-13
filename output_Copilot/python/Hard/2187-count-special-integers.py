#https://leetcode.com/problems/count-special-integers/
#We call a positive integer special if all of its digits are distinct.
#Given a positive integer n, return the number of special integers that belong to the interval [1, n].
# 
#Example 1:
#Input: n = 20
#Output: 19
#Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
#Example 2:
#Input: n = 5
#Output: 5
#Explanation: All the integers from 1 to 5 are special.
#Example 3:
#Input: n = 135
#Output: 110
#Explanation: There are 110 integers from 1 to 135 that are special.
#Some of the integers that are not special are: 22, 114, and 131.
# 
#Constraints:
#	1 <= n <= 2 * 109
class Solution(object):
    def countSpecialNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        def count(n):
            s = str(n)
            m = len(s)
            ans = 0
            for i in range(1, m):
                ans += 9 * perm(9, i - 1)   
            seen = set()

            for i in range(m):
                x = int(s[i])
                for j in range(1 if i == 0 else 0, x):
                    if j not in seen:
                        ans += perm(9 - i, m - i - 1) 
                if x in seen:
                    break
                seen.add(x)
            else:
                ans += 1
            return ans
        def perm(n, k):
            if k == 0:
                return 1
            res = 1
            for i in range(k):
                res *= n - i
            return res
        return count(n) - 1     