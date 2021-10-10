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
	cout << "effektivnost:" << station.eff << endl;
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

void savepipe(const pipe& pipe)
{
	ofstream fout;
	fout.open("pipe.txt", ios::out);
	if (fout.is_open())
	{
		cout << "ID:" << pipe.id << endl;
		cout << "dlina:" << pipe.dlina << endl;
		cout << "diametr:" << pipe.diametr << endl;
		cout << "v remonte:" << pipe.v_remonte << endl;
		fout.close();
	}
}
void savestation(const station& station)
{
	ofstream fout;
	fout.open("station.txt", ios::out);
	if (fout.is_open())
	{
		cout << "ID:" << station.id << endl;
		cout << "name:" << station.name << endl;
		cout << "tseh:" << station.tseh << endl;
		cout << "tsehi v rabote:" << station.tseh_v_rabote << endl;
		cout << "effektivnost:" << station.eff << end
		fout.close();
	}
}

void save(const pipe& pipe, const station& station)
{
	ofstream fout;
	fout.open("all.txt", ios::out);
	if (fout.is_open())
	{
		cout << "ID:" << pipe.id << endl;
		cout << "dlina:" << pipe.dlina << endl;
		cout << "diametr:" << pipe.diametr << endl;
		cout << "v remonte:" << pipe.v_remonte << endl;
		cout << "ID:" << station.id << endl;
		cout << "name:" << station.name << endl;
		cout << "tseh:" << station.tseh << endl;
		cout << "tsehi v rabote:" << station.tseh_v_rabote << endl;
		cout << "effektivnost:" << station.eff << endl;
		fout.close();
	}
}
void saveall(int e, const pipe& pipe, const station& station)
{
	switch (e)
	{
	case 1:
		savepipe(pipe);
		break;
	case 2:
		savestation(station);
		break;
	case 3:
		save(pipe, station);
		break;
	}
 }

pipe browsepipe()
{
	pipe pipe;
	ifstream fin;
	fin.open("pipe.txt", ios::in);
	if (fin.is_open())
	{
		fin >> pipe.dlina ;
		fin >> pipe.diametr;
		fin >> pipe.v_remonte;
		fin.close();
		return pipe;
	}
};
pipe browsestation()
{
	station station;
	ifstream fin;
	fin.open("station.txt", ios::in);
	if (fin.is_open())
	{
		fin >> station.name;
		fin >> station.tseh;
		fin >> station.tseh_v_rabote;
		fin >> station.eff;
		fin.close();
		return station;
	}
};

void browse(pipe& pipe, station& station)
{
	ifstream fin;
	fin.open("all.txt", ios::in);
	if (fin.is_open())
	{
		fin >> pipe.dlina;
		fin >> pipe.diametr;
		fin >> pipe.v_remonte;
		fin >> station.name;
		fin >> station.tseh;
		fin >> station.tseh_v_rabote;
		fin >> station.eff;
	}
	fin.close();
};

void browseall(pipe& pipe, station& station)
{
	switch (proverka(1, 3, "\n Vyberite 1-truba, 2-stantsiya, 3-vse vmeste: "))
	{
	case 1:
		lookpipe(browsepipe());
		break;
	case 2:
		lookstation(browsestation());
		break;
	case 3:
		browse(pipe, station);
		break;
	}
}

void printmenu()
{
	cout << 1.truba << endl;
	cout << 2.stantsiya << endl;
	cout << 3.look << endl;
	cout << 4.redaktirovat truby(edit) << endl;
	cout << 5.redaktirovat stantsiyu(edit)<< endl;
	cout << 6.sohranit(save) << endl;
	cout << 7.zagruzit(browse) << endl;
	cout << 0.viyti(exit) << endl;
}

int main()
{
	pipe pipe;
	station station;
	bool is_pipe = 0;
	bool is_station = 0;
	while (1)
	{
		printmenu();
		switch (proverka(0,7,"menu:"))
		{
		case 1:
		{
			pipe = createpipe();
			is_pipe == true;
			break;
		}
		case 2:
		{
			station = createstation();
			is_station == true;
			break;
		}
		case 3:
			if (is_pipe == true && is_station == true)
			{
				{
					cout << "vyberite variant 1-pipe, 2-station";
					int q = 0;
					cin >> q;
					lookall(q, pipe, station);
					break;
				}
			}
			else
			{
				cout << "vvedite dannye dlya 1 and 2";
			}
		case 4:
		{
			if (is_pipe == true)
			{
				editpipe(pipe);
				break;
			}
		}
		case 5:
		{
			if (is_station == true)
			{
				editstation(station);
				break;
			}
		}
		case 6:
		{
			if (is_pipe--true && is_station == true)
			{
				cout << "Vyberite: 1-pipe, 2-station, 3-all";
				int e = 0;
				cin >> e;
				saveall(e, pipe, station);
				break;
			}
		}
		case 7:
		{
			if (is_pipe == true && is_station == true)
			{
				browseall(pipe, station)
				break;
			}
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "oshibka!!!";
		}
		}
	}
	return 0;
}

