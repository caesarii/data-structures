
#include "Queue.h"


struct QueueStruct {
    List *list;
};

Queue *
QueueCreate(void) {
    Queue *s = malloc(sizeof(Queue));
    List *l = ListCreate(NULL, 0);
    s->list = l;
    return s;
}

void
QueueLog(Queue *queue) {
    ListLog(queue->list);
}

int
QueueLength(Queue *queue) {
     return ListLength(queue->list);
}


void QueueEnqueue(Queue *queue, type element){
    ListAppend(queue->list, element);
};

int
QueueDequeue(Queue *queue) {
    int deleted = ListShift(queue->list);
    return deleted;
}


bool
QueueIsEmpty(Queue *queue) {

    if(ListLength(queue->list) == 0) {
        return true;
    } else {
        return false;
    }
}

void
QueueClear(Queue *queue) {
    while(!QueueIsEmpty(queue)) {
        QueueDequeue(queue);
    }
}

void
QueueRemove(Queue *queue){
   QueueClear(queue);
    free(queue);

}
