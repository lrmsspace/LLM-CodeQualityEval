/**https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/ */
//Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.
// 
//Example 1:
//Input: num = 33
//Output: [10,11,12]
//Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
//10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
//Example 2:
//Input: num = 4
//Output: []
//Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
// 
//Constraints:
//	0 <= num <= 1015
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> result;
        for (long long i = 1; i <= num; i++) {
            if (num - 2 * i >= 0) {
                result.push_back(i);
                result.push_back(i + 1);
                result.push_back(i + 2);
                return result;
            }
        }
        return result;  // If num cannot be expressed as the sum of three consecutive integers, return an empty array.
        
    }
};