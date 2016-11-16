/*
 Dungeon Quest-ish.cpp
 Author: Garrett Webb
 Version: 2.1.5
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
int roomnum = 0;
bool play = true;
bool hasStarted = 0;
int life = 3;
string name = "default";
string m = "default";
bool br1 = 0;
bool br2 = 0;
bool br3 = 0;
bool br4 = 0;
bool br5 = 0;
bool br6 = 0;
bool br7 = 0;
bool br8 = 0;
bool br9 = 0;
bool hasSword = 0;
bool hasShield = 0;
bool hasPuzzle = 0;



void starting()
{
	cout << "DUNGEON QUESTish \nA game by Garrett and Max Webb \n\n\n\n";
	cout << "l'I              .---.                    " << endl;
	cout << "l  'I          .I     I.                  " << endl;
	cout << "l   'I         I       I                  " << endl;
	cout << "l  'I          'I     I'                  " << endl;
	cout << "l'I  UNGEON      '---''l. UEST-ish  \n\n\n" << endl;
	cout << "what would you like your name to be?" << endl;
	getline(cin, name);
	cout << "\nInteresting choice...\n\n" << endl;
	cout << "instructions: (write this down) \nwhen asked what do do, you may \n";
	cout << "Ask for instructions and see the graphic again: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
	hasStarted = 1;
}


void GUI()
{
	if (hasStarted == 0) starting();
	cout << setw(120) << right << name << endl;
	cout << setw(120) << right << "--------------------" << endl;
	if (life == 1) cout << setw(120) << right << "<3  X  X" << endl;
	if (life == 2) cout << setw(120) << right << "<3 <3  X" << endl;
	if (life == 3) cout << setw(120) << right << "<3 <3 <3" << endl;
    
}


void combat()
{
	int itemchoice = 0;
	string ICin = "";
	cout << "What would you like to use?\n";
	cout << "Sword: 1\n";
	cout << "Shield: 2\n";
	cout << "Cube: 3\n";
	while (true) {
		cout << "Please enter a valid number: ";
		getline(cin, ICin);
		// This code converts from string to number safely.
		stringstream myStream(ICin);
		if (myStream >> itemchoice)
			break;
		cout << "Invalid number, please try again" << endl;
	}
	if (itemchoice == 1 && hasSword == 1) {
		cout << "You reach into your immensely large pocket, and pull out the SWORD you found earlier. \n";
		cout << "Taking the SWORD with both hands, you charge at the GOBLIN and swing with all of your might. \n";
		cout << "However, your puny attempts to harm this majestic beast are to no avail. \n";
		cout << "The Goblin grabs your sword out of mid-swing and crushes you with the hilt you are grasping. \n";
		cout << "Sometimes strength isn't the answer. \nCongratulations. You were bested by your own weapon.\n\n\n";
		play = false;
	}
	if (itemchoice == 1 && hasSword == 0) {
		cout << "You have no such item.\n\n\n";
	}
	if (itemchoice == 2 && hasShield == 0) {
		cout << "You have no such item.\n\n\n";
	}
	if (itemchoice == 2 && hasShield == 1) {
		cout << "You cautiously bring out the SHIELD from before and slowly approach the GOBLIN. \n";
		cout << "Displeased with your almost embarrassing attempt the GOBLIN half-heartedly flicks you. \n";
		cout << "Your shield takes the bulk of the blow and is shattered before your eyes, but at least you are not dead.\n\n\n";
		hasShield = 0;
	}
	if (itemchoice == 3 && hasPuzzle == 0) {
		cout << "You have no such item.\n\n\n";
	}
	if (itemchoice == 3 && hasPuzzle == 1) {
		cout << "\n\nWell this isn't the choice I would have made, but despite the obviously unbalanced odds, you approach the mighty GOBLIN with a mere Rubick's Cube. \n";
		cout << "However, the GOBLIN appears amused by this puzzle and snatches it from your hands. \n";
		cout << "He begins to mutter to himself about how he has always wanted one of these, and proceeds to take the cube to the corner and play with it.\n\n";
		cout << "\nAs if to celebrate your triumph, a gust of wind blows open the door and reveals the outside world. \n";
		cout << "You have escaped only by sheer luck. \nWow... I guess you won.\n\n\n\n\n\n";
		cout << "Congratulations, " << name << "\n\n\n\n" << endl;
		cout << "Game made by Garrett and Max Webb. \n\nProgramming: \nGarrett Webb \n\nWriting: \nMax Webb \nGarrett Webb\n\n";
		play = false;
	}
    
}

void takeItem()
{
	if (roomnum == 0) {
		cout << "You found your wallet. You clearly recognize that it is yours and glance at your I.D. \nYou can only faintly read the card.";
		cout << "What do you think it says?\n";
		getline(cin, name);
		cout << "\n\n\nYou have decided that your name will be " << name << "." << "\n\n\n";
		roomnum = 5;
		return;
	}
	if (roomnum == 1) {
		//room 1 death by taking treasure
		cout << string(10, '\n');
		cout << "The doors behind you shut and a Genie pops out from behind a chalice. \n";
		cout << "In the voice of Robin Williams, he screams: \n'HAVEN'T YOU SEEN ALADDIN YA WANK?'\n\n";
		cout << "Congratulations, your foolish greed has led to your eventual starvation. \n";
		cout << "At least you have that treasure...\n\n";
		play = false;
		return;
	}
	if (roomnum == 2) {
		//room 2 death by using "t"
		cout << string(10, '\n');
		cout << "You attempt to grab the goblin and put it in your pocket.\n";
		cout << "Upon seeing that he does not fit, you put him down. \n";
		cout << "He is quite angry at you at this point, and decides to consume you. \n";
		cout << "Congratulations, you are now goblin poop.\n\n";
		play = false;
		return;
	}
	if (roomnum == 3) {
		cout << "" << endl;
	}
	if (roomnum == 4) {
		cout << "You fumble around for a bit in your blinded state, and find that there is nothing to take here.\n\n";
		return;
	}
	if (roomnum == 5) {
		cout << "You found your wallet. You clearly recognize that it is yours and glance at your I.D. \nYou can only faintly read the card.";
		cout << "What do you think it says?\n";
		cin >> name;
		cout << "\n\n\nYou have decided that your name will be " << name << "." << "\n\n\n";
		roomnum = 5;
		return;
	}
	if (roomnum == 6) {
		cout << "You have taken the shield.\n\n\n";
		hasShield = 1;
		return;
	}
	if (roomnum == 7) {
		cout << "                                  " << endl;
		cout << "                                  " << endl;
		cout << "                     </>          " << endl;
		cout << "    </>                           " << endl;
		cout << "                          0       " << endl;
		cout << "                          ||      " << endl;
		cout << "  +=======================||=====0" << endl;
		cout << "    '''===================||      " << endl;
		cout << "                          ||      " << endl;
		cout << "   </>                    0       " << endl;
		cout << "                                  " << endl;
		cout << "          ==============          " << endl;
		cout << "       ====================       " << endl;
		cout << "      ======================      " << endl;
		cout << "You have taken the sword.\n";
		cout << "You put the incredibly heavy sword into your pocket," << endl;
		cout << "and immediately forget about it.\n\n";
		hasSword = 1;
		return;
	}
	if (roomnum == 8) {
		cout << "The book is too heavy and not worth taking.\n\n";
		return;
	}
	if (roomnum == 9) {
		cout << "RUBICK'S CUBE GET! You have filled your pockets with a useless block.\n\n";
		cout << "      ======================     " << endl;
		cout << "      ||    |        |    ||     " << endl;
		cout << "      ||    |        |    ||     " << endl;
		cout << "      ||----|--------|----||     " << endl;
		cout << "      ||    |Rubick's|    ||     " << endl;
		cout << "      ||    |Cube    |    ||     " << endl;
		cout << "      ||    |Get!    |    ||     " << endl;
		cout << "      ||----|--------|----||     " << endl;
		cout << "      ||    |        |    ||     " << endl;
		cout << "      ||    |(why?)  |    ||     " << endl;
		cout << "      ======================     " << endl;
		hasPuzzle = 1;
		return;
	}
	return;
}

void roomOutput()
{
	string m = "default";
	if (roomnum == 0) {
		cout << "You wake up in the middle of a dark room with no source of light anywhere.\n";
		cout << "There is a faint dizzy feeling in your head along with an unmistakable musky scent. \n";
		cout << "Maybe you are at your grandma's house... Or a dungeon?\n\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 1 && br1 == 0) {
		cout << "          ===|===========|===        " << endl;
		cout << "       ======|===========|======     " << endl;
		cout << "      =======|===.....===|=======    " << endl;
		cout << "      ===========|</>|===========    " << endl;
		cout << "      =======|==='''''===|=======    " << endl;
		cout << "      =======|===========|=======    " << endl;
		cout << "      =======|===========|=======    " << endl;
		cout << "      =======|===========|=======    " << endl;
		cout << "You enter a room filled to the brim with exotic gems, mountains of gold, and a single chest sitting atop all of it like a throne. It calls to you.\n\n";
		cout << "what will you do?\n";
		br1 = 1;
	}
    
	if (roomnum == 1 && br1 == 1) {
		cout << "You are in the room with the mountains of riches.";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 2 && br2 == 0) {
		cout << "   ==============================    " << endl;
		cout << "   ========= ========== =========    " << endl;
		cout << "   ========== =      = ==========    " << endl;
		cout << "   ===========        ===========    " << endl;
		cout << "   ============      ============    " << endl;
		cout << "   ==============  ==============    " << endl;
		cout << "   =========            ======= =    " << endl;
		cout << "   ========  =        =  ===== ==    " << endl;
		cout << "   =======  ===      ===  === ===    " << endl;
		cout << "   ======  ====      ====  = ====    " << endl;
		cout << "   =====  =====      =====  =====    " << endl;
		cout << "   ===========   ==   === =======    " << endl;
		cout << "   =========   ======   =========    " << endl;
		cout << "   ========   ========   ========    " << endl;
		cout << "   =======   ==========   =======    " << endl;
		cout << "   =====     ==========     =====    " << endl;
		cout << "   ==============================    " << endl;
		cout << "   ==============================    " << endl;
		cout << "You move into a room. There is a slight glow to this room. \n";
		cout << "Much to your surprise, there is an oversized GOBLIN guarding a golden door to the north. \n";
		cout << "It is surrounded by the glow of what you can only assume to be the light of day. \n";
		cout << "You start to wonder how this goblin can stand in front of this door for eternity without food. \n";
		cout << "Then you realize that it might be carnivorous. \nYou decide not to think about that option.\n\n";
		cout << "This foe seems quite formidable, and you decide that your bare hands will not be able to topple its majestic might.\n\n";
		cout << "Maybe use an item?\n\n";
		cout << "what will you do?\n";
	}
	if (roomnum == 2 && br2 == 1) {
		cout << "You are in the Goblin room.\n";
		cout << "The GOBLIN guarding a golden door to the north. \n";
		cout << "Maybe use an item?\n\n";
		cout << "what will you do?\n";
	}
    
    
	if (roomnum == 3) {
		// This room Kills you instantly.
		cout << string(10, '\n');
		cout << "You have entered what appears to be an ordinary room. \n";
		cout << "Before you can decide what to do, you trip on a banana peel, hit your head on the ground, and lose consciousness. \n";
		cout << "When you awake, you see that your trip caused the door behind you to close forever. \n";
		cout << "Congratulations. You were killed by a banana.\n\n";
		play = false;
	}
    
	if (roomnum == 4 && br4 == 0) {
		cout << "   ???????????????????    " << endl;
		cout << "   ???????????????????    " << endl;
		cout << "   ???????????????????    " << endl;
		cout << "   ???????????????????    " << endl;
		cout << "   ???????????????????    " << endl;
		cout << "   ???????????????????    " << endl;
		cout << "   ???????????????????    " << endl;
		cout << "   ???????????????????    " << endl;
		cout << "You have moved into a room with only 3 walls. Interesting. There is a blinding light to your west.\nYou cannot see a thing.\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 4 && br4 == 1) {
		cout << "You are in a room with only 3 walls. There is a blinding light to your west.\n";
		cout << "what will you do?\n";
	}
    
    
	if (roomnum == 5 && br5 == 0) {
		cout << "You are in the room you woke up in. I would suggest mapping this game out on a piece of paper.\n\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 5 && br5 == 1) {
		cout << "You are back where you started again. Are you lost?\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 6 && br6 == 0) {
		cout << "   ==============================    " << endl;
		cout << "   ==============================    " << endl;
		cout << "   =====      ===================    " << endl;
		cout << "   ====  0..0  ==================    " << endl;
		cout << "   =====  --  ===================    " << endl;
		cout << "   ======    ====================    " << endl;
		cout << "   ==============================    " << endl;
		cout << "   ===============||-----||======    " << endl;
		cout << "   =============|  |     |  |====    " << endl;
		cout << "   ============|---|-</>-|---|===    " << endl;
		cout << "   ==============| |     | |=====    " << endl;
		cout << "   ===============||-----||======    " << endl;
		cout << "   ================|     |=======    " << endl;
		cout << "   =================|___|========    " << endl;
		cout << "   ==============================    " << endl;
		cout << "Upon entering this room, you see a decaying skeleton on the ground sprawled out clutching what appears to be a single wooden shield. \n";
		cout << "You look at the skeleton with some skepticism, as you have seen movies in which these come to life. \nspoopy.\n\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 6 && br6 == 1) {
		cout << "You are in the room with the skeleton and the wooden shield.\n";
		cout << "what will you do?\n";
        
	}
    
	if (roomnum == 7 && br7 == 0) {
		cout << "                0               " << endl;
		cout << "        </>     |               " << endl;
		cout << "                |               " << endl;
		cout << "            0=======0           " << endl;
		cout << "               |||              " << endl;
		cout << "               |||      </>     " << endl;
		cout << "     </>       |||              " << endl;
		cout << "               |||   </>        " << endl;
		cout << "               |||              " << endl;
		cout << "          ==============        " << endl;
		cout << "       ====================     " << endl;
		cout << "      ======================    " << endl;
		cout << "You enter a room, there is a light source radiating from the centerpiece of the room. \n";
		cout << "After a few minutes of letting your eyes adjust, you see that it is a sword glistening in all of its glory. \n";
		cout << "Surely this will be useful.\n\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 7 && br7 == 1) {
		cout << "You are in the Sword room. \n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 8 && br8 == 0) {
		cout << "                                             " << endl;
		cout << "                  Dusty Book                 " << endl;
		cout << "                                             " << endl;
		cout << "             ,======,     ,======,           " << endl;
		cout << "         ,============, ,===========,        " << endl;
		cout << "      ,================================,     " << endl;
		cout << "you enter a room and find a large, dusty book on the ground. It is too heavy to take, but you decide to read it.\n";
		cout << "It is a tale of the ancient Greek Sphinx.\n";
		cout << "In the story, the hero was only able to make his way past the sphinx by answering a riddle.\n";
		cout << "What an interesting story... You probably don't care.\n\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 8 && br8 == 1) {
		cout << "You are in the room with the large dusty book.\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 9 && br9 == 0) {
		cout << "you waltz into a room feeling more confident than ever that this will be the end.\n";
		cout << "Much to your disappointment, the only item in the room is a Rubick's Cube. \n";
		cout << "You remember that one of your friends at home loves these puzzles. \n";
		cout << "It might be a good idea to take this back to him.\n\n";
		cout << "what will you do?\n";
	}
    
	if (roomnum == 9 && br9 == 1) {
		cout << "You are in the Rubick's Cube room.\n";
		cout << "what will you do?\n";
	}
    
    
	if (roomnum == 11) {
		//room 4 death by "w"
		cout << string(10, '\n');
		cout << "Congratulations, you walked into the blinding light and in the process fell off a cliff. \nDid anyone ever tell you not to look at the sun?\n\n";
		cout << "Game over, I guess.\n\n";
		play = false;
	}
    
	if (roomnum == 14) {
		//room 2 "n" death
		cout << string(10, '\n');
		cout << "You attempted to walk through the massive goblin. \n";
		cout << "Not the best idea if I might add. \nWith one swing of his club, he flattens you. \n";
		cout << "Congratulations. You are now his new doormat.\n\n";
		play = false;
	}
}

void roomnumber()
{
	getline(cin, m);
	/*
     inputs the direction, or move "m",
     processes the current room number,
     then the directon,
     and changes the room number if necessary
     */
	if (roomnum == 0) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 2;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			roomnum = 6;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			roomnum = 8;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			roomnum = 4;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") cout << "What? You expected to start the game with an item? \nHow Quaint.\n\n";
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions and see the graphic again: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		return;
	}
    
	if (roomnum == 1) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			cout << "you ran into a wall. Better not go that way.\n\n";
			roomnum = 1;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			roomnum = 2;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			roomnum = 4;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			cout << "you ran into a wall. Better not go that way.\n\n";
			roomnum = 1;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			cout << "There is no need to use an item here. It's not like you have a bag to put all this treasure in or anything.\n\n";
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "          ===|===========|===        " << endl;
			cout << "       ======|===========|======     " << endl;
			cout << "      =======|===.....===|=======    " << endl;
			cout << "      ===========|</>|===========    " << endl;
			cout << "      =======|==='''''===|=======    " << endl;
			cout << "      =======|===========|=======    " << endl;
			cout << "      =======|===========|=======    " << endl;
			cout << "      =======|===========|=======    " << endl;
			cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions and see the graphic again: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		}
		br1 = 1;
		return;
	}
    
	if (roomnum == 2) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 14;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			roomnum = 3;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			roomnum = 5;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			roomnum = 1;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			combat();
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "   ==============================    " << endl;
			cout << "   ========= ========== =========    " << endl;
			cout << "   ========== =      = ==========    " << endl;
			cout << "   ===========        ===========    " << endl;
			cout << "   ============      ============    " << endl;
			cout << "   ==============  ==============    " << endl;
			cout << "   =========            ======= =    " << endl;
			cout << "   ========  =        =  ===== ==    " << endl;
			cout << "   =======  ===      ===  === ===    " << endl;
			cout << "   ======  ====      ====  = ====    " << endl;
			cout << "   =====  =====      =====  =====    " << endl;
			cout << "   ===========   ==   === =======    " << endl;
			cout << "   =========   ======   =========    " << endl;
			cout << "   ========   ========   ========    " << endl;
			cout << "   =======   ==========   =======    " << endl;
			cout << "   =====     ==========     =====    " << endl;
			cout << "   ==============================    " << endl;
			cout << "   ==============================    " << endl;
			cout << "You audibly call out for help." << endl;
			cout << "The GOBLIN is thoroughly confused, and asks you what the problem is." << endl;
			cout << "The GOBLIN is wondering if you are scared of him." << endl;
			cout << "You explain that you are not scared at all, as this is a video game and poses noo real danger." << endl;
			cout << "the GOBLIN is relieved, and lets you pass through the door." << endl;
			cout << "CONGRATULATIONS!!! you have won the game by asking for help." << endl;
			play = false;
			return;
		}
		br2 = 1;
		return;
	}
    
	if (roomnum == 4) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 1;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			roomnum = 5;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			roomnum = 7;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			roomnum = 11;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			cout << "There is no need to use an item here.\n\n";
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "   ???????????????????    " << endl;
			cout << "   ???????????????????    " << endl;
			cout << "   ???????????????????    " << endl;
			cout << "   ???????????????????    " << endl;
			cout << "   ???????????????????    " << endl;
			cout << "   ???????????????????    " << endl;
			cout << "   ???????????????????    " << endl;
			cout << "   ???????????????????    " << endl;
			cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		}
		br4 = 1;
		return;
	}
    
	if (roomnum == 5) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 2;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			roomnum = 6;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			roomnum = 8;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			roomnum = 4;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			cout << "There is no need to use an item here.\n\n";
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		}
		br5 = 1;
		return;
	}
    
	if (roomnum == 6) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 3;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			cout << "You ran into a wall. Better not go that way.\n\n";
			roomnum = 6;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			roomnum = 9;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			roomnum = 5;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			cout << "There is no need to use an item here. The skeleton is already dead.\n\n";
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "   ==============================    " << endl;
			cout << "   ==============================    " << endl;
			cout << "   =====      ===================    " << endl;
			cout << "   ====  0..0  ==================    " << endl;
			cout << "   =====  --  ===================    " << endl;
			cout << "   ======    ====================    " << endl;
			cout << "   ==============================    " << endl;
			cout << "   ===============||-----||======    " << endl;
			cout << "   =============|  |     |  |====    " << endl;
			cout << "   ============|---|-</>-|---|===    " << endl;
			cout << "   ==============| |     | |=====    " << endl;
			cout << "   ===============||-----||======    " << endl;
			cout << "   ================|     |=======    " << endl;
			cout << "   =================|___|========    " << endl;
			cout << "   ==============================    " << endl;
			cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		}
		br6 = 1;
		return;
	}
    
	if (roomnum == 7) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 4;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			roomnum = 8;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			cout << "You ran into a wall. Better not go that way.\n\n";
			roomnum = 7;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			cout << "You ran into a wall. Better not go that way.\n\n";
			roomnum = 7;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			cout << "That is against the rules. I will not allow it.\n\n";
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "                0               " << endl;
			cout << "        </>     |               " << endl;
			cout << "                |               " << endl;
			cout << "            0=======0           " << endl;
			cout << "               |||              " << endl;
			cout << "               |||      </>     " << endl;
			cout << "     </>       |||              " << endl;
			cout << "               |||   </>        " << endl;
			cout << "               |||              " << endl;
			cout << "          ==============        " << endl;
			cout << "       ====================     " << endl;
			cout << "      ======================    " << endl;
			cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		}
		br7 = 1;
		return;
	}
    
	if (roomnum == 8) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 5;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			roomnum = 9;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			cout << "You ran into a wall. Better not go that way.\n\n";
			roomnum = 8;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			roomnum = 7;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			cout << "There is no need to use an item here. You thought it best not to damage the ancient book.\n\n";
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "                                             " << endl;
			cout << "                  Dusty Book                 " << endl;
			cout << "                                             " << endl;
			cout << "             ,======,     ,======,           " << endl;
			cout << "         ,============, ,===========,        " << endl;
			cout << "      ,================================,     " << endl;
			cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		}
		br8 = 1;
		return;
	}
    
	if (roomnum == 9) {
		if (m == "north" || m == "North" || m == "n" || m == "N" || m == "NORTH") {
			roomnum = 6;
		}
		if (m == "east" || m == "East" || m == "e" || m == "E" || m == "EAST") {
			cout << "You ran into a wall. Better not go that way.\n\n";
			roomnum = 9;
		}
		if (m == "south" || m == "South" || m == "s" || m == "S" || m == "SOUTH") {
			cout << "You ran into a wall. Better not go that way.\n\n";
			roomnum = 9;
		}
		if (m == "west" || m == "West" || m == "w" || m == "W" || m == "WEST") {
			roomnum = 8;
		}
		if (m == "t" || m == "T" || m == "take" || m == "Take" || m == "TAKE") {
			takeItem();
		}
		if (m == "u" || m == "U" || m == "use" || m == "Use" || m == "USE") {
			cout << "There is no need to use an item here.\n\n";
		}
		if (m == "i" || m == "I" || m == "help" || m == "HELP" || m == "h" || m == "H" || m == "instructions" || m == "Instructions" || m == "INSTRUCTIONS") {
			cout << "instructions: (write this down) \nwhen asked what do do, you may \nAsk for instructions: i \ngo North: n \ngo East: e \ngo South: s \ngo West: w \nTake the item in the room: t \nUse an item: u\n\n\n\n";
		}
		br9 = 1;
		return;
	}
	return;
}


int main()
{
	do {
		GUI();
		roomOutput();
		roomnumber();
	} while (play == true);
}

