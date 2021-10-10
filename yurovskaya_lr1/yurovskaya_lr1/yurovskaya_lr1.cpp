#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

template <typename T>
T proverka(T min, T max < string n)
{
	T x;
	cout << n;
	while ((cin > n).fail() || n > max || n < min)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << n;
	}
	return n;
}

struct pipe
{
	int id;
	float dlina;
	float diametr;
	bool v_remonte;
	bool is_pipe;
};

struct station
{
	int id;
	string name;
	int tseh;
	int tceh_v_rabote;
	float eff;
	bool is_station;
};

bool isNuumber(char Symbol)
{
	if (Symbol >= '0' && Symbol <= '9')
		return true;
	return false;
}

pipe createpipe()
{
	pipe pipe;
	pipe.is_pipe == true;
	pipe.id = 1;
	pipe.dlina = proverka(1, 1000, "\n'Vvedite dlinu truby:");
	pipe.diametr = proverka(1, 1000, "\n'Vvedite diametr truby:");
	pipe.v_remonte= proverka(0, 1, "\n'Vvedite znachenie v reonte:");
	return pipe;
}

pipe createstation()
{
	station station;
	station.is_pipe == true;
	station.id = 1;
	cout << "Vvedite nazvanie station:" << endl;
	getline(cin, station.name);
	cin >> station.name;
	station.tseh = proverka(1, 1000, "\n'Vvedite kolvo tsehov:");
	station.tseh_v_rabote = proverka(1, station.tseh, "\n'Vvedite kolvo tsehov v rabote:");
	station.eff = proverka(1, 100, "\n'Kakova effektivnost:");
	return station;
}