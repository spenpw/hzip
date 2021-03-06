struct FreqTable {
    unsigned int* table;
};

struct FreqTable create_frequency_table();

void destroy_frequency_table(struct FreqTable table);

unsigned int get_frequency(struct FreqTable table, unsigned char byte);

void increment_frequency(struct FreqTable table, unsigned char byte);

struct FreqTable generate_frequencies(const unsigned char* buffer, int size);

void print_frequency_table(struct FreqTable table);
