#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#pragma once
#ifndef Engine
using namespace std;

class Item
{
protected:
	int power;
	int trigger;
	string name;
public:
	Item()
	{
		power = 0;
		trigger = 0;
		name = "item";
	}
	Item(string x, int y)
	{
		name = x;
		power = y;
		trigger = 0;
	}
	Item(int z, string x, int y)
	{
		trigger = z;
		name = x;
		power = y;
	}
	void print() 
	{
		cout << name << " -power:  " << power << endl;
	}
	void setdefault()
	{
		power = 0;
		trigger = 0;
		name = "Empty";
	}
	int getpower()
	{
		return power;
	}
	string getname()
	{
		return name;
	}
	void operator=(const Item &r)
	{
		power = r.power;
		trigger = r.trigger;
		name = r.name;
	}
};

class Room
{
protected:
	int DangerLvl;
	bool hasBeen;
	string desc;
public:
	Room()
	{
		desc = "Unexplored";
		hasBeen = false;
		DangerLvl = 0;
	}
	bool getHasBeen()
	{
		return hasBeen;
	}
	string getdesc()
	{
		return desc;
	}
	void setdesc(string x)
	{
		desc = x;
	}
	void setHasBeen(bool x)
	{
		hasBeen = x;
	}
	void setDangerLvl(int x)
	{
		DangerLvl = x;
	}
};

class Map : public Room
{
protected:
	Room map[5][5]; //2d array of strings
public:
	Map()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				map[i][j].setdesc("Unexplored");
				map[i][j].setHasBeen(false);
				map[i][j].setDangerLvl(0);
			}
		}
	}
	bool getHasBeen()
	{
		return hasBeen;
	}
	void printMap()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << setw(11) << " " << map[i][j].getdesc() << " ";
			}//end nested for
			cout << "\n";
		}//end for
	}//end printMap()
};

class Ent //entity
{
protected:
	string name;
	int hp; //hitpoints
	int st; //stamina
	Item item; //item currently being weilded 
public:
	virtual int attack(Item x) = 0;
	void setitem(Item x) { //set item
		item = x;
	}
	Item getitem()const {
		return item;
	}
	string getname()const
	{
		return name;
	}
	int gethp()const
	{
		return hp;
	}
	int getst()const
	{
		return st;
	}
	void setname(string x)
	{
		name = x;
	}
	void sethp(int x)
	{
		hp = x;
	}
	void setst(int x)
	{
		st = x;
	}
};

class Mob : public Ent //mob is an entity
{
protected:
	int mobnum;
public:
	int random()
	{
		int rn = 0;
		srand(time(0));
		rn = rand() % 6;
		return rn;
	}
	void mobrand()
	{
		mobnum = random();
		switch (mobnum) {
		case 1:
			name = "Skeleton";
			hp = 3;
			st = 2;
			item = Item("Bow", 2);
		case 2:
			name = "Zombie";
			hp = 4;
			st = 2;
			item = Item("Fist", 1);
		case 3:
			name = "Creepy Crawler";
			hp = 1;
			st = 1;
			item = Item("Tentacle Thing?", 4);
		case 4:
			name = "Dungeon Master";
			hp = 4;
			st = 1;
			item = Item("D12", 0);
		case 5:
			name = "Big Ol' Spider";
			hp = 1;
			st = 3;
			item = Item("Hairy Legs", 2);
		default:
			name = "There is nothing here";
			hp = 0;
			st = 0;
		}
	}
	Mob()
	{
		mobrand();
	}

	Mob(string n, int HP, int ST, string itemw, int itempower)
	{
		name = n;
		hp = HP;
		st = ST;
		item = Item(itemw, itempower);
	}

	void print()
	{
		cout << name << endl;
		cout << "HP: " << hp << " ST: " << st;
		cout << " Attacks with: ";
		item.print();
	}
	int attack(Item x)
	{
		return 0;
	}
};

class Player : public Ent //player is an entity
{
protected:
	Item inv[100];
public:
	Player()
	{
		name = "name";
		hp = 10;
		st = 5;
		for (int i; i < 100; i++)
			inv[i].setdefault();

	}
	Player(string n, int HP, int ST)
	{
		name = n;
		hp = HP;
		st = ST;
		for (int i; i < 100; i++)
			inv[i].setdefault();
	}
	void printinv()
	{
		for (int i = 0; i < 100; i++)
		{
			if (inv[i].getname() != "Empty")
				inv[i].print();
		}
	}
	int attack(Item x)
	{
		return 0;
	}
};
#endif // !Player
