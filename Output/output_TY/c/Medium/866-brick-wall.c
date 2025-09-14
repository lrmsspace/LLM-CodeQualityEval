/**https://leetcode.com/problems/brick-wall/ */
//There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.
//Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
//Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.
// 
//Example 1:
//Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
//Output: 2
//Example 2:
//Input: wall = [[1],[1],[1]]
//Output: 3
// 
//Constraints:
//	n == wall.length
//	1 <= n <= 104
//	1 <= wall[i].length <= 104
//	1 <= sum(wall[i].length) <= 2 * 104
//	sum(wall[i]) is the same for each row i.
//	1 <= wall[i][j] <= 231 - 1
int leastBricks(int** wall, int wallSize, int* wallColSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int *a,*b,*c,*d,*e,*f,*g,*h,*i,*j,*k,*l,*m,*n,*o,*p,*q,*r,*s,*t,*u,*v,*w,*x,*y,*z;
    a=(int *)calloc(wallSize,sizeof(int));
    b=(int *)calloc(wallSize,sizeof(int));
    for(i=0;i<wallSize;i++){
        for(j=0;j<wallColSize[i]-1;j++){
            a[i]+=wall[i][j];
        }
    }
    for(i=0;i<wallSize;i++){
        b[i]=a[i]%wallColSize[i];
    }
    for(i=0;i<wallSize;i++){
        for(j=0;j<wallSize;j++){
            if(i==j){
                continue;
            }
            if(b[i]==b[j]){
                a[i]+=wallColSize[i]-wallColSize[j];
                b[i]=a[i]%wallColSize[i];
            }
        }
    }
    return wallSize-*max_element(a,a+wallSize);
}