import random

def generate_maze(rows, cols):
    maze = [['#'] * cols for _ in range(rows)]  # 初始化迷宫地图为全墙
    # 随机选择一个起始点作为入口
    start_row = random.randint(0, rows - 1)
    start_col = random.randint(0, cols - 1)
    maze[start_row][start_col] = '.'

    stack = [(start_row, start_col)]  # 使用栈保存当前路径的位置

    while stack:
        current_row, current_col = stack[-1]
        directions = [(0, 2), (2, 0), (0, -2), (-2, 0)]  # 上、下、左、右四个方向
        random.shuffle(directions)  # 随机打乱方向顺序

        found = False  #判断当前位置是否有可走的方向

        for direction in directions:
            next_row = current_row + direction[0]
            next_col = current_col + direction[1]

            if next_row >= 0 and next_row < rows and next_col >= 0 and next_col < cols and maze[next_row][next_col] == '#':
                maze[next_row][next_col] = '.'  # 打通当前位置和下一个位置之间的墙
                maze[current_row + direction[0] // 2][current_col + direction[1] // 2] = '.'  # 打通当前位置和下一个位置之间的墙
                stack.append((next_row, next_col))
                found = True
                break

        if not found:
            stack.pop()  # 如果当前位置没有可走的方向，则回退到上一个位置

    return maze


maze = generate_maze(50, 50)

# 打印迷宫地图
if __name__ == 'main':
    for row in maze:
        print(' '.join(row))
