/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.
// 
//Example 1:
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
int maximumGap(int* nums, int numsSize){
    if(numsSize < 2) return 0;
    int max_val = nums[0], min_val = nums[0];
    for(int i = 0; i < numsSize; i++){
        max_val = max(max_val, nums[i]);
        min_val = min(min_val, nums[i]);
    }
    int bucket_size = max(1, (max_val - min_val) / (numsSize - 1));
    int bucket_num = (max_val - min_val) / bucket_size + 1;
    int *bucket_min = (int *)malloc(sizeof(int) * bucket_num);
    int *bucket_max = (int *)malloc(sizeof(int) * bucket_num);
    memset(bucket_min, 0x7f, sizeof(int) * bucket_num);
    memset(bucket_max, 0x80, sizeof(int) * bucket_num);
    for(int i = 0; i < numsSize; i++){
        int idx = (nums[i] - min_val) / bucket_size;
        bucket_min[idx] = min(bucket_min[idx], nums[i]);
    }
    for(int i = 0; i < numsSize; i++){
        int idx = (nums[i] - min_val) / bucket_size;
        bucket_max[idx] = max(bucket_max[idx], nums[i]);
    }
    for(int i = 0; i < bucket_num; i++){
        if(bucket_min[i] == 0x7f) continue;
        if(i > 0 && bucket_max[i - 1] != 0x80) res = max(res, bucket_min[i] - bucket_max[i - 1]);
        if(i < bucket_num - 1 && bucket_min[i + 1] != 0x7f) res = max(res, bucket_max[i] - bucket_min[i + 1]);
    }
    return res;
}