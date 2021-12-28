/**
* @file VeriYapılarıOdev1
* @description MinGW C++ ile yazılacak program, açıldığı gibi Veri.txt dosyasını okuyacaktır. Bu dosyada her satırda 
	yapılacak işlemi belirten bilgi ve eklenecek veri bulunmaktadır. Veriler iki yönlü Bağıl Listeye 
	eklenecektir. 
* @course 2. Öğretim B Grubu
* @assignment 1
* @date 10.11.2021
* @author Adem Yılmaz adem.yilmaz10@ogr.sakarya.edu.tr
*/
#include "LinkedList.hpp"

Node* LinkedList::FindCurrentNode(int index){
	if(index==0) return head;
	
		Node *current=head;
		int i=1;
		for(Node *itr=head;itr->next!=NULL&& i!=index;itr=itr->next,i++) {
		current=current->next;
		}
		return current;
	

}

LinkedList::LinkedList(){
	head=NULL;
	size=0;
}
int LinkedList::Count()const{
	return size;
}
bool LinkedList::isEmpty()const{
	return size==0;
}
Node* LinkedList::lastNode(){
			
	return FindCurrentNode(size);
}
void LinkedList::add(const string item){
	insert(size,item);
}
void LinkedList::insert(int index,const string item){
	
	if(size==0){
		head=new Node(item,NULL,head);
	}
	
	else if(index==size)
	{
		Node *last=lastNode();
		last->next=new Node(item,NULL,last);
	}
	else{
		Node *last=lastNode();
		Node *currentNode=FindCurrentNode(index+1);
		last->next=new Node(" ",NULL,last);
	
		for(Node *itr=last->next;itr->prev!=NULL&& itr!=currentNode;itr=itr->prev){
			itr->data=itr->prev->data;
		}
		currentNode->data=item;
		
	}
	size++;
	}
int LinkedList::indexOf(const string item) const{
	int index=0;
	for(Node *itr=head;itr!=NULL;itr=itr->next){
		if(itr->data==item) return index;
			index++;
	}
	throw  "ELEMAN YOK";
}
void LinkedList::remove(const string item){
	int index=indexOf(item);
	removeAt(index);
}
void LinkedList::removeAt(int index){
	
	Node *del;
	if(size==1){
		del=head;
		head=head->next;
		head->prev=NULL;
	}
	else{
		Node* currentNode=FindCurrentNode(index+1);
		Node* last=lastNode();
		del=last;
		
		for(Node *itr=currentNode;itr->next!=NULL&& itr!=last;itr=itr->next){
			itr->data=itr->next->data;
		}
		del->prev->next=NULL;
		
	}
	
	delete del;
	size--;
}
void LinkedList::clear(){
	while(!isEmpty())
	{
		Node *del;
		del=head;
		head=head->next;
		if(head!=NULL)
			head->prev=NULL;
		
		delete del;
		size--;
		
	}
		
	
}
ostream& operator<<(ostream& screen, const LinkedList& right){
	for(Node *itr=right.head;itr!=NULL;itr=itr->next){
		screen<<itr->data<<"->";
	}
	screen<<"NULL"<<endl;
	return screen;
}
LinkedList::~LinkedList(){
	clear();
	
}
	
