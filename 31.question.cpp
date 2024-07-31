#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16 

void left_shift(uint8_t *input, uint8_t *output, int size) {
    uint8_t overflow = 0;
    for (int i = size - 1; i >= 0; i--) {
        output[i] = (input[i] << 1) | overflow;
        overflow = (input[i] & 0x80) ? 1 : 0;
    }
}

void xor_with_constant(uint8_t *input, uint8_t constant, int size) {
    input[size - 1] ^= constant;
}

void generate_subkeys(uint8_t *key, uint8_t *K1, uint8_t *K2) {
    uint8_t L[BLOCK_SIZE] = {0};
    uint8_t constant;

   
    memcpy(L, key, BLOCK_SIZE);

  
    constant = (BLOCK_SIZE == 8) ? 0x1B : 0x87;

    left_shift(L, K1, BLOCK_SIZE);
    if (L[0] & 0x80) {
        xor_with_constant(K1, constant, BLOCK_SIZE);
    }


    left_shift(K1, K2, BLOCK_SIZE);
    if (K1[0] & 0x80) { 
        xor_with_constant(K2, constant, BLOCK_SIZE);
    }
}

int main() {
    uint8_t key[BLOCK_SIZE] = {0};
    uint8_t K1[BLOCK_SIZE];
    uint8_t K2[BLOCK_SIZE];

    generate_subkeys(key, K1, K2);

    printf("K1: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", K1[i]);
    }
    printf("\n");

    printf("K2: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", K2[i]);
    }
    printf("\n");

    return 0;
}
