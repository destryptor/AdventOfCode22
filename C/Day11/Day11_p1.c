#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front, rear, size;
    unsigned capacity;
    int *array;
} QUEUE;

QUEUE *createQueue(unsigned capacity)
{
    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));

    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));

    return queue;
}

int isFull(QUEUE *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(QUEUE *queue)
{
    return (queue->size == 0);
}

void enqueue(QUEUE *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue FULL!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % (queue->capacity);
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(QUEUE *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue EMPTY!\n");
        return -100000;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % (queue->capacity);
    queue->size = queue->size - 1;
    return item;
}

int front(QUEUE *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue EMPTY!\n");
        return -100000;
    }
    return queue->array[queue->front];
}

void insertionSort(int *arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; ++i)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0 && arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    FILE *fptr;

    fptr = fopen("C:/Users/Asus/Desktop/AdventOfCode22/Input/Day11.txt", "r");
    if (fptr == NULL)
    {
        printf("\nError in opening file\n");
        exit(-1);
    }

    char buffer[10000];

    int monkeys = 0;

    while (fgets(buffer, 10000, fptr) != NULL)
    {
        if (sscanf(buffer, "Monkey %d:\n", &monkeys) == 1)
        {
            continue;
        }
    }

    monkeys++;

    QUEUE **monkey = (QUEUE **)malloc(monkeys * sizeof(QUEUE *));

    if (monkey == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(-1);
    }

    for (int i = 0; i < monkeys; i++)
    {
        monkey[i] = createQueue(100);
    }


    enqueue(monkey[0], 77);
    enqueue(monkey[0], 69);
    enqueue(monkey[0], 76);
    enqueue(monkey[0], 77);
    enqueue(monkey[0], 50);
    enqueue(monkey[0], 58);

    enqueue(monkey[1], 75);
    enqueue(monkey[1], 70);
    enqueue(monkey[1], 82);
    enqueue(monkey[1], 83);
    enqueue(monkey[1], 96);
    enqueue(monkey[1], 64);
    enqueue(monkey[1], 62);

    enqueue(monkey[2], 53);

    enqueue(monkey[3], 85);
    enqueue(monkey[3], 64);
    enqueue(monkey[3], 93);
    enqueue(monkey[3], 64);
    enqueue(monkey[3], 99);

    enqueue(monkey[4], 61);
    enqueue(monkey[4], 92);
    enqueue(monkey[4], 71);

    enqueue(monkey[5], 79);
    enqueue(monkey[5], 73);
    enqueue(monkey[5], 50);
    enqueue(monkey[5], 90);

    enqueue(monkey[6], 50);
    enqueue(monkey[6], 89);

    enqueue(monkey[7], 83);
    enqueue(monkey[7], 56);
    enqueue(monkey[7], 64);
    enqueue(monkey[7], 58);
    enqueue(monkey[7], 93);
    enqueue(monkey[7], 91);
    enqueue(monkey[7], 56);
    enqueue(monkey[7], 65);

    rewind(fptr);

    int rounds = 0;
    int topitem;

    int inspect[8] = {0};

    while (rounds < 20)
    {
        for (int i = 0; monkey[0]->size > 0; i++)
        {
            topitem = dequeue(monkey[0]);
            inspect[0]++;
            topitem *= 11;
            topitem = topitem / 3;

            if (topitem % 5 == 0)
            {
                enqueue(monkey[1], topitem);
            }
            else
            {
                enqueue(monkey[5], topitem);
            }
        }

        for (int i = 0; monkey[1]->size > 0; i++)
        {
            topitem = dequeue(monkey[1]);
            inspect[1]++;
            topitem += 8;
            topitem = topitem / 3;

            if (topitem % 17 == 0)
            {
                enqueue(monkey[5], topitem);
            }
            else
            {
                enqueue(monkey[6], topitem);
            }
        }

        for (int i = 0; monkey[2]->size > 0; i++)
        {
            topitem = dequeue(monkey[2]);
            inspect[2]++;

            if (topitem % 2 == 0)
            {
                enqueue(monkey[0], topitem);
            }
            else
            {
                enqueue(monkey[7], topitem);
            }
        }

        for (int i = 0; monkey[3]->size > 0; i++)
        {
            topitem = dequeue(monkey[3]);
            inspect[3]++;
            topitem += 4;
            topitem = topitem / 3;

            if (topitem % 7 == 0)
            {
                enqueue(monkey[7], topitem);
            }
            else
            {
                enqueue(monkey[2], topitem);
            }
        }

        for (int i = 0; monkey[4]->size > 0; i++)
        {
            topitem = dequeue(monkey[4]);
            inspect[4]++;
            topitem *= topitem;
            topitem = topitem / 3;

            if (topitem % 3 == 0)
            {
                enqueue(monkey[2], topitem);
            }
            else
            {
                enqueue(monkey[3], topitem);
            }
        }

        for (int i = 0; monkey[5]->size > 0; i++)
        {
            topitem = dequeue(monkey[5]);
            inspect[5]++;
            topitem += 2;
            topitem = topitem / 3;

            if (topitem % 11 == 0)
            {
                enqueue(monkey[4], topitem);
            }
            else
            {
                enqueue(monkey[6], topitem);
            }
        }

        for (int i = 0; monkey[6]->size > 0; i++)
        {
            topitem = dequeue(monkey[6]);
            inspect[6]++;
            topitem += 3;
            topitem = topitem / 3;

            if (topitem % 13 == 0)
            {
                enqueue(monkey[4], topitem);
            }
            else
            {
                enqueue(monkey[3], topitem);
            }
        }
        for (int i = 0; monkey[7]->size > 0; i++)
        {
            topitem = dequeue(monkey[7]);
            inspect[7]++;
            topitem += 5;
            topitem = topitem / 3;

            if (topitem % 19 == 0)
            {
                enqueue(monkey[1], topitem);
            }
            else
            {
                enqueue(monkey[0], topitem);
            }
        }

        rounds++;
    }

    insertionSort(inspect, 8);

    printf("Monkey Business: %d\n", inspect[7] * inspect[6]);

    return 0;
}
