#include "vector.h"


void vector_destroy(vector_t *vec);

void vector_push_back(vector_t *vec, const void *element);

void vector_pop_back(vector_t *vec);

struct VectorMethods vector_methods = {
        .destroy = vector_destroy,
        .push_back = vector_push_back,
        .pop_back = vector_pop_back
};

vector_t *vector_create(size_t element_size) {
    vector_t *vec = (vector_t *) malloc(sizeof(vector_t));
    if (!vec) {
        return NULL;
    }
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    vec->element_size = element_size;
    vec->methods = &vector_methods;
    return vec;
}

void vector_destroy(vector_t *vec) {
    if (vec) {
        if (vec->data != NULL) {
            free(vec->data);
        }
        free(vec);
    }
}

void vector_push_back(vector_t *vec, const void *element) {
    if (vec->size == vec->capacity) {
        size_t new_capacity = vec->capacity == 0 ? 1 : vec->capacity * 2;
        void *new_data = realloc(vec->data, new_capacity * vec->element_size);
        if (new_data == NULL) {
            return;
        }
        vec->data = new_data;
        vec->capacity = new_capacity;
        vector_push_back(vec, element);
    } else {
        memcpy((char *) vec->data + vec->size * vec->element_size, element, vec->element_size);
        vec->size++;
    }
}

void vector_pop_back(vector_t *vec) {
    if (vec->size > 0) {
        vec->size--;
        if (vec->size < vec->capacity / 4) {
            size_t new_capacity = vec->capacity / 2;
            void *new_data = realloc(vec->data, new_capacity * vec->element_size);
            if (new_data != NULL) {
                vec->data = new_data;
                vec->capacity = new_capacity;
            }
        }
    }
}
