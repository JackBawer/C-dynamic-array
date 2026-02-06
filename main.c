#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *items;
    size_t count;
    size_t capacity;
} Numbers;

typedef struct {
    float *items;
    size_t count;
    size_t capacity;
} Prices;

typedef struct {
    char **items;
    size_t count;
    size_t capacity;
} Names;

#define da_append(da, x)\
    do {\
        if (da.count >= da.capacity) {\
            if (da.capacity == 0) {\
                da.capacity = 256;\
            } else {\
                da.capacity *= 2;\
            }\
            da.items = realloc(da.items, da.capacity * sizeof(*da.items));\
        }\
        da.items[da.count++] = x;\
    } while(0);\

int main(void) {
    Numbers da = {0};
    
    for (int x = 0; x < 10; ++x) da_append(da, x);

    for (size_t i; i < da.count; ++i) printf("%d\n", da.items[i]);

    return 0;
}
