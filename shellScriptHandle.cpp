#include <iostream>

using namespace std;

int main() {
    char cmd[100];
    fgets(cmd, 100, stdin); 
    FILE* in = popen(cmd, "r");
    char** res;
    res = (char**) malloc (100*sizeof(char*));
    int i = 0;
    while(!feof(in)) {
        res[i] = (char*) malloc(100*sizeof(char));
        fgets(res[i], 100, in);
        i++;
    }
    res[i] = NULL;
    i = 0;
    while (res[i] != NULL) {
        cout << res[i];
        i++;
    }
    return 0;
}