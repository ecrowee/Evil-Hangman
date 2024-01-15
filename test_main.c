#include <stdio.h>
#include "my_string.h"

int main()
{
    // Test my_string_init_default
    MY_STRING str1 = my_string_init_default();
    printf("Initialized empty string with default capacity. Size: %d, Capacity: %d\n",
        my_string_get_size(str1), my_string_get_capacity(str1));

    // Test my_string_init_c_string
    const char* testString = "Hello, World!";
    MY_STRING str2 = my_string_init_c_string(testString);
    printf("Initialized string from C string: %s\n", my_string_c_str(str2));

    // Test my_string_compare
    MY_STRING str3 = my_string_init_c_string("abc");
    MY_STRING str4 = my_string_init_c_string("def");
    int compareResult = my_string_compare(str3, str4);
    printf("Comparison result: %d\n", compareResult);

    // Test my_string_push_back
    my_string_push_back(str2, '!');
    printf("After push_back: %s\n", my_string_c_str(str2));

    // Test my_string_pop_back
    my_string_pop_back(str2);
    printf("After pop_back: %s\n", my_string_c_str(str2));

    // Test my_string_concat
    MY_STRING str5 = my_string_init_c_string("Concatenated ");
    MY_STRING str6 = my_string_init_c_string("Strings");
    my_string_concat(str5, str6);
    printf("After concatenation: %s\n", my_string_c_str(str5));

    // Test my_string_empty
    printf("Is str1 empty? %s\n", my_string_empty(str1) ? "Yes" : "No");
    printf("Is str2 empty? %s\n", my_string_empty(str2) ? "Yes" : "No");

    // Test my_string_at
    printf("Character at index 2 in str3: %c\n", *my_string_at(str3, 2));

    // Test my_string_insertion and my_string_extraction
    FILE* filePointer = fopen("simple.txt", "w");

    my_string_insertion(str5, filePointer);
    fclose(filePointer);

    filePointer = fopen("simple.txt", "r");
    MY_STRING str7 = my_string_init_default();
    my_string_extraction(str7, filePointer);
    fclose(filePointer);
    printf("String read from file: %s\n", my_string_c_str(str7));

    MY_STRING test1 = my_string_init_c_string("Amazeballs");


    MY_STRING test2 = my_string_init_c_string("Awesomesauce");
    printf("Strings before swap: %s, %s\n", my_string_c_str(test1), my_string_c_str(test2));

    my_string_swap(&test1, &test2);



    printf("Strings after swap: %s, %s\n", my_string_c_str(test1), my_string_c_str(test2));




    // Test my_string_destroy
    my_string_destroy(&str1);
    my_string_destroy(&str2);
    my_string_destroy(&str3);
    my_string_destroy(&str4);
    my_string_destroy(&str5);
    my_string_destroy(&str6);
    my_string_destroy(&str7);
    my_string_destroy(&test1);
    my_string_destroy(&test2);


    printf("Destroyification complete!\n");

    return 0;
}
