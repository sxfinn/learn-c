#include"tree.h"
#include"queue.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (*pi >= n || a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	assert(root);
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}


// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);
	if(root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left)
		return left;
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right)
		return right;
	return NULL;
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	BinaryTreeInOrder(root->_right);
	printf("%c ", root->_data);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* ret = QueuePop(&q);
		if (ret)	
			printf("%c ", ret->_data);
		else
			printf("NULL ");
		if (ret)
		{
			QueuePush(&q, ret->_left);
			QueuePush(&q, ret->_right);
		}
	}
	QueueDestory(&q);
}


// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return true;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* ret = QueuePop(&q);
		if (ret == NULL)
			break;
		QueuePush(&q, ret->_left);
		QueuePush(&q, ret->_right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* ret = QueuePop(&q);
		if (ret)
		{
			QueueDestory(&q);
			return false;
		}
	}
	QueueDestory(&q);
	return true;
}


