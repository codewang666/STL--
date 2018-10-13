
//单链表
#include "stdafx.h"
#include <iostream>
#include "assert.h"


 struct Node  
{
	int  data;
	 Node* next;
};


class ChainNode
{
public:
	ChainNode(int size=10);
	ChainNode(const ChainNode& );
	~ChainNode();
	bool empty()const
	{
		return chainNum==0;
	}
	int chianSize()
	{
		return chainNum;
	}
	int& GetElement(int index)const;
	int FindElementIndex(const int&)const;
	bool EraseNode(int index);
	bool insertNode(int index,const int& theElement);
	void Display();
	void clearChainNode();

protected:
private:
	Node* pfirstNode;
	int chainNum;

};


ChainNode::ChainNode(int size)
{
	assert(size>1);
	pfirstNode=NULL;
	chainNum=0;
}
 


ChainNode::ChainNode(const ChainNode& NewNode )
{
	if(NewNode.chainNum<1)
		throw "execption";

	chainNum=NewNode.chainNum;
	//复制头结点
    Node* sourceNode=NewNode.pfirstNode;
	pfirstNode=new Node;
	pfirstNode->data=sourceNode->data;

   //要复制的结点后移
	sourceNode=sourceNode->next;
	Node* TargetNode=pfirstNode;

  
	while (sourceNode!=NULL)
	{

		TargetNode->next=new Node();
		TargetNode=TargetNode->next;
		TargetNode->data=sourceNode->data;

		sourceNode=sourceNode->next;

	}
	TargetNode->next=NULL;

}

ChainNode::~ChainNode()
{
	while (pfirstNode!=NULL)
	{
        Node* NextNode=pfirstNode->next;
		delete pfirstNode;
	    pfirstNode=NextNode;
	}
}

int& ChainNode::GetElement(int index)const
{
	if(index<0||index>chainNum)
		throw "EXECPTION";

	Node* currentnode=pfirstNode;
    for(int i=0;i<index;i++)
	{
		currentnode=currentnode->next;
	}

	return currentnode->data;

}

int ChainNode::FindElementIndex(const int& T)const
{
	int index=0;

	Node* temp=pfirstNode;
	while (temp!=NULL&&T!=temp->data)
	{
		temp=temp->next;
		index++;
	}
	if(temp==NULL)
		return -1;
	else
	   return index;
	
}

bool ChainNode::EraseNode(int index)
{
	 Node* temp=pfirstNode;
	 Node* frontNode=temp;

	 if(index<0||index>chainNum)
		 return false;

	 if(index==0)
	 {
		  pfirstNode=pfirstNode->next;
		  delete temp;
		  chainNum--;
		  return true;
	 }
		
	 int i =0;
	 while(i!=index)
	 {
		 frontNode=temp;
		 temp=temp->next;
		 i++;
	 }

	
	 frontNode->next=temp->next;
	 delete temp;
	 chainNum--;
	 return true;

}

bool ChainNode::insertNode(int index,const int& theElement)
{
	//检查索引
	 if(index<0||index>chainNum)
		 return false;

	Node* NewNode=new Node;
	Node* temp=pfirstNode;

	NewNode->data=theElement;
	if(index==0)
	{
		NewNode->next=pfirstNode;
		pfirstNode=NewNode;
		chainNum++;
		return true;
		 
	}
	else
	{
		int i=0;
		while (i!=index-1)
		{
			temp=temp->next;
			i++;
		}
		NewNode->next=temp->next;
		temp->next=NewNode;
		chainNum++;
	    return true;

	}

}

void ChainNode::Display()	
{
	Node* currentNode=pfirstNode;
	while (currentNode!=NULL)
	{
		std::cout<<currentNode->data<<std::endl;
		currentNode=currentNode->next;
	}

}

void ChainNode::clearChainNode()
{
	Node* temp;
	while (pfirstNode!=NULL)
	{
		temp=pfirstNode->next;
		delete pfirstNode;
		pfirstNode=temp;

	}
	chainNum=0;

}
