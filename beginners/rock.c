#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define MAX 3

void choose(int *n);
long int random();

struct choice {
    char *name;
    int n;
};

struct options {
    struct choice choice[MAX];
};

int main() {

    struct options o = {
        .choice = {
            [0].name = "Rock",
            [0].n = 1,

            [1].name = "Paper",
            [1].n = 2,

            [2].name = "Scissors",
            [2].n = 3,
        }
    };

    int n = 0;

    int pc = random();

    while ((n <= 0) || (n >= 4)) {
        choose(&n);
    }

    for (int i = 0; i <= 2; i++) {
        if (n == o.choice[i].n) {
            printf("You chose %s.\n", o.choice[i].name);
        }
    }

    for (int i = 0; i <= 2; i++) {
        if (pc == o.choice[i].n) {
            printf("The computer chose %s.\n", o.choice[i].name);
        }
    }

    if (n == pc) {
        printf("It's a draw!\n");

        return 0;
    }

    switch (n) {
        case 1:
            if (pc == 2) {
                printf("You lose!\n");
            } else {
                printf("You win!\n");
        }
            break;

        case 2:
            if (pc == 3) {
                printf("You lose!\n");
            } else {
                printf("You win!\n");
        }
            break;

        case 3:
            if (pc == 1) {
                printf("You lose!\n");
            } else {
                printf("You win!\n");
        }
            break;
    }

    return 0;
}

void choose(int *n) {
    printf("Options:\n");
    printf("1 - Rock\n");
    printf("2 - Paper\n");
    printf("3 - Scissors\n");
    printf("Choose one: ");
    scanf("%d", n);
}

long int random() {
    srand(time(0));
    return (rand() % 3) + 1;
}

