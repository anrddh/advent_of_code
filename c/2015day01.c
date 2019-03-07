#include <stdio.h>

int part_one(FILE *inp) {
    int floor = 0;
    char c;

    while ((c = fgetc(inp)) != EOF) {
        if (c == '(')
            ++floor;
        else
            --floor;
    }

    return floor;
}

int part_two(FILE *inp) {
    int floor = 0;
    int pos = 1;
    char c;

    while ((c = fgetc(inp)) != EOF) {
        if (c == '(')
            ++floor;
        else
            --floor;

        if (floor < 0)
            return pos;
        ++pos;
    }

    return floor;
}

int main() {
    FILE *inp = fopen("2015day01.txt", "r");

    int part_one_ans = part_one(inp);

    rewind(inp);
    int part_two_ans = part_two(inp);

    fclose(inp);

    printf("Part 1 Answer: %d\nPart 2 Answer: %d\n", part_one_ans, part_two_ans);
}
