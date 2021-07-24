#include "Aviculture_back.h"
#pragma warning(disable: 4996)



Aviculture_back::Aviculture_back(int _shenaseP)
{

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
	fin.open("Aviculture.txt", std::ios::in);
	if (!fin) {
		fin.close();
		fout.open("Aviculture.txt");
		fout.close();
		fin.open("Aviculture.txt", std::ios::in);
	}
	bool find = 1;
	fin.seekg(0, std::ios::end);
	int size = fin.tellg();
	fin.seekg(0, std::ios::beg);
	while (size>fin.tellg()) {/////////////////////taghir dar hame
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
		start_day_of_upgrading = 2147483640;
		start_day_of_produce = 2147483640;
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
		A.start_day_of_upgrading = 2147483640;
		A.start_day_of_produce = 2147483640;
		A.shenaseP = _shenaseP;
		A.isfed = false;
		A.havecrop = false;
		A.upgrading = false;
		A.start_day_of_building = -1;
		A.isbuildingmade = false;
		A.isbuildingmaking = false;
		fout.open("Aviculture.txt", std::ios::app);
		fout.write((char*)&A, sizeof(temp));
		fout.close();
	}

}

Aviculture_back::~Aviculture_back() {
	Update_file();
}

void Aviculture_back::setcurrent(int _current) { current = _current; }
void Aviculture_back::setcapacity(int _capacity) { capacity = _capacity; }
void Aviculture_back::setlevel(int _level) { level = _level; }
void Aviculture_back::set_start_day_of_upgrading(int _start_day_of_upgrading) { start_day_of_upgrading = _start_day_of_upgrading; }
void Aviculture_back::set_start_day_of_produce(int _start_day_of_produce) { start_day_of_produce = _start_day_of_produce; }
void Aviculture_back::setshenaseP(int _shenaseP) { shenaseP = _shenaseP; }
void Aviculture_back::setisfed(bool _isfed) { isfed = _isfed; }
void Aviculture_back::sethavecrop(bool _havecrop) { havecrop = _havecrop; }
void Aviculture_back::setupgrading(bool _upgrading) { upgrading = _upgrading; }
void Aviculture_back::setisbuildingmade(bool _isbuildingmade) { isbuildingmade = _isbuildingmade; }
void Aviculture_back::setisbuildingmaking(bool _isbuildingmaking) { isbuildingmaking = _isbuildingmaking; }
void Aviculture_back::set_start_day_of_building(int _start_day_of_building) { start_day_of_building = _start_day_of_building; }

int Aviculture_back::getcurrent() { return current; }
int Aviculture_back::getcapacity() { return capacity; }
int Aviculture_back::getlevel() { return level; }
int Aviculture_back::get_start_day_of_upgrading() { return start_day_of_upgrading; }
int Aviculture_back::get_start_day_of_produce() { return start_day_of_produce; }
int Aviculture_back::getshenaseP() { return shenaseP; }
bool Aviculture_back::getisfed() { return isfed; }
bool Aviculture_back::gethavecrop() { return havecrop; }
bool Aviculture_back::getupgrading() { return upgrading; }
bool Aviculture_back::getisbuildingmade() { return isbuildingmade; }
bool Aviculture_back::getisbuildingmaking() { return isbuildingmaking; }
int Aviculture_back::get_start_day_of_building() { return start_day_of_building; }

int Aviculture_back::isfull() {
	if (current == capacity)
		return 0;
	return capacity - current;
}


int Aviculture_back::addchicken(int num)
{

	if (capacity - current < num)
		return 2;//nabod zarfiat;
	else if (isfed)
		return 3;//darhal ghaza khordan
	else if (havecrop)
		return 4;//mahsolat jam avari nashodeand
	
	current += num;
	return 1;
	
}

int Aviculture_back::removechicken(int num) {
	if (current < num)
		return 2;//in teadad morgh mojod nist;
	else if (isfed)
		return 3;//darhal ghaza khordan
	else if (havecrop)
		return 4;//mahsolat jam avari nashodeand
	current -= num;
	return 1;

}

void Aviculture_back::checkcrop(int _day) {
	if (isfed && (_day - start_day_of_produce >= 2)) {
		havecrop = true;
		isfed=false;
		start_day_of_produce = -1;
	}
}

void Aviculture_back::checkupdate(int _day) {

	if (upgrading && (_day - start_day_of_upgrading >= 3)) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
		upgrading = false;
	}
}

void Aviculture_back::checkbuilding(int _day) {
	if (isbuildingmaking && (_day - start_day_of_building >= 3)) {
		isbuildingmade = true;
		start_day_of_building = -1;
		isbuildingmaking = false;
	}
}

/*dakhel slot ha.......................................
int Aviculture_back::starting_upgrade()
{
	if (owner.getlevel() < 3)
		return 2
	else if (getnail() < 1)
		return 3;
	else if (owner.getcoin() < 10)
		return 4;
	
	start_day_of_upgrading = /*getday();
		
		//owner.setCoin(owner.getCoin() - 10);
		//owner.setExp(owner.getExp() + 5);
		//va anbar ke codesh felan nist;
		return 1;
}*/
//zamani....................................................
/*
void Aviculture_back::upgrading() {
	if (/*getday() -start_day_of_upgrading >= 3) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
	}
}*/
/*/dakhel slot ha..................................................
int Aviculture_back::feeding() {
	if (current == 0)
		return 2;//morghi braye ghaza dadan nist;
	else if (havecrop)
		return 3;//mahsolat jam avari nashodeand
	else if (/*tabe ke check kone silo be andaze curren gandom dare ya na)
		return 4;//gandom kafi nist;
		
			start_day_of_produce = /*getday();
			isfed = true;
			//gandom ra kam mikonim;
			//owner.setExp(owner.getExp() + 1);
}*/
//zamani //////////////
/*
void Aviculture_back::cropready() {
	if (isfed && (/*getday()-start_day_of_produce >= 2)) {
		havecrop = true;
		isfed = false;
		start_day_of_produce = -1;
	}
}*/
/*/dakhel slot ha...............................
int Aviculture_back::removal() {
	if (isfed && !havecrop)
		return 2; //farayande tokhomgozari tamam nashode ast;
	else if (!havecrop)
		return 3; //mahsoli baray bardasht nist;
	else if (/*check inke aya anbar zarfiat tommorgh be teadad current dare aya?)
		return 4; //anbar ja nadard;

		//set tokhme dakhel anbar
	//owner.setExp(owner.getExp() + 2);
		havecrop = false;
		return 1;
}
*/
void Aviculture_back::Update_file() {

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

	infile.open("Aviculture.txt", std::ios::in);
	if (infile.is_open()) {
		outfile.open("Aviculture-temp.txt", std::ios::out);//make file.
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
		std::remove("Aviculture.txt");
		std::rename("Aviculture-temp.txt", "Aviculture.txt");
	}
}
