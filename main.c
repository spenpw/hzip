#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "file_util.h"
#include "hzip.h"

int main(int argc, char** argv) {

    if (argc < 3) {
        printf("Usage: hzip <output_file> <input_file>\n");
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Input file '%s' not found\n", argv[1]);
        return 1;
    }

    int file_size = get_file_size(input_file);
    unsigned char* file_buffer = calloc(file_size * sizeof(char), 1);
    for (int buf_pos = 0; buf_pos < file_size; buf_pos++) {
        file_buffer[buf_pos] = (unsigned char)getc(input_file);
    }
    fclose(input_file);

    unsigned char* compressed_buffer = calloc(file_size * sizeof(char), 1);

    int hzip_result = huffman_compress(file_buffer, compressed_buffer, file_size);
    
    if (hzip_result == 0) {
        printf("Unsuccessful compression");
    }

    FILE* output_file = fopen(argv[2], "w");
    if (!output_file) {
        printf("Couldn't write to '%s'\n", argv[2]);
        return 1;
    }
    fwrite(compressed_buffer, 1, hzip_result, output_file);
    fclose(output_file);

    free(compressed_buffer);
    free(file_buffer);
    return 0;

}
