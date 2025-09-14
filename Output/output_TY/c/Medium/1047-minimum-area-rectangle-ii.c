/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: points = [[1,2],[2,1],[1,0],[0,1]]
//Output: 2.00000
//Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
//Example 2:
//Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
//Output: 1.00000
//Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
//Example 3:
//Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
//Output: 0
//Explanation: There is no possible rectangle to form from these points.
// 
//Constraints:
//	1 <= points.length <= 50
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
double minAreaFreeRect(int** points, int pointsSize, int* pointsColSize){   
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    double a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    double ans=DBL_MAX;
    for(i=0;i<pointsSize;i++){
        for(j=i+1;j<pointsSize;j++){
            a=points[i][0]-points[j][0];
            b=points[i][1]-points[j][1];
            c=sqrt(a*a+b*b);
            for(k=j+1;k<pointsSize;k++){
                d=points[k][0]-points[i][0];
                e=points[k][1]-points[i][1];
            }
        }
    }
    return ans==DBL_MAX?0:ans;
}