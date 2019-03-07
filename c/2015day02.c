#include <stdio.h>

// Utility
int min2(int, int);
int min3(int, int, int);

// Part 1
int get_slack(int, int, int);
int get_paper_area(int, int, int);
int part_one(FILE *);

// Part 2
int get_ribbon_length(int, int, int);
int get_perimeter(int, int);
int part_two(FILE *);

int main() {
    FILE *inp = fopen("2015day02.txt", "r");

    int part_one_ans = part_one(inp);
    rewind(inp);

    int part_two_ans = part_two(inp);
    fclose(inp);

    printf("Part 1 Answer: %d\nPart 2 Answer: %d\n",
           part_one_ans,
           part_two_ans);
}

int part_one(FILE *inp) {
    int l,w,h;
    int paper_area = 0;

    while (fscanf(inp, "%dx%dx%d", &l, &w, &h) == 3) {
        paper_area += get_paper_area(l,w,h);
    }

    return paper_area;
}

int get_slack(int l, int w, int h) {
    if (l <= w) { 
        if (h <= w) // l,h <= w
            return l * h;
        else // l <= w < h
            return l * w;
    } else {
        if (h <= l) // w < l; h <= l
            return w * h;
        else // w < l < h
            return w * l;
    }
}

int get_paper_area(int l, int w, int h) {
    return (2*l*w) + (2*w*h) + (2*h*l) + get_slack(l,w,h);
}

int part_two(FILE *inp) {
    int l,w,h;
    int ribbon_length = 0;

    while (fscanf(inp, "%dx%dx%d", &l, &w, &h) == 3)
        ribbon_length += get_ribbon_length(l,w,h);

    return ribbon_length;
}

int get_ribbon_length(int l, int w, int h) {
    return min3(get_perimeter(l,w),
                get_perimeter(l,h),
                get_perimeter(w,h))
        + (l * w * h);
}

int get_perimeter(int l, int w) {
    return 2 * (l + w);
} 

int min3(int x, int y, int z) {
    return min2(min2(x, y), z);
}

int min2(int x, int y) {
    if (x <= y)
        return x;
    else
        return y;
}
