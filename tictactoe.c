#include <stdio.h>

char chess_board[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
char player = 'X';

void show_board();
void place_chess(char player);
char check();

int main() {
    int loop;
    show_board();
    for (loop = 1; loop <= 9; loop++) {
        place_chess(player);
        if (loop % 2 == 0)
            player = 'X';
        else
            player = 'O';
        system("cls");
        if (check() != 0) break;
        show_board();
    }
    printf("winner: %c !!!", check());
    system("pause");
    return 0;
}

void show_board() {
    int row = 0, col = 0;
    for (row = 0; row <= 2; row++) {
        for (col = 0; col <= 2; col++) {
            printf("%c", chess_board[row][col]);
        }
        printf("\n");
    }
}

void place_chess(char player) {
    int row = 0, col = 0, i = 1;
    for (; i > 0;) {
        printf("Rows and columns (e.g.0,0):\n");
        scanf("%d,%d", &row, &col);
        if (chess_board[row][col] == '.') {
            chess_board[row][col] = player;
            break;
        }
    }
}

char check() {
    if ((chess_board[0][0] == chess_board[0][1]) &&
        (chess_board[0][1] == chess_board[0][2]) &&
        (chess_board[0][0] != '.') == 1) {
        return chess_board[0][0];
    } else if ((chess_board[1][0] == chess_board[1][1]) &&
               (chess_board[1][1] == chess_board[1][2]) &&
               (chess_board[1][0] != '.') == 1) {
        return chess_board[1][0];
    } else if ((chess_board[2][0] == chess_board[2][1]) &&
               (chess_board[2][1] == chess_board[2][2]) &&
               (chess_board[2][0] != '.') == 1) {
        return chess_board[2][0];
    } else if ((chess_board[0][0] == chess_board[1][0]) &&
               (chess_board[1][0] == chess_board[2][0]) &&
               (chess_board[0][0] != '.') == 1) {
        return chess_board[0][0];
    } else if ((chess_board[0][1] == chess_board[1][1]) &&
               (chess_board[1][1] == chess_board[2][1]) &&
               (chess_board[0][1] != '.') == 1) {
        return chess_board[0][1];
    } else if ((chess_board[0][2] == chess_board[1][2]) &&
               (chess_board[1][2] == chess_board[2][2]) &&
               (chess_board[0][2] != '.') == 1) {
        return chess_board[0][2];
    } else if ((chess_board[0][0] == chess_board[1][1]) &&
               (chess_board[1][1] == chess_board[2][2]) &&
               (chess_board[0][0] != '.') == 1) {
        return chess_board[0][0];
    } else if ((chess_board[0][2] == chess_board[1][1]) &&
               (chess_board[1][1] == chess_board[2][0]) &&
               (chess_board[0][2] != '.') == 1) {
        return chess_board[0][2];
    } else {
        return 0;
    }
}
