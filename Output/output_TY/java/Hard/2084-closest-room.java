/**https://leetcode.com/problems/closest-room/ */
//There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where rooms[i] = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size equal to sizei. Each roomIdi is guaranteed to be unique.
//You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej]. The answer to the jth query is the room number id of a room such that:
//	The room has a size of at least minSizej, and
//	abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
//If there is a tie in the absolute difference, then use the room with the smallest such id. If there is no such room, the answer is -1.
//Return an array answer of length k where answer[j] contains the answer to the jth query.
// 
//Example 1:
//Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
//Output: [3,-1,3]
//Explanation: The answers to the queries are as follows:
//Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, and its size of 2 is at least 1. The answer is 3.
//Query = [3,3]: There are no rooms with a size of at least 3, so the answer is -1.
//Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, and its size of 2 is at least 2. The answer is 3.
//Example 2:
//Input: rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
//Output: [2,1,3]
//Explanation: The answers to the queries are as follows:
//Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, and its size of 3 is at least 3. The answer is 2.
//Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. The answer is 1 since it is smaller.
//Query = [2,5]: Room number 3 is the only room with a size of at least 5. The answer is 3.
// 
//Constraints:
//	n == rooms.length
//	1 <= n <= 105
//	k == queries.length
//	1 <= k <= 104
//	1 <= roomIdi, preferredj <= 107
//	1 <= sizei, minSizej <= 107
class Solution {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        int n=rooms.length;
        int k=queries.length;
        int[] ans=new int[k];
        int[][] arr=new int[k][3];
        for(int i=0;i<k;i++){
            arr[i][0]=queries[i][0];
            arr[i][1]=queries[i][1];
            arr[i][2]=i;
        }
        Arrays.sort(rooms,(a,b)->(b[1]-a[1]));
        Arrays.sort(arr,(a,b)->(b[1]-a[1]));
        int j=0;
        TreeSet<Integer> set=new TreeSet<>();
        for(int i=0;i<k;i++){
            int l=arr[i][0];
            int r=arr[i][1];
            int idx=arr[i][2];
            while(j<k && rooms[j][0]<=r){
                set.add(rooms[j][1]);
                j++;
            }
            if(set.size()==0){
                ans[idx]=-1;
            }
            else{
                Integer x=set.floor(l);
                if(x==null){
                    ans[idx]=-1;
                }
                else{
                    ans[idx]=x;
                   set.remove(x);
                }
            }
        }  
        return ans; 
    }
}