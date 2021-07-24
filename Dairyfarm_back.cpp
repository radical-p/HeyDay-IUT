#include "Dairyfarm_back.h"



Dairyfarm_back::Dairyfarm_back(int _shenaseP) {

	struct temp {
		int current;
		int capacity;
		int level;
		int start_day_of_upgrading;
		int start_day_of_produce;
		int shenaseP;
		bool isfed;
		bool havecrop;
		bool upgrading;
		bool isbuildingmade;//
		bool isbuildingmaking;//
		int start_day_of_building;//
	};

	temp A;
	
	std::ifstream fin;
	std::ofstream fout;
	fin.open("Dairyfarm.txt", std::ios::in);
	if (!fin) {
		fin.close();
		fout.open("Dairyfarm.txt");
		fout.close();
		fin.open("Dairyfarm.txt", std::ios::in);
	}
	bool find = 1;
	fin.seekg(0, std::ios::end);
	int size = fin.tellg();
	fin.seekg(0, std::ios::beg);
	while (size > fin.tellg()) {
		fin.read((char*)&A, sizeof(temp));
		if (A.shenaseP == _shenaseP) {
			current = A.current;
			capacity = A.capacity;
			level = A.level;
			start_day_of_upgrading = A.start_day_of_upgrading;
			start_day_of_produce = A.start_day_of_produce;
			shenaseP = A.shenaseP;
			isfed = A.isfed;
			havecrop = A.havecrop;
			upgrading = A.upgrading;
			start_day_of_building = A.start_day_of_building;
			isbuildingmade = A.isbuildingmade;
			isbuildingmaking = A.isbuildingmaking;
			find = 0;
			break;
		}
	}
	fin.close();
	if (find) {    //first login
		current = 0;
		capacity = 2;
		level = 1;
		start_day_of_upgrading = -1;
		start_day_of_produce = -1;
		shenaseP = _shenaseP;
		isfed = false;
		havecrop = false;
		upgrading = false;
		start_day_of_building = -1;
		isbuildingmade = false;
		isbuildingmaking = false;
		//..................
		A.current = 0;
		A.capacity = 2;
		A.level = 1;
		A.start_day_of_upgrading = -1;
		A.start_day_of_produce = -1;
		A.shenaseP = _shenaseP;
		A.isfed = false;
		A.havecrop = false;
		A.upgrading = false;
		A.start_day_of_building = -1;
		A.isbuildingmade = false;
		A.isbuildingmaking = false;

		fout.open("Dairyfarm.txt", std::ios::app);
		fout.write((char*)&A, sizeof(temp));
		fout.close();
	}
}
Dairyfarm_back::~Dairyfarm_back() {
	Update_file();
}

void Dairyfarm_back::setcurrent(int _current) { current = _current; }
void Dairyfarm_back::setcapacity(int _capacity) { capacity = _capacity; }
void Dairyfarm_back::setlevel(int _level) { level = _level; }
void Dairyfarm_back::set_start_day_of_upgrading(int _start_day_of_upgrading) { start_day_of_upgrading = _start_day_of_upgrading; }
void Dairyfarm_back::set_start_day_of_produce(int _start_day_of_produce) { start_day_of_produce = _start_day_of_produce; }
void Dairyfarm_back::setshenaseP(int _shenaseP) { shenaseP = _shenaseP; }
void Dairyfarm_back::setisfed(bool _isfed) { isfed = _isfed; }
void Dairyfarm_back::sethavecrop(bool _havecrop) { havecrop = _havecrop; }
void Dairyfarm_back::setupgrading(bool _upgrading) { upgrading = _upgrading; }
void Dairyfarm_back::setisbuildingmade(bool _isbuildingmade) { isbuildingmade = _isbuildingmade; }
void Dairyfarm_back::setisbuildingmaking(bool _isbuildingmaking) { isbuildingmaking = _isbuildingmaking; }
void Dairyfarm_back::set_start_day_of_building(int _start_day_of_building) { start_day_of_building = _start_day_of_building; }

int Dairyfarm_back::getcurrent() { return current; }
int Dairyfarm_back::getcapacity() { return capacity; }
int Dairyfarm_back::getlevel() { return level; }
int Dairyfarm_back::get_start_day_of_upgrading() { return start_day_of_upgrading; }
int Dairyfarm_back::get_start_day_of_produce() { return start_day_of_produce; }
int Dairyfarm_back::getshenaseP() { return shenaseP; }
bool Dairyfarm_back::getisfed() { return isfed; }
bool Dairyfarm_back::gethavecrop() { return havecrop; }
bool Dairyfarm_back::getupgrading() { return upgrading; }
bool Dairyfarm_back::getisbuildingmade() { return isbuildingmade; }
bool Dairyfarm_back::getisbuildingmaking() { return isbuildingmaking; }
int Dairyfarm_back::get_start_day_of_building() { return start_day_of_building; }


int Dairyfarm_back::isfull() {
	if (current == capacity)
		return 0;
	return capacity - current;
}


int Dairyfarm_back::addcow(int num) {
	if (capacity - current < num)
		return 2;//nabod zarfiat;
	else if (isfed)
		return 3;//darhal ghaza khordan
	else if (havecrop)
		return 4;//mahsolat jam avari nashodeand

	current += num;
	return 1;
}

int Dairyfarm_back::removecow(int num) {
	if (current < num)
		return 2;//in teadad morgh mojod nist;
	else if (isfed)
		return 3;//darhal ghaza khordan
	else if (havecrop)
		return 4;//mahsolat jam avari nashodeand
	current -= num;
	return 1;
}

void Dairyfarm_back::checkcrop(int _day) {
	if (isfed && (_day - start_day_of_produce >= 3)) {
		havecrop = true;
		isfed = false;
		start_day_of_produce = -1;
	}
}

void Dairyfarm_back::checkupdate(int _day) {

	if (upgrading && (_day - start_day_of_upgrading >= 5)) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
		upgrading = false;
	}
}

void Dairyfarm_back::checkbuilding(int _day) {
	if (isbuildingmaking && (_day - start_day_of_building >= 5)) {
		isbuildingmade = true;
		start_day_of_building = -1;
		isbuildingmaking = false;
	}
}
/*
int Dairyfarm_back::starting_upgrade() {
	if (owner.getlevel() < 5)
		return 2
	else if (getnail() < 2)
		return 3;
	else if (owner.getcoin() < 15)
		return 4;

	start_day_of_upgrading = /*getday();

	//owner.setCoin(owner.getCoin() - 15);
	//owner.setExp(owner.getExp() + 6);
	//va anbar ke codesh felan nist;
	return 1;
}*/
//zamani..........
/*
void Dairyfarm_back::upgrading() {
	if (/*getday() -start_day_of_upgrading >= 5) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
	}
}*/
/*
int Dairyfarm_back::feeding() {
	if (current == 0)
		return 2;//morghi braye ghaza dadan nist;
	else if (havecrop)
		return 3;//mahsolat jam avari nashodeand
	else if (/*tabe ke check kone anbar be andaze 2*curren yonje dare ya na)
		return 4;//yonje kafi nist;

	start_day_of_produce = /*getday();
	isfed = true;
	//yonje ra kam mikonim;
	//owner.setExp(owner.getExp() + 3);
}*/
//zamani..........
/*
void Dairyfarm_back::cropready() {
	if (isfed && (/*getday()-start_day_of_produce >= 3)) {
		havecrop = true;
		isfed = false;
		start_day_of_produce = -1;
	}
}*/
/*
int Dairyfarm_back::removal() {
	if (isfed && !havecrop)
		return 2; //farayande dorost kardan shir tamam nashode ast;
	else if (!havecrop)
		return 3; //mahsoli baray bardasht nist;
	else if (/*check inke aya anbar zarfiat shir be teadad current dare aya?)
		return 4; //anbar ja nadard;

		//set shir dakhel anbar
	//owner.setExp(owner.getExp() + 5);
	havecrop = false;
	return 1;
}
*/
void Dairyfarm_back::Update_file() {

	struct temp {
		int current;
		int capacity;
		int level;
		int start_day_of_upgrading;
		int start_day_of_produce;
		int shenaseP;
		bool isfed;
		bool havecrop;
		bool upgrading;
		bool isbuildingmade;//
		bool isbuildingmaking;//
		int start_day_of_building;//
	};

	temp p;

	std::ofstream outfile;//for writing in new file.
	std::ifstream infile;//for reading.

	infile.open("Dairyfarm.txt", std::ios::in);
	if (infile.is_open()) {
		outfile.open("Dairyfarm-temp.txt", std::ios::out);//make file.
		infile.seekg(0, std::ios::end);
		int size = infile.tellg();
		infile.seekg(0, std::ios::beg);
		while (infile.tellg() < size) {
			infile.read((char*)&p, sizeof(p));
			if (shenaseP == p.shenaseP) {
				p.current = current;
				p.capacity = capacity;
				p.level = level;
				p.start_day_of_upgrading = start_day_of_upgrading;
				p.start_day_of_produce = start_day_of_produce;
				p.isfed = isfed;
				p.havecrop = havecrop;
				p.shenaseP = shenaseP;
				p.upgrading = upgrading;
				p.start_day_of_building = start_day_of_building;
				p.isbuildingmade = isbuildingmade;
				p.isbuildingmaking = isbuildingmaking;
			}
			outfile.write((char*)&p, sizeof(p));
		}
		outfile.close();
		infile.close();
		std::remove("Dairyfarm.txt");
		std::rename("Dairyfarm-temp.txt", "Dairyfarm.txt");
	}
}
