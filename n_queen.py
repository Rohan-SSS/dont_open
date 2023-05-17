def is_safe(board, row, col):
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] ==  1:
            return False
    
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] ==  1:
            return False
    return True

def solve(board, col):
    if col >= N:
        return True
    for i in range(N):
        if is_safe(board, i, col):
            board[i][col] = 1
            if solve(board, col+1) == True:
                return True
            board[i][col] = 0
    return False

def nq():
    board = [[0 for i in range(N)] for i in range(N)]
    if solve(board, 0) == False:
        print('no sol')
        return False
    for row in board:
        print(row)

if __name__ == '__main__':
    global N
    N = int (input ( "Enter N = " ))
    nq()