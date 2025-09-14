/*
 You are given a 2D array events which represents a sequence of events where a child pushes a series of buttons on a keyboard.
 Each events[i] = [indexi, timei] indicates that the button at index indexi was pressed at time timei.
 The array is sorted in increasing order of time.
 The time taken to press a button is the difference in time between consecutive button presses. The time for the first button is simply the time at which it was pressed.
 Return the index of the button that took the longest time to push. If multiple buttons have the same longest time, return the button with the smallest index.
 Example 1:
 Input: events = [[1,2],[2,5],[3,9],[1,15]]
 Output: 1
 Explanation:
 Button with index 1 is pressed at time 2.
 Button with index 2 is pressed at time 5, so it took 5 - 2 = 3 units of time.
 Button with index 3 is pressed at time 9, so it took 9 - 5 = 4 units of time.
 Button with index 1 is pressed again at time 15, so it took 15 - 9 = 6 units of time.
 Example 2:
 Input: events = [[10,5],[1,7]]
 Output: 10
 Explanation:
 Button with index 10 is pressed at time 5.
 Button with index 1 is pressed at time 7, so it took 7 - 5 = 2 units of time.
 Constraints:
 1 <= events.length <= 1000
 events[i] == [indexi, timei]
 1 <= indexi, timei <= 105
 The input is generated such that events is sorted in increasing order of timei.
*/

class Solution {
    public int buttonWithLongestTime(int[][] events) {
        int maxTime = 0;
        int buttonIndex = -1;
        int lastTime = 0;

        for (int[] event : events) {
            int index = event[0];
            int time = event[1];

            // Calculate the time taken to press the button
            int timeTaken = time - lastTime;

            // Check if this button has the longest time taken
            if (timeTaken > maxTime || (timeTaken == maxTime && index < buttonIndex)) {
                maxTime = timeTaken;
                buttonIndex = index;
            }

            // Update the last time to the current event's time
            lastTime = time;
        }

        return buttonIndex;
        
    }
}