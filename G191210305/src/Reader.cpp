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

Reader::Reader()
{
	ifstream dosyaOku;
	dosyaOku.open("./doc/Veri.txt");
	LinkedList *isimler= new LinkedList();
	satir=0;
	if(dosyaOku){
	
	while(!dosyaOku.eof())
	{
		
		getline(dosyaOku,line);
		satir++;
		sonIndis=line.length()-1;
		for(int s=0;s<line.length();s++)
		{
			if(line[s]=='E'||line[s]=='S')
				break;
			
			basIndis=(s+1);
			
		}
		if(line[basIndis]=='E'&&(line[(basIndis+1)]=='('&&line[sonIndis]==')'))
		{
			
			for(int k=0;k<line.length();k++)
			{
				if(line[k]=='#')
					
					break;
				veriBaslangicIndex=(k+2);
				
			}
			for(int j=(basIndis+2);j<line.length();j++)
			{
				if(line[j]=='#')
					break;
				if(line[j]!=' '&&line[j]!=')')
					indisLine+=line[j];
			}
			for(int i=veriBaslangicIndex;i<line.length();i++)    
			{
				if(line[i]==')')
					break;
				if(line[i]!=' '&&line[i]!=')')
					veri+=line[i];
			
			}
	
			if(veri==""&&indisLine==""){cout<<satir<<".satirda eklenecek deger ve indis degeri yok."<<endl;}
			else if(veri==""){cout<<satir<<".satirda eklenecek deger yok."<<endl;}
			else if(indisLine==""){cout<<satir<<".satirda indis degeri yok."<<endl;}	
			else
			{
				index=stoi(indisLine);
				if(index<0) {cout<<satir<<". satirda hatali indis"<<endl;}
				else if(isimler->isEmpty() || index>=isimler->Count()){
					isimler->add(veri);
					
				}
				else
				{
					isimler->insert(index,veri);
					
				}
				
			}
			
		}
		
		else if(line[basIndis]=='S'&&(line[(basIndis+1)]=='('&&line[sonIndis]==')'))
		{
			for(int j=(basIndis+2);j<line.length();j++)
			{
				if(line[j]==')')
					break;
				
				indisLine+=line[j];
			}
			if(indisLine==""){cout<<satir<<".satirda indis degeri yok."<<endl;}
			else
			{
				index=stoi(indisLine);
				if(index<0) {cout<<satir<<". satirda hatali indis"<<endl;}
			
				else if(isimler->isEmpty())
				{
					cout<<"Once eleman ekleyiniz.."<<endl;
				}
					
				else if(index>=isimler->Count())
				{
					int size=isimler->Count();
					isimler->removeAt(size-1);
					
				}
					
						
				else if(!isimler->isEmpty() && index<isimler->Count()){
					isimler->removeAt(index);
					
				}
			}
			
		}
		else if(line=="")
		{
			cout<<satir<<".satir bos!!!"<<endl;
		}
		else 
		{
			cout<<satir<<".satirda hatali bilgi girisi!!!"<<endl;
		}
		
	

		indisLine="";
		veri="";	
		basIndis=0;
		
		
	}
	
	cout<<*isimler;
	delete isimler;
	}
	
	dosyaOku.close();
	
}