/**https://leetcode.com/problems/sequential-digits/ */
//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
// 
//Example 1:
//Input: low = 100, high = 300
//Output: [123,234]
//Example 2:
//Input: low = 1000, high = 13000
//Output: [1234,2345,3456,4567,5678,6789,12345]
// 
//Constraints:
//	10 <= low <= high <= 10^9
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int length = 2; length <= 9; ++length) {
            for (int start = 1; start <= 10 - length; ++start) {
                int num = 0;
                for (int i = 0; i < length; ++i) {
                    num = num * 10 + (start + i);
                }
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;

    }
};