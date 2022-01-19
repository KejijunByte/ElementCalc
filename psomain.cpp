#include "PSO.h"

int main(int argc, char* argv[]) {
	
	char* name=argv[1];
	char parameter = '0';
	if (argv[1] == 0) {
		cout << "Please enter your name: ";
		cin >> name;
	}
	cout << "Please enter your level: ";
	cin >> parameter;
	Pso isPoint(name, parameter);
	//あなたの名show：（
	isPoint.show();
	//总分还是平均:
	isPoint.switchChoice();
	return 0;
}
