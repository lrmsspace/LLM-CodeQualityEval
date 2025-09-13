/**https://leetcode.com/problems/longest-cycle-in-a-graph/ */
//You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
//The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.
//Return the length of the longest cycle in the graph. If no cycle exists, return -1.
//A cycle is a path that starts and ends at the same node.
// 
//Example 1:
//Input: edges = [3,3,4,2,3]
//Output: 3
//Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
//The length of this cycle is 3, so 3 is returned.
//Example 2:
//Input: edges = [2,-1,3,1]
//Output: -1
//Explanation: There are no cycles in this graph.
// 
//Constraints:
//	n == edges.length
//	2 <= n <= 105
//	-1 <= edges[i] < n
//	edges[i] != i
int longestCycle(int* edges, int edgesSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int *visited=(int *)malloc(sizeof(int)*edgesSize);
    int *time=(int *)malloc(sizeof(int)*edgesSize);
    int *time2=(int *)malloc(sizeof(int)*edgesSize);
    for(i=0;i<edgesSize;i++){
        visited[i]=0;
        time[i]=0;
        time2[i]=0;
    }
    for(i=0;i<edgesSize;i++){
        if(visited[i]==0){
            int cur=i;
            int cnt=0;
            while(cur!=-1&&visited[cur]==0){
                visited[cur]=1;
                time[cur]=cnt;
                time2[cur]=cnt;
                cnt++;
                cur=edges[cur];
            }
        }
    }
    for(i=0;i<edgesSize;i++){
        if(visited[i]==1){
            int cur=i;
        }
    }
    for(i=0;i<edgesSize;i++){
        if(visited[i]==1){
            int cur=i;
            while(cur!=-1&&visited[cur]==1){
                visited[cur]=2;
                time2[cur]=time[cur];
                cur=edges[cur];
            }
        }
    }
    for(i=0;i<edgesSize;i++){
        if(visited[i]==2){
            int cur=i;
            while(cur!=-1&&visited[cur]==2){
                visited[cur]=3;
                time2[cur]=time[cur];
                cur=edges[cur];
            }
            if(cur!=-1){
                int cur2=cur;
                int cnt=0;
                while(cur2!=-1&&visited[cur2]==3){
                    visited[cur2]=4;
                    time2[cur2]=time[cur2];
                    cnt++;
                    cur2=edges[cur2];
                }
                if(cur2!=-1){
                   time2[cur2]=time[cur2];
                }
            }
        }
    }
    for(i=0;i<edgesSize;i++){
        if(visited[i]==4){
            int cur=i;
            while(cur!=-1&&visited[cur]==4){
                visited[cur]=5;
                time2[cur]=time[cur];
                cur=edges[cur];
            }
            if(cur!=-1){
                int cur2=cur;
                int cnt=0;
                while(cur2!=-1&&visited[cur2]==5){
                    visited[cur2]=6;
                    time2[cur2]=time[cur2];
                    cnt++;
                    cur2=edges[cur2];
                }
                if(cur2!=-1){
                  time2[cur2]=time[cur2];
                }
            }
        }
    }
    for(i=0;i<edgesSize;i++){
        if(visited[i]==6){
            int cur=i;
            while(cur!=-1&&visited[cur]==6){
                visited[cur]=7;
                time2[cur]=time[cur];
                cur=edges[cur];
            }
            if(cur!=-1){
                int cur2=cur;
                int cnt=0;
                while(cur2!=-1&&visited[cur2]==7){
                    visited[cur2]=8;
                    time2[cur2]=time[cur2];
                    cnt++;
                    cur2=edges[cur2];
                    if(cur2!=-1){
                      time2[cur2]=time[cur2];
                    }
                    if(cnt==2){
                        return time2[cur2]-time2[cur];
                    }
                }
            }
        }
    }
    return -1;
}