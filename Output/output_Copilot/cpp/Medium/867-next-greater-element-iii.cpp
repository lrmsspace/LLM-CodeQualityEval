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
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long res = stol(s);
        return (res > INT_MAX || res <= n) ? -1 : res;        
    }
};