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
#ifndef READER_HPP
#define READER_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include "LinkedList.hpp"

using namespace std;

class Reader{
	private:
		string veri;
		int index;
	public:
		string line;
		string indisLine;
		int satir;
		int veriBaslangicIndex;
		int basIndis;
		int sonIndis;
		Reader(); 
};
#endif