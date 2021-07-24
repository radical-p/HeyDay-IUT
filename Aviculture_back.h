#pragma once
#include <iostream>
#include <fstream>
//using namespace std;
class Aviculture_back
{
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

public:

	Aviculture_back(int);
	~Aviculture_back();

	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	void set_start_day_of_upgrading(int _start_day_of_upgrading);
	void set_start_day_of_produce(int _start_day_of_produce);
	void setshenaseP(int _shenaseP);
	void setisfed(bool _isfed);
	void sethavecrop(bool _havecrop);
	void setupgrading(bool _upgrading);
	void setisbuildingmade(bool _isbuildingmade);
	void setisbuildingmaking(bool _isbuildingmaking);
	void set_start_day_of_building(int _start_day_of_building);


	int getcurrent();
	int getcapacity();
	int getlevel();
	int get_start_day_of_upgrading();
	int get_start_day_of_produce();
	int getshenaseP();
	bool getisfed();
	bool gethavecrop();
	bool getupgrading();
	bool getisbuildingmade();
	bool getisbuildingmaking();
	int get_start_day_of_building();

	int isfull();
	int addchicken(int num);
	int removechicken(int num);
	void checkcrop(int);
	void checkupdate(int);
	void checkbuilding(int);
	//int starting_upgrade();
	//void upgrading();//zamani
	//int feeding();
	//void cropready();//zamani
	//int removal();
	void Update_file();//distructor
};
