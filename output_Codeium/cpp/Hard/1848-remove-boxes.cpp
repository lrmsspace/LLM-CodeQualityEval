/**https://leetcode.com/problems/remove-boxes/ */
//You are given several boxes with different colors represented by different positive numbers.
//You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
//Return the maximum points you can get.
// 
//Example 1:
//Input: boxes = [1,3,2,2,2,3,4,3,1]
//Output: 23
//Explanation:
//[1, 3, 2, 2, 2, 3, 4, 3, 1] 
//----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
//----> [1, 3, 3, 3, 1] (1*1=1 points) 
//----> [1, 1] (3*3=9 points) 
//----> [] (2*2=4 points)
//Example 2:
//Input: boxes = [1,1,1]
//Output: 9
//Example 3:
//Input: boxes = [1]
//Output: 1
// 
//Constraints:
//	1 <= boxes.length <= 100
//	1 <= boxes[i] <= 100
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<int> dp(n, 0);
        function<int(int, int, int)> dfs = [&](int l, int r, int k) {
            if (l > r) return 0;
            if (dp[l]) return dp[l];

            int i = l + 1;
            while (i <= r && boxes[i] == boxes[l]) i++;
            int cur = (k + i - l) * (k + i - l) + dfs(i, r, 0);

            for (int j = i; j <= r; ++j) {
                if (boxes[j] == boxes[l]) {
                    cur = max(cur, dfs(i, j - 1, k + i - l) + dfs(j, r, 0));
                }
            }

            return dp[l] = cur;
        };

        return dfs(0, n - 1, 0);
    }
};