/**https://leetcode.com/problems/course-schedule-iii/ */
//There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
//You will start on the 1st day and you cannot take two or more courses simultaneously.
//Return the maximum number of courses that you can take.
// 
//Example 1:
//Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
//Output: 3
//Explanation: 
//There are totally 4 courses, but you can take 3 courses at most:
//First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
//Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
//Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
//The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
//Example 2:
//Input: courses = [[1,2]]
//Output: 1
//Example 3:
//Input: courses = [[3,2],[4,3]]
//Output: 0
// 
//Constraints:
//	1 <= courses.length <= 104
//	1 <= durationi, lastDayi <= 104
int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    // Sort the courses by the end date in ascending order
    qsort(courses, coursesSize, sizeof(courses[0]), cmp);
    
    // Initialize the heap to store the end dates of courses
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int totalDays = 0;
    for (int i = 0; i < coursesSize; i++) {
        int duration = courses[i][0];
        int lastDay = courses[i][1];
        
        // If the total days plus the duration of the current course does not exceed the last day,
        // add the current course's end date to the heap and update the total days
        if (totalDays + duration <= lastDay) {
            pq.push(lastDay);
            totalDays += duration;
        }
        // If the total days plus the duration of the current course exceeds the last day,
        // remove the course with the earliest end date from the heap until the total days plus the duration of the current course does not exceed the last day
        else {
            while (totalDays + duration > lastDay &&!pq.empty()) {
                totalDays -= pq.top();
                pq.pop();
            }
            if (totalDays + duration <= lastDay) {
                pq.push(lastDay);
                totalDays += duration;
            }
        }
    }
    
    // Return the number of courses that can be taken
    return pq.size();
}