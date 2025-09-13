/**https://leetcode.com/problems/possible-bipartition/ */
//We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
//Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
// 
//Example 1:
//Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
//Output: true
//Explanation: The first group has [1,4], and the second group has [2,3].
//Example 2:
//Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
//Output: false
//Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
// 
//Constraints:
//	1 <= n <= 2000
//	0 <= dislikes.length <= 104
//	dislikes[i].length == 2
//	1 <= ai < bi <= n
//	All the pairs of dislikes are unique.
bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
    int i,j;
    int *color = (int *)calloc(n+1,sizeof(int));
    int **graph = (int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++){
        graph[i] = (int *)calloc(n+1,sizeof(int));
    }
    for(i=0;i<dislikesSize;i++){
        graph[dislikes[i][0]][dislikes[i][1]] = 1;
    }
    for(i=1;i<=n;i++){
        if(color[i]==0){
            color[i] = 1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(j=1;j<=n;j++){
                    if(graph[cur][j]==1){   
                        if(color[j]==color[cur]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}