#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int first = 0;
int second = 0;

void win() {    
    char *flag = getenv("FLAG_VAL");
    if(first && second) 
        puts(flag);
}

void step1(){
    first = 1;
}

void step2() {
    second = 1;
}

void func() {
    char buffer[32];
    printf("%s","Input username:");
    read(0,buffer,128);
    printf("Your name is %s", buffer);
}

void _init_streams() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}


int main() {
    _init_streams();
    func();
}
