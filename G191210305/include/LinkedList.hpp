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
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <iostream>
#include "Node.hpp"

class LinkedList{
	private:
		Node *head;
		int size;
	public:
		
		LinkedList();
		Node *FindCurrentNode(int);
		int Count()const;
		bool isEmpty()const;
		Node* lastNode();
		void add(const string);
		void insert(int,const string);
		int indexOf(const string) const;
		void remove(const string);
		void removeAt(int);
		void clear();
		friend ostream& operator<<(ostream&, const LinkedList&);
		
		~LinkedList();
	
};