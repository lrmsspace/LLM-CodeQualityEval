/*
 You are given an array nums, where each number in the array appears either once or twice.
 Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.
 Example 1:
 Input: nums = [1,2,1,3]
 Output: 1
 Explanation:
 The only number that appears twice in nums is 1.
 Example 2:
 Input: nums = [1,2,3]
 Output: 0
 Explanation:
 No number appears twice in nums.
 Example 3:
 Input: nums = [1,2,2,1]
 Output: 3
 Explanation:
 Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 50
 Each number in nums appears either once or twice.
*/

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int xor_of_all = 0;
        for(int i = 0; i < nums.size(); i++){
            xor_of_all ^= nums[i];
        }
        
        int xor_of_1_to_n = 0;
        for(int i = 1; i <= nums.size(); i++){
            xor_of_1_to_n ^= i;
        }
        
        int xor_of_1_to_n_and_xor_of_all = xor_of_1_to_n ^ xor_of_all;
        
        int right_most_bit = xor_of_1_to_n_and_xor_of_all & -xor_of_1_to_n_and_xor_of_all;
        int xor_of_a = 0, xor_of_b = 0;

        for(int i = 0; i < nums.size(); i++){
            if(right_most_bit & nums[i]){
                xor_of_a ^= nums[i];
            }else{
                xor_of_b ^= nums[i];
            }
        }

        return {xor_of_a, xor_of_b};
        
    }
};