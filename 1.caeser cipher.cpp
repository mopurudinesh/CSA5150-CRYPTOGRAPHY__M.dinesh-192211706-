#include <stdio.h>
void caesarCipher(char str[], int shift)
{
    for(int i = 0; str[i]; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = 'a' + (str[i] - 'a' + shift) % 26;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'A' + (str[i] - 'A' + shift) % 26;
    }
}

int main() {
    char str[100];
    int shift;
    
    printf("Enter a string: ");
    scanf("%99s", str);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    
    caesarCipher(str, shift);
    
    printf("Encrypted string: %s\n", str);
    
    return 0;
}
