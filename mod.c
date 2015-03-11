#include <stdio.h>

int process(int x, int n) {
    int diff = x - n;
    while(diff > 0) {
        diff -= n;
    }
    diff += n;
    return diff;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int i;
    while (fgets(line, 1024, file)) {
    //    printf("%s", line);
        for(i = 0; line[i] != ','; i ++);
        line[i] = '\0';
        printf("%d\n", process(atoi(&line[0]), atoi(&line[i+1])));
    }
    return 0;
} 
