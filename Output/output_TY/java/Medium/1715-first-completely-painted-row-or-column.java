/**https://leetcode.com/problems/first-completely-painted-row-or-column/ */
//You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
//Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
//Return the smallest index i at which either a row or a column will be completely painted in mat.
// 
//Example 1:
//Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
//Output: 2
//Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
//Example 2:
//Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
//Output: 3
//Explanation: The second column becomes fully painted at arr[3].
// 
//Constraints:
//	m == mat.length
//	n = mat[i].length
//	arr.length == m * n
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= arr[i], mat[r][c] <= m * n
//	All the integers of arr are unique.
//	All the integers of mat are unique.
class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int n=arr.length;
        int m=mat.length;
        int[][] row=new int[m][n];
        int[][] col=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i][j]=mat[i][j];
                col[i][j]=mat[i][j];
            }
        }
        int[] freq=new int[n+1];
        int count=0;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            if(freq[arr[i]]==1){
                count++;
            }
        } 
        for(int i=0;i<n;i++){
            int r=row[arr[i]-1]/n;
            int c=row[arr[i]-1]%n;
            row[r][c]=0;
            col[c][r]=0;
            if(row[r][0]==0){
                return i;
            }
            if(col[c][0]==0){
                return i;
            }
        }
        return -1;  
    }
}