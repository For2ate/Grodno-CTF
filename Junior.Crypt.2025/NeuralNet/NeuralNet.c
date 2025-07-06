#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void unlock_secret_research_data() {
    printf("\n*** HIDDEN CORRELATION DETECTED! ***\n");
    printf("Access granted to 'Lead Data Scientist' research data...\n");
    printf("You've gained root access to the main dataset server.\n");
    system("/bin/sh");
}

void train_model() {
    printf("TRAINING: Model processed 1000 cat images. Accuracy is improving.\n");
}

void predict_outcome() {
    printf("PREDICTION: With 98.7%% probability, the image contains a cat.\n");
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    unsigned long addr_to_write;
    unsigned long value_to_write;
    int choice;

    printf("--- Neural Net Simulator v0.1 (by Alex the Intern) ---\n");
    
    printf("Prediction module address (predict_outcome): %p\n", predict_outcome);

    while(1) {
        printf("\nModel Control Menu:\n");
        printf("1. Train model (train_model)\n");
        printf("2. Make a prediction (predict_outcome)\n");
        printf("3. Neural Intervention (debug)\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                train_model();
                break;
            case 2:
                predict_outcome();
                break;
            case 3:
                printf("Enter 'neuron' address to modify (hex): > ");
                scanf("%lx", &addr_to_write);
                printf("Enter new 'neuron' weight (hex): > ");
                scanf("%lx", &value_to_write);

                *(unsigned long *)addr_to_write = value_to_write;
                printf("Weight at address 0x%lx successfully modified.\n", addr_to_write);
                break;
            case 4:
                printf("Saving model... Shutting down.\n");
                exit(0);
            default:
                printf("Unknown operation. The model is not responding.\n");
        }
    }
    return 0;
}
