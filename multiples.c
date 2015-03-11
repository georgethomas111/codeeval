/* Sample code to read in test cases: Given numbers x and n, where n is a power of 2, print out the smallest multiple of n which is greater than or equal to x. Do not use division or modulo operator.
 *
 * INPUT SAMPLE:
 *
 * The first argument will be a path to a filename containing a comma separated list of two integers, one list per line. E.g.
 *
 * 13,8
 * 17,16
 * OUTPUT SAMPLE:
 *
 * Print to stdout, the smallest multiple of n which is greater than or equal to x, one per line. E.g.
 * 16
 * 32
 */
#include <stdio.h>

int process(int x, int n) {
    int diff = x - n;
    int N = n;
    if (diff < 0) {
        return n;
    } else {
        while(diff > 0) {
            N += n;
            diff -= n;
        }
    }
    return N;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int i;
    while (fgets(line, 1024, file)) {
        // Do something with the line
    //    printf("%s", line);
        for(i = 0; line[i] != ','; i ++);
        line[i] = '\0';
       // printf("Arg1 %d Arg2 %d\n", atoi(line[0]), atoi(line[i+1]));
        printf("%d\n", process(atoi(&line[0]), atoi(&line[i+1])));
    }
    return 0;
} 
