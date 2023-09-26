#include <stdio.h>
#include <stdlib.h>
//����һ�����ṹ��
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

/* �����ڵ� �����Ľ�� *///���Ǵ����˽�㲢��data�������ȥ��
Node* CreateNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));//����һ����̬�ռ�
    node->data = data;
    node->left = NULL;//���������ͷ��㣬ֻ��data��ֵ�����ֽ�Ϊ��
    node->right = NULL;

    return node;
}

/* ���нṹ */
typedef struct Queue
{
    Node** array;//array�����node�ĵ�ַ����ʵ�������Ԫ�ر���������
    int front;//��ʼ��ͷ��λ��
    int rear;//��ʼ��β��λ��
    int size;//���зŽ�����Ԫ�ظ���
}Queue;

/* �������� */
Queue* CreateQueue(int size)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));//����һ���ռ�
    queue->size = size;//����ָ���size��������Ĳ�����
    queue->front = queue->rear = -1;//����ָ���ͷ��β����-1��
    queue->array = (Node**)malloc(queue->size * sizeof(Node*));//array���Ƿ���Ŀռ���Ϊ���ڶ���ָ�룬������Node**,queue->size���������˶��ٵ�λ��
    //��Щ��λ* node*���;���������ܳ��ȡ�
    return queue;//��󷵻�queue������ǳ�ʼ����һ������
}

/* ��� */
void EnQueue(Queue* queue, Node* node) //��node���͵Ĳ������ڶ�������ʵ��
{
    if (queue->rear == queue->size - 1)//����β�͵��ϱ���ڷŽ�����Ԫ�صĸ���-1����Ϊ��0 ��ʼ���ܻ���һ����
        printf("Queue is Full\n");//��ӡ������
    else
    {
        queue->rear++;//β�巨��β�ͼ�һ
        queue->array[queue->rear] = node;//�������Ԫ�ز��뵽���ʱ���β��λ�á�
    }
}

/* ���� */
Node* DeQueue(Queue* queue) //ֻ��Ҫ�ڶ�������ʵ��
{
    if (queue->front == queue->rear + 1)//������е�ͷ�Ƕ��е�β��+1��ͷβ���һ����һ�������ģ�
    {
        printf("Queue is Empty\n");//��ӡ������һ���յ�
    }
    else
    {
        queue->front++;//���У��Ƚ��ȳ�
        return queue->array[queue->front];//��ʱ����һλ�����Ԫ��ռ����һλ��
    }

    return NULL;//ǰһ��Ҫ���ӣ�����ǰһ����ǿ���
}

/* ���������б��� */
void LevelOrderTraversal(Node* root)//����һ���� 
{
    Queue* queue = CreateQueue(100);//������100Ԫ�صĶ��С������е������������ڶ�����
    EnQueue(queue, root);//������ݻ���ʧ����������Ľṹ�Ǵ��ڵģ�ֻ������������ҽ��Ŵ�

    while (queue->front != queue->rear) //ͷ��㲻����β��㡣�Ǿ��ǿ����������
    {
        Node* current = DeQueue(queue);//��ͷɾ�����������Ӵ浽current��
        printf("%d ", current->data);//ÿ�η��붼��ӡһ�Σ�����1��ȥ������2��3.2����ȥ������4��5.

        if (current->left) //���currentָ�����������֣���ô��ߵ�������汾���÷Ž�ȥ�����ӽ�
            EnQueue(queue, current->left);

        if (current->right)//ͬ��
            EnQueue(queue, current->right);
    }
}

int main()
{

    /* ���������� */
    Node* root = CreateNode(1);//��1����node���͵ĸ�����
    root->left = CreateNode(2);//��2���ڸ������
    root->right = CreateNode(3);//��3���ڸ����ұ�ͬʱɾ��1���Ѿ�
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);
    LevelOrderTraversal(root);

    return 0;
}