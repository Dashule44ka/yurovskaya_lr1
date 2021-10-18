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
	int dlina;
	int diametr;
	bool v_remonte;
	//bool is_pipe;
};

struct Station
{
	int id;
	string name;
	int tseh;
	int tseh_v_rabote;
	float eff;
	//bool is_station;
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
	//p.is_pipe == true;
	p.id = 1;
	p.dlina = proverka(0, 1000, "\n'vvedite dlinu truby:");
	p.diametr = proverka(0, 1000, "\n'vvedite diametr truby:");
	p.v_remonte = proverka(0, 1, "\n'vvedite znachenie v reonte:");
	return p;
};

Station createStation()
{
	Station s;
	//s.is_station == true;
	s.id = 1;
	cout << "vvedite nazvanie station:" << endl;
	cin.ignore(10000, '\n');
	getline(cin, s.name);
	s.tseh = proverka(1, 10000, "\n'vvedite kolvo tsehov:");
	s.tseh_v_rabote = proverka(0, s.tseh, "\n'vvedite kolvo tsehov v rabote:");
	s.eff = proverka(1, 100, "\n'kakova effektivnost:");
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
	if (p.v_remonte == 0)
	{
		p.v_remonte = 0;
		cout << "\n truba ne v remonte!!!";
	}
	else
	{
		p.v_remonte = 1;
		cout << "\n truba v remonte!!!";
	}

	p.v_remonte = proverka(0, 1, "\n'izmenite znachenie v reonte: 1-truba v remonte 0-ne v remonte");

};

void editStation(Station& s)
{
	cout << "\n 3)kolichestvo vseh tsehov:" << s.tseh;
	cout << "\n 2)tseh v rabote:"<< s.tseh_v_rabote;
	int choise;
	choise = proverka(0, 1, "\n'vvedite znachenie 1 dlya uvelecheniya ili 0 dlya umensheniya kolichestva tsehov: ");
	do
	{
		if (choise == 1 && s.tseh_v_rabote < s.tseh)
		{
			s.tseh_v_rabote +=1;
		}
		else if(choise == 0 &&  s.tseh_v_rabote >0)
		{
			cout << " umenshaem kolichestvo tsehov \n";
			s.tseh_v_rabote -= 1;
		}
		else 
		{
			cout << "impossible" << endl;
		}

	
	} 
	while (cin.fail() || isNumber(int(choise)));
};

void savepipe(const pipe& p, ofstream& fout)
{
	if (fout.is_open())
	{
		fout << p.id << endl
			<< p.dlina << endl
			 << p.diametr << endl
			 << p.v_remonte << endl;
	}
}

void saveStation(const Station& s, ofstream&fout)
{
	if (fout.is_open())
	{
		fout << s.id << endl
		     << s.name << endl
		     << s.tseh << endl
			 << s.tseh_v_rabote << endl
			 << s.eff << endl;
	}
}

pipe browsepipe(ifstream& fin)
{
	if (fin.is_open())
	{
		pipe p;
		fin >> p.id;
		fin >> p.dlina;
		fin >> p.diametr;
		fin >> p.v_remonte;
		return p;
	}
	return {};
};

Station browseStation(ifstream& fin )
{
	if (fin.is_open())
	{
		Station s;
		fin >> s.id;
		fin >> s.name;
		fin >> s.tseh;
		fin >> s.tseh_v_rabote;
		fin >> s.eff;
		return s;
	}
	return {};
}

void printmenu()
{
	cout << "1.truba" << endl;
	cout << "2 stantsiya" << endl;
	cout << "3.look" << endl;
	cout << "4.redaktirovat truby(edit)" << endl;
	cout << "5.redaktirovat stantsiyu(izmenit kolichestvo tsehov)(edit)"<< endl;
	cout << "6.sohranit(save)" << endl;
	cout << "7.zagruzit(browse)" << endl;
	cout << "0.viyti(exit)"<< endl;
}

int main()
{
	pipe pi;
	Station st;
	bool is_pipe = false;
	bool is_station = false;
	while (1)
	{
		printmenu();
		switch (proverka(0, 7, "menu:"))
		{
		case 1:
		{
			pi = createpipe();
			is_pipe = true;
			break;
		}
		case 2:
		{
			st = createStation();
			is_station = true;
			break;
		}
		case 3:
			if (is_pipe && is_station)
			{
				{
					cout << "vyberite variant 1-pipe, 2-station";
					int q = 0;
					cin >> q;
					viewall(q, pi, st);
				}
			}
			else
			{
				cout << "vvedite dannye dlya 1 and 2";
			}
			break;
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
			if (!is_pipe && !is_station)
			{
				cout << "no data" << endl;
				break;
			}
			ofstream fout;
			fout.open("all.txt", ios::out);
			if (!fout.is_open())
			{
				cout << "Save failed" << endl;
				break;
			}
			fout << is_pipe<<endl;
			if (is_pipe)
				savepipe(pi, fout);
			fout << is_station << endl;
			if (is_station)
				saveStation(st, fout);
			fout.close();
			break;

		}
		case 7:
		{
			ifstream fin;
			fin.open("all.txt", ios::in);
			if (!fin.is_open())
			{
				cout << "loaad failed" << endl;
				break;
			}
			fin >> is_pipe;
			if(is_pipe)
				pi = browsepipe(fin);
			fin >> is_station;
			if(is_station)
				st = browseStation(fin);
			fin.close();
			break;
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


