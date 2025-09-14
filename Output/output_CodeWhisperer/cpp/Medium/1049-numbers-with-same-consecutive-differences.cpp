/**https://leetcode.com/problems/numbers-with-same-consecutive-differences/ */
//Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
//Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
// 
//Example 1:
//Input: n = 3, k = 7
//Output: [181,292,707,818,929]
//Explanation: Note that 070 is not a valid number, because it has leading zeroes.
//Example 2:
//Input: n = 2, k = 1
//Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
// 
//Constraints:
//	2 <= n <= 9
//	0 <= k <= 9 
class Solution {
    public:
        vector<int> numsSameConsecDiff(int n, int k) {
            // Start with all single-digit numbers (1-9)
            queue<int> q;
            for (int i = 1; i <= 9; i++) {
                q.push(i);
            }
            
            // Process numbers of length 1 to n-1
            for (int len = 1; len < n; len++) {
                int size = q.size();
                
                // Process all numbers of the current length
                for (int i = 0; i < size; i++) {
                    int num = q.front();
                    q.pop();
                    
                    int lastDigit = num % 10;
                    
                    // Try adding a digit that differs by k
                    vector<int> nextDigits;
                    nextDigits.push_back(lastDigit + k);
                    if (k != 0) {  // Avoid duplicates when k = 0
                        nextDigits.push_back(lastDigit - k);
                    }
                    
                    for (int nextDigit : nextDigits) {
                        if (nextDigit >= 0 && nextDigit <= 9) {
                            int nextNum = num * 10 + nextDigit;
                            q.push(nextNum);
                        }
                    }
                }
            }
            
            // Convert queue to vector for the result
            vector<int> result;
            while (!q.empty()) {
                result.push_back(q.front());
                q.pop();
            }
            
            return result;
        }
    };
    