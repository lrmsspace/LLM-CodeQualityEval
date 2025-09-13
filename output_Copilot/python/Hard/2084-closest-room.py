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
        # Sort rooms by size in descending order
        rooms.sort(key=lambda x: -x[1])
        
        # Sort queries by minimum size in descending order, keeping track of the original index
        queries = sorted(enumerate(queries), key=lambda x: -x[1][1])
        
        result = [-1] * len(queries)       
        room_set = set()
        room_map = {}
        j = 0
        for idx, (preferred, min_size) in queries:
            # Add rooms that meet the size requirement to the room_set
            while j < len(rooms) and rooms[j][1] >= min_size:
                room_set.add(rooms[j][0])
                room_map[rooms[j][0]] = rooms[j][1]
                j += 1
            
            # Find the closest room to the preferred room number
            if room_set:
                closest_room = min(room_set, key=lambda x: (abs(x - preferred), x))
                result[idx] = closest_room

                # Remove the closest room from the set to avoid using it again
                room_set.remove(closest_room)
                del room_map[closest_room]
        return result