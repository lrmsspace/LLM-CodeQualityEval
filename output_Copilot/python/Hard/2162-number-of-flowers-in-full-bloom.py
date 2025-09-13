#https://leetcode.com/problems/number-of-flowers-in-full-bloom/
#You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.
#Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.
# 
#Example 1:
#Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
#Output: [1,2,2,2]
#Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
#For each person, we return the number of flowers in full bloom during their arrival.
#Example 2:
#Input: flowers = [[1,10],[3,3]], people = [3,3,2]
#Output: [2,2,1]
#Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
#For each person, we return the number of flowers in full bloom during their arrival.
# 
#Constraints:
#	1 <= flowers.length <= 5 * 104
#	flowers[i].length == 2
#	1 <= starti <= endi <= 109
#	1 <= people.length <= 5 * 104
#	1 <= people[i] <= 109
class Solution(object):
    def fullBloomFlowers(self, flowers, people):
        """
        :type flowers: List[List[int]]
        :type people: List[int]
        :rtype: List[int]
        """
        # Sort the flowers by their start time
        flowers.sort(key=lambda x: x[0])
        
        # Create a list to store the number of flowers in bloom at each person's arrival time
        bloom_count = [0] * len(people)
        
        # Create a list of tuples (time, type) for all flower start and end times
        events = []
        for start, end in flowers:
            events.append((start, 1))  
            events.append((end + 1, -1))
        events.sort()

        # Create a list of tuples (time, index) for all people arrival times
        # This will help us to keep track of the original indices of the people
        people_with_index = [(time, i) for i, time in enumerate(people)]
        people_with_index.sort()
        people_count = 0

        event_index = 0
        num_events = len(events)
        num_people = len(people_with_index)
        for time, index in people_with_index:
            # Process all events that occur before or at the same time as the current person
            while event_index < num_events and events[event_index][0] <= time:
                people_count += events[event_index][1]
                event_index += 1
            # Store the number of flowers in bloom for this person
            bloom_count[index] = people_count


        return bloom_count      