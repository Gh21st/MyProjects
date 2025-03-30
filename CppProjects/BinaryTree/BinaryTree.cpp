/*BinaryTree.cpp
 *My implementation of a Binary Tree (Traversable both ways) 
 *Isaac Boteler 
 *IsaacNAB14@gmail.com 
 *
 * */

#include <iostream> 


//For Binary Tree 
template <typename T> class Node {
	public: 
		Node();
		Node(T,Node*,Node*,Node*);
		
		void SetData(T);
		T GetData();

		void SetBack(Node*);
		Node* GetBack();

		void SetNextL(Node*);
		Node* GetNextL();
		
		void SetNextR(Node*); 
		Node* GetNextR();

	private:
		T m_data; 
		Node* m_back; 
		Node* m_nextL; 
		Node* m_nextR;
} 

//General Purpose, I combined Binary Tree Constructor + Spider (curr)  
template <typename T> class BinaryTree {
	public: 
		BinaryTree();
		BinaryTree(T*,bool); //Takes in array, populates wide (bool == 0) or tall (bool == 1)
		//curr is initialized as head for all trees 


		bool moveU();
		bool moveL();
		bool moveR()
		

	private:
		int m_height;
		Node* m_curr; 
}
template <typename T>
Node::Node():m_data(null),m_back(nullptr),m_nextL(nullptr),m_nextR(nullptr) {} 

template <typename T>
Node::Node(T data,Node* back,Node* left,Node* right):m_data(data),m_back(back),m_nextL(left),m_nextR(right) {}

template <typename T>
void Node::SetData(T data) {m_data = data;}

template <typename T> 
T Node::GetData() {return m_data;}

void Node::SetBack(Node* back) {m_back = back;}
Node* Node::GetBack() {return m_back;};

void Node::SetNextL(Node* back) {m_nextL = nextL;}
Node* Node::GetNextL() {return m_nextL;};

void Node::SetNextR(Node* back) {m_nextR = nextR;}
Node* Node::GetNextR() {return m_nextR;};








