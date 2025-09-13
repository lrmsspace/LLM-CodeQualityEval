/**https://leetcode.com/problems/minimum-time-to-make-rope-colorful/ */
//Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
//Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
//Return the minimum time Bob needs to make the rope colorful.
// 
//Example 1:
//Input: colors = "abaac", neededTime = [1,2,3,4,5]
//Output: 3
//Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
//Bob can remove the blue balloon at index 2. This takes 3 seconds.
//There are no longer two consecutive balloons of the same color. Total time = 3.
//Example 2:
//Input: colors = "abc", neededTime = [1,2,3]
//Output: 0
//Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
//Example 3:
//Input: colors = "aabaa", neededTime = [1,2,3,4,1]
//Output: 2
//Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
//There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
// 
//Constraints:
//	n == colors.length == neededTime.length
//	1 <= n <= 105
//	1 <= neededTime[i] <= 104
//	colors contains only lowercase English letters.
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<int> count(26, 0);
        for (char c : colors) {
            count[c - 'a']++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.push({count[i], i});
            }
        }
        
        int ans = 0;
        while (pq.size() > 1) {
            auto [c1, color1] = pq.top(); pq.pop();
            auto [c2, color2] = pq.top(); pq.pop();
            
            ans += neededTime[color1];
            ans += neededTime[color2];
            
            c1--;
            c2--;
            if (c1 > 0) {
                pq.push({c1, color1});
            }
            if (c2 > 0) {
                pq.push({c2, color2});
            }
        }
        
        return ans;
        
    }
};