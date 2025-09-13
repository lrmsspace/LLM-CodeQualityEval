/**https://leetcode.com/problems/find-palindrome-with-fixed-length/ */
//Given an integer array queries and a positive integer intLength, return an array answer where answer[i] is either the queries[i]th smallest positive palindrome of length intLength or -1 if no such palindrome exists.
//A palindrome is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.
// 
//Example 1:
//Input: queries = [1,2,3,4,5,90], intLength = 3
//Output: [101,111,121,131,141,999]
//Explanation:
//The first few palindromes of length 3 are:
//101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
//The 90th palindrome of length 3 is 999.
//Example 2:
//Input: queries = [2,4,6], intLength = 4
//Output: [1111,1331,1551]
//Explanation:
//The first six palindromes of length 4 are:
//1001, 1111, 1221, 1331, 1441, and 1551.
// 
//Constraints:
//	1 <= queries.length <= 5 * 104
//	1 <= queries[i] <= 109
//	1 <= intLength <= 15
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> result;
        for (int query : queries) {
            if (query > (1LL << (intLength - 1)) - 1) {
                result.push_back(-1);
            } else {
                string s = to_string(query);
                reverse(s.begin(), s.end());
                string left = s.substr(0, (intLength - 1) / 2);
                string right = s.substr((intLength - 1) / 2);
                if (intLength % 2 == 0) {
                    right = left;
                }
                result.push_back(stol(left + right));
            }
        }
        return result;
    }
};