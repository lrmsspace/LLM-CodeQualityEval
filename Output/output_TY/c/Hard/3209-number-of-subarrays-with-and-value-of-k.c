/*
 Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.
 Example 1:
 Input: nums = [1,1,1], k = 1
 Output: 6
 Explanation:
 All subarrays contain only 1's.
 Example 2:
 Input: nums = [1,1,2], k = 1
 Output: 3
 Explanation:
 Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].
 Example 3:
 Input: nums = [1,2,3], k = 2
 Output: 2
 Explanation:
 Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i], k <= 109
*/

long long countSubarrays(int* nums, int numsSize, int k) {  
    long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int j = i, cnt = 0, sum = 0;
        while (j < numsSize && sum + nums[j] <= k) {
            sum += nums[j];
            j++;
            cnt++;
        }
        ans += cnt;
        sum = 0;
        cnt = 0;
        for (; j < numsSize; j++) {
            sum += nums[j];
            cnt++;
            while (sum * cnt > k) {
                sum -= nums[i];
                i++;
                cnt--;
            }
            if (sum * cnt == k) ans++;
        }
    }
    return ans;
    
}