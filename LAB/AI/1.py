from collections import deque

# Directions for moving in the maze: (up, down, left, right)
directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfs(maze, start, end):
    # Get number of rows and columns in the maze
    rows, cols = len(maze), len(maze[0])

    # Initialize a queue for BFS and add the start point with path length 0
    queue = deque([(start[0], start[1], [])])  # (row, col, path_to_this_point)

    # Set of visited positions to avoid cycles
    visited = set()
    visited.add(start)

    while queue:
        x, y, path = queue.popleft()

        # If we have reached the end point, return the path
        if (x, y) == end:
            return path + [(x, y)]

        # Explore all 4 possible directions (up, down, left, right)
        for dx, dy in directions:
            nx, ny = x + dx, y + dy

            # Check if the new position is within bounds and is walkable
            if 0 <= nx < rows and 0 <= ny < cols and maze[nx][ny] == 1:
                if (nx, ny) not in visited:
                    visited.add((nx, ny))
                    queue.append((nx, ny, path + [(x, y)]))

    # If no path exists
    return None

def get_maze_input():
    # Get maze dimensions
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    
    # Initialize maze with user input
    maze = []
    print("Enter the maze row by row (0 for wall, 1 for path):")
    for i in range(rows):
        row_input = input("Row " + str(i + 1) + ": ")
        row = list(map(int, row_input.split()))
        maze.append(row)
    
    return maze, rows, cols

# Main driver function
if __name__ == "__main__":
    # Get the maze from user input
    maze, rows, cols = get_maze_input()

    # Get the start and end points from the user
    start_x, start_y = map(int, input("Enter start coordinates (row col): ").split())
    end_x, end_y = map(int, input("Enter end coordinates (row col): ").split())
    
    # Ensure the start and end positions are valid
    if maze[start_x][start_y] == 0 or maze[end_x][end_y] == 0:
        print("Start or end position is blocked (wall). Please try again.")
    else:
        start = (start_x, start_y)
        end = (end_x, end_y)
        
        # Call the BFS function to find the shortest path
        path = bfs(maze, start, end)
        
        if path:
            print("Shortest path:", path)
        else:
            print("No path found.")
