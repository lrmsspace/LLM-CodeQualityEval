/**https://leetcode.com/problems/kth-smallest-instructions/ */
//Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down. You are going to help Bob by providing instructions for him to reach destination.
//The instructions are represented as a string, where each character is either:
//	'H', meaning move horizontally (go right), or
//	'V', meaning move vertically (go down).
//Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.
//However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.
//Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.
// 
//Example 1:
//Input: destination = [2,3], k = 1
//Output: "HHHVV"
//Explanation: All the instructions that reach (2, 3) in lexicographic order are as follows:
//["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
//Example 2:
//Input: destination = [2,3], k = 2
//Output: "HHVHV"
//Example 3:
//Input: destination = [2,3], k = 3
//Output: "HHVVH"
// 
//Constraints:
//	destination.length == 2
//	1 <= row, column <= 15
//	1 <= k <= nCr(row + column, row), where nCr(a, b) denotes a choose b​​​​​.
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        
        int row = destination[0], col = destination[1];
        int row_left = row, col_left = col;
        string ans;
        while(row_left > 0 || col_left > 0){
            int row_choose = row_left - col_left;
            int col_choose = col_left - 1;
            int row_choose_num = 1;
            int col_choose_num = 1;
            while(row_choose > 0){
                row_choose_num *= row_choose;
                row_choose--;
            }
            while(col_choose > 0){
                col_choose_num *= col_choose;
               col_choose--;
            }
        }
        while(row_left > 0 && col_left > 0){
            int row_choose = row_left - col_left;
            int col_choose = col_left - 1;
            int row_choose_num = 1;
            int col_choose_num = 1;
            while(row_choose > 0){
                row_choose_num *= row_choose;
                row_choose--;
            }
            while(col_choose > 0){
                col_choose_num *= col_choose;
               col_choose--;
            }
            int choose_num = row_choose_num * col_choose_num;
            if(choose_num >= k){
                ans += 'H';
                row_left--;
                k -= row_choose_num;
                while(row_left > 0){
                    ans += 'V';
                    row_left--;
                }
            }
        }
        while(row_left > 0){
            ans += 'V';
            row_left--;
        }
        while(col_left > 0){
            ans += 'H';
            col_left--;
        }
        return ans;
    }
};