#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>
//Reference for queue implementation : https://gist.github.com/ArnonEilat/4471278

typedef struct {
	char name[3];
	double qTime;
} DATA;

typedef struct process_t {
	DATA data;
	struct process_t *prev;
} process;

typedef struct Queue {
	process *head;
	process *tail;
	char Qname[20];
	double QueueQuantum;
	int size;
	int limit;
} Queue;

Queue *ConstructQueue(int limit);
int Enqueue(Queue *pQueue, process *item);
process *Dequeue(Queue *pQueue);
int isEmpty(Queue* pQueue);

Queue *ConstructQueue(int limit) {
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) {
		return NULL;
	}
	if (limit <= 0) {
		limit = 65535;
	}
	queue->limit = limit;
	queue->size = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

int Enqueue(Queue *pQueue, process *item) {

	if ((pQueue == NULL) || (item == NULL)) {
		return 0;
	}
	if (pQueue->size >= pQueue->limit) {
		return 0;
	}

	item->prev = NULL;
	if (pQueue->size == 0) {
		pQueue->head = item;
		pQueue->tail = item;
	}
	else {
		pQueue->tail->prev = item;
		pQueue->tail = item;
	}
	pQueue->size++;

	//Control if queue is FCFS or not
	if (strcmp(pQueue->Qname, "FCFS") == 0)
		item->data.qTime = item->data.qTime - item->data.qTime;

	else {

		if (item->data.qTime <= pQueue->QueueQuantum)
			item->data.qTime = item->data.qTime - item->data.qTime;
		else
			item->data.qTime = item->data.qTime - pQueue->QueueQuantum;
	}
	return 1;
}

process * Dequeue(Queue *pQueue) {
	process *item;
	if (isEmpty(pQueue))
		return NULL;
	item = pQueue->head;
	pQueue->head = (pQueue->head)->prev;
	pQueue->size--;
	return item;
}

int isEmpty(Queue* pQueue) {
	if (pQueue == NULL) {
		return 0;
	}
	if (pQueue->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void main()
{
	srand(time(0));
	process *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11,
		*p12, *p13, *p14, *p15, *p16, *p17, *p18, *p19, *p20;

	p1 = (process *)malloc(sizeof(process));
	strcpy_s(p1->data.name, 5, "P01"); ;
	p1->data.qTime = (rand() % (8 + 1 - 4) + 4);
	p1->data.qTime = p1->data.qTime / 1000;

	p2 = (process *)malloc(sizeof(process));
	strcpy_s(p2->data.name, 5, "P02"); ;
	p2->data.qTime = (rand() % (24 + 1 - 8) + 8);
	p2->data.qTime = p2->data.qTime / 1000;

	p3 = (process *)malloc(sizeof(process));
	strcpy_s(p3->data.name, 5, "P03");
	p3->data.qTime = (rand() % (50 + 1 - 24) + 24);
	p3->data.qTime = p3->data.qTime / 1000;

	p4 = (process *)malloc(sizeof(process));
	strcpy_s(p4->data.name, 5, "P04");

	p5 = (process *)malloc(sizeof(process));
	strcpy_s(p5->data.name, 5, "P05");

	p6 = (process *)malloc(sizeof(process));
	strcpy_s(p6->data.name, 5, "P06");

	p7 = (process *)malloc(sizeof(process));
	strcpy_s(p7->data.name, 5, "P07");

	p8 = (process *)malloc(sizeof(process));
	strcpy_s(p8->data.name, 5, "P08");

	p9 = (process *)malloc(sizeof(process));
	strcpy_s(p9->data.name, 5, "P09");

	p10 = (process *)malloc(sizeof(process));
	strcpy_s(p10->data.name, 5, "P10");

	p11 = (process *)malloc(sizeof(process));
	strcpy_s(p11->data.name, 5, "P11");

	p12 = (process *)malloc(sizeof(process));
	strcpy_s(p12->data.name, 5, "P12");

	p13 = (process *)malloc(sizeof(process));
	strcpy_s(p13->data.name, 5, "P13");

	p14 = (process *)malloc(sizeof(process));
	strcpy_s(p14->data.name, 5, "P14");

	p15 = (process *)malloc(sizeof(process));
	strcpy_s(p15->data.name, 5, "P15");

	p16 = (process *)malloc(sizeof(process));
	strcpy_s(p16->data.name, 5, "P16");

	p17 = (process *)malloc(sizeof(process));
	strcpy_s(p17->data.name, 5, "P17");

	p18 = (process *)malloc(sizeof(process));
	strcpy_s(p18->data.name, 5, "P18");

	p19 = (process *)malloc(sizeof(process));
	strcpy_s(p19->data.name, 5, "P19");

	p20 = (process *)malloc(sizeof(process));
	strcpy_s(p20->data.name, 5, "P20");

	int processArrayLength = 20;
	process processArray[20] = { *p1, *p2, *p3,  *p4,  *p5,  *p6,  *p7,  *p8,  *p9,  *p10,  *p11,
		*p12,  *p13,  *p14,  *p15,  *p16,  *p17,  *p18,  *p19,  *p20 };

	for (int i = 3; i < 20;i++) {
		processArray[i].data.qTime = (rand() % (50 + 1 - 4) + 4);
		processArray[i].data.qTime = processArray[i].data.qTime / 1000;
	}

	Queue *pQ1 = ConstructQueue(20);
	pQ1->QueueQuantum = 0.008;
	strcpy_s(pQ1->Qname, 25, "Round Robin");
	printf("---------- Burst time for all process ---------- \n");
	for (int i = 0; i < processArrayLength; i++)
		printf("Burst time for %s => %.3f \n", processArray[i].data.name, processArray[i].data.qTime);

	for (int i = 0; i < processArrayLength; i++)
		Enqueue(pQ1, &processArray[i]);

	printf("---------- After first queue ---------- \n");

	for (int i = 0; i < processArrayLength; i++) {
		process *p = Dequeue(pQ1);
		printf("Remaining burst time for %s => %.3f \n", p->data.name, p->data.qTime);
	}

	for (int i = 0; i < processArrayLength; i++) {
		if (processArray[i].data.qTime <= 0.0) {
			for (int c = i; c < processArrayLength; c++) {
				if (c != processArrayLength - 1 && i != processArrayLength - 1)
				{
					strcpy_s(processArray[c].data.name, 5, processArray[c + 1].data.name);
					processArray[c].data.qTime = processArray[c + 1].data.qTime;
				}
			}
			processArrayLength--;
			i--;
		}
	}

	Queue *pQ2 = ConstructQueue(20);
	pQ2->QueueQuantum = 0.016;
	strcpy_s(pQ2->Qname, 25, "Round Robin");
	for (int i = 0; i < processArrayLength; i++)
		Enqueue(pQ2, &processArray[i]);

	printf("---------- After second queue ---------- \n");

	for (int i = 0; i < processArrayLength; i++) {
		process *p = Dequeue(pQ2);
		printf("Remaining burst time for %s => %.3f \n", p->data.name, p->data.qTime);
	}

	for (int i = 0; i < processArrayLength; i++) {
		if (processArray[i].data.qTime <= 0.0) {
			for (int c = i; c < processArrayLength; c++) {
				if (c != processArrayLength - 1 && i != processArrayLength - 1)
				{
					strcpy_s(processArray[c].data.name, 5, processArray[c + 1].data.name);
					processArray[c].data.qTime = processArray[c + 1].data.qTime;;
				}
			}
			processArrayLength--;
			i--;
		}
	}

	Queue *pQ3 = ConstructQueue(20);
	strcpy_s(pQ3->Qname, 25, "FCFS");
	for (int i = 0; i < processArrayLength; i++)
		Enqueue(pQ3, &processArray[i]);

	printf("---------- After third queue ---------- \n");

	for (int i = 0; i < processArrayLength; i++) {
		process *p = Dequeue(pQ3);
		printf("Remaining burst time for %s => %.3f \n", p->data.name, p->data.qTime);
	}

	for (int i = 0; i < processArrayLength; i++) {
		if (processArray[i].data.qTime <= 0.0) {
			for (int c = i; c < processArrayLength; c++) {
				if (c != processArrayLength - 1 && i != processArrayLength - 1)
				{
					strcpy_s(processArray[c].data.name, 5, processArray[c + 1].data.name);
					processArray[c].data.qTime = processArray[c + 1].data.qTime;;
				}
			}
			processArrayLength--;
			i--;
		}
	}
	system("pause");
}
