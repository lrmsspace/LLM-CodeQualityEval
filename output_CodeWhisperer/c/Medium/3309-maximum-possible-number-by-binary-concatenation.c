/*
 You are given an array of integers nums of size 3.
 Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.
 Note that the binary representation of any number does not contain leading zeros.
 Example 1:
 Input: nums = [1,2,3]
 Output: 30
 Explanation:
 Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
 Example 2:
 Input: nums = [2,8,16]
 Output: 1296
 Explanation:
 Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.
 Constraints:
 nums.length == 3
 1 <= nums[i] <= 127
*/

int maxGoodNumber(int* nums, int numsSize) {
    // Store all possible permutations of binary strings
    char bin[3][8];
    int maxNum = 0;
    
    // Convert each number to binary string
    for(int i = 0; i < 3; i++) {
        int num = nums[i];
        int idx = 0;
        char temp[8] = {0};
        
        while(num > 0) {
            temp[idx++] = num % 2 + '0';
            num /= 2;
        }
        
        // Reverse to get correct binary string
        int len = strlen(temp);
        for(int j = 0; j < len; j++) {
            bin[i][j] = temp[len-1-j];
        }
        bin[i][len] = '\0';
    }
    
    // Try all possible permutations
    int perm[6][3] = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};
    
    for(int i = 0; i < 6; i++) {
        char concat[24] = {0};
        strcat(concat, bin[perm[i][0]]);
        strcat(concat, bin[perm[i][1]]); 
        strcat(concat, bin[perm[i][2]]);
        
        // Convert binary string to decimal
        int val = 0;
        int len = strlen(concat);
        for(int j = 0; j < len; j++) {
            val = val * 2 + (concat[j] - '0');
        }
        
        if(val > maxNum) {
            maxNum = val;
        }
    }
    
    return maxNum;
}    