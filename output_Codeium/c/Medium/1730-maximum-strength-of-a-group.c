/**https://leetcode.com/problems/maximum-strength-of-a-group/ */
//You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].
//Return the maximum strength of a group the teacher can create.
// 
//Example 1:
//Input: nums = [3,-1,-5,2,5,-9]
//Output: 1350
//Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.
//Example 2:
//Input: nums = [-4,-5,-4]
//Output: 20
//Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.
// 
//Constraints:
//	1 <= nums.length <= 13
//	-9 <= nums[i] <= 9
long long maxStrength(int* nums, int numsSize) {
    long long res = 0, neg = 1, zero = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) neg *= nums[i];
        else if (nums[i] == 0) zero++;
        else res = max(res, (long long)nums[i]);
    }
    if (zero > 0) return res;
    if (neg == 0) return res;
    return max(res, neg);
}