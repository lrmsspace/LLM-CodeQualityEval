/*
 You are given a 0-indexed array nums of non-negative integers, and two integers l and r.
 Return the count of sub-multisets within nums where the sum of elements in each subset falls within the inclusive range of [l, r].
 Since the answer may be large, return it modulo 109 + 7.
 A sub-multiset is an unordered collection of elements of the array in which a given value x can occur 0, 1, ..., occ[x] times, where occ[x] is the number of occurrences of x in the array.
 Note that:
 Two sub-multisets are the same if sorting both sub-multisets results in identical multisets.
 The sum of an empty multiset is 0.
 Example 1:
 Input: nums = [1,2,2,3], l = 6, r = 6
 Output: 1
 Explanation: The only subset of nums that has a sum of 6 is {1, 2, 3}.
 Example 2:
 Input: nums = [2,1,4,2,7], l = 1, r = 5
 Output: 7
 Explanation: The subsets of nums that have a sum within the range [1, 5] are {1}, {2}, {4}, {2, 2}, {1, 2}, {1, 4}, and {1, 2, 2}.
 Example 3:
 Input: nums = [1,2,1,3,5,2], l = 3, r = 5
 Output: 9
 Explanation: The subsets of nums that have a sum within the range [3, 5] are {3}, {5}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {1, 1, 2}, {1, 1, 3}, and {1, 2, 2}.
 Constraints:
 1 <= nums.length <= 2 * 104
 0 <= nums[i] <= 2 * 104
 Sum of nums does not exceed 2 * 104.
 0 <= l <= r <= 2 * 104
*/
#define MOD 1000000007

// 计算最大公约数
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int countSubMultisets(int* nums, int numsSize, int l, int r) {
    // 统计每个数字的出现次数和计算数组和
    int count[20001] = {0};
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
        sum += nums[i];
    }
    
    // 如果总和小于l，则无解
    if (sum < l) return 0;
    // 如果r大于总和，将r限制为总和
    r = r < sum ? r : sum;
    
    // dp[i]表示和为i的子集数量
    long long* dp = (long long*)calloc(r + 1, sizeof(long long));
    dp[0] = 1;  // 空集的和为0
    
    // 特殊处理0
    if (count[0] > 0) {
        // 0可以取任意次，所以要乘以(count[0] + 1)
        for (int i = 0; i <= r; i++) {
            dp[i] = (dp[i] * (count[0] + 1)) % MOD;
        }
    }
    
    // 对每个非0数字进行DP
    for (int num = 1; num <= 20000; num++) {
        if (count[num] == 0) continue;
        
        // 从大到小更新dp数组，避免重复计算
        for (int sum = r; sum >= 0; sum--) {
            if (dp[sum] == 0) continue;
            
            long long curr = dp[sum];
            long long mult = 1;
            
            // 对于当前数字，可以选择1到count[num]个
            for (int k = 1; k <= count[num] && sum + k * num <= r; k++) {
                mult = (mult * num) % MOD;
                dp[sum + k * num] = (dp[sum + k * num] + curr) % MOD;
            }
        }
    }
    
    // 计算[l,r]范围内的和
    long long result = 0;
    for (int i = l; i <= r; i++) {
        result = (result + dp[i]) % MOD;
    }
    
    free(dp);
    return (int)result;
}
