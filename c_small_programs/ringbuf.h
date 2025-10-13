#ifndef RINGBUF_H
#define RINGBUF_H

#include <stddef.h>
#include <stdbool.h>
#include <stdbool.h>

typedef struct {
    unit8_t *data;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t size;
} ringbuf_t;

bool ringbuf_init(ringbuf_t *rb, size_t capacity);
void ringbuf_free(ringbuf_t *rb);

