#include<iostream>
using namespace std;

template<class T>
struct BTNode
{
	T data;
	BTNode<T> *lChild,*rChild;

	BTNode()
	{
		lChild=rChild=NULL;
	}

	BTNode(const T &val,BTNode<T> *Childl=NULL,BTNode<T> *Childr=NULL)
	{
		data=val;
		lChild=Childl;
		rChild=Childr;
	}

	BTNode<T>* CopyTree()
	{
		BTNode<T> *nl,*nr,*nn;

		if(&data==NULL)
		return NULL;

		nl=lChild->CopyTree();
		nr=rChild->CopyTree();

		nn=new BTNode<T>(data,nl,nr);
		return nn;
	}
};


template<class T>
class BinaryTree
{
	public:
		BTNode<T> *root;
		BinaryTree();
		~BinaryTree();

		void Pre_Order();
		void In_Order();
		void Post_Order();
		int Weight_Of(T dataF);

		int TreeHeight()const;
		int TreeNodeCount()const;

		void DestroyTree();
		void MakeTree(T pData,BinaryTree<T> leftTree,BinaryTree<T> rightTree);
		void Change(BTNode<T> *r);

	private:
		void Destroy(BTNode<T> *&r);
		void PreOrder(BTNode<T> *r);
		void InOrder(BTNode<T> *r);
		void PostOrder(BTNode<T> *r);

		int Height(const BTNode<T> *r)const;
		int NodeCount(const BTNode<T> *r)const;
};

template<class T>
BinaryTree<T>::BinaryTree()
{
	root=NULL;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	
}

template<class T>
void BinaryTree<T>::Pre_Order()
{
	PreOrder(root);
}

template<class T>
void BinaryTree<T>::In_Order()
{
	InOrder(root);
}

template<class T>
void BinaryTree<T>::Post_Order()
{
	PostOrder(root);
}

template<class T>
int BinaryTree<T>::TreeHeight()const
{
	return Height(root);
}

template<class T>
int BinaryTree<T>::TreeNodeCount()const
{
	return NodeCount(root);
}

template<class T>
void BinaryTree<T>::DestroyTree()
{
	Destroy(root);
}

template<class T>
void BinaryTree<T>::PreOrder(BTNode<T> *r)
{
	if(r!=NULL)
	{
		cout<<r->data<<' ';
		PreOrder(r->lChild);
		PreOrder(r->rChild);
	}
}

template<class T>
void BinaryTree<T>::InOrder(BTNode<T> *r)
{
	if(r!=NULL)
	{
		InOrder(r->lChild);
		cout<<r->data<<' ';
		InOrder(r->rChild);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(BTNode<T> *r)
{
	if(r!=NULL)
	{
		PostOrder(r->lChild);
		PostOrder(r->rChild);
		cout<<r->data<<' ';
	}
}

template<class T>
int BinaryTree<T>::NodeCount(const BTNode<T> *r)const
{
	if(r==NULL)
		return 0;
	else
		return 1+NodeCount(r->lChild)+NodeCount(r->rChild);
}

template<class T>
int BinaryTree<T>::Height(const BTNode<T> *r)const
{
	if(r==NULL)
		return 0;
	else
	{
		int lh,rh;
		lh=Height(r->lChild);
		rh=Height(r->rChild);
		return 1+(lh>rh?lh:rh);
	}
}

template<class T>
void BinaryTree<T>::Destroy(BTNode<T> *&r)
{
	if(r!=NULL)
	{
		Destroy(r->lChild);
		Destroy(r->rChild);
		delete r;
		r=NULL;
	}
}

template<class T>
void BinaryTree<T>::Change(BTNode<T> *r)//��������bt���н���������������
{
	BTNode<T> *p;
	if(r){ 
		p=r->lChild;
		r->lChild=r->rChild;
		r->rChild=p; //������Ů����
		Change(r->lChild);  //���������������н�����������
		Change(r->rChild);  //���������������н�����������
	}
}

template<class T>
void BinaryTree<T>::MakeTree(T pData,BinaryTree<T> leftTree,BinaryTree<T> rightTree)
{
	root = new BTNode<T>();
	root->data = pData;
	root->lChild = leftTree.root;
	root->rChild = rightTree.root;
}

//weight-find
template<class T>
int BinaryTree<T>::Weight_Of(T dataF)
{
	if(data==dataF)
		return 
}