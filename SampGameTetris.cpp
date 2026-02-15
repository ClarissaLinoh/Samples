#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//double linklist untuk pemilihan menu
typedef struct mode {
    char name[50];
    int size;
    struct mode *next;
    struct mode *prev;
} Mode;

Mode* createMode(const char *name, int size) {
    Mode *newMode = (Mode*)malloc(sizeof(Mode));
    strcpy(newMode->name, name);
    newMode->size = size;
    newMode->next = NULL;
    newMode->prev = NULL;
    return newMode;
}

int graph; // global var

// tampilkan preview mode
int showMode(Mode *m) {
    system("cls");
    printf("\nUse LEFT/RIGHT arrows to choose a mode.\nPress ENTER to confirm, ESC to go back.\n");

    printf("\n============================\n");
    printf("%s Mode\n", m->name);
    printf("----------------------------\n");

    graph = m->size;
    for (int i = 0; i < graph; i++) {
        for (int j = 0; j < graph; j++) {
            printf(". ");
        }
        printf("\n");
    }
    return graph;
}

// fungsi menggambar papan dengan blok bergerak
void petaEasy(int size) {
    char board[32][32]; // batas maksimal ukuran 16x16

    // posisi awal blok
    int posX = 2, posY = 2;

    // bentuk blok sederhana (2x2)
    int block[2][2] = {
        {1, 1},
        {1, 1}
    };

    // loop utama untuk gerakan manual
    while (1) {
        system("cls");
        printf("Gunakan WASD untuk bergerak, ESC untuk keluar.\n\n");

        // bersihkan papan
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = '.';
            }
        }

        // gambar blok pada posisi sekarang
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int bx = posX + j;
                int by = posY + i;
                if (bx >= 0 && bx < size && by >= 0 && by < size && block[i][j] == 1) {
                    board[by][bx] = '#';
                }
            }
        }

        // tampilkan papan
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // baca input gerakan
        char c = getch();
        if (c == 'a' || c == 'A') {
            if (posX > 0) posX--; // kiri
        } else if (c == 'd' || c == 'D') {
            if (posX < size - 2) posX++; // kanan
        } else if (c == 'w' || c == 'W') {
            if (posY > 0) posY--; // atas
        } else if (c == 's' || c == 'S') {
            if (posY < size - 2) posY++; // bawah
        } else if (c == 27) { // ESC
            break;
        }
    }
}

// menu pemilihan mode --> pakai prinsip double linklist
void menu1() {
    Mode *modeEasy = createMode("Easy", 8);
    Mode *modeMedium = createMode("Medium", 12);
    Mode *modeHard = createMode("Hard", 16);

    modeEasy->next = modeMedium;
    modeMedium->prev = modeEasy;
    modeMedium->next = modeHard;
    modeHard->prev = modeMedium;

    Mode *current = modeEasy;
    int key;

    while (1) {
        showMode(current);
        key = getch();

        if (key == 0 || key == 224) {
            key = getch();
            if (key == 75 && current->prev) current = current->prev;
            else if (key == 77 && current->next) current = current->next;
        } else if (key == 13) { // ENTER
            system("cls");
            printf("%s mode dipilih!\n", current->name);
            petaEasy(current->size);
            break;
        } else if (key == 27) { // ESC
            printf("\nKembali ke menu utama...\n");
            break;
        }
    }

    free(modeEasy);
    free(modeMedium);
    free(modeHard);
}

void menu2() {
    system("cls");
    printf("Gamess\n");
    printf("------------------ HOW TO PLAY -----------------------\n");
    printf("W - move up\nS - move down\nA - move left\nD - move right\nESC - return\n");
    printf("\nPress any key to return to menu...");
    getch();
}

void menu3() {
    system("cls");
    printf("Goodbyee!\n");
}

int main() {
    int input;
    do {
        system("cls");
        printf("=== GAMESS ===\n");
        printf("1. New Game\n");
        printf("2. How To Play\n");
        printf("3. Exit\n");
        printf("=================\n");
        printf(">> ");
        scanf("%d", &input);
        getchar();

        switch (input) {
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                menu3();
                break;
            default:
                printf("Input tidak valid!");
                getch();
        }
    } while (input != 3);

    return 0;
}


