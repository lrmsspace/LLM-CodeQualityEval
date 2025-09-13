/*
 You are given an array of positive integers nums and an integer k.
 You may perform at most k operations. In each operation, you can choose one element in the array and double its value. Each element can be doubled at most once.
 The score of a contiguous subarray is defined as the product of its length and the greatest common divisor (GCD) of all its elements.
 Your task is to return the maximum score that can be achieved by selecting a contiguous subarray from the modified array.
 Note:
 The greatest common divisor (GCD) of an array is the largest integer that evenly divides all the array elements.
 Example 1:
 Input: nums = [2,4], k = 1
 Output: 8
 Explanation:
 Double nums[0] to 4 using one operation. The modified array becomes [4, 4].
 The GCD of the subarray [4, 4] is 4, and the length is 2.
 Thus, the maximum possible score is 2 × 4 = 8.
 Example 2:
 Input: nums = [3,5,7], k = 2
 Output: 14
 Explanation:
 Double nums[2] to 14 using one operation. The modified array becomes [3, 5, 14].
 The GCD of the subarray [14] is 14, and the length is 1.
 Thus, the maximum possible score is 1 × 14 = 14.
 Example 3:
 Input: nums = [5,5,5], k = 1
 Output: 15
 Explanation:
 The subarray [5, 5, 5] has a GCD of 5, and its length is 3.
 Since doubling any element doesn't improve the score, the maximum score is 3 × 5 = 15.
 Constraints:
 1 <= n == nums.length <= 1500
 1 <= nums[i] <= 109
 1 <= k <= n
*/

long long maxGCDScore(int* nums, int numsSize, int k) {

    // Base case: if k is 0, return 0
    if (k == 0) {
        return 0;
    }
    // Initialize variables to keep track of the maximum score and the current subarray
    long long maxScore = 0;
    long long currScore = 0;
    // Initialize variables to keep track of the current subarray and its length
    int start = 0;
    int end = 0;
    // Initialize variables to keep track of the current subarray's GCD
    long long currGCD = 1;
    // Iterate through the array
    for (int i = 0; i < numsSize; i++) {
        // Calculate the GCD of the current element with the current GCD
        currGCD = gcd(currGCD, nums[i]);
        // Update the current subarray's score
        currScore += currGCD;
        // If the current subarray's length exceeds k, remove the first element and update the start index
        if (end - start + 1 > k) {
            currScore -= gcd(currScore, nums[start]);
            start++;
        }
        // Update the maximum score if the current subarray's score is greater
        maxScore = max(maxScore, currScore);
        // Update the end index
        end++;
    }
    // Return the maximum score
    return maxScore;
}