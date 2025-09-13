#https://leetcode.com/problems/robot-collisions/
#There are n 1-indexed robots, each having a position on a line, health, and movement direction.
#You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.
#All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.
#If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.
#Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final health of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.
#Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.
#Note: The positions may be unsorted.
# 
# 
#Example 1:
#Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
#Output: [2,17,9,15,10]
#Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
#Example 2:
#Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
#Output: [14]
#Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].
#Example 3:
#Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
#Output: []
#Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].
# 
#Constraints:
#	1 <= positions.length == healths.length == directions.length == n <= 105
#	1 <= positions[i], healths[i] <= 109
#	directions[i] == 'L' or directions[i] == 'R'
#	All values in positions are distinct
class Solution(object):
    def survivedRobotsHealths(self, positions, healths, directions):
        """
        :type positions: List[int]
        :type healths: List[int]
        :type directions: str
        :rtype: List[int]
        """
        # 1. 机器人位置、生命值、方向的组合
        robots = list(zip(positions, healths, directions))
        # 2. 按照位置排序
        robots.sort(key=lambda x: x[0])
        # 3. 初始化栈，用于存储剩余机器人的生命值
        stack = []
        # 4. 遍历机器人列表
        for pos, health, direction in robots:
            # 5. 如果方向是向右移动，直接添加到栈中
            if direction == 'R':
                stack.append(health)
            else:
                # 6. 如果方向是向左移动，处理与栈顶元素的碰撞
                while stack and stack[-1] > 0:
                    if stack[-1] > health:
                        stack[-1] -= 1     
                        break
                    elif stack[-1] < health:
                        health -= 1
                        stack.pop()
                    else:
                        stack.pop()
                        break
                # 7. 如果栈为空，说明没有碰撞，直接添加生命值
                # 8. 如果栈不为空，说明有碰撞，添加剩余生命值
                if health > 0:
                    stack.append(health)
        # 9. 返回栈中的生命值
        return stack   