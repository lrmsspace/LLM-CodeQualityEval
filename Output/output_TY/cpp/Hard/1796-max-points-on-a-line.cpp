/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2){
            return n;
        }
        int ans = 2;
        for(int i=0;i<n;i++){
            map<pair<int,int>,int> mp;
            for(int j=i+1;j<n;j++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int gcd = __gcd(dx,dy);
                mp[{dx/gcd,dy/gcd}]++;
            }
            int max_count = 0;
            for(auto it:mp){
                max_count = max(max_count,it.second);
            }
            ans = max(ans,max_count+1);
        }
        return ans;
    }
};