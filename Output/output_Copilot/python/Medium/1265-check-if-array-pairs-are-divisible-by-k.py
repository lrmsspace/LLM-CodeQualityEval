#https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
#Given an array of integers arr of even length n and an integer k.
#We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
#Return true If you can find a way to do that or false otherwise.
# 
#Example 1:
#Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
#Output: true
#Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
#Example 2:
#Input: arr = [1,2,3,4,5,6], k = 7
#Output: true
#Explanation: Pairs are (1,6),(2,5) and(3,4).
#Example 3:
#Input: arr = [1,2,3,4,5,6], k = 10
#Output: false
#Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
# 
#Constraints:
#	arr.length == n
#	1 <= n <= 105
#	n is even.
#	-109 <= arr[i] <= 109
#	1 <= k <= 105
class Solution(object):
    def canArrange(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: bool
        """
        # 计算每个元素对 k 的余数
        remainder_count = [0] * k
        for num in arr:
            remainder = num % k
            if remainder < 0:
                remainder += k
            remainder_count[remainder] += 1

        # 检查余数为 0 的元素是否成对
        if remainder_count[0] % 2 != 0:
            return False

        # 检查其他余数是否成对
        for i in range(1, (k // 2) + 1):
            if i == k - i:        
                if remainder_count[i] % 2 != 0:
                    return False
            else:
                if remainder_count[i] != remainder_count[k - i]:
                    return False
        return True 