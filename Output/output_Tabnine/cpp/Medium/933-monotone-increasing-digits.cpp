/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num_str = to_string(n);
        int n_size = num_str.size();
        int i = n_size - 1;
        while (i > 0 && num_str[i] <= num_str[i - 1]) --i;
        if (i == 0) return n;
        
        --num_str[i - 1];
        for (int j = i; j < n_size; ++j) num_str[j] = '9';
        return stoi(num_str);
        
    }
};