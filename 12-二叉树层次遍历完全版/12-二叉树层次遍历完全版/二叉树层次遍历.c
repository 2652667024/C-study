#include <stdio.h>
#include <stdlib.h>
//创建一个树结构体
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

/* 创建节点 是树的结点 *///就是创造了结点并且data是输入进去的
Node* CreateNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));//开辟一个动态空间
    node->data = data;
    node->left = NULL;//这是这个的头结点，只给data赋值左右字节为空
    node->right = NULL;

    return node;
}

/* 队列结构 */
typedef struct Queue
{
    Node** array;//array存的是node的地址。其实就是这个元素表（树）链接
    int front;//初始化头部位置
    int rear;//初始化尾部位置
    int size;//队列放进来的元素个数
}Queue;

/* 创建队列 */
Queue* CreateQueue(int size)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));//分配一个空间
    queue->size = size;//队列指向的size就是输入的参数。
    queue->front = queue->rear = -1;//队列指向的头和尾都是-1；
    queue->array = (Node**)malloc(queue->size * sizeof(Node*));//array就是分配的空间因为存在二级指针，所以是Node**,queue->size就是输入了多少单位，
    //这些单位* node*类型就是申请的总长度。
    return queue;//最后返回queue。这就是初始化了一个队列
}

/* 入队 */
void EnQueue(Queue* queue, Node* node) //将node类型的参数放在队列里面实现
{
    if (queue->rear == queue->size - 1)//队列尾巴的上标等于放进来的元素的个数-1（因为从0 开始，总会少一个）
        printf("Queue is Full\n");//打印，满了
    else
    {
        queue->rear++;//尾插法。尾巴加一
        queue->array[queue->rear] = node;//将这个新元素插入到这个时候的尾巴位置。
    }
}

/* 出队 */
Node* DeQueue(Queue* queue) //只需要在队列里面实现
{
    if (queue->front == queue->rear + 1)//如果队列的头是队列的尾巴+1（头尾相差一才是一个完整的）
    {
        printf("Queue is Empty\n");//打印队列是一个空的
    }
    else
    {
        queue->front++;//队列，先进先出
        return queue->array[queue->front];//此时是上一位后面的元素占到这一位了
    }

    return NULL;//前一项要出队，所以前一项就是空了
}

/* 二叉树队列遍历 */
void LevelOrderTraversal(Node* root)//创建一个根 
{
    Queue* queue = CreateQueue(100);//创建了100元素的队列。用来承担二叉树，放在队列里
    EnQueue(queue, root);//这个内容会消失，但是这个的结构是存在的，只能在这个的左右接着存

    while (queue->front != queue->rear) //头结点不等于尾结点。那就是可以正常存读
    {
        Node* current = DeQueue(queue);//将头删除，把俩孩子存到current。
        printf("%d ", current->data);//每次放入都打印一次，这样1出去。留下2和3.2，出去，留下4和5.

        if (current->left) //如果current指向的左存在数字，那么左边的子树结存本来该放进去的左子结
            EnQueue(queue, current->left);

        if (current->right)//同理
            EnQueue(queue, current->right);
    }
}

int main()
{

    /* 构建二叉树 */
    Node* root = CreateNode(1);//将1给到node类型的根里面
    root->left = CreateNode(2);//将2存在根的左边
    root->right = CreateNode(3);//将3存在跟的右边同时删除1了已经
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);
    LevelOrderTraversal(root);

    return 0;
}