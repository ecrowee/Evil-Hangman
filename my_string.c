#include "status.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
#include <string.h>
#include <ctype.h>
#include "generic_vector.h"
#include "generic.h"

//Precondition: None
//Postcondition: Allocate space for a string object that represents the empty
// string. The string will have capacity 7 and size 0 by default. A copy of
// the address of the opaque object will be returned on success and NULL on
// failure.
struct my_string
{
    int size;
    int capacity;
    char* data;
};

typedef struct my_string My_string;

Boolean check_if_used(MY_STRING guess_list, char c)
{
    My_string* pMy_string = (My_string*)guess_list;

    int i;

    for (i = 0; i < my_string_get_size(guess_list); i++)
    {
        if (pMy_string->data[i] == c)
        {
            return TRUE;
        }
    }
    return FALSE;
}
MY_STRING my_string_init_default(void)
{
    My_string* pMy_string = (My_string*)malloc(sizeof(My_string));

    if (pMy_string != NULL)
    {
        pMy_string->size = 0;
        pMy_string->capacity = 7;
        pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
    }
    else
    {
        free(pMy_string);
        pMy_string = NULL;
    }
    return (MY_STRING)pMy_string;
}


//Precondtion: c_string is a valid null terminated c-string.
//Postcondition: Allocate space for a string object that represents a string
// with the same value as the given c-string. The capacity of the string
// object will be set to be one greater than is required to hold the string.
// As an example, the string "the" would set capacity at 4 instead of 3. A
// copy of the address of the opaque object will be returned on success and
// NULL on failure.
//
MY_STRING my_string_init_c_string(const char* c_string)
{
    int i = 0;
    int capacity = 0;
    int size = 0;
    char c = 'd';

    for (i = 0; c != '\0'; i++)
    {
        c = c_string[i];
    }
    size = i - 1;
    capacity = size;

    My_string* pMy_string = (My_string*)malloc(sizeof(My_string));

    if (pMy_string != NULL)
    {
        pMy_string->size = size;
        pMy_string->capacity = capacity;
        pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
    }
    else
    {
        free(pMy_string);
        pMy_string = NULL;
    }

    for (i = 0; i < capacity; i++)
    {
        pMy_string->data[i] = c_string[i];
    }

    return (MY_STRING)pMy_string;
}

//Precondition: hMy_string is the handle of a valid My_string object.
//Postcondtion: Returns a copy of the integer value of the object's capacity.

int my_string_get_capacity(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;

    return pMy_string->capacity;
}


//Precondition: hMy_string is the handle of a valid My_string object.
//Postcondtion: Returns a copy of the integer value of the object's size.
int my_string_get_size(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;

    return pMy_string->size;
}

//Precondition: hLeft_string and hRight_string are valid My_string objects.
//Postcondition: returns an integer less than zero if the string represented
// by hLeft_string is lexicographically smaller than hRight_string. If
// one string is a prefix of the other string then the shorter string is
// considered to be the smaller one. (app is less than apple). Returns
// 0 if the strings are the same and returns a number greater than zero
// if the string represented by hLeft_string is bigger than hRight_string.
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{

    My_string* pLeft_string = (My_string*)hLeft_string;


    My_string* pRight_string = (My_string*)hRight_string;

    int i;


    for (i = 0; i < pLeft_string->size && i < pRight_string->size; i++)
    {


        if (pLeft_string->data[i] < pRight_string->data[i])

        {

            return -1;

        }
        else if (pLeft_string->data[i] > pRight_string->data[i])
        {


            return 1;

        }

    }
    return 0;
}


//Precondition: phMy_string holds the address of a valid handle to a MY_STRING
// object.
//Postcondition: The memory used for the MY_STRING object has be reclaimed by
// the system and the handle referred to by the pointer phMy_string has been
// set to NULL.
void my_string_destroy(MY_STRING* phMy_string)
{
    My_string* pMy_string = (My_string*)*phMy_string;


    free(pMy_string->data);
    free(pMy_string);

    *phMy_string = NULL;


    return;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    My_string* pMy_string = (My_string*)hMy_string;
    char c = 'd';
    int i = 0;
    c = fgetc(fp);

    while (isspace(c))
    {
        c = fgetc(fp);
        if (c == EOF)
        {
            return FAILURE;
        }
    }
    pMy_string->size = 0;

    for (i = 0; !isspace(c); i++)
    {
        if (pMy_string->capacity > i + 1)
        {
            pMy_string->data[i] = c;
            pMy_string->size = i + 1;
        }
        else
        {
            pMy_string->data = (char*)realloc(pMy_string->data, pMy_string->capacity * 2);
            if (pMy_string->data == NULL)
            {
                return FAILURE;
            }
            pMy_string->capacity *= 2;
            pMy_string->data[i] = c;
            pMy_string->size = i + 1;
        }
        c = fgetc(fp);

        if (c == EOF)
        {
            return FAILURE;
        }

    }
    ungetc(c, fp);

    return SUCCESS;
}


Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
    My_string* pMy_string = (My_string*)hMy_string;

    char c = 'd';
    int i = 0;

    if (pMy_string == NULL)
    {
        return FAILURE;
    }
    else
    {
        for (i = 0; i < pMy_string->size; i++)
        {
            c = pMy_string->data[i];
            fprintf(fp, "%c", c);
        }
        return SUCCESS;
    }
}


//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: If successful, places the character item at the end of the
// string and returns SUCCESS. If the string does not have enough room and
// cannot resize to accomodate the new character then the operation fails
// and FAILURE is returned. The resize operation will attempt to amortize
// the cost of a resize by making the string capacity somewhat larger than
// it was before (up to 2 times bigger).
Status my_string_push_back(MY_STRING hMy_string, char item)
{
    My_string* pMy_string = (My_string*)hMy_string;

    if (pMy_string->capacity > pMy_string->size + 1)
    {
        pMy_string->data[pMy_string->size] = item;
        pMy_string->size = pMy_string->size + 1;
    }
    else
    {
        pMy_string->data = (char*)realloc(pMy_string->data, pMy_string->capacity * 2);
        if (pMy_string->data == NULL)
        {
            return FAILURE;
        }
        else
        {
            pMy_string->capacity *= 2;
            pMy_string->data[pMy_string->size] = item;
            pMy_string->size = pMy_string->size + 1;
        }
    }
    return SUCCESS;
}
//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Removes the last character of a string in constant time.
// Guaranteed to not cause a resize operation of the internal data. Returns
// SUCCESS on success and FAILURE if the string is empty.
Status my_string_pop_back(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;

    if (pMy_string->size > 0)
    {
        pMy_string->size = pMy_string->size - 1;
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}
//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Returns the address of the character located at the given
// index if the index is in bounds but otherwise returns NULL. This address
// is not usable as a c-string since the data is not NULL terminated and is
// intended to just provide access to the element at that index.
char* my_string_at(MY_STRING hMy_string, int index)
{
    My_string* pMy_string = (My_string*)hMy_string;

    if (index < pMy_string->size && index >= 0)
    {
        return (char*)&pMy_string->data[index];
    }
    else
    {
        return NULL;
    }
}
//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Returns the address of the first element of the string object
// for use as a c-string. The resulting c-string is guaranteed to be NULL
// terminated and the memory is still maintained by the string object though
// the NULL is not actually counted as part of the string (in size).
char* my_string_c_str(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;

    my_string_push_back(hMy_string, '\0');

    pMy_string->size = pMy_string->size - 1;

    return (char*)&(pMy_string->data[0]);
}
//Precondition: hResult and hAppend are handles to valid My_string objects.
//Postcondition: hResult is the handle of a string that contains the original
// hResult object followed by the hAppend object concatenated together. This
// function should guarantee no change to the hAppend object and return
// SUCCESS if they operation is successful and FAILURE if the hResult object
// is unable to accomodate the characters in the hAppend string perhaps
// because of a failed resize operation. On FAILURE, no change to either
// string should be made.
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{

    My_string* pResult = (My_string*)hResult;

    My_string* pAppend = (My_string*)hAppend;

    int needed_size = (int)pResult->size + (int)pAppend->size;

    int i = 0;
    int continued_i = 0;
    char* c = NULL;
    char* pTemp = NULL;

    pTemp = (char*)malloc(sizeof(char) * needed_size);
    if (pTemp == NULL)
    {
        return FAILURE;
    }

    c = my_string_c_str(hResult);
    for (i = 0; i < pResult->size; i++)
    {
        pTemp[i] = *(c + i);
    }

    continued_i = i;

    c = my_string_c_str(hAppend);
    for (i = 0; i < pAppend->size; i++)
    {
        pTemp[continued_i] = *(c + i);
        continued_i++;
    }

    free(pResult->data);
    pResult->data = pTemp;
    pResult->size = needed_size;
    pResult->capacity = needed_size;

    return SUCCESS;
}
//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: Returns an enumerated type with value TRUE if the string
// is empty and FALSE otherwise.
Boolean my_string_empty(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;

    if (pMy_string->size <= 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}
//Precondition: hLeft and hRight contain the handles of valid
// MY_STRING objects.
//Postcondition: On Success hLeft will contain the handle
// to a valid MY_STRING object that is a deep copy of the object indicated
// by hRight. The object indicated by the handle at the address pLeft will
// attempt to resize to hold the data in Right. If the object on the left
// already has enough room to store all of the data on the right then it
// will not resize. hLeft will have the same size as hRight if the call
// succeeds but the capacities may differ. The data in the dynamic arrays
// up to size number of elements will be identical in both objects.
// On failure pLeft will be unchanged and a Status of FAILURE will be
// returned.
Status my_string_assignment(MY_STRING hLeft, MY_STRING hRight)
{
    struct my_string* left = (struct my_string*)hLeft;
    struct my_string* right = (struct my_string*)hRight;

    if (left == NULL || right == NULL)
    {
        return FAILURE; // Invalid handles
    }

    // Ensure that the left object has enough capacity
    if (left->capacity < right->size)
    {
        // Resize the left object
        char* newData = (char*)realloc(left->data, (right->size + 1) * sizeof(char)); // +1 for null terminator
        if (newData == NULL)
        {
            return FAILURE; // Memory reallocation failed
        }
        left->data = newData;
        left->capacity = right->size;
    }

    // Copy the data from right to left

    for (int i = 0; i < right->size; i++)
    {
        left->data[i] = right->data[i];
    }

    left->data[right->size] = '\0';

    left->size = right->size;


    return SUCCESS;
}
//Precondition: hMy_string is the handle to a valid MY_STRING object.
//Postcondition: Will return the handle to a valid MY_STRING object that
//is a deep copy of the object indicated by hMy_string. This means the
//copied object will be a complete and independent copy and not share
//any data with the object we are copying from. On failure the function will
//return NULL.
MY_STRING my_string_init_copy(MY_STRING hMy_string)
{
    struct my_string* original = (struct my_string*)hMy_string;
    if (original == NULL)
    {
        return NULL; // Invalid handle
    }

    struct my_string* newString = (struct my_string*)malloc(sizeof(struct my_string));
    if (newString == NULL)
    {
        return NULL; // Memory allocation failed
    }

    newString->size = original->size;
    newString->capacity = original->capacity;

    // Allocate memory for the new string data
    newString->data = (char*)malloc((newString->capacity + 1) * sizeof(char)); // +1 for null terminator
    if (newString->data == NULL)
    {
        free(newString);
        return NULL; // Memory allocation failed
    }

    // Copy the data from the original string
    for (int i = 0; i < original->size; ++i)
    {
        newString->data[i] = original->data[i];
    }

    newString->data[newString->size] = '\0';


    return (MY_STRING)newString;
}

//Precondition: hLeft and hRight are handles to valid MY_STRING objects.
//Postcondition: After the function hLeft will contain the size capacity and
//data of the object indicated by hRight and hRight will contain
//the size capacity and data of the oject indicated by hLeft. This function
//will be much faster than making deep copies of the objects using
//my_string_assignment and attempting to swap them in the traditional way
//calling my_string assignment in place of the '=' below.
//temp = a;
//a = b;
//b = temp;

void my_string_swap(MY_STRING hLeft, MY_STRING hRight)
{

    struct my_string* pLeft = (struct my_string*)hLeft;
    struct my_string* pRight = (struct my_string*)hRight;


    if (pLeft != NULL && pRight != NULL)
    {
        // Swap the size, capacity, and data pointers
        int tempSize = pLeft->size;
        int tempCapacity = pLeft->capacity;
        char* tempData = pLeft->data;

        pLeft->size = pRight->size;
        pLeft->capacity = pRight->capacity;
        pLeft->data = pRight->data;

        pRight->size = tempSize;
        pRight->capacity = tempCapacity;
        pRight->data = tempData;
    }

}
