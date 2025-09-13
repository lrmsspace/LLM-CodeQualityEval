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
        // Step 1: Create a boolean array to mark prime numbers
        boolean[] isPrime = new boolean[101];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 100; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 100; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Step 2: Find the indices of prime numbers
        List<Integer> primeIndices = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (isPrime[nums[i]]) {
                primeIndices.add(i);
            }
        }
        
        // Step 3: Find the maximum distance between prime indices
        int maxDistance = 0;
        for (int i = 1; i < primeIndices.size(); i++) {
            maxDistance = Math.max(maxDistance, primeIndices.get(i) - primeIndices.get(i - 1));
        }
        
        return maxDistance;
        
    }
}