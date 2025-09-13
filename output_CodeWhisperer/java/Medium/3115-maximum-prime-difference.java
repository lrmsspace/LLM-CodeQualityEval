/*
 You are given an integer array nums.
 Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
 Example 1:
 Input: nums = [4,2,9,5,3]
 Output: 3
 Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.
 Example 2:
 Input: nums = [4,8,2,8]
 Output: 0
 Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.
 Constraints:
 1 <= nums.length <= 3 * 105
 1 <= nums[i] <= 100
 The input is generated such that the number of prime numbers in the nums is at least one.
*/

class Solution {
    public int maximumPrimeDifference(int[] nums) {
    int maxDiff = 0;
    int firstPrime = -1;
    int lastPrime = -1;
    
    // Check each number in array
    for(int i = 0; i < nums.length; i++) {
        if(isPrime(nums[i])) {
            if(firstPrime == -1) {
                firstPrime = i;
            }
            lastPrime = i;
            // Update max difference between any two prime indices found so far
            maxDiff = Math.max(maxDiff, lastPrime - firstPrime);
        }
    }
    
    return maxDiff;
}

private boolean isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3; i <= Math.sqrt(n); i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}                    
}