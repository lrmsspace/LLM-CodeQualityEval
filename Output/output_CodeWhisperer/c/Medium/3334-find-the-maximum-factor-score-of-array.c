/*
 You are given an integer array nums.
 The factor score of an array is defined as the product of the LCM and GCD of all elements of that array.
 Return the maximum factor score of nums after removing at most one element from it.
 Note that both the LCM and GCD of a single number are the number itself, and the factor score of an empty array is 0.
 Example 1:
 Input: nums = [2,4,8,16]
 Output: 64
 Explanation:
 On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of 4 * 16 = 64.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: 60
 Explanation:
 The maximum factor score of 60 can be obtained without removing any elements.
 Example 3:
 Input: nums = [3]
 Output: 9
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 30
*/

long long maxScore(int* nums, int numsSize) {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        int score = 1;
        for (int j = 0; j < numsSize; j++) {
            if (i == j) continue;
            score = lcm(score, nums[j]);
        }
        score *= gcd(nums[i], nums[i]);
        if (score > max) max = score;
    }
    return max;    
}