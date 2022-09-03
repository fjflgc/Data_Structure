#include <cassert>
#include <algorithm>

using namespace std;

typedef int HPDataType;
typedef struct Heap {
    int size;
    int capacity;
    HPDataType *a;
} HP;

void heap_init(HP *heap);

void heap_destroy(HP *heap);

void heap_push(HP *heap, HPDataType x);

void heap_pop(HP *heap);

HPDataType heap_top(HP *heap);

int heap_size(HP *heap);

void adjust_up(HPDataType *a, int child)
{
    assert(a);
    int parent = (child - 1) / 2;//找出父节点
    //child等于0说明已经到了根部
    while (child > 0)
    {
        if (a[child] < a[parent])
        {
            swap(a[child], a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
            break;
    }
}

void heap_push(HP *heap, HPDataType x)
{
    assert(heap);
    if (heap->size == heap->capacity)
    {
        int newcapacity = heap->capacity == 0 ? 4 : heap->capacity * 2;
        HPDataType *temp = (HPDataType *) realloc(heap->a, newcapacity * sizeof(HPDataType));
        if (!temp)
            exit(-1);
        heap->a = temp;
        heap->capacity = newcapacity;
    }
    heap->a[heap->size] = x;
    heap->size++;
    adjust_up(heap->a, heap->size - 1);
}

//向下调整
void adjust_down(HPDataType *a, int size, int parent)
{
    assert(a);
    int child = parent * 2 + 1;
    while (child < size)
    {
        //挑出两个子节点中更大或更小的那个
        if (child + 1 < size && a[child + 1] < a[child])//建小堆后面用小于号，建大堆后面用大于号
            child++;
        //儿子与父亲作比较
        if (a[child] < a[parent])
        {
            swap(a[child], a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;
    }
}

void heap_pop(HP *heap)
{
    assert(heap);
    assert(heap->a);
    swap(heap->a[0], heap->a[heap->size - 1]);//将根节点与最后一个节点交换
    heap->size--;
    adjust_down(heap->a, heap->size, 0);
}

//堆排序，降序
void heap_sort(int *a, int n)
{
    //向下调整建堆
    for (int i = (n - 2) / 2; i >= 0; i--)
        adjust_down(a, n, i);

    //向上调整建堆
    for (int i = 0; i < n; i++)
        adjust_up(a, i);

int end=n;
while(end>0){
    swap(a[0],a[end-1]);
    end--;
    adjust_down(a,end,0);
}
}