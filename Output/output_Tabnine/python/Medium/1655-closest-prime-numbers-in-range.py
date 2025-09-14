#https://leetcode.com/problems/closest-prime-numbers-in-range/
#Given two positive integers left and right, find the two integers num1 and num2 such that:
#	left <= num1 < num2 <= right .
#	num1 and num2 are both prime numbers.
#	num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
#Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the minimum num1 value or [-1, -1] if such numbers do not exist.
#A number greater than 1 is called prime if it is only divisible by 1 and itself.
# 
#Example 1:
#Input: left = 10, right = 19
#Output: [11,13]
#Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
#The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
#Since 11 is smaller than 17, we return the first pair.
#Example 2:
#Input: left = 4, right = 6
#Output: [-1,-1]
#Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
# 
#Constraints:
#	1 <= left <= right <= 106
# 
#.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
#}
#.spoiler {overflow:hidden;}
#.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
#.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
#.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
class Solution(object):
    def closestPrimes(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        primes = self.sieve_of_eratosthenes(right)
        primes = [p for p in primes if left < p <= right]
        if not primes:
            return [-1, -1]
        
        min_diff = float('inf')
        closest_primes = [-1, -1]
        
        for i in range(len(primes) - 1):
            diff = primes[i + 1] - primes[i]
            if diff < min_diff:
                min_diff = diff
                closest_primes = [primes[i], primes[i + 1]]
        
        return closest_primes
        