/**https://leetcode.com/problems/number-of-operations-to-make-network-connected/ */
//There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
//You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
//Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[0,2],[1,2]]
//Output: 1
//Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
//Example 2:
//Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
//Output: 2
//Example 3:
//Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
//Output: -1
//Explanation: There are not enough cables.
// 
//Constraints:
//	1 <= n <= 105
//	1 <= connections.length <= min(n * (n - 1) / 2, 105)
//	connections[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	There are no repeated connections.
//	No two computers are connected by more than one cable.
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    int i,j,k,l,m,n1,n2,c,d,e,f,g,h,t,u,v,w,x,y,z;
    int *a,*b,*c1,*d1,*e1,*f1,*g1,*h1;
    a=(int *)malloc(sizeof(int)*n);
    b=(int *)malloc(sizeof(int)*n);
    c1=(int *)malloc(sizeof(int)*n);
    d1=(int *)malloc(sizeof(int)*n);
    e1=(int *)malloc(sizeof(int)*n);
    f1=(int *)malloc(sizeof(int)*n);    
    g1=(int *)malloc(sizeof(int)*n);
    h1=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        a[i]=i;
    }
    for(i=0;i<connectionsSize;i++){
        n1=connections[i][0];
        n2=connections[i][1];
        for(j=0;j<n;j++){
            if(a[j]==n1){
                a[j]=n2;
            }
            if(a[j]==n2){
                a[j]=n1;
            }
        }
    }
    for(i=0;i<n;i++){
        b[i]=a[i];
    }
    for(i=0;i<n;i++){
        c1[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]==i){
                c1[i]++;
            }
        }
    }
    for(i=0;i<n;i++){
        d1[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]==i){
                d1[i]+=c1[j];
            }
        }
    }
    for(i=0;i<n;i++){
        e1[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]==i){
                e1[i]+=d1[j];
            }
        }
    }
    for(i=0;i<n;i++){
        f1[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]==i){
                f1[i]+=e1[j];
            }
        }
    }
    for(i=0;i<n;i++){
        g1[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]==i){
                g1[i]+=f1[j];
            }
        }
    }
    for(i=0;i<n;i++){
        h1[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]==i){
                h1[i]+=g1[j];
            }
        }
    }
    for(i=0;i<n;i++){   
        if(h1[i]==0){
            return -1;
        }
    }
    return h1[0]-1;
}