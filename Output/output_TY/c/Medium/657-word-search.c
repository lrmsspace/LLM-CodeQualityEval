/**https://leetcode.com/problems/word-search/ */
//Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// 
//Example 1:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//Output: true
//Example 2:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
//Output: true
//Example 3:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
//Output: false
// 
//Constraints:
//	m == board.length
//	n = board[i].length
//	1 <= m, n <= 6
//	1 <= word.length <= 15
//	board and word consists of only lowercase and uppercase English letters.
// 
//Follow up: Could you use search pruning to make your solution faster with a larger board?
bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int i,j,k,m,n,l,flag,count,x,y;
    m=boardSize;
    n=*boardColSize;
    l=strlen(word);
    flag=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(board[i][j]==word[0]){
                count=1;
            }
        }
    }
    if(count==0){
        return false;
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(board[i][j]==word[0]){
                for(k=0;k<4;k++){
                    x=i;
                    y=j;
                    if(k==0){
                        x=i-1;
                    }
                    else if(k==1){
                        x=i+1;
                    }
                }
            }
        }
    }
    return true;
}