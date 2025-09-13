/**https://leetcode.com/problems/minimum-time-difference/ */
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// 
//Example 1:
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//Example 2:
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//Constraints:
//	2 <= timePoints.length <= 2 * 104
//	timePoints[i] is in the format "HH:MM".
int findMinDifference(char ** timePoints, int timePointsSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int a[1440]={0};
    for(i=0;i<timePointsSize;i++){
        a[atoi(timePoints[i])]=1;
    }
    for(i=0;i<1440;i++){
        if(a[i]==1){
            for(j=i+1;j<1440;j++){
                if(a[j]==1){
                    if(j-i<ans) ans=j-i;
                }
            }
        }
    }
    return ans;
}