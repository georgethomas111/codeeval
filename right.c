#include <stdio.h>

int process(char *string, char c) {
    int i = 0;
    int N = -1;
    for(i = 0; string[i] != '\0'; i++) {
        if(string[i] == c) {
            N = i;
        }
    }
    return N;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int i;
    while (fgets(line, 1024, file)) {
        for(i = 0; line[i] != ','; i ++);
        line[i] = '\0';
        printf("%d\n", process(&line[0], line[i+1]));
    }
    return 0;
}
