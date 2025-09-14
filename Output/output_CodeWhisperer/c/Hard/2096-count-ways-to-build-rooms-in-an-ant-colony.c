/**https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/ */
//You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.
//You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.
//Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: prevRoom = [-1,0,1]
//Output: 1
//Explanation: There is only one way to build the additional rooms: 0 → 1 → 2
//Example 2:
//Input: prevRoom = [-1,0,0,1,2]
//Output: 6
//Explanation:
//The 6 ways are:
//0 → 1 → 3 → 2 → 4
//0 → 2 → 4 → 1 → 3
//0 → 1 → 2 → 3 → 4
//0 → 1 → 2 → 4 → 3
//0 → 2 → 1 → 3 → 4
//0 → 2 → 1 → 4 → 3
// 
//Constraints:
//	n == prevRoom.length
//	2 <= n <= 105
//	prevRoom[0] == -1
//	0 <= prevRoom[i] < n for all 1 <= i < n
//	Every room is reachable from room 0 once all the rooms are built.
int waysToBuildRooms(int* prevRoom, int prevRoomSize)
{
    int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0;
    long long ans = 0, mod = 1000000007;
    int* dp = (int*)malloc(sizeof(int) * prevRoomSize);

    for (i = 0; i < prevRoomSize; i++) {
        dp[i] = 0;
    }


    for (i = 1; i < prevRoomSize; i++) {
        dp[prevRoom[i]]++;
    }


    for (i = 0; i < prevRoomSize; i++) {
        if (dp[i] > max) {
            max = dp[i];
            cnt = 1;
        }
        else if (dp[i] == max) {
            cnt++;
        }
    }


    ans = max;
    for (i = 0; i < cnt; i++) {
        ans = (ans * (prevRoomSize - 1)) % mod;
    }


    for (i = 0; i < prevRoomSize; i++) {
        if (dp[i] == max) {
            for (j = 0; j < prevRoomSize; j++) {
                if (prevRoom[j] == i) {
                    for (k = 0; k < prevRoomSize; k++) {
                        if (prevRoom[k] == j) {
                            for (l = 0; l < prevRoomSize; l++) {
                                if (prevRoom[l] == k) {
                                    ans = (ans * 2) % mod;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    return (int)ans;


}