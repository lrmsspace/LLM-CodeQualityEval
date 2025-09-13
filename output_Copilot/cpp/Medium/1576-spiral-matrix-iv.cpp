/**https://leetcode.com/problems/spiral-matrix-iv/ */
//You are given two integers m and n, which represent the dimensions of a matrix.
//You are also given the head of a linked list of integers.
//Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
//Return the generated matrix.
// 
//Example 1:
//Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
//Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
//Explanation: The diagram above shows how the values are printed in the matrix.
//Note that the remaining spaces in the matrix are filled with -1.
//Example 2:
//Input: m = 1, n = 4, head = [0,1,2]
//Output: [[0,1,2,-1]]
//Explanation: The diagram above shows how the values are printed from left to right in the matrix.
//The last space in the matrix is set to -1.
// 
//Constraints:
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	The number of nodes in the list is in the range [1, m * n].
//	0 <= Node.val <= 1000
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = 0, k = 0, l = 0, r = n - 1, u = 0, d = m - 1;
        while (k < nums.size()) {
            for (j = l; j <= r && k < nums.size(); ++j) {
                res[u][j] = nums[k++];
            }
            ++u;
            for (i = u; i <= d && k < nums.size(); ++i) {
                res[i][r] = nums[k++];
            }
            --r;
            for (j = r; j >= l && k < nums.size(); --j) {
                res[d][j] = nums[k++];
            }
            --d;
            for (i = d; i >= u && k < nums.size(); --i) {
                res[i][l] = nums[k++];
            }
            ++l;
        }  
        return res;      
    }
};