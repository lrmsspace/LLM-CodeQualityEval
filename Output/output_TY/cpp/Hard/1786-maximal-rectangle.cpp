/**https://leetcode.com/problems/maximal-rectangle/ */
//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 6
//Explanation: The maximal rectangle is shown in the above picture.
//Example 2:
//Input: matrix = [["0"]]
//Output: 0
//Example 3:
//Input: matrix = [["1"]]
//Output: 1
// 
//Constraints:
//	rows == matrix.length
//	cols == matrix[i].length
//	1 <= row, cols <= 200
//	matrix[i][j] is '0' or '1'.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int left[n], right[n], height[n];
        fill(left, left+n, -1);
        fill(right, right+n, n);
        fill(height, height+n, 0);
        int ans = 0;
        for(int i = 0; i < m; i++){
            int cur_left = -1, cur_right = n;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            if(left[i] == -1) left[i] = -1;
            else left[i] = left[i-1];
            while(cur_left + 1 < n && height[cur_left+1] >= height[i]) cur_left++;
            left[i] = cur_left;
            if(right[i] == n) right[i] = n;
            else right[i] = right[i-1];
            while(cur_right - 1 >= 0 && height[cur_right-1] >= height[i]) cur_right--;
            right[i] = cur_right;
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, height[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};