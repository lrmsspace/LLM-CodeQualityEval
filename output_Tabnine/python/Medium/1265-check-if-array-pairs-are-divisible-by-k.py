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
        # Count the frequency of each number modulo k
        count = [0] * k
        
        # Count the frequency of each pair sum modulo k
        pair_count = [0] * k
        
        for num in arr:
            # Count the frequency of the number modulo k
            count[num % k] += 1
        
        # If there are odd numbers, we can't form pairs
        if count[0] % 2!= 0:
            return False
        
        # Iterate over the count array
        for i in range(1, k // 2 + 1):
            # If the count of the current pair sum modulo k is odd, we can't form pairs
            if count[i] % 2!= 0 or count[k - i] % 2!= 0:
                return False
            
            # Count the pairs with the current pair sum modulo k
            pair_count[i] = count[i] // 2
            pair_count[k - i] = count[k - i] // 2
        
        # If there are more than half of the pairs, we can't form pairs
        if any(pair_count[i] > k // 2 for i in range(k // 2 + 1, k)):
            return False
        
        return True
        