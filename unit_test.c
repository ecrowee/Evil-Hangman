#include <stdio.h>
#include "unit_test.h"
#include <stdlib.h>


int main(int argc, char* argv[])
{
    Status(*tests[])(char*, int) =
    {
        test_init_default_returns_nonNULL,

        test_get_size_on_init_default_returns_0,

        ecrowe_test_get_capacity_on_init_default_returns_7,

        ecrowe_test_init_c_string_returns_nonNULL,

        ecrowe_test_destroy_changes_handle_to_NULL,

        ecrowe_test_my_string_pop_back_reduces_size,

        ecrowe_test_my_string_push_back_returns_success,

        ecrowe_test_my_string_push_back_allocates_more_memory,

        ecrowe_test_my_string_pop_back_fails_on_empty_string,

        ecrowe_test_pop_back_returns_success,

        ecrowe_test_pop_back_decrements_size,

        ecrowe_test_my_string_empty_returns_true_on_empty_string,

        ecrowe_test_my_string_empty_returns_false_on_non_empty_string,

        ecrowe_test_concat_returns_success_with_empty_string,

        ecrowe_test_concat_returns_success_with_no_empty_string,

        ecrowe_test_concat_allocates_more_memory,

        ecrowe_test_compare_returns_less_than_zero,

        ecrowe_test_compare_returns_greater_than_zero,

        ecrowe_test_compare_returns_zero,

        //ecrowe_test_extraction_copies_files_correctly,

        ecrowe_test_my_string_at_returns_correct_address,

        ecrowe_test_my_string_concat_adjusts_size,

        ecrowe_test_my_string_c_str_does_not_adjust_size,

        ecrowe_test_my_string_empty_works_on_popped_back_string,


        ecrowe_test_my_string_c_str_returns_data_address,

        ecrowe_test_my_string_compare_works_with_all_characters,



    };

    int number_of_functions = sizeof(tests) / sizeof(tests[0]);
    int i;
    char buffer[500];
    int success_count = 0;
    int failure_count = 0;

    for (i = 0; i < number_of_functions; i++)
    {
        if (tests[i](buffer, 500) == FAILURE)
        {
            printf("FAILED: Test %d failed miserably\n", i);
            printf("\t%s\n", buffer);
            failure_count++;
        }
        else
        {
            // printf("PASS: Test %d passed\n", i);
            // printf("\t%s\n", buffer);
            success_count++;
        }
    }
    printf("Total number of tests: %d\n", number_of_functions);
    printf("%d/%d Pass, %d/%d Failure\n", success_count,
        number_of_functions, failure_count, number_of_functions);
    return 0;
}