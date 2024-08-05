#include <stdio.h>
#include <string.h>

// Function to validate input and check if it is accepted by the DFA
int isAcceptedByDFA(const char *str) {
    int currentState = 0; // Start state

    for (int i = 0; i < strlen(str); i++) {
        // Check if the character is valid
        if (str[i] != 'a' && str[i] != 'b' && str[i] != 'c') {
            return -1; // Invalid character detected
        }

        // Determine the next state based on the current state and input character
        switch (currentState) {
            case 0:
                if (str[i] == 'a') currentState = 1;
                break;
            case 1:
                if (str[i] == 'b') currentState = 2;
                else if (str[i] == 'a') currentState = 1;
                else currentState = 0;
                break;
            case 2:
                if (str[i] == 'c') currentState = 3;
                else if (str[i] == 'a') currentState = 1;
                else currentState = 0;
                break;
            case 3:
                // Accept state, stays the same
                break;
        }
    }

    return currentState == 3 ? 1 : 0; // Return 1 if in accept state, 0 otherwise
}

int main() {
    char str[100];
    
    printf("Enter a string made of {a, b, c}: ");
    scanf("%s", str);

    int result = isAcceptedByDFA(str);

    if (result == -1) {
        printf("Invalid input! The string must only contain characters 'a', 'b', 'c'.\n");
    } else if (result == 1) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is not accepted by the DFA.\n");
    }

    return 0;
}

