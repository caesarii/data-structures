#ifndef __GUAQUEUE_H__
#define __GUAQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"

struct QuenueStruct;
typedef struct QueueStruct Queue;


Queue *
QueueCreate(void);

void
QueueLog(Queue *queue);

int
QueueLength(Queue *queue);

void
QueueEnqueue(Queue *queue, type element);

int
QueueDequeue(Queue *queue);

bool
QueueIsEmpty(Queue *queue);

void
QueueClear(Queue *queue);

void
QueueRemove(Queue *queue);

#endif // GUAQUEUE_H_INCLUDED
