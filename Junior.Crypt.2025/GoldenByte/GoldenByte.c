#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define lucky_a 0xFDE9
#define lucky_b 0xBEE0

void jackpot() {
    char *flag = getenv("FLAG_VAL");
    puts(flag);
}

void _init_streams() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

struct LotteryTicket{
    uint16_t part_a;
    uint16_t part_b;
};

int main() {

    _init_streams();   

    struct LotteryTicket ticket;
        
    ticket.part_a = 0;
    ticket.part_b = 0;

     int32_t user_ticket_number = 0;

    printf("--- 'Golden Byte' Lottery ---\n");
    printf("Ready to test your luck? Enter your lottery ticket number: > ");

    scanf("%d", &user_ticket_number);

    printf("\nChecking ticket number %d...\n", user_ticket_number);
    *(int32_t*)(&ticket.part_a) = user_ticket_number;
   
    if (ticket.part_a == lucky_a && ticket.part_b == lucky_b) {
        jackpot();
    } else {
        printf("Sorry, your ticket didn't win. Better luck next time!\n");
    }

    return 0;

}

