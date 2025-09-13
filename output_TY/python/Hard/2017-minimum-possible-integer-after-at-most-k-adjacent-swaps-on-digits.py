#https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
#You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
#Return the minimum integer you can obtain also as a string.
# 
#Example 1:
#Input: num = "4321", k = 4
#Output: "1342"
#Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
#Example 2:
#Input: num = "100", k = 1
#Output: "010"
#Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
#Example 3:
#Input: num = "36789", k = 1000
#Output: "36789"
#Explanation: We can keep the number without any swaps.
# 
#Constraints:
#	1 <= num.length <= 3 * 104
#	num consists of only digits and does not contain leading zeros.
#	1 <= k <= 109
class Solution(object):
    def minInteger(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        n = len(num)
        num = [int(i) for i in num]
        ans = [0] * n
        for i in range(n):
            min_val = 10
            min_idx = -1
            for j in range(i, n):
                if num[j] < min_val:
                    min_val = num[j]
                    min_idx = j
            if min_idx != i:
                k -= (min_idx - i) * (n - min_idx - 1)
                if k < 0:
                    return ''.join([str(i) for i in ans])
                ans[i:min_idx+1] = num[min_idx::-1]
                num[min_idx:] = num[min_idx+1:]
        return ''.join([str(i) for i in ans])