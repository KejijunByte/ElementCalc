//PSO.H--计分。
#pragma once

#ifndef _Pso_H_
#define _Pso_H_
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<random>
#include<new>
#include<cmath>
#include<array>
#include<fstream>
#include<string>

#ifndef _PSO_
#define _PSO_
using namespace std;

class Pso 
{
private:
	const char* Username;
	char code;
	double Mark[8] = {0,0,0,0,0,0,0,0};
protected:
	//TODO:加点你要付出1万甚至5000的努力写mode罢
public:
	Pso(const char* chr =0, char cds = 0);
	~Pso();
	void switchChoice();
	void show();
};
#endif
Pso::~Pso() {}
void Pso::show(){
	cout << "User: " << Username << "\nWelcome to access it!!\nHave fun!\n";
}

ifstream ifs;

//inline void readFile() {
//	ifs.open(FLNM, ios_base::binary | ios_base::in);
//	if (!ifs.is_open()) { return; }
//	if (ifs.is_open()) {
//		ifs.close();
//	}
//}

void Pso::switchChoice() {
	cout << "请输入 " << Username << " 的Mark：";
	
	ofstream ofs; const char* FLNM = "Marks.BIN";

	ofs.open(FLNM, ios_base::binary | ios_base::app | ios_base::out);
	//if (!ofs.is_open()) {
	//	return;
	//}
	ofs << "User: " << Username << endl;
	double MarkAll=0;
	int ZeroTimes=0;
	for (int MaSize = 0; MaSize < 8; MaSize++) {
		//<summary>
		//FOR:计分叠加
		//</summary>
		cin >> Mark[MaSize];
		MarkAll+=Mark[MaSize];
		if(Mark[MaSize]>=0){
		ZeroTimes++;
		}
	}

	switch (code) {
	case '1':
		cout << "Average : " << MarkAll / ZeroTimes<< endl;
		ofs << "Average : " << MarkAll / ZeroTimes<< endl;
		break;
	case '2':
		cout << "All " << MarkAll << endl;
		ofs << "Status: All " << endl << MarkAll << endl;
		break;
		//The developing of read files.
		/*case'f':
		case'F':
			break;*/
	};

	ofs.close();
}

Pso::Pso(const char* chr,char cds) :Username(chr) ,code(cds){}

#endif
