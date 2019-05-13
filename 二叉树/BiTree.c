/***********************************************************
• 二叉树数据结构的二叉链表表示法
• 动态创建二叉树
• 三种遍历算法的实现
************************************************************/
#include <iostream>
#include <string>

using namespace std;

typedef struct BiTNode_Def
{
	string data;
	BiTNode_Def *lchild, *rchild;
}BiTNode_Def, *BiTNode;

class BiTree
{
private:
	
public:
	BiTNode node;							// 根节点

	BiTree();
	~BiTree();

	void CreatTree(BiTNode *T);				// 创建树

	void PreOrderTracerse(BiTNode T);		// 前序遍历
	void InOrderTracerse(BiTNode T);		// 中序遍历
	void PostOrderTracerse(BiTNode T);		// 后续遍历
};

BiTree::BiTree()
{
	node = NULL;
}

BiTree::~BiTree()
{
	;
}

void BiTree::CreatTree(BiTNode *T)
{
	 string data;
	 cout << "enter the value of node:";
	 cin >> data;

	 if (data == "#")
	 	*T = NULL;
	 else
	 {
	 	*T = new BiTNode_Def;
	 	cout << *T << endl;
	 	if(!(*T))
	 		exit(0);
	 	(*T)->data = data;					// 生成根节点
	 	CreatTree(& (*T)->lchild);			// 构建左子树
	 	CreatTree(& (*T)->rchild);
	 }	
}
/*前序遍历*/
void BiTree::PreOrderTracerse(BiTNode T)
{
	if(T == NULL)
		return;
	cout << T->data << ' ';

	PreOrderTracerse(T->lchild);
	PreOrderTracerse(T->rchild);
}

/*中序遍历*/
void BiTree::InOrderTracerse(BiTNode T)
{
	if(T == NULL)
		return;

	InOrderTracerse(T->lchild);
	cout << T->data << ' ';
	InOrderTracerse(T->rchild);
}

/*后序遍历*/
void BiTree::PostOrderTracerse(BiTNode T)
{
	if(T == NULL)
		return;
	
	PostOrderTracerse(T->lchild);
	PostOrderTracerse(T->rchild);
	cout << T->data << ' ';
}

int main()
{
	BiTree BT;

	BT.CreatTree(& BT.node);
	cout << endl << "PreOrderTracerse:" <<endl;
	BT.PreOrderTracerse(BT.node);
	cout << endl << "InOrderTracerse:" <<endl;
	BT.InOrderTracerse(BT.node);
	cout << endl << "PostOrderTracerse:" <<endl;
	BT.PostOrderTracerse(BT.node);

	return 0;
}
