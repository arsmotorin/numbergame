#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function
int main() {

    // Generator for random numbers
    srand(time(0));

    int secretNumber = rand() % 100 + 1; // Random number between 1 and 100 (+1 to include 100)
    int guess;
    int attempts = 0;
    int maxAttempts = 10;

    printf("Hello! 'Guess the number'!\n");
    printf("1-100. You have %d attempts.\n", maxAttempts);

    // Main game loop
    do {
        // Ask the player for a guess
        printf("Enter your number: ");
        scanf("%d", &guess); // %d is used for integers (like 5, 10, etc.)
        attempts++;

        if (guess > secretNumber) {
            printf("Tip: smaller... Attempts: %d\n", maxAttempts - attempts);
        } else if (guess < secretNumber) {
            printf("Tip: bigger. Attempts: %d\n", maxAttempts - attempts);
        } else {
            printf("Congratulations! You have guessed the number %d in %d attempts!\n", secretNumber, attempts);
            break;
        }

        if (attempts >= maxAttempts) {
            printf("Game over. My number was: %d\n", secretNumber);
            break;
        }
    } while (1); // Infinite loop until break is called

    printf("Do you want to play again? (1/0): ");
    int playAgain;
    scanf("%d", &playAgain);

    if (playAgain == 1) {
        main();
    } else {
        printf("Good game! Bye.\n");
    }

    return 0;
}