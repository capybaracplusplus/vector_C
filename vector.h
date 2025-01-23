#ifndef TESTC_VECTOR_H
#define TESTC_VECTOR_H

#include <malloc.h>
#include <stddef.h>
#include <memory.h>


struct VectorMethods {
    struct Vector *(*create)(size_t element_size);

    void (*destroy)(struct Vector *vec);

    void (*push_back)(struct Vector *vec, const void *element);

    void (*pop_back)(struct Vector *vec);
};

struct Vector {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
    struct VectorMethods *methods;
};

struct Vector *vector_create(size_t element_size);

#endif
