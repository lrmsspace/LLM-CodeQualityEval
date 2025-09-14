#https://leetcode.com/problems/task-scheduler/
#You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
#Return the minimum number of CPU intervals required to complete all tasks.
# 
#Example 1:
#Input: tasks = ["A","A","A","B","B","B"], n = 2
#Output: 8
#Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
#After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
#Example 2:
#Input: tasks = ["A","C","A","B","D","B"], n = 1
#Output: 6
#Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
#With a cooling interval of 1, you can repeat a task after just one other task.
#Example 3:
#Input: tasks = ["A","A","A", "B","B","B"], n = 3
#Output: 10
#Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
#There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
# 
#Constraints:
#	1 <= tasks.length <= 104
#	tasks[i] is an uppercase English letter.
#	0 <= n <= 100
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        # 统计每个任务的出现次数
        task_count = {}
        for task in tasks:
            if task in task_count:
                task_count[task] += 1
            else:
                task_count[task] = 1

        # 找到出现次数最多的任务的次数
        max_count = max(task_count.values())
        # 统计有多少个任务是出现次数最多的
        max_count_tasks = sum(1 for count in task_count.values() if count == max_count)

        # 计算最少的时间间隔
        return max(len(tasks), (max_count - 1) * (n + 1) + max_count_tasks)        