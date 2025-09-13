/**https://leetcode.com/problems/jump-game-iv/ */
//Given an array of integers arr, you are initially positioned at the first index of the array.
//In one step you can jump from index i to index:
//	i + 1 where: i + 1 < arr.length.
//	i - 1 where: i - 1 >= 0.
//	j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.
// 
//Example 1:
//Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
//Output: 3
//Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
//Example 2:
//Input: arr = [7]
//Output: 0
//Explanation: Start index is the last index. You do not need to jump.
//Example 3:
//Input: arr = [7,6,9,6,9,6,9,7]
//Output: 1
//Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
// 
//Constraints:
//	1 <= arr.length <= 5 * 104
//	-108 <= arr[i] <= 108
class Solution {
    public int minJumps(int[] arr) {
            int n=arr.length;
            if(n==1) return 0;
            HashMap<Integer,ArrayList<Integer>> map=new HashMap<>();
            for(int i=0;i<n;i++){
                if(map.containsKey(arr[i])) map.get(arr[i]).add(i);
                else{
                    ArrayList<Integer> list=new ArrayList<>();
                    list.add(i);
                    map.put(arr[i],list);
                }
            }
            boolean[] visited=new boolean[n];
            Queue<Integer> q=new LinkedList<>();
            q.add(0);
            int count=0;
            while(!q.isEmpty()){
                int cur=q.poll();
                visited[cur]=true;
                int x=cur/n;
                int y=cur%n;
                if(cur==n*m-1) count++;
                for(int[] dir:dirs){
                    int nx=x+dir[0];
                    int ny=y+dir[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx*n+ny] && grid[nx][ny]!=1){
                        q.add(nx*n+ny);
                    }
                }
            }
            level++;
            count*=level;
            count%=mod;
            level%=mod;
            return count;
    }
}