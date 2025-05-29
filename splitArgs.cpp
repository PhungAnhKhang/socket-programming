#include <cstring>
#include <iostream>
#include <ctype.h>

void splitArgs(char* msg, char** & args) {
    args = (char**) malloc(100*sizeof(char*));
    char *token = strtok(msg, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

void strip(char* msg) {
    int len = strlen(msg);
    int i = len - 1;
    while (msg[i] != '\n' && msg[i] != ' ') {
        i--;
    }
    msg[i] = '\0';
}

int main() {
    char s[1000];
    fgets(s, 1000, stdin);
    strip(s);
    char** args;
    splitArgs(s, args);
    int i = 0;
    while (args[i] != NULL) {
        std::cout << args[i++] << '\n';
    }
    return 0;
}