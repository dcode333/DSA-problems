import math


class TicTacToeBoard:
    def __init__(self):
        self.board = [['.' for _ in range(3)] for _ in range(3)]

    def get_possible_moves(self):
        possible_moves = []
        for i in range(3):
            for j in range(3):
                if self.board[i][j] == '.':
                    possible_moves.append((i, j))
        return possible_moves

    def make_move(self, move, mark):
        self.board[move[0]][move[1]] = mark

    def undo(self):
        for i in range(3):
            for j in range(3):
                if self.board[i][j] != '.':
                    self.board[i][j] = '.'
                    return

    def get_state(self):
        for row in self.board:
            if row[0] == row[1] and row[1] == row[2] and row[0] != '.':
                return "WIN"
        for i in range(3):
            if self.board[0][i] == self.board[1][i] and self.board[1][i] == self.board[2][i] and self.board[0][i] != '.':
                return "WIN"
        if self.board[0][0] == self.board[1][1] and self.board[1][1] == self.board[2][2] and self.board[0][0] != '.':
            return "WIN"
        if self.board[0][2] == self.board[1][1] and self.board[1][1] == self.board[2][0] and self.board[0][2] != '.':
            return "WIN"
        if '.' not in [item for sublist in self.board for item in sublist]:
            return "DRAW"
        else:
            return "NOT_OVER"

    def get_winner(self):
        if self.get_state() == "WIN":
            for row in self.board:
                if row[0] == row[1] and row[1] == row[2] and row[0] != '.':
                    return row[0]
            for i in range(3):
                if self.board[0][i] == self.board[1][i] and self.board[1][i] == self.board[2][i] and self.board[0][i] != '.':
                    return self.board[0][i]
            if self.board[0][0] == self.board[1][1] and self.board[1][1] == self.board[2][2] and self.board[0][0] != '.':
                return self.board[0][0]
            if self.board[0][2] == self.board[1][1] and self.board[1][1] == self.board[2][0] and self.board[0][2] != '.':
                return self.board[0][2]


def minimax(isMaxTurn, maximizerMark, board, depth):
    if depth == 0:
        return -math.inf
    state = board.get_state()
    if (state == "DRAW"):
        return 0
    elif (state == "WIN"):
        return 1 if board.get_winner() == maximizerMark else -1

    scores = []
    for move in board.get_possible_moves():
        board.make_move(move, maximizerMark)
        scores.append(minimax(not isMaxTurn, maximizerMark, board, depth-1))
        board.undo()

    return max(scores) if isMaxTurn else min(scores)


def make_best_move(board, aiPlayer, humanPlayer):
    if board is None:
        return None
    bestScore = -math.inf
    bestMove = None
    for move in board.get_possible_moves():
        board.make_move(move, aiPlayer)
        score = minimax(False, humanPlayer, board, 5)
        board.undo()
        if (score > bestScore):
            bestScore = score
            bestMove = move
    if bestMove:
        board.make_move(bestMove, aiPlayer)
        return bestMove
    return None


ticTacBoard = TicTacToeBoard()
aiPlayer = "X"
humanPlayer = "O"

print(ticTacBoard.board)  # printing the initial board
print(ticTacBoard.get_possible_moves())  # printing the possible moves
best_move = make_best_move(ticTacBoard, aiPlayer, humanPlayer)
print(best_move)
