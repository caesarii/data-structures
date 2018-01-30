#include <stdio.h>
#include "../Queue.h"
void
testQueue() {

    void
    testQueueLength() {
        Queue *q = QueueCreate();
        ensure(QueueLength(q) == 0, "test queue length 1");

        printf("queue length \n");
    }

    void
    testEnqueueDeque() {
        Queue *q = QueueCreate();
        QueueEnqueue(q, 0);
        QueueEnqueue(q, 1);
        QueueEnqueue(q, 2);
        QueueLog(q);
        ensure(QueueLength(q) == 3, "test enqueue 1");

        ensure(QueueIsEmpty(q) == false, "test isEmpyt 1");

        ensure(QueueDequeue(q) == 0, "test dequeue 1");
        ensure(QueueDequeue(q) == 1, "test dequeue 2");
        ensure(QueueDequeue(q) == 2, "test dequeue 3");
        ensure(QueueDequeue(q) == -1, "test dequeue 4");
        QueueLog(q);
        ensure(QueueIsEmpty(q) == true, "test isEmpyt 2");

        printf("enque deque isEmpty \n");
    }

    void
    testQueueClear() {
        Queue *q = QueueCreate();
        QueueEnqueue(q, 0);
        QueueEnqueue(q, 1);
        QueueEnqueue(q, 2);
        QueueClear(q);
        ensure(QueueLength(q) == 0, "test clear 1");
        QueueRemove(q);
        printf("queue clear \n");
    }

    testQueueLength();
    testEnqueueDeque();
    testQueueClear();
}

