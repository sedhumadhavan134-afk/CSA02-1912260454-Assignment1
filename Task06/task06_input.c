#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
static int parse_two_readings(char *line, long *previous, long *current) {
    char *p = line, *end;
    errno = 0; long a = strtol(p, &end, 10);
    if (p == end || errno || a < 0 || a > 65535) return 0;
    p = end; while (isspace((unsigned char)*p)) ++p;
    errno = 0; long b = strtol(p, &end, 10);
    if (p == end || errno || b < 0 || b > 65535) return 0;
    p = end; while (isspace((unsigned char)*p)) ++p;
    if (*p != '\0') return 0;
    *previous = a; *current = b; return 1;
}
int main(void) {
    char line[128]; long previous, current;
    puts("Enter previous and current readings on one line (0-65535):");
    if (!fgets(line, sizeof line, stdin) || !parse_two_readings(line, &previous, &current)) {
        puts("Invalid input: enter exactly two readings in the range 0..65535.");
        return 1;
    }
    printf("Readings accepted: %ld %ld\n", previous, current);
    return 0;
}