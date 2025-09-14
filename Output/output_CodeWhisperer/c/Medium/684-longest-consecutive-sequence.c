/**https://leetcode.com/problems/longest-consecutive-sequence/ */
//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//You must write an algorithm that runs in O(n) time.
// 
//Example 1:
//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//Example 2:
//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
// 
//Constraints:
//	0 <= nums.length <= 105
//	-109 <= nums[i] <= 109
int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int max = 1;
    int* hash = (int*)calloc(1000000000, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]] = 1;
    }
    for (int i = 0; i < numsSize; i++) {
        if (hash[nums[i]] == 0) {
            continue;
        }
        int count = 1;
        int j = nums[i] + 1;
        while (hash[j] == 1) {
            count++;
            hash[j] = 0;
            j++;
        }
        j = nums[i] - 1;
        while (hash[j] == 1) {
            count++;
            hash[j] = 0;
            j--;
        }
        if (count > max) {
            max = count;
        }
    }
    return max;
}