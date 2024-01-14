#include <iostream>

namespace AVLTree {

	class bst
	{
	private:
		struct Node
		{
			int value;	// ��ǰֵ
			int height;	// ��ǰ�ĸ߶�
			Node* leftChild, * rightChild, * parent;
		};

		// ����һ���ڵ�
		Node* createNode(Node* x, int value)
		{
			Node* p = new Node();
			p->rightChild = p->leftChild = nullptr;
			p->value = value;
			p->height = 1;
			p->parent = x;
			return p;
		}

		int getHeight(Node* p)
		{
			if (!p) return 0;

			return std::max(p->leftChild ? p->leftChild->height : 0, p->rightChild ? p->rightChild->height : 0) + 1;
		}

		/* LL(Y rotates to the right):

				 p                   X
			   /  \                 /  \
			  X    s     ==>       L    p
			 / \                      /  \
			L   R                    R    s
		*/
		/*
		 Return which the root pointer(at a higher level) should point to
		 */
		Node* rotate_LL(Node* p) {
			Node* x = p->leftChild;
			p->leftChild = x->rightChild;
			x->rightChild = p;
			x->parent = p->parent;
			p->parent = x;
			p->height = getHeight(p);
			x->height = getHeight(x);
			return x;
		}

		/* RR(Y rotates to the left):

				 p                       X
			   /  \                     /  \
			  S     X         ==>       p   R
				  /  \                /  \
				 L    R              S    L
		*/
		Node* rotate_RR(Node* p) {
			Node* x = p->rightChild;
			p->rightChild = x->leftChild;
			x->leftChild = p;
			x->parent = p->parent;
			p->parent = x;

			p->height = getHeight(p);
			x->height = getHeight(x);
			return x;
		}

		/* LR(B rotates to the left, then C rotates to the right):

			   x                          x                       k2
			 /  \                       /  \                     /  \
			k1   D                     k2   D                   k1    x
		   /  \         ==>           /  \        ==>          / \   / \
		  A    k2                    k1   C                   A  B  C   D
			  /  \                  /  \
			 B    C                A    B

		*/
		Node* rotate_LR(Node* x) {
			x->leftChild = rotate_RR(x->leftChild);
			return rotate_LL(x);
		}

		/* RL(D rotates to the right, then C rotates to the left):

			   k3                         k3                          k2
			  /  \                       /  \                        /  \
			 A    k1                    A    k2                     k3   k1
				 /  \       ==>             /  \         ==>       /  \  / \
				k2   B                     C    k1                A   C D   B
			   /  \                            /  \
			  C    D                          D    B

		 */
		Node* rotate_RL(Node* x) {
			x->rightChild = rotate_LL(x->rightChild);
			return rotate_RR(x);
		}

		Node* rotate(Node* x)
		{
			if (!x) return x;
			if (getHeight(x->leftChild) - getHeight(x->rightChild) == 2)
			{
				if (getHeight(x->leftChild->rightChild) > getHeight(x->leftChild->leftChild))
				{
					x = rotate_RL(x);
				}
				else
				{
					x = rotate_LL(x);
				}
			}
			else if (getHeight(x->rightChild) - getHeight(x->leftChild) == 2)
			{
				if (getHeight(x->rightChild->rightChild) > getHeight(x->rightChild->leftChild))
				{
					x = rotate_RR(x);
				}
				else
				{
					x = rotate_LR(x);
				}
			}
			return x;
		}

		// ɾ����
		void deleteTree(Node* p)
		{
			if (p == nullptr)
				return;

			deleteTree(p->leftChild);
			deleteTree(p->rightChild);
			delete p;
		}

		// �������
		void middle_order(Node* p)
		{
			if (p == nullptr) return;
			middle_order(p->leftChild);
			std::cout << "    value: " << p->value << " h" << p->height;
			middle_order(p->rightChild);
		}

		Node* insert(Node* p, int value)
		{
			if (p == nullptr) return createNode(p, value);

			if (value < p->value)
			{
				p->leftChild = insert(p->leftChild, value);
			}
			else
			{
				p->rightChild = insert(p->rightChild, value);
			}

			p->height = getHeight(p);
			return rotate(p);
		}

		Node* getSmallestTree(Node* p)
		{
			if (nullptr == p->leftChild) return p;
			return getSmallestTree(p->leftChild);
		}

		Node* delete_value(Node* p, int value)
		{
			if (!p) return p;

			if (value < p->value)
				p->leftChild = delete_value(p->leftChild, value);
			else if (value > p->value)
				p->rightChild = delete_value(p->rightChild, value);
			else
			{

				if (nullptr == p->rightChild)
				{
					Node* tmp = p;
					p = p->leftChild;
					delete tmp;
					return p;
				}
				else
				{
					Node* pSmall = getSmallestTree(p->rightChild);
					p->value = pSmall->value;
					pSmall->value = value;
					p->rightChild = delete_value(p->rightChild, value);
				}
			}
			p->height = getHeight(p);
			return rotate(p);
		}

	public:
		bst() : root(nullptr)
		{
		}

		~bst()
		{
			if (root)
				deleteTree(root);
		}

		void middle_order()
		{
			middle_order(root);
		}

		void insert(int value)
		{
			if (root == nullptr)
			{
				root = createNode(nullptr, value);
			}
			else
			{
				root = insert(root, value);
			}
		}

		void delete_value(int value)
		{
			if (root == nullptr) return;
			else
			{
				root = delete_value(root, value);
			}
		}

	private:
		Node* root;

	};


	int test()
	{
		std::cout << "---��AVL����---" << std::endl;
		// ����AVL��
		bst tree;

		// ˳���ӡAVL��
		std::cout << "����Ԫ�غ��AVL����" << std::endl;
		// ����Ԫ��
		tree.insert(2);
		tree.middle_order();
		std::cout << std::endl;
		tree.insert(1);
		tree.middle_order();
		std::cout << std::endl;
		tree.insert(3);
		tree.middle_order();
		std::cout << std::endl;
		tree.insert(4);
		tree.middle_order();
		std::cout << std::endl;
		tree.insert(5);
		tree.middle_order();
		std::cout << std::endl;
		tree.insert(6);
		tree.middle_order();
		std::cout << std::endl;
		tree.insert(7);
		tree.middle_order();
		std::cout << std::endl;
		tree.insert(8);
		tree.middle_order();
		std::cout << std::endl;

		// ɾ��Ԫ��
		tree.delete_value(2);

		// ˳���ӡAVL��
		std::cout << "ɾ��Ԫ�� 2 ���AVL����" << std::endl;
		tree.middle_order();

		// ����
		tree.~bst();

		getchar();
		return 0;
	}
};