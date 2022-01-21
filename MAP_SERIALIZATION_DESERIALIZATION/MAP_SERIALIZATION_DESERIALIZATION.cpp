// MAP_SERIALIZATION_DESERIALIZATION.cpp: определяет точку входа для приложения.
//

#include "MAP_SERIALIZATION_DESERIALIZATION.h"

using namespace std;

int main() {
	//I would like to serialize a map of pointers.

	//Map creation :
	float* data = new float[1000];
	std::map<int, std::map<std::string, float*> > mapa;
	mapa[4]["foo"] = data;

	//Serialize map to file :
	string path = "/serialiation";
	std::ofstream ofs(path);
	boost::archive::binary_oarchive oa(ofs);
	oa << mapa;
	ofs.close();

	//Loading map from file :
	std::ifstream ifs("somefile", std::ios::binary);
	boost::archive::binary_iarchive ia(ifs);
	std::map<int, std::map<std::string, float*> > newMapa;
	ia >> newMapa;
	ifs.close();
	
	
	cout << "Hello CMake." << endl;
	return 0;
}
