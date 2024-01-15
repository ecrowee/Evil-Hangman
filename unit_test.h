#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int lengh);

Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status ecrowe_test_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status ecrowe_test_init_c_string_returns_nonNULL(char* buffer, int length);


Status ecrowe_test_destroy_changes_handle_to_NULL(char* buffer, int length);

Status ecrowe_test_my_string_pop_back_reduces_size(char* buffer, int length);

Status ecrowe_test_my_string_push_back_returns_success(char* buffer, int length);

Status ecrowe_test_my_string_push_back_allocates_more_memory(char* buffer, int length);

Status ecrowe_test_my_string_pop_back_fails_on_empty_string(char* buffer, int length);

Status ecrowe_test_pop_back_returns_success(char* buffer, int length);

Status ecrowe_test_pop_back_decrements_size(char* buffer, int length);

Status ecrowe_test_my_string_empty_returns_true_on_empty_string(char* buffer, int length);

Status ecrowe_test_my_string_empty_returns_false_on_non_empty_string(char* buffer, int length);

Status ecrowe_test_concat_returns_success_with_empty_string(char* buffer, int length);

Status ecrowe_test_concat_returns_success_with_no_empty_string(char* buffer, int length);

Status ecrowe_test_concat_allocates_more_memory(char* buffer, int length);

Status ecrowe_test_compare_returns_less_than_zero(char* buffer, int length);

Status ecrowe_test_compare_returns_greater_than_zero(char* buffer, int length);

Status ecrowe_test_compare_returns_zero(char* buffer, int length);

//Status ecrowe_test_extraction_copies_files_correctly(char* buffer, int length);

Status ecrowe_test_my_string_at_returns_correct_address(char* buffer, int length);

Status ecrowe_test_my_string_concat_adjusts_size(char* buffer, int length);

Status ecrowe_test_my_string_c_str_does_not_adjust_size(char* buffer, int length);

Status ecrowe_test_my_string_empty_works_on_popped_back_string(char* buffer, int length);

Status ecrowe_test_my_string_c_str_returns_data_address(char* buffer, int length);

Status ecrowe_test_my_string_compare_works_with_all_characters(char* buffer, int length);



#endif
