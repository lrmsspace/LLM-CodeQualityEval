/**https://leetcode.com/problems/pascals-triangle-ii/ */
//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// 
//Example 1:
//Input: rowIndex = 3
//Output: [1,3,3,1]
//Example 2:
//Input: rowIndex = 0
//Output: [1]
//Example 3:
//Input: rowIndex = 1
//Output: [1,1]
// 
//Constraints:
//	0 <= rowIndex <= 33
// 
//Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>();
        row.add(1);
        
        if (rowIndex == 0) {
            return row;
        }
        
        for (int i = 1; i <= rowIndex; i++) {
            List<Integer> nextRow = new ArrayList<>();
            nextRow.add(1);
            for (int j = 1; j < i; j++) {
                nextRow.add(row.get(j-1) + row.get(j));
            }
            nextRow.add(1);
            row = nextRow;
        }
        
        return row;
        
    }
}