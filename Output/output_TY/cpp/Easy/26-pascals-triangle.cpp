/**https://leetcode.com/problems/pascals-triangle/ */
//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// 
//Example 1:
//Input: numRows = 5
//Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//Example 2:
//Input: numRows = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= numRows <= 30
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)
                    temp.push_back(1);
                else
                    temp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
        }
        return res;
    }
};