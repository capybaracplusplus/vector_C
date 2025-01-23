#include <stdio.h>
#include "vector.h"


int main(void) {

    printf("Hello, World!\n");

    struct Vector *vector = vector_create(sizeof(int));
    vector->methods->push_back(vector, &(int) {43});
    vector->methods->pop_back(vector);
    vector->methods->push_back(vector, &(int) {44});
    vector->methods->push_back(vector, &(int) {45});
    vector->methods->pop_back(vector);
    vector->methods->push_back(vector, &(int) {46});
    vector->methods->push_back(vector, &(int) {47});

    for (size_t i = 0; i < vector->size; i++) {
        printf("%d ", *((int *) ((char *) vector->data + i * vector->element_size)));
    }
    printf("\n");

    vector->methods->destroy(vector);

    return 0;
}
