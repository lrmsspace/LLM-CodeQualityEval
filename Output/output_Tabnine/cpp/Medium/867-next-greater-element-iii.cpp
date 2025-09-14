/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
class Solution {
public:
    int nextGreaterElement(int n) {
        string numStr = to_string(n);
        int len = numStr.size();
        int i = len - 2;
        
        // Find the first digit from right which is smaller than the next digit
        while (i >= 0 && numStr[i] >= numStr[i + 1]) --i;
        
        // If no such digit found, return -1
        if (i == -1) return -1;
        
        // Find the first digit from right which is greater than the digit at index i
        int j = len - 1;
        while (j >= 0 && numStr[j] <= numStr[i]) --j;
        
        // Swap the digits at indices i and j
        swap(numStr[i], numStr[j]);
        
        // Reverse the digits to the right of index i
        reverse(numStr.begin() + i + 1, numStr.end());
        
        // Convert the string back to an integer
        int result = stoi(numStr);
        
        // Check if the result fits in 32-bit integer
        if (result > INT_MAX) return -1;
        
        return result;
        
    }
};