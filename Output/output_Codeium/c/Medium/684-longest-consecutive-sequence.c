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
    if (numsSize == 0) return 0;

    int max = 1;
    int count = 1;
    int* map = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        map[i] = 0;
    }   

    for (int i = 0; i < numsSize; i++) {
        if (map[i] == 0) {
            map[i] = 1;
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] == nums[i] + 1) {
                    map[j] = 1;
                    count++;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] == nums[i] - 1) {
                    map[j] = 1;
                    count++;
                }
            }
            if (count > max) {
                max = count;
            }
            count = 1;
        }
    }

    return max; 
}