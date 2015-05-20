/*
*       X-OR encryption & decryption
*
*NOTE:
*               -for BUFFER_SIZE overflow the decryption is done without decrypt key
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 10

#define buffer_overflow(size) (size > BUFFER_SIZE ? true : false)

int main()
{
        char encrypt_value[BUFFER_SIZE];
        char encrypt_key[BUFFER_SIZE];
        char decrypt_value[BUFFER_SIZE];
        char decrypt_key[BUFFER_SIZE];
        int i;

       //encryption 
        fprintf(stdout, "enter text:\n"); 
        fgets(encrypt_value, BUFFER_SIZE, stdin);
        /*
        if(buffer_overflow(strlen(encrypt_value)));
                return EXIT_FAILURE;
        */

        fprintf(stdout, "enter encryption key: ");
        fgets(encrypt_key, BUFFER_SIZE, stdin);
        /*
        if(buffer_overflow(strlen(encrypt_key)));
                return EXIT_FAILURE;
        */

        for(i = 0; i < strlen(encrypt_key); i++)
        {
                encrypt_value[i] = encrypt_value[i] ^ encrypt_key[i];
        }
        fprintf(stdout, "after encryption: ");
        puts(encrypt_value);
        
        //decryption

        fprintf(stdout, "enter decrypt key: ");
        fgets(decrypt_key, BUFFER_SIZE, stdin);
        /*
        if(buffer_overflow(strlen(decrypt_key)));
                return EXIT_FAILURE;
        */

        for(i = 0; i < strlen(decrypt_key); i++)
        {
                decrypt_value[i] = encrypt_value[i] ^ decrypt_key[i];
        }
        fprintf(stdout, "after decryption: ");
        puts(decrypt_value);
        printf("\n");

        return EXIT_SUCCESS;
}
