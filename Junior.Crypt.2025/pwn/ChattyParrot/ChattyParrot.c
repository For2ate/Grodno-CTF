#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char SECRET[256] = {0};

void vuln() {
    char buff[256];
    read(0, buff, 256);
    printf(buff);
}

void _init_streams() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
    _init_streams();
    
    const char* tmp = getenv("FLAG_VAL");

    if (tmp) {
        strncpy(SECRET, tmp, sizeof(SECRET) - 1);
    } else {
        fprintf(stderr, "FLAG_VAL not set!\n");
        exit(1);
    }

    printf("%s","Input your phrase:");
    vuln();
} 
