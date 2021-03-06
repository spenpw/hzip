#include <stdlib.h>
#include <stdio.h>
#include "frequency.h"

struct FreqTable create_frequency_table() {
    int size = sizeof(unsigned int) * 0x100;
    struct FreqTable table;
    table.table = calloc(size, 1);
    return table;
}

void destroy_frequency_table(struct FreqTable table) {
    free(table.table);
}

unsigned int get_frequency(const struct FreqTable table, const unsigned char byte) {
    return table.table[byte];
}

void increment_frequency(struct FreqTable table, const unsigned char byte) {
    table.table[byte] += 1;
}

struct FreqTable generate_frequencies(const unsigned char* buffer, int size) {
    struct FreqTable table = create_frequency_table();
    for (unsigned int position = 0; position < size; position++) {
        increment_frequency(table, buffer[position]);
    }
    return table;
}

void print_frequency_table(struct FreqTable table) {
    for (unsigned int character = 0; character < 0x100; character++) {
        printf("%u(%c): %d\n", character, character, get_frequency(table, character));
    }
}
