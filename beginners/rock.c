#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <errno.h> 
#define MAX 3

void choose(long *n);
long random(void);

struct choice {
    char *name;
    int n;
};

struct options {
    struct choice choice[MAX];
};

int main(void) {

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

    long n = 0;

    long pc = random();

    for (;;) {
        if ((n <= 0) || (n >= 4)) {
            choose(&n);
        }
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
        default:
            printf("This shouldn't have happened.\n");
            break;
    }

    return 0;
}

void choose(long *n) {
    char temp[4] = "a\0";
    char *endptr;

    printf("\nOptions:\n");
    printf("1 - Rock\n");
    printf("2 - Paper\n");
    printf("3 - Scissors\n");
    printf("Choose one: ");
    if (fgets(temp, 4, stdin) == NULL) {
        printf("error: %d\n", errno);
    };
    *n = strtol(temp, &endptr, 10);

}

long random(void) {
    srand((unsigned int)time(0)); // this conversion isn't ideal, but I don't
    // mind losing the first part of this data
    return (rand() % 3) + 1;
}

