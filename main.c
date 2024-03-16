#include <stdio.h>
#include <stdbool.h>
int x, y, count = 0;
char turn, winner;
bool gameover = false;

char table[5][5] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void ptable () {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
    count++;
}

void choice () {
    printf("Enter coordinate (X,Y) : ");
    scanf("%d,%d", &x, &y);
    if (table[x][y] == ' ') {
        table[x][y] = turn;
    }
    else {
        printf("This tile already occupied.\n");
    };
}

void cturn () {
    if (count % 2 == 0) {
        turn = 'O';
    }
    else {
        turn = 'X';
    }
}

char wcheck () {
    char arr[2] = {'X', 'O'};
    for (int i = 0; i < 2; i++) {
        int stemp;
        //Pattern 1 (Correct)
        for (int j = 0; j < 3; j++) {
            stemp = 0;
            for (int k = 0; k < 3; k++) {
                if (table[j][k] == arr[i]) {
                    stemp++;
                }
            }
            if (stemp == 3) {
                gameover = true;
                winner = arr[i];
            }
        }
        //Pattern 2 (Correct)
        for (int j = 0; j < 3; j++) {
            stemp = 0;
            for (int k = 0; k < 3; k++) {
                if (table[k][j] == arr[i]) {
                    stemp++;
                }
            }
            if (stemp == 3) {
                gameover = true;
                winner = arr[i];
            }
        }
        //Pattern 3 (Correct)
        stemp = 0;
        for (int j = 0; j < 3; j++) {
            if (table[j][j] == arr[i]) {
                stemp++;
            }
        }
        if (stemp == 3) {
            gameover = true;
            winner = arr[i];
        }
        //Pattern 4 (Correct)
        stemp = 0;
        int arrtemp[2] = {0,2};
        for (int j = 0; j < 3; j++) {
            if (table[arrtemp[0]][arrtemp[1]] == arr[i]) {
                stemp++;
                arrtemp[0]++;
                arrtemp[1]--;
            }
        }
        if (stemp == 3) {
            gameover = true;
            winner = arr[i];
        }
    }
}

int main () {
    while (gameover != true) {
        ptable();
        cturn();
        printf("It is %c turn.\n", turn);
        choice();
        wcheck();
        printf("--------------------------------------------\n");
    }
    printf("%c is winner!\n", winner);
}
