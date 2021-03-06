#include <stdio.h>
#include <string.h>

int longestPalindrome(char str[]){
    int size = strlen(str);

    int maxLength = 1, start = 0;

    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            int flag = 1;

            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            // Palindrome
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    return maxLength;
}

int main() {
    
    char input[2000];
    scanf("%s", input);

    int max = longestPalindrome(input);
    printf("%d\n", max);

    return 0;
}

