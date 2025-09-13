/**https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/ */
//You are given an integer num. You will apply the following steps exactly two times:
//	Pick a digit x (0 <= x <= 9).
//	Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
//	Replace all the occurrences of x in the decimal representation of num by y.
//	The new integer cannot have any leading zeros, also the new integer cannot be 0.
//Let a and b be the results of applying the operations to num the first and second times, respectively.
//Return the max difference between a and b.
// 
//Example 1:
//Input: num = 555
//Output: 888
//Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
//The second time pick x = 5 and y = 1 and store the new integer in b.
//We have now a = 999 and b = 111 and max difference = 888
//Example 2:
//Input: num = 9
//Output: 8
//Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
//The second time pick x = 9 and y = 1 and store the new integer in b.
//We have now a = 9 and b = 1 and max difference = 8
// 
//Constraints:
//	1 <= num <= 108
class Solution {
public:
    int maxDiff(int num) {
        int max_diff = 0;
        int min_digit = num;
        int max_digit = num;
        
        while (num!= 0) {
            int digit = num % 10;
            max_digit = max(max_digit, digit);
            min_digit = min(min_digit, digit);
            num /= 10;
        }
        
        for (int i = 0; i < 10; ++i) {
            if (i!= min_digit && i!= max_digit) {
                int new_num = num;
                while (new_num!= 0) {
                    int digit = new_num % 10;
                    if (digit == min_digit) {
                        new_num = new_num / 10 * 10 + i;
                        break;
                    }
                    new_num /= 10;
                }
                
                int new_max_digit = new_num;
                while (new_max_digit!= 0) {
                    int digit = new_max_digit % 10;
                    max_diff = max(max_diff, new_max_digit - digit);
                    new_max_digit /= 10;
                }
            }
        }
        
        return max_diff;
        
    }
};