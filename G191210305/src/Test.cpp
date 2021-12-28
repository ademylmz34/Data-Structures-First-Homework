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
#include "Reader.hpp"

using namespace std;

int main()
{
    Reader *reader = new Reader();
	delete reader;
    cin.get();
	cin.ignore();
	 
	
}