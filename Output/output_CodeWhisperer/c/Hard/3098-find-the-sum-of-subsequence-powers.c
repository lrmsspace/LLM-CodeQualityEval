/*
 You are given an integer array nums of length n, and a positive integer k.
 The power of a subsequence is defined as the minimum absolute difference between any two elements in the subsequence.
 Return the sum of powers of all subsequences of nums which have length equal to k.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [1,2,3,4], k = 3
 Output: 4
 Explanation:
 There are 4 subsequences in nums which have length 3: [1,2,3], [1,3,4], [1,2,4], and [2,3,4]. The sum of powers is |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4.
 Example 2:
 Input: nums = [2,2], k = 2
 Output: 0
 Explanation:
 The only subsequence in nums which has length 2 is [2,2]. The sum of powers is |2 - 2| = 0.
 Example 3:
 Input: nums = [4,3,-1], k = 2
 Output: 10
 Explanation:
 There are 3 subsequences in nums which have length 2: [4,3], [4,-1], and [3,-1]. The sum of powers is |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10.
 Constraints:
 2 <= n == nums.length <= 50
 -108 <= nums[i] <= 108 
 2 <= k <= n
*/

int sumOfPowers(int* nums, int numsSize, int k) {
    const int MOD = 1000000007;
    long long result = 0;
    
    // Sort array to make it easier to find min difference
    for(int i = 0; i < numsSize-1; i++) {
        for(int j = 0; j < numsSize-i-1; j++) {
            if(nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1]; 
                nums[j+1] = temp;
            }
        }
    }
    
    // Generate all possible subsequences of length k
    int* subsequence = (int*)malloc(k * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));
    
    void generateSubsequences(int pos, int start) {
        if(pos == k) {
            // Find minimum absolute difference
            int minDiff = INT_MAX;
            for(int i = 0; i < k; i++) {
                for(int j = i+1; j < k; j++) {
                    int diff = abs(subsequence[i] - subsequence[j]);
                    if(diff < minDiff) {
                        minDiff = diff;
                    }
                }
            }
            result = (result + minDiff) % MOD;
            return;
        }
        
        for(int i = start; i < numsSize; i++) {
            if(!used[i]) {
                used[i] = 1;
                subsequence[pos] = nums[i];
                generateSubsequences(pos + 1, i + 1);
                used[i] = 0;
            }
        }
    }
    
    generateSubsequences(0, 0);
    
    free(subsequence);
    free(used);
    
    return (int)result;
}            
