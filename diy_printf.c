/* Week 1 a1
DIY printf
*/

#include<stdio.h>
#include<stdarg.h>
#include <limits.h>

void printint(int n) {
    if (n < 0) {
        n *= -1;
        putchar('-');
    } else if (n == 0) {
        putchar('0');
        return;
    }
    int cnt = 0;
    int output[999999];
    while (n > 0) {
        // printf("%d + %d%d%d%d", n, output[0], output[1], output[2], output[3]);
        output[cnt++] = (n % 10);
        n /= 10;
        // printf("  n_write: %d \n", cnt - 1);
    }
    
    for (int i = (cnt - 1); i >= 0; i--) {
        putchar(output[i] + '0');
    }
}

void myprintf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    for (const char* it = fmt; *it != '\0'; it++) {
        if (*it == '%') {
            char ident;
            ident = *(++it);
            
            switch(ident) {
                case 'd': {
                    int i = va_arg(args, int);
                    // puts("ooointooo");
                    printint(i);
                    //putchar(i + '0');
                    break;
                }
                case 's': {
                    const char* s = va_arg(args, char*);
                    fputs(s, stdout);
                    break;
                }
                case 'c': {
                    int c = va_arg(args, int);
                    putchar(c);
                    break;
                }
            }
        } else {
            putchar(*it);
        }
    }
}

int main() {
    myprintf("string test: %s\n", "123456");
    myprintf("int max: %d\n", INT_MAX);
    myprintf("int negative: %d\n", -1243);
    myprintf("char %c %c %c \n", 'a', 'b', 'c');
    myprintf("mixed: %c %s %d \n", 'a', "abc", 1234);
}