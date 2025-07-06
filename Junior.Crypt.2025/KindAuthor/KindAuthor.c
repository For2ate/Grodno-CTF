#include <stdio.h>
#include <unistd.h>

void ROPHelp() {
    asm("pop %rdi\n\t"
         "ret");
}

void func() {
    char buffer[32];
    read(0,buffer, 128);
}

void _init_streams() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
    _init_streams();
    puts("Hello\nInput your data:");
    func(); 
}
