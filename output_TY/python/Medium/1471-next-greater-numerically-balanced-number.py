#https://leetcode.com/problems/next-greater-numerically-balanced-number/
#An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
#Given an integer n, return the smallest numerically balanced number strictly greater than n.
# 
#Example 1:
#Input: n = 1
#Output: 22
#Explanation: 
#22 is numerically balanced since:
#- The digit 2 occurs 2 times. 
#It is also the smallest numerically balanced number strictly greater than 1.
#Example 2:
#Input: n = 1000
#Output: 1333
#Explanation: 
#1333 is numerically balanced since:
#- The digit 1 occurs 1 time.
#- The digit 3 occurs 3 times. 
#It is also the smallest numerically balanced number strictly greater than 1000.
#Note that 1022 cannot be the answer because 0 appeared more than 0 times.
#Example 3:
#Input: n = 3000
#Output: 3133
#Explanation: 
#3133 is numerically balanced since:
#- The digit 1 occurs 1 time.
#- The digit 3 occurs 3 times.
#It is also the smallest numerically balanced number strictly greater than 3000.
# 
#Constraints:
#	0 <= n <= 106
class Solution(object):
    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        def next_num(n):
            s = str(n)
            for i in range(len(s)-1, -1, -1):
                if s[i] != '9':
                    return int(s[:i] + str(int(s[i])+1) + '0'*(len(s)-i-1))
            return n+1
        
        while True:
            n += 1
            s = str(n)
            d = [0]*10
            for c in s:
                d[int(c)] += 1
            if all(x==i for i, x in enumerate(d)):
                return n
        return next_num(n)