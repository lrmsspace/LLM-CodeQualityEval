/**https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ */
//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
//Return true if it is possible. Otherwise, return false.
// 
//Example 1:
//Input: nums = [1,2,3,3,4,4,5,6], k = 4
//Output: true
//Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
//Example 2:
//Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
//Output: true
//Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
//Example 3:
//Input: nums = [1,2,3,4], k = 3
//Output: false
//Explanation: Each array should be divided in subarrays of size 3.
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	1 <= nums[i] <= 109
// 
//Note: This question is the same as 846: https://leetcode.com/problems/hand-of-straights/
    int compare(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }

    bool isPossibleDivide(int* nums, int numsSize, int k) {
        if (numsSize % k != 0) {
            return false;
        }

        qsort(nums, numsSize, sizeof(int), compare);

        int* count = (int*)calloc(numsSize, sizeof(int));
        int uniqueCount = 0;

        for (int i = 0; i < numsSize; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[uniqueCount] = nums[i];
                count[uniqueCount] = 1;
                uniqueCount++;
            } else {
                count[uniqueCount - 1]++;
            }
        }

        for (int i = 0; i < uniqueCount; i++) {
            if (count[i] > 0) {
                int freq = count[i];
                for (int j = 0; j < k; j++) {
                    if (i + j >= uniqueCount || nums[i + j] != nums[i] + j || count[i + j] < freq) {
                        free(count);
                        return false;
                    }
                    count[i + j] -= freq;
                }
            }
        }

        free(count);
        return true;
    }   