#include <stdio.h>
#include <stdlib.h>

#define CYL 5000
#define REQS 1000

int random_array[REQS];
int test_array[REQS];

int start = 0;

int* sortArray()
{

    int temp = 0;
    int i = 0;
    int k = 0;

    for(i = 0; i < REQS; ++i)
    {
        for(k = k + 1; k < REQS; ++k)
        {
            if(random_array[i] > random_array[k])
            {
                temp = random_array[i];
                random_array[i] = random_array[k];
                random_array[k] = temp;
            }

        }

    }

    return random_array;
}

int firstCome(int *random_array)
{
    int i = 0;
    int head_move = 0;
    int new_start = random_array[start];

    for(i = start; i < REQS; i++)
    {
        head_move += abs(random_array[i] - new_start);
    }
    
    for(i = 0; i < start; i++)
    {
        head_move += abs(new_start - random_array[i]);
    }

    return head_move;

}

int shortestSeek(int * random_array)
{
    random_array = sortArray();

    int lower_i = start - 1;
    int large_i = start + 1;

    int lower_diff = 0;
    int large_diff = 0;

    int head_move = 0;
    int total = REQS - 2;
    int new_head = start;
    int val_head = random_array[start];

    while(total >= 0)
    {
        lower_diff = abs(random_array[new_head] - random_array[lower_i]);
        large_diff = abs(random_array[large_i] - random_array[new_head]);

        if(lower_diff < large_diff)
        {
            head_move += lower_diff;
            new_head = lower_i;
            lower_i--;
        }

        else
        {
            head_move += large_diff;
            new_head = large_i;
            large_i++;
        }

        total--;

    }

    return head_move;
}

int scan(int * random_array)
{
    int i = 0;
    int curr = 0;
    int prev = random_array[start];
    int diff = 0;

    int head_move = 0;
    int k = 0;

    for(i = start - 1; i >= 0; --i)
    {
        curr = random_array[i];
        diff = abs(prev - curr);
        head_move += diff;
        prev = curr;
    }

    head_move += prev;
    prev = 0;

    for(i = start + 1; i < REQS; i++)
    {
        curr = random_array[i];
        diff = abs(curr - prev);
        head_move += diff;
        prev = curr;
    }

    return head_move;
}

int main(int arg, char *args[])
{
    int i = 0;
    start = atoi(args[1]);

    for (i = 0; i < REQS; i++)
    {
        random_array[i] = rand() % 5000;
    }

    printf("FCFS:  %d\n", firstCome(random_array));
    printf("SSTF:  %d\n", shortestSeek(random_array));
    printf("SCAN:  %d\n", scan(random_array));
}