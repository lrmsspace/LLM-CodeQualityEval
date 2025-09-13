/**https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/ */
//You are given a positive integer array grades which represents the grades of students in a university. You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:
//	The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
//	The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
//Return the maximum number of groups that can be formed.
// 
//Example 1:
//Input: grades = [10,6,12,7,3,5]
//Output: 3
//Explanation: The following is a possible way to form 3 groups of students:
//- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
//- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
//- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
//It can be shown that it is not possible to form more than 3 groups.
//Example 2:
//Input: grades = [8,8]
//Output: 1
//Explanation: We can only form 1 group, since forming 2 groups would lead to an equal number of students in both groups.
// 
//Constraints:
//	1 <= grades.length <= 105
//	1 <= grades[i] <= 105
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        vector<int> cnt(105);
        for (int i = 0; i < n; i++) {
            cnt[grades[i]]++;
        }
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) {
                continue;
            }
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += grades[i];
                }
            }
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    int new_mask = mask | (1 << i);
                    if (sum % 105 == 0) {
                        dp[new_mask] = max(dp[new_mask], dp[mask] + 1);
                    } else {
                        int rem = sum % 105;
                        int need = (105 - rem) % 105;
                        if (cnt[need] > 0) {
                            cnt[need]--;
                            dp[new_mask] = max(dp[new_mask], dp[mask]);
                        }
                    }
                }
            }
        }
        return dp[(1 << n) - 1];        
    }
};