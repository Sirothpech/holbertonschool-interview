#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

void merge_adjacent(int *line, size_t size, int direction);
int slide_line(int *line, size_t size, int direction);
void shift_non_zero_elements(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
