/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s;
        priority_queue<pair<int, char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        while (pq.size() > 1) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            auto [cnt2, ch2] = pq.top(); pq.pop();
            if (cnt1 >= 2) {
                s += ch1; s += ch1;
                cnt1 -= 2;
            } else {
                s += ch1;
                cnt1--;
            }
            if (cnt2 >= 2 && cnt1 < cnt2) {
                s += ch2; s += ch2;
                cnt2 -= 2;
            } else {
                s += ch2;
                cnt2--;
            }
            if (cnt1) pq.push({cnt1, ch1});
            if (cnt2) pq.push({cnt2, ch2});
        }
        if (pq.size()) {
            auto [cnt, ch] = pq.top(); pq.pop();
            if (s.empty() || s.back() != ch) {
                if (cnt >= 2) {
                    s += ch; s += ch;
                } else {
                    s += ch;
                }
            } else {
                if (cnt >= 2) {
                    s += ch; s += ch;
                }
            }
        }
        return s;        
    }
};