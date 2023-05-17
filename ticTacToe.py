def out_grid(grid):
    for row in grid:
        print(row)

def play_x(grid, i, j):
    grid[i][j] = 1

def play_o(grid, i, j):
    grid[i][j] = 2

def check_row(grid):
    for i in range(3):
        if grid[i][0] == grid[i][1] == grid[i][2] != 0:
            return True
    return False

def check_col(grid):
    for i in range(3):
        if grid[0][i] == grid[1][i] == grid[2][i] != 0:
            return True
    return False

def check_diag(grid):
    if grid[0][0] == grid[1][1] == grid[2][2] != 0:
        return True
    elif grid[0][2] == grid[1][1] == grid[2][0] != 0:
        return True
    else:
        return False

def won(grid):
    if check_col(grid) or check_row(grid) or check_diag(grid):
        return True
    else:
        return False

if __name__ == '__main__':
    grid = [[0 for _ in range(3)] for _ in range(3)]
    i = 0
    while not won(grid):
        if i == 8:
            print("Tie")
            break
        out_grid(grid)
        if i % 2 == 0:
            x, y = map(int, input("Enter pos for X: ").split(","))
            play_x(grid, x, y)
        else:
            x, y = map(int, input("Enter pos for O: ").split(","))
            play_o(grid, x, y)
        i += 1
    if i % 2 != 0:
        out_grid(grid)
        print("X Won")
    else:
        print("O Won")

