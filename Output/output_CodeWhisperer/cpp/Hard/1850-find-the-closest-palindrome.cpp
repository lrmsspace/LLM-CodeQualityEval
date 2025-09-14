/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].
class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        vector<long long> candidates;
        candidates.emplace_back(pow(10, len) + 1);
        candidates.emplace_back(pow(10, len - 1) - 1);
        long long leftHalf = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; i++) {
            string prefix = to_string(leftHalf + i);
            string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            candidates.emplace_back(stoll(candidate));
        }
        long long ans = -1;
        long long diff = LONG_MAX;
        for (long long candidate : candidates) {
            if (candidate == num) continue;
            if (abs(candidate - num) < diff) {
                diff = abs(candidate - num);
                ans = candidate;
            } else if (abs(candidate - num) == diff) {
                ans = min(ans, candidate);
            }
        }
        return to_string(ans);       
    }
};