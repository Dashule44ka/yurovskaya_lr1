#include <iostream> 
#include <fstream>
#include <string>

using namespace std;

template <typename T>
T proverka(T min, T max , string n)
{
	T x;
	cout << n;
	while ((cin >> x).fail() || x > max || x < min)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << n;
	}
	return x;
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

bool isNumber(char Symbol)
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

Station createStation()
{
	Station s;
	s.is_station == true;
	s.id = 1;
	cout << "Vvedite nazvanie station:" << endl;
	getline(cin, s.name);
	cin >> s.name;
	s.tseh = proverka(1, 10000, "\n'Vvedite kolvo tsehov:");
	s.tseh_v_rabote = proverka(1, s.tseh, "\n'Vvedite kolvo tsehov v rabote:");
	s.eff = proverka(1, 100, "\n'Kakova effektivnost:");
	return s;
};

void viewpipe(const pipe& p)
{
	cout << "ID:" << p.id << endl;
	cout << "dlina:" << p.dlina << endl;
	cout << "diametr:" << p.diametr << endl;
	cout << "v remonte:" << p.v_remonte << endl;
}

void viewStation(const Station& s)
{
	cout << "ID:" << s.id << endl;
	cout << "name:" << s.name << endl;
	cout << "tseh:" << s.tseh << endl;
	cout << "tsehi v rabote:" << s.tseh_v_rabote << endl;
	cout << "effektivnost:" << s.eff << endl;
}

void viewall(int q, const pipe& pi, const Station& st)
{
	switch (q)
	{
	case 1:
		viewpipe(pi);
		break;
	case 2:
		viewStation(st);
		break;
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
		p.v_remonte = 1;
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

void savepipe(const pipe& p, ofstream& fout)
{
	if (fout.is_open())
	{
		//fout << p.id << endl;
		fout << p.dlina << endl;
		fout << p.diametr << endl;
		fout << p.v_remonte << endl;
	}
}

void saveStation(const Station& s, ofstream&fout)
{
	if (fout.is_open())
	{
		//fout << s.id << endl;
		fout << s.name << endl;
		fout << s.tseh << endl;
		fout << s.tseh_v_rabote << endl;
		fout << s.eff << endl;
	}
}

pipe browsepipe(pipe& p, ifstream& fin)
{
	
	if (fin.is_open())
	{
		fin >> p.dlina ;
		fin >> p.diametr;
		fin >> p.v_remonte;
		
		return p;
	}
};
Station browseStation(Station& s, ifstream& fin)
{
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



void printmenu()
{
	cout << "1.truba" << endl;
	cout << "2 stantsiya" << endl;
	cout << "3.look" << endl;
	cout << "4.redaktirovat truby(edit)" << endl;
	cout << "5.redaktirovat stantsiyu(edit)"<< endl;
	cout << "6.sohranit(save)" << endl;
	cout << "7.zagruzit(browse)" << endl;
	cout << "0.viyti(exit)"<< endl;
}

int main()
{
	
	pipe pi;
	Station st;
	bool is_pipe = 1;
	bool is_station = 1;
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
					viewall(q, pi, st);
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
			if (is_pipe==true && is_station == true)

			{
				ofstream fout;
				fout.open("all.txt", ios::out);
				savepipe(pi, fout);
				saveStation(st, fout);
				fout.close();
				break;
			}
		}
		case 7:
		{
			if (is_pipe == true && is_station == true)
			{
				ifstream fin;
				fin.open("all.txt", ios::in);
				browsepipe(pi, fin);
				browseStation(st, fin);
				fin.close();
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

