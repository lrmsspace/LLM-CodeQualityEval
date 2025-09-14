/*
 You are given an integer array nums containing positive integers. We define a function encrypt such that encrypt(x) replaces every digit in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.
 Return the sum of encrypted elements.
 Example 1:
 Input: nums = [1,2,3]
 Output: 6
 Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.
 Example 2:
 Input: nums = [10,21,31]
 Output: 66
 Explanation: The encrypted elements are [11,22,33]. The sum of encrypted elements is 11 + 22 + 33 == 66.
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 1000
*/

int sumOfEncryptedInt(int* nums, int numsSize) {
    int sum = 0;
    int max = 0;
    int temp = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        temp = nums[i];
        max = 0;
        count = 0;
        while (temp > 0) {
            if (temp % 10 > max) {
                max = temp % 10;
            }
            temp /= 10;
            count++;
        }
        temp = nums[i];
        while (count > 0) {
            sum += max;
            max *= 10;
            count--;
        }
    }
    return sum;    
}