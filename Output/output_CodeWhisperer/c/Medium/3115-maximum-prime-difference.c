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

int maximumPrimeDifference(int* nums, int numsSize) {
    int max = 0;
    int min = 0;
    int flag = 0;
    for(int i = 0; i < numsSize; i++)
    {
        flag = 0;
        if(nums[i] == 1)
            continue;
        for(int j = 2; j < nums[i]; j++)
        {
            if(nums[i] % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            if(min == 0)
                min = i;
            max = i;
        }
    }
    return max - min;    
}