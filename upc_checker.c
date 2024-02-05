#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ERROR CODES
#define EXIT_SUCCESS 0
#define EXIT_FEW_ARGS 1
#define EXIT_TOO_MANY_ARGS 2
#define EXIT_SHORT_UPC 3
#define EXIT_INVALID_UPC_CHECKDIGIT 4

int main(int argc,char* argv[]){

    // char to int converter using ASCII map
    int char_to_int(const char vector_item){
        int converted_ascii_char = vector_item - 48;

        return converted_ascii_char;
    }

    // UPC Validitychecker
    bool upc_checker(const char *upc){

        bool upc_valid = false;
        const int upc_check_digit = char_to_int(upc[strlen(upc)-1]);
        int first_num_blk = char_to_int(upc[0]) + char_to_int(upc[2]) + char_to_int(upc[4]) + char_to_int(upc[6]) + char_to_int(upc[8]) + char_to_int(upc[10]);
        int second_num_blk = char_to_int(upc[1]) + char_to_int(upc[3]) + char_to_int(upc[5]) + char_to_int(upc[7]) + char_to_int(upc[9]);

        int comp_remainder = (((( first_num_blk * 3 ) + second_num_blk ) - 1) % 10);

        if((9 - comp_remainder) == upc_check_digit){
            upc_valid = true;
        }

        return upc_valid;
    }

    if(argc < 2){
        printf("\n%s: Missing arguments!\n\nUsage: test [UPC]\n\n", argv[0]);
        exit(EXIT_FEW_ARGS);
    }else if(argc > 2){
        printf("\n%s: Too many arguments!\n\nUsage: test [UPC]\n\n", argv[0]);
        exit(EXIT_TOO_MANY_ARGS);
    }else{
        const char* upc_arg = argv[1];

        if(strlen(upc_arg) != 12){
            printf("\nInvalid UPC!\nThe entered UPC contains %ld digits, whereas 12 are required.\n",strlen(upc_arg));
            exit(EXIT_SHORT_UPC);
        }else{
            if(upc_checker(upc_arg)){
                printf("\nValid UPC!\n");
            }else{
                printf("\nInvalid UPC - Check digit fail!\n");
                exit(EXIT_INVALID_UPC_CHECKDIGIT);
            }
        }

    }

    exit(EXIT_SUCCESS);
}
