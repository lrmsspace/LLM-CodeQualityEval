#https://leetcode.com/problems/closest-room/
#There is a hotel with n rooms. The rooms are represented by a 2D integer array rooms where rooms[i] = [roomIdi, sizei] denotes that there is a room with room number roomIdi and size equal to sizei. Each roomIdi is guaranteed to be unique.
#You are also given k queries in a 2D array queries where queries[j] = [preferredj, minSizej]. The answer to the jth query is the room number id of a room such that:
#	The room has a size of at least minSizej, and
#	abs(id - preferredj) is minimized, where abs(x) is the absolute value of x.
#If there is a tie in the absolute difference, then use the room with the smallest such id. If there is no such room, the answer is -1.
#Return an array answer of length k where answer[j] contains the answer to the jth query.
# 
#Example 1:
#Input: rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
#Output: [3,-1,3]
#Explanation: The answers to the queries are as follows:
#Query = [3,1]: Room number 3 is the closest as abs(3 - 3) = 0, and its size of 2 is at least 1. The answer is 3.
#Query = [3,3]: There are no rooms with a size of at least 3, so the answer is -1.
#Query = [5,2]: Room number 3 is the closest as abs(3 - 5) = 2, and its size of 2 is at least 2. The answer is 3.
#Example 2:
#Input: rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
#Output: [2,1,3]
#Explanation: The answers to the queries are as follows:
#Query = [2,3]: Room number 2 is the closest as abs(2 - 2) = 0, and its size of 3 is at least 3. The answer is 2.
#Query = [2,4]: Room numbers 1 and 3 both have sizes of at least 4. The answer is 1 since it is smaller.
#Query = [2,5]: Room number 3 is the only room with a size of at least 5. The answer is 3.
# 
#Constraints:
#	n == rooms.length
#	1 <= n <= 105
#	k == queries.length
#	1 <= k <= 104
#	1 <= roomIdi, preferredj <= 107
#	1 <= sizei, minSizej <= 107
class Solution(object):
    def closestRoom(self, rooms, queries):
        """
        :type rooms: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        import bisect
        rooms.sort(key=lambda x: -x[1])
        m = len(queries)
        res = [-1] * m
        ids = [q[0] for q in queries]
        sorted_ids = sorted(ids)
        queries = sorted(zip(queries, range(m)), key=lambda x: -x[0][1])
        room_ids = [room[0] for room in rooms]
        i = 0
        for (preferred, minSize), j in queries:
            while i < len(rooms) and rooms[i][1] >= minSize:
                bisect.insort(room_ids, rooms[i][0])
                i += 1
            if len(room_ids) == 0:
                continue
            k = bisect.bisect_left(room_ids, preferred)
            if k == len(room_ids):
                res[j] = room_ids[-1]
            elif k == 0:
                res[j] = room_ids[0]
            else:
                res[j] = min(room_ids[k] - preferred, preferred - room_ids[k - 1], key=abs)
        return [room_ids[bisect.bisect_left(room_ids, x)] if x in room_ids else -1 for x in ids]
        