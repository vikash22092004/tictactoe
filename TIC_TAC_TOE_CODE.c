#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},2
                    {' ', ' ', ' '}};

int mux(int a, int b, int c) {
  return c ? b : a;
}

void display_board() {
  printf("\n");
  printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

int check_win() {
  int i;
  // Check rows
  for (i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return 1;
    }
  }
  // Check columns
  for (i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return 1;
    }
  }
  // Check diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return 1;
  }
  if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
    return 1;
  }
  return 0;
}

int main() {
  int i, j, player = 1, x, y, win = 0;
  for (i = 0; i < 9 && !win; i++) {
    display_board();
    printf("Player %d, enter your move (row column): ", mux(2, 1, player));
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (board[x][y] != ' ') {
      printf("Invalid move!\n");
      i--;
    } else {
      board[x][y] = mux('O', 'X', player);
      player = !player;
      win = check_win();
    }
  }
  display_board();
  if (win) {
    printf("Player %d wins!\n", mux(1, 2, player));
  } 
  else 
  {
    printf("Draw!\n");
}

}
