#ifndef _VECTOR_H
#define _VECTOR_H
typedef struct{
    void* vector;
    int size;
    int capacity;
    int front;
    int rear;
} vector;

vector* vector_init();
int vector_size(vector* vector);
int vector_capacity(vector* vector);
int vector_empty(vector* vector);
int vector_pop(vector* vector);
void vector_push(vector* vector,void* data);
void vector_delete(vector* vector,int index);
void vector_insert(vector* vector,int index,void* data);

#endif
