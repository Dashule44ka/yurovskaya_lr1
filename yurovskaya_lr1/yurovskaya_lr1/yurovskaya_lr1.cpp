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

struct Station
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
	pipe p;
	p.is_pipe == true;
	p.id = 1;
	p.dlina = proverka(1, 1000, "\n'Vvedite dlinu truby:");
	p.diametr = proverka(1, 1000, "\n'Vvedite diametr truby:");
	p.v_remonte = proverka(0, 1, "\n'Vvedite znachenie v reonte:");
	return p;
};

pipe createStation()
{
	Station s;
	s.is_station == true;
	s.id = 1;
	cout << "Vvedite nazvanie station:" << endl;
	getline(cin, station.name);
	cin >> s.name;
	s.tseh = proverka(1, 1000, "\n'Vvedite kolvo tsehov:");
	s.tseh_v_rabote = proverka(1, station.tseh, "\n'Vvedite kolvo tsehov v rabote:");
	s.eff = proverka(1, 100, "\n'Kakova effektivnost:");
	return s;
};

void lookpipe(const pipe& p);
{
	cout << "ID:" << p.id << endl;
	cout << "dlina:" << p.dlina << endl;
	cout << "diametr:" << p.diametr << endl;
	cout << "v remonte:" << p.v_remonte << endl;
}

void lookStation(cont Station& s);
{
	cout << "ID:" << s.id << endl;
	cout << "name:" << s.name << endl;
	cout << "tseh:" << s.tseh << endl;
	cout << "tsehi v rabote:" << s.tseh_v_rabote << endl;
	cout << "effektivnost:" << s.eff << endl;
}

void lookall(int q, const pipe& pi, const Station& st)
{
	switch (q)
	{
	case 1:
		lookpipe(pi);
		break;
	case 2:
		lookStation(st);
		break
	}
}

void editpipe(pipe& p)
{
	if (p.v_remonte == 1)
	{
		p.v_remonte = 0;
		cout << "\n truba ne v remonte!!!";
	}
	else
	{
		p.v_remonte_remonte = 1;
		cout << "\n truba v remonte!!!";
	}
};

void editStation(Station& s)
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
			s.tseh_v_rabote += 1;
		}
		else
		{
			s.tseh_v_rabote -= 1;
		}
	} 
	while (cin.fail() || isNumber(int(choise)));
};

void savepipe(const pipe& p)
{
	ofstream fout;
	fout.open("pipe.txt", ios::out);
	if (fout.is_open())
	{
		cout << "ID:" << p.id << endl;
		cout << "dlina:" << p.dlina << endl;
		cout << "diametr:" << p.diametr << endl;
		cout << "v remonte:" << p.v_remonte << endl;
		fout.close();
	}
}
void saveStation(const station& s)
{
	ofstream fout;
	fout.open("station.txt", ios::out);
	if (fout.is_open())
	{
		cout << "ID:" << s.id << endl;
		cout << "name:" << s.name << endl;
		cout << "tseh:" << s.tseh << endl;
		cout << "tsehi v rabote:" << s.tseh_v_rabote << endl;
		cout << "effektivnost:" << s.eff << end
		fout.close();
	}
}

void save(const pipe& p, const Station& s)
{
	ofstream fout;
	fout.open("all.txt", ios::out);
	if (fout.is_open())
	{
		cout << "ID:" << p.id << endl;
		cout << "dlina:" << p.dlina << endl;
		cout << "diametr:" << p.diametr << endl;
		cout << "v remonte:" << p.v_remonte << endl;
		cout << "ID:" << s.id << endl;
		cout << "name:" << s.name << endl;
		cout << "tseh:" << s.tseh << endl;
		cout << "tsehi v rabote:" << s.tseh_v_rabote << endl;
		cout << "effektivnost:" << s.eff << endl;
		fout.close();
	}
}
void saveall(int e, const pipe& pi, const Station& st)
{
	switch (e)
	{
	case 1:
		savepipe(pi);
		break;
	case 2:
		savestation(st);
		break;
	case 3:
		save(pi, st);
		break;
	}
 }

pipe browsepipe()
{
	pipe pi;
	ifstream fin;
	fin.open("pipe.txt", ios::in);
	if (fin.is_open())
	{
		fin >> p.dlina ;
		fin >> p.diametr;
		fin >> p.v_remonte;
		fin.close();
		return p;
	}
};
pipe browseStation()
{
	Station s;
	ifstream fin;
	fin.open("station.txt", ios::in);
	if (fin.is_open())
	{
		fin >> s.name;
		fin >> s.tseh;
		fin >> s.tseh_v_rabote;
		fin >> s.eff;
		fin.close();
		return s;
	}
};

void browse(pipe& p, Station& s)
{
	ifstream fin;
	fin.open("all.txt", ios::in);
	if (fin.is_open())
	{
		fin >> p.dlina;
		fin >> p.diametr;
		fin >> p.v_remonte;
		fin >> s.name;
		fin >> s.tseh;
		fin >> s.tseh_v_rabote;
		fin >> s.eff;
	}
	fin.close();
};

void browseall(pipe& p, Station& s)
{
	switch (proverka(1, 3, "\n Vyberite 1-truba, 2-stantsiya, 3-vse vmeste: "))
	{
	case 1:
		lookpipe(browsepipe());
		break;
	case 2:
		lookStation(browseStation());
		break;
	case 3:
		browse(p, s);
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
	pipe pi;
	Station st;
	bool is_pipe = 0;
	bool is_station = 0;
	while (1)
	{
		printmenu();
		switch (proverka(0,7,"menu:"))
		{
		case 1:
		{
			pi = createpipe();
			is_pipe == true;
			break;
		}
		case 2:
		{
			st = createStation();
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
					lookall(q, pi, st);
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
				editpipe(pi);
				break;
			}
		}
		case 5:
		{
			if (is_station == true)
			{
				editStation(st);
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
				saveall(e, pi, st);
				break;
			}
		}
		case 7:
		{
			if (is_pipe == true && is_station == true)
			{
				browseall(pi, st)
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

