/**https://leetcode.com/problems/couples-holding-hands/ */
//There are n couples sitting in 2n seats arranged in a row and want to hold hands.
//The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
//Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.
// 
//Example 1:
//Input: row = [0,2,1,3]
//Output: 1
//Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
//Example 2:
//Input: row = [3,2,0,1]
//Output: 0
//Explanation: All couples are already seated side by side.
// 
//Constraints:
//	2n == row.length
//	2 <= n <= 30
//	n is even.
//	0 <= row[i] < 2n
//	All the elements of row are unique.
int minSwapsCouples(int* row, int rowSize) {
    int n = rowSize / 2;
    int *pos = (int *)malloc(sizeof(int) * rowSize);
    for (int i = 0; i < rowSize; i++) {
        pos[row[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = row[2 * i];
        int y = row[2 * i + 1];
        if (x % 2 == 0) {
            if (y != x + 1) {
                int tmp = row[pos[x + 1]];
                row[pos[x + 1]] = y;
                row[pos[y]] = tmp;
                pos[tmp] = pos[x + 1];
                pos[y] = pos[x + 1];
                ans++;
            }
        } else {
            if (y != x - 1) {
                int tmp = row[pos[x - 1]];
                row[pos[x - 1]] = y;
                row[pos[y]] = tmp;
                pos[tmp] = pos[x - 1];
                pos[y] = pos[x - 1];
                ans++;
            }
        }
    }
    return ans;    
}