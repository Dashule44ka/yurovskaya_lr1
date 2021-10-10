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
	int tseh_v_rabote;
	float eff;
	bool is_station;
};

bool isNuumber(char Symbol)
{
	if (Symbol >= '0' && Symbol <= '9')
		return true;
	return false;
};

pipe createpipe()
{
	pipe pipe;
	pipe.is_pipe == true;
	pipe.id = 1;
	pipe.dlina = proverka(1, 1000, "\n'Vvedite dlinu truby:");
	pipe.diametr = proverka(1, 1000, "\n'Vvedite diametr truby:");
	pipe.v_remonte = proverka(0, 1, "\n'Vvedite znachenie v reonte:");
	return pipe;
};

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
};

void lookpipe(const pipe& pipe);
{
	cout << "ID:" << pipe.id << endl;
	cout << "dlina:" << pipe.dlina << endl;
	cout << "diametr:" << pipe.diametr << endl;
	cout << "v remonte:" << pipe.v_remonte << endl;
}

void lookstation(cont ctation& station);
{
	cout << "ID:" << station.id << endl;
	cout << "name:" << station.name << endl;
	cout << "tseh:" << station.tseh << endl;
	cout << "tsehi v rabote:" << station.tseh_v_rabote << endl;
}

void lookall(int q, const pipe& pipe, const station& station)
{
	switch (q)
	{
	case 1:
		lookpipe(pipe);
		break;
	case 2:
		lookstation(station);
		break
	}
}

void editpipe(pipe& pipe)
{
	if (pipe.v_remonte == 1)
	{
		pipe.v_remonte = 0;
		cout << "\n truba ne v remonte!!!";
	}
	else
	{
		pipe.v_remonte_remonte = 1;
		cout << "\n truba v remonte!!!";
	}
};

void editstation(station& station)
{
	cout << "\n 1)tseh v rabote:";
	cout << "\n 2)tseh ne v rabote:";
	cout << "\n 3)nuzno vybrat:";
	int choise;
	cin >> choise;
	do
	{
		if (choise == 1)
		{
			station.tseh_v_rabote += 1;
		}
		else
		{
			station.tseh_v_rabote -= 1;
		}
	} 
	while (cin.fail() || isNumber(int(choise)));
};
