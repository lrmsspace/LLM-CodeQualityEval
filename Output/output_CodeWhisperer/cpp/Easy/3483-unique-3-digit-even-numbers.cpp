/*
 You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.
 Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
 Example 1:
 Input: digits = [1,2,3,4]
 Output: 12
 Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.
 Example 2:
 Input: digits = [0,2,2]
 Output: 2
 Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.
 Example 3:
 Input: digits = [6,6,6]
 Output: 1
 Explanation: Only 666 can be formed.
 Example 4:
 Input: digits = [1,3,5]
 Output: 0
 Explanation: No even 3-digit numbers can be formed.
 Constraints:
 3 <= digits.length <= 10
 0 <= digits[i] <= 9
*/

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
    // Count frequency of each digit
    vector<int> freq(10, 0);
    for(int d : digits) {
        freq[d]++;
    }
    
    // Set to store unique numbers
    set<int> result;
    
    // Try all possible 3 digit combinations
    int n = digits.size();
    for(int i = 0; i < n; i++) {
        // Skip if digit is 0 since we can't have leading zeros
        if(digits[i] == 0) continue;
        
        // Decrease frequency of first digit
        freq[digits[i]]--;
        
        for(int j = 0; j < n; j++) {
            // Skip if digit already used
            if(freq[digits[j]] == 0) continue;
            
            // Decrease frequency of second digit
            freq[digits[j]]--;
            
            for(int k = 0; k < n; k++) {
                // Skip if digit already used or last digit is odd
                if(freq[digits[k]] == 0 || digits[k] % 2 != 0) continue;
                
                // Form 3 digit number
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                result.insert(num);
            }
            
            // Restore frequency of second digit
            freq[digits[j]]++;
        }
        
        // Restore frequency of first digit
        freq[digits[i]]++;
    }
    
    return result.size();
}                
    
};