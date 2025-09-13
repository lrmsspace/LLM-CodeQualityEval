/**https://leetcode.com/problems/find-unique-binary-string/ */
//Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
// 
//Example 1:
//Input: nums = ["01","10"]
//Output: "11"
//Explanation: "11" does not appear in nums. "00" would also be correct.
//Example 2:
//Input: nums = ["00","01"]
//Output: "11"
//Explanation: "11" does not appear in nums. "10" would also be correct.
//Example 3:
//Input: nums = ["111","011","001"]
//Output: "101"
//Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 16
//	nums[i].length == n
//	nums[i] is either '0' or '1'.
//	All the strings of nums are unique.
char* findDifferentBinaryString(char** nums, int numsSize) {
    // Convert the array of strings to an array of integers
    int* nums_int = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int num = 0;
        for (int j = 0; j < nums[i][j] - '0'; j++) {
            num |= (1 << j);
        }
        nums_int[i] = num;
    }
    
    // Initialize a boolean array to track the used bits
    bool used[1 << 16] = {false};
    
    // Iterate over all possible binary strings
    for (int i = 0; i < (1 << 16); i++) {
        // Check if the current binary string does not appear in nums
        bool unique = true;
        for (int j = 0; j < numsSize; j++) {
            if (nums_int[j] == i) {
                unique = false;
                break;
            }
        }
        
        // If the current binary string is unique, return it
        if (unique) {
            char* result = (char*)malloc(17 * sizeof(char));
            sprintf(result, "%016d", i);
            return result;
        }
    }
    
    // If no unique binary string is found, return an empty string
    return "";
    
}