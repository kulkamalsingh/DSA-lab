#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 5

int sequentialSearch(int block[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (block[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int indexSequentialSearch(int data[], int size, int key)
{
    int numBlocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    int index[numBlocks];
    int blockStart[numBlocks];

    for (int i = 0; i < numBlocks; i++)
    {
        blockStart[i] = i * BLOCK_SIZE;
        if (blockStart[i] + BLOCK_SIZE - 1 < size)
        {
            index[i] = data[blockStart[i] + BLOCK_SIZE - 1];
        }
        else
        {
            index[i] = data[size - 1];
        }
    }

    int blockIndex = -1;
    for (int i = 0; i < numBlocks; i++)
    {
        if (key <= index[i])
        {
            blockIndex = i;
            break;
        }
    }

    if (blockIndex != -1)
    {
        int start = blockStart[blockIndex];
        int end = start + BLOCK_SIZE;
        if (end > size)
        {
            end = size;
        }
        int pos = sequentialSearch(&data[start], end - start, key);
        if (pos != -1)
        {
            return start + pos;
        }
    }

    return -1;
}

int main()
{
    int data[] = {3, 5, 7, 9, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
    int size = sizeof(data) / sizeof(data[0]);
    int key = 24;

    int result = indexSequentialSearch(data, size, key);
    if (result != -1)
    {
        printf("Element %d found at index %d.\n", key, result);
    }
    else
    {
        printf("Element %d not found.\n", key);
    }

    return 0;
}
