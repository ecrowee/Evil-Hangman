#include "status.h"
#include "unit_test.h"
#include <string.h>
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
    MY_STRING hString = NULL;

    hString = my_string_init_default();
    if (hString == NULL)
    {
        strncpy(buffer, "test_init_default_returns_nonNULL\n"
            "my_string_init_default returns NULL", length);
        return FAILURE;
    }
    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
        return SUCCESS;
    }
}
Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{

    MY_STRING hString = NULL;

    Status status;


    hString = my_string_init_default();

if (my_string_get_size(hString) != 0)
{

    status = FAILURE;

    printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));

    strncpy(buffer, "test_get_size_on_init_default_returns_0\n"

        "Did not receive 0 from get_size after init_default\n", length);
}
else
{
    status = SUCCESS;

    strncpy(buffer, "test_get_size_on_init_default_returns_0\n"

        , length);

}

my_string_destroy(&hString);

return status;
}
Status ecrowe_test_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
    MY_STRING hString = NULL;

    hString = my_string_init_default();

    Status status;

    if (my_string_get_capacity(hString) != 7)
    {
        status = FAILURE;

        printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));

        strncpy(buffer, "ecrowe_test_get_capacity_on_init_default_returns_7\n"

            "Did not recieve 7 from get_capacity after init_default\n", length);
    }
    else
    {
        status = SUCCESS;

        strncpy(buffer, "ecrowe_test_get_capacity_returns_7\n", length);
    }
    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_init_c_string_returns_nonNULL(char* buffer, int length)
{

    MY_STRING hString = NULL;


    hString = my_string_init_c_string("Amazeballs");

    if (hString == NULL)
    {
        strncpy(buffer, "test_init_c_string_returns_nonNULL\n"
            "my_string_init_c_string returns NULL", length);
        return FAILURE;
    }
    else
    {
        my_string_destroy(&hString);
        strncpy(buffer, "\ttest_init_c_string_returns_nonNULL\n", length);
        return SUCCESS;
    }
}
Status ecrowe_test_destroy_changes_handle_to_NULL(char* buffer, int length)
{
    MY_STRING hString = NULL;

    Status status;

    int* test;

    hString = my_string_init_c_string("Amazeballs");

    my_string_destroy(&hString);

    test = (int*)hString;

    if (test != NULL)
    {
        strncpy(buffer, "ecrowe_test_destroy_changes_handle_to_NULL\n"
            "my_string_destroy does not return NULL"
            , length);

        status = FAILURE;
    }
    else
    {
        strncpy(buffer, "ecrowe_test_destory_changes_handle_to_NULL\n"
            , length);
status = SUCCESS;
        }

        my_string_destroy(&hString);

        return status;
}
Status ecrowe_test_my_string_pop_back_reduces_size(char* buffer, int length)
{
    MY_STRING hString = NULL;

    Status status;

    hString = my_string_init_c_string("Amazeballs");

    my_string_pop_back(hString);

    if (my_string_get_size(hString) != 9)
    {
        strncpy(buffer, "ecrowe_test_my_string_pop_back_reduces_size\n"
            "get_size does not return 9"
            , length);

        status = FAILURE;
    }
    else
    {
        strncpy(buffer, "ecrowe_test_my_string_pop_back_reduces_size\n"
            , length);

        status = SUCCESS;
    }

    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_compare_returns_greater_than_zero(char* buffer, int length)
{


    MY_STRING hLeft_string = NULL;

    MY_STRING hRight_string = NULL;

    Status status;

    hLeft_string = my_string_init_c_string("Awesomesauce");
    hRight_string = my_string_init_c_string("Amazeballs");

    if (my_string_compare(hLeft_string, hRight_string) > 0)
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_compare_returns_greater_than_zero\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_compare_returns_greater_than_zero\n"
            "my_string_compare returns less than zero\n", length);
    }

    my_string_destroy(&hLeft_string);
    my_string_destroy(&hRight_string);

    return status;
}
Status ecrowe_test_compare_returns_less_than_zero(char* buffer, int length)
{
    MY_STRING hLeft_string = NULL;

    MY_STRING hRight_string = NULL;

    Status status;

    hLeft_string = my_string_init_c_string("Amazeballs");
    hRight_string = my_string_init_c_string("Awesomesauce");

    if (my_string_compare(hLeft_string, hRight_string) < 0)
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_compare_returns_less_than_zero\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_compare_returns_less_than_zero\n"
            "my_string_compare returns greater than zero\n", length);
    }

    my_string_destroy(&hLeft_string);
    my_string_destroy(&hRight_string);

    return status;

}
Status ecrowe_test_my_string_push_back_returns_success(char* buffer, int length)
{
    MY_STRING hString = NULL;

    hString = my_string_init_c_string("Amazeballs balls");

    Status status;

    if (my_string_push_back(hString, '.'))
    {
        status = SUCCESS;

        strncpy(buffer, "ecrowe_test_my_string_push_back_returns_success\n"
            , length);
    }
    else
    {
        status = FAILURE;

        strncpy(buffer, "ecrowe_test_my_string_push_back_returns_success\n"
            "my_string_push_back does not return success\n", length);
    }

    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_my_string_pop_back_fails_on_empty_string(char* buffer, int length)
{

    MY_STRING hString = NULL;

    hString = my_string_init_default();

    Status status;

    if (!(my_string_pop_back(hString)))
    {
        status = SUCCESS;

        strncpy(buffer, "ecrowe_test_pop_back_fails_on_empty_string\n", length);
    }
    else
    {
        status = FAILURE;

        strncpy(buffer, "ecrowe_test_pop_back_fails_on_empty_string\n"

            "my_string_pop_back does not fail\n", length);
    }

    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_pop_back_returns_success(char* buffer, int length)
{

    MY_STRING hString = NULL;


    hString = my_string_init_c_string("Amazeballs");

    Status status;

    if ((my_string_pop_back(hString)))
    {
        status = SUCCESS;

        strncpy(buffer, "ecrowe_test_pop_back_returns_success\n", length);
    }
    else
    {
        status = FAILURE;

        strncpy(buffer, "ecrowe_test_pop_back_returns_success\n"

            "my_string_pop_back does not return success\n", length);
    }

    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_my_string_push_back_allocates_more_memory(char* buffer, int length)
{

    MY_STRING hString = NULL;

    Status status;

    int capacity;


    hString = my_string_init_c_string("Amazeballs");

    capacity = my_string_get_capacity(hString);


    my_string_push_back(hString, ' ');

    if (capacity < my_string_get_capacity(hString))
    {

        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_push_back_allocates_more_memory\n", length);

    }
    else
    {

        status = FAILURE;
        strncpy(buffer, "ecrowe_test_push_back_allocates_more_memory\n"

            "my_string_push_back does not allocate more memory\n", length);

    }

    my_string_destroy(&hString);
    return status;

}
Status ecrowe_test_pop_back_decrements_size(char* buffer, int length)
{
    MY_STRING hString = NULL;

    Status status;

    int size1, size2;

    hString = my_string_init_c_string("Amazeballs");
    size1 = my_string_get_size(hString);
    my_string_pop_back(hString);
    size2 = my_string_get_size(hString);

    if (size1 - 1 == size2)
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_pop_back_decrements_size\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_pop_back_decrements_size\n"
            "my_string_pop_back does not decrement size\n", length);
    }
    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_my_string_empty_returns_true_on_empty_string(char* buffer, int length)
{
    MY_STRING hString = NULL;

    Status status;

    hString = my_string_init_default();

    if (my_string_empty(hString))
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_my_string_empty_returns_true_on_empty_string\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_my_string_empty_returns_true_on_empty_string\n"
            "my_string_empty did not return true\n", length);
    }
    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_my_string_empty_returns_false_on_non_empty_string(char* buffer, int length)
{
    MY_STRING hString = NULL;

    Status status;

    hString = my_string_init_c_string("Amazeballs");

    if (!(my_string_empty(hString)))
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_my_string_empty_returns_false_on_non_empty_string\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_my_string_empty_returns_false_on_non_empty_string\n"
            "my_string_empty did not return false\n", length);
    }
    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_concat_returns_success_with_empty_string(char* buffer, int length)
{
    MY_STRING hLString = NULL;

    MY_STRING hRString = NULL;

    Status status;

    hLString = my_string_init_c_string("Amazeballs");

    hRString = my_string_init_default();

    if (my_string_concat(hLString, hRString))
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_concat_returns_success_with_empty_string\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_concat_returns_success_with_empty_string\n"
            "my_string_concat does not return success\n", length);
    }
    my_string_destroy(&hLString);
    my_string_destroy(&hRString);


    return status;


}
Status ecrowe_test_concat_returns_success_with_no_empty_string(char* buffer, int length)
{

    MY_STRING hLString = NULL;


    MY_STRING hRString = NULL;

    Status status;

    hLString = my_string_init_c_string("Amazeballs");

    hRString = my_string_init_c_string("Awesomesauce");

    if (my_string_concat(hLString, hRString))
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_concat_returns_success_with_no_empty_string\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_concat_returns_success_with_no_empty_string\n"
            "my_string_concat does not return success\n", length);
    }
    my_string_destroy(&hLString);
    my_string_destroy(&hRString);


    return status;
}
Status ecrowe_test_concat_allocates_more_memory(char* buffer, int length)
{

MY_STRING hLeft_string = NULL;

MY_STRING hRight_string = NULL;

Status status;

hLeft_string = my_string_init_c_string("Awesomesauce");
hRight_string = my_string_init_c_string("Amazeballs");

if (my_string_compare(hLeft_string, hRight_string) > 0)
{
    status = SUCCESS;
    strncpy(buffer, "ecrowe_test_compare_returns_greater_than_zero\n", length);
}
else
{
    status = FAILURE;
    strncpy(buffer, "ecrowe_test_compare_returns_greater_than_zero\n"
        "my_string_compare returns less than zero\n", length);
}

my_string_destroy(&hLeft_string);
my_string_destroy(&hRight_string);

return status;
}
Status ecrowe_test_compare_returns_zero(char* buffer, int length)
{


    MY_STRING hLeft_string = NULL;

    MY_STRING hRight_string = NULL;

    Status status;

    hLeft_string = my_string_init_c_string("Amazeballs");
    hRight_string = my_string_init_c_string("Amazeballs");

    if (my_string_compare(hLeft_string, hRight_string) == 0)
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_compare_returns_zero\n", length);
    }
    else
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_compare_returns_zero\n"
            "my_string_compare does not return zero\n", length);
    }

    my_string_destroy(&hLeft_string);
    my_string_destroy(&hRight_string);

    return status;
}
/*Status ecrowe_test_extraction_copies_files_correctly(char* buffer, int length)
{
        MY_STRING hString = NULL;

        char string[10] = "Amazeballs";

        Status status;

        FILE* fp;

        int i = 0;

        hString = my_string_init_default();

        fp = fopen("testcases.txt", "d");
        fprintf(fp, "Amazeballs balls");
        fclose(fp);

        fp = fopen("testcases.txt", "r");
        my_string_extraction(hString, fp);
        fclose(fp);

        for(i = 0; i < 10; i++)
        {
                if(*my_string_at(hString, i) != string[i])
                {
                        status = FAILURE;
                }
        }
        if(status == FAILURE)
        {
                strncpy(buffer, "ecrowe_test_extraction_copies_files_correctly\n"
                                "my_string_extraction does not copy correctly", length);
        }
        else
        {
                strncpy(buffer, "ecrowe_test_extraction_copies_files_correctly\n", length);
                status = SUCCESS;
        }
        remove("testcases.txt");

        my_string_destroy(&hString);

        return status;
}*/

Status ecrowe_test_my_string_at_returns_correct_address(char* buffer, int length)
{
    MY_STRING hString = NULL;

    Status status = SUCCESS;

    char string[10] = "Amazeballs";

    int i = 0;

    hString = my_string_init_c_string(string);

    for (i = 0; i < 10; i++)
    {
        if (*my_string_at(hString, i) != string[i])
        {
            status = FAILURE;
        }
    }
    if (status == FAILURE)
    {
        strncpy(buffer, "ecrowe_test_my_string_at_returns_correct_address\n"
            "my_string_at returns wrong address\n", length);
    }
    else
    {
        strncpy(buffer, "ecrowe_test_my_string_at_returns_correct_address\n", length);
    }
    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_my_string_concat_adjusts_size(char* buffer, int length)
{


    MY_STRING hFirstString = NULL;

    MY_STRING hSecondString = NULL;

    Status status;

    hFirstString = my_string_init_c_string("Amazeballs");

    hSecondString = my_string_init_c_string("Awesomesauce");

    my_string_concat(hFirstString, hSecondString);
    if (my_string_get_size(hFirstString) != 22)
    {
        strncpy(buffer,
            "ecrowe_test_my_string_concat_adjusts_size\n"
            "my_string_concat did not properly adjust size"
            , length);
        status = FAILURE;
    }
    else
    {
        strncpy(buffer,
            "ecrowe_test_my_string_concat_adjusts_size\n"
            , length);
        status = SUCCESS;
    }

    my_string_destroy(&hFirstString);
    my_string_destroy(&hSecondString);
    return status;
}
Status ecrowe_test_my_string_c_str_does_not_adjust_size(char* buffer, int length)
{

    MY_STRING hString = NULL;

    Status status;

    hString = my_string_init_c_string("Amazeballs");

    my_string_c_str(hString);


    if (my_string_get_size(hString) != 10)
    {
        strncpy(buffer,
            "ecrowe_test_my_string_c_str_does_not_adjust_size\n"
            "my_string_c_str adjusted the size"
            , length);
        status = FAILURE;
    }
    else
    {
        strncpy(buffer,
            "ecrowe_test_my_string_c_str_does_not_adjust_size\n"
            , length);
        status = SUCCESS;
    }

    my_string_destroy(&hString);
    return status;
}
Status ecrowe_test_my_string_empty_works_on_popped_back_string(char* buffer, int length)
{
    MY_STRING hString = NULL;

    Status status;

    hString = my_string_init_c_string("Amazeballs");

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    my_string_pop_back(hString);

    if (!my_string_empty(hString))
    {
        strncpy(buffer, "ecrowe_test_my_string_empty_works_on_popped_back_string\n"
            "my_string_empty did not work\n", length);
        status = FAILURE;
    }
    else
    {
        strncpy(buffer, "ecrowe_test_my_string_empty_works_on_popped_back_string\n", length);
        status = SUCCESS;
    }
    my_string_destroy(&hString);

    return status;
}
Status ecrowe_test_my_string_c_str_returns_data_address(char* buffer, int length)
{
    MY_STRING hString = NULL;

    char* c;

    int i = 0;

    Status status = SUCCESS;

    char string[10] = "Amazeballs";

    hString = my_string_init_c_string(string);

    c = my_string_c_str(hString);

    for (i = 0; i < 10; i++, c++)
    {
        if (*c != string[i])
        {
            status = FAILURE;
        }
    }

    if (status == FAILURE)
    {
        strncpy(buffer, "ecrowe_test_my_string_c_str_returns_data_address\n"
            "my_string_c_str does not return correct address\n", length);
    }
    else
    {
        strncpy(buffer, "ecrowe_test_my_string_c_str_returns_data_address\n", length);
    }
    my_string_destroy(&hString);
    return status;
}
Status ecrowe_test_my_string_compare_works_with_all_characters(char* buffer, int length)
{
    MY_STRING hLString = NULL;
    MY_STRING hRString = NULL;

    int result = 0;

    Status status;

    hLString = my_string_init_c_string("!@#$%");
    hRString = my_string_init_c_string("^&*()?");

    result = my_string_compare(hLString, hRString);

    if (result >= 0)
    {
        status = FAILURE;
        strncpy(buffer, "ecrowe_test_my_string_compare_works_with_all_characters\n"
            "my_string_compare returned wrong value\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "ecrowe_test_my_string_compare_works_with_all_characters\n", length);
    }
    my_string_destroy(&hLString);
    my_string_destroy(&hRString);

    return status;
}