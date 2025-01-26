#ifndef TESTC_VECTOR_H
#define TESTC_VECTOR_H

#include <malloc.h>
#include <stddef.h>
#include <memory.h>

typedef struct  {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
    struct VectorMethods *methods;
} vector_t;

struct VectorMethods {
    vector_t *(*create)(size_t element_size);

    void (*destroy)(vector_t *vec);

    void (*push_back)(vector_t *vec, const void *element);

    void (*pop_back)(vector_t *vec);
};

vector_t *vector_create(size_t element_size);

#endif
