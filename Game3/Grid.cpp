#include "Grid.h"

Grid::Grid(sf::Texture &Tall_Collisions_Sprite_Sheet, sf::Texture &Short_Collisions_Sprite_Sheet, sf::Texture &Floor_Tiles_Sprite_Sheet, sf::Texture &Character_Sprite_Sheet, sf::FloatRect Boundary_)
{
	Boundary = Boundary_;
	Adj_List_Boundary.left = Boundary.left - Boundary.width;
	Adj_List_Boundary.top = Boundary.top - Boundary.height;
	Adj_List_Boundary.width = Boundary.width * 3;
	Adj_List_Boundary.height = Boundary.height * 3;

	passive_npcs_iterator = 0;

	unsigned int design = rand() % 4;

	/*Floor_Tiles.push_back(buildAlleyFloor(sf::Vector2f(Boundary.left, Boundary.top), sf::Vector2f(Boundary.left + Boundary.width, Boundary.top + Boundary.height), Floor_Tiles_Sprite_Sheet));*/
	Floor_Tiles.push_back(buildAlleyFloor(sf::Vector2f(0,0), sf::Vector2f(Boundary.width, Boundary.height), Floor_Tiles_Sprite_Sheet));

	if(design == 0)
	{
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(150,100), sf::Vector2f(850,150), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1050,100), sf::Vector2f(1450,150), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(150,150), sf::Vector2f(200,950), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,950), sf::Vector2f(700,1000), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(400,800), sf::Vector2f(450,950), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(650,800), sf::Vector2f(700,950), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(700,900), sf::Vector2f(850,950), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(900,700), sf::Vector2f(1400,750), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1400,150), sf::Vector2f(1450,800), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1200,900), sf::Vector2f(1450,950), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1400,950), sf::Vector2f(1450,1150), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1200,1050), sf::Vector2f(1250,1300), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1250,1150), sf::Vector2f(1450,1200), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1400,1200), sf::Vector2f(1450,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1150,1400), sf::Vector2f(1450,1450), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1000,900), sf::Vector2f(1050,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,1000), sf::Vector2f(100,1150), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,1150), sf::Vector2f(150,1200), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(250,1150), sf::Vector2f(400,1200), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(500,1150), sf::Vector2f(600,1200), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,1200), sf::Vector2f(100,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(300,1200), sf::Vector2f(350,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(550,1200), sf::Vector2f(600,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,1400), sf::Vector2f(1050,1450), Tall_Collisions_Sprite_Sheet));

		Short_Collisions.push_back(buildFryers(sf::Vector2f(725,1375), Short_Collisions_Sprite_Sheet, 270));
		Short_Collisions.push_back(buildGrill(sf::Vector2f(925,1375), Short_Collisions_Sprite_Sheet, 270));
		Short_Collisions.push_back(buildExpoTable(sf::Vector2f(900,1125), Short_Collisions_Sprite_Sheet, 270));
		Short_Collisions.push_back(buildBathroomSink(sf::Vector2f(1275,1125), Short_Collisions_Sprite_Sheet, 0));
		Short_Collisions.push_back(buildBathroomSink(sf::Vector2f(1275,1225), Short_Collisions_Sprite_Sheet, 0));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(1150,200), sf::Vector2f(1300,350), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(1150,500), sf::Vector2f(1300,650), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(300,200), sf::Vector2f(450,350), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(600,200), sf::Vector2f(750,350), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(300,450), sf::Vector2f(450,600), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(600,450), sf::Vector2f(750,600), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(250,800), sf::Vector2f(350,950), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(500,800), sf::Vector2f(600,950), Short_Collisions_Sprite_Sheet));

		
		Floor_Tiles.push_back(buildDinerFloor(sf::Vector2f(150,100), sf::Vector2f(1450,950), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildDinerFloor(sf::Vector2f(50,950), sf::Vector2f(1450,1450), Floor_Tiles_Sprite_Sheet));

		Floor_Tiles.push_back(buildToilet(sf::Vector2f(1375,1125), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildToilet(sf::Vector2f(1375,1225), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningBooth(sf::Vector2f(225,875), Floor_Tiles_Sprite_Sheet, 0));
		Floor_Tiles.push_back(buildDiningBooth(sf::Vector2f(375,875), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningBooth(sf::Vector2f(475,875), Floor_Tiles_Sprite_Sheet, 0));
		Floor_Tiles.push_back(buildDiningBooth(sf::Vector2f(625,875), Floor_Tiles_Sprite_Sheet, 180));

		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1225,175), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1325,275), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1225,375), Floor_Tiles_Sprite_Sheet, 270));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1125,275), Floor_Tiles_Sprite_Sheet, 0));

		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1225,475), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1325,575), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1225,675), Floor_Tiles_Sprite_Sheet, 270));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1125,575), Floor_Tiles_Sprite_Sheet, 0));

		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(675,175), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(775,275), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(675,375), Floor_Tiles_Sprite_Sheet, 270));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(575,275), Floor_Tiles_Sprite_Sheet, 0));

		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(675,425), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(775,525), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(675,625), Floor_Tiles_Sprite_Sheet, 270));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(575,525), Floor_Tiles_Sprite_Sheet, 0));
		
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(375,175), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(475,275), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(375,375), Floor_Tiles_Sprite_Sheet, 270));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(275,275), Floor_Tiles_Sprite_Sheet, 0));

		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(375,425), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(475,525), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(375,625), Floor_Tiles_Sprite_Sheet, 270));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(275,525), Floor_Tiles_Sprite_Sheet, 0));
				
		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left, Boundary.top, 1500, 100)));
		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left, Boundary.top, 150, 950)));

		Hostile_NPC_Spawn_Vector = HashVector(sf::FloatRect(950,750,100,100));

		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(0,0,150,100)));
		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(0,850,100,100)));
		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(950,750,100,100)));

		std::vector<HashVector> Temp;
		/*Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1300, Boundary.top + 1100, 50, 50), 175, 185, 5, 10));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1350, Boundary.top + 1100, 50, 50), 355, 5, 5, 10));*/
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 200, Boundary.top + 850, 50, 50), 355, 5, 100, 200));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1300, Boundary.top + 1100, 50, 50), 175, 185, 5, 10));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1350, Boundary.top + 1100, 50, 50), 355, 5, 5, 10));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 350, Boundary.top + 850, 50, 50), 175, 185, 100, 200));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[2].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		/*Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1300, Boundary.top + 1200, 50, 50), 175, 185, 5, 10));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1350, Boundary.top + 1200, 50, 50), 355, 5, 5, 10));*/
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 450, Boundary.top + 850, 50, 50), 355, 5, 100, 200));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		/*Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1300, Boundary.top + 1200, 50, 50), 175, 185, 5, 10));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1350, Boundary.top + 1200, 50, 50), 355, 5, 5, 10));*/
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 600, Boundary.top + 850, 50, 50), 175, 185, 100, 200));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1300, Boundary.top + 1200, 50, 50), 175, 185, 5, 10));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1350, Boundary.top + 1200, 50, 50), 355, 5, 5, 10));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1100, Boundary.top + 550, 50, 50), 355, 5, 100, 200));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[2].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 250, Boundary.top + 700, 100, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 500, Boundary.top + 700, 100, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 800, Boundary.top + 1050, 200, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1100, Boundary.top + 450, 50, 50), 40, 50, 10, 20));

		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(100,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[2].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 250, Boundary.top + 700, 100, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 500, Boundary.top + 700, 100, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 800, Boundary.top + 1050, 200, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1100, Boundary.top + 450, 50, 50), 40, 50, 10, 20));

		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(100,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 650, Boundary.top + 1300, 150, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 850, Boundary.top + 1300, 150, 50), 85, 95, 10, 20));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 800, Boundary.top + 1150, 200, 50), 265, 275, 10, 20));

		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(75,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Background_SFX.push_back(BackgroundSFX(sf::Vector2f(Boundary.left + 750, Boundary.top + 750), 750, "diner",100));
	}
	if(design == 1)
	{
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(150,50), sf::Vector2f(200,150), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(200,50), sf::Vector2f(1250,100), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1250,50), sf::Vector2f(1300,100), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(0,250), sf::Vector2f(50,750), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(0,750), sf::Vector2f(250,800), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(0,800), sf::Vector2f(50,950), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(200,800), sf::Vector2f(250,1000), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,900), sf::Vector2f(100,1150), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(100,1100), sf::Vector2f(200,1150), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(200,1100), sf::Vector2f(250,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(200,1400), sf::Vector2f(750,1450), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(850,1400), sf::Vector2f(1450,1450), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1400,250), sf::Vector2f(1450,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildGroceryShelves(sf::Vector2f(475,750), Tall_Collisions_Sprite_Sheet, 0));
		Tall_Collisions.push_back(buildGroceryShelves(sf::Vector2f(825,750), Tall_Collisions_Sprite_Sheet, 0));
		Tall_Collisions.push_back(buildGroceryShelves(sf::Vector2f(1175,750), Tall_Collisions_Sprite_Sheet, 0));

		Short_Collisions.push_back(buildCounter(sf::Vector2f(150,350), sf::Vector2f(300,400), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildCounter(sf::Vector2f(150,550), sf::Vector2f(300,600), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildCashRegister(sf::Vector2f(275,425), Short_Collisions_Sprite_Sheet, 180));
		Short_Collisions.push_back(buildCashRegister(sf::Vector2f(275,625), Short_Collisions_Sprite_Sheet, 180));
		Short_Collisions.push_back(buildBathroomSink(sf::Vector2f(175,825), Short_Collisions_Sprite_Sheet, 180));

		Floor_Tiles.push_back(buildFloorZero(sf::Vector2f(150,100), sf::Vector2f(1300,250), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildFloorZero(sf::Vector2f(50,250), sf::Vector2f(1400,1150), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildFloorZero(sf::Vector2f(250,1150), sf::Vector2f(1450,1450), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildToilet(sf::Vector2f(75,875), Floor_Tiles_Sprite_Sheet, 0));

		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left, Boundary.top, 150, 250)));
		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left + 1300, Boundary.top, 200, 250)));

		Hostile_NPC_Spawn_Vector = HashVector(sf::FloatRect(550,600,150,150));

		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(50,150,200,200)));
		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(1250,150,150,100)));
		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(750,1300,100,100)));

		std::vector<HashVector> Temp;
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 550, Boundary.top + 250, 50, 1000), 175, 185, 15, 110));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 700, Boundary.top + 250, 50, 1000), 355, 5, 15, 110));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 900, Boundary.top + 250, 50, 1000), 175, 185, 100, 200));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1050, Boundary.top + 250, 50, 1000), 355, 5, 100, 200));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[1].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[2].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[3].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[3].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));
		
		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 200, Boundary.top + 400, 50, 50), 275, 355, 1000, 2000));

		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(125,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Background_SFX.push_back(BackgroundSFX(sf::Vector2f(Boundary.left + 750, Boundary.top + 750), 750, "grocery store",100));

	}
	if(design == 2)
	{
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(750,50), sf::Vector2f(1150,100), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(750,100), sf::Vector2f(800,200), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1300,50), sf::Vector2f(1450,100), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,200), sf::Vector2f(800,250), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1400,100), sf::Vector2f(1450,350), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(750,350), sf::Vector2f(1450,400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,250), sf::Vector2f(100,1450), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(50,1450), sf::Vector2f(200,1500), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(300,1450), sf::Vector2f(1450,1500), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1400,1350), sf::Vector2f(1450,1450), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1200,1000), sf::Vector2f(1250,1100), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1200,650), sf::Vector2f(1250,750), Tall_Collisions_Sprite_Sheet));

		Short_Collisions.push_back(buildCounter(sf::Vector2f(1100,200), sf::Vector2f(1400,250), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildToolTable(sf::Vector2f(725,625), Short_Collisions_Sprite_Sheet, 0));
		Short_Collisions.push_back(buildToolTable(sf::Vector2f(725,925), Short_Collisions_Sprite_Sheet, 180));
		Short_Collisions.push_back(buildToolTable(sf::Vector2f(725,1225), Short_Collisions_Sprite_Sheet, 0));
		Short_Collisions.push_back(buildCar(sf::Vector2f(400,450), Short_Collisions_Sprite_Sheet, 90));
		Short_Collisions.push_back(buildCar(sf::Vector2f(400,850), Short_Collisions_Sprite_Sheet, 90));
		Short_Collisions.push_back(buildCar(sf::Vector2f(400,1250), Short_Collisions_Sprite_Sheet, 270));
		Short_Collisions.push_back(buildCar(sf::Vector2f(1000, 850), Short_Collisions_Sprite_Sheet, 270));

		Floor_Tiles.push_back(buildFloorZero(sf::Vector2f(750,100), sf::Vector2f(1100,400), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildFloorZero(sf::Vector2f(1100,50), sf::Vector2f(1400,400), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,125), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(975,125), Floor_Tiles_Sprite_Sheet, 90));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(1075,125), Floor_Tiles_Sprite_Sheet, 90));
		
		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left, Boundary.top, 750, 200)));
		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left + 750, Boundary.top + 1100, 650, 350)));

		Hostile_NPC_Spawn_Vector = HashVector(sf::FloatRect(700,700,150,150));

		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(950,200,100,100)));
		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(900,1050,100,100)));
		
		std::vector<HashVector> Temp;
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 850, Boundary.top + 100, 50, 50), 85, 95, 15, 110));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 950, Boundary.top + 100, 50, 50), 85, 95, 15, 110));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1050, Boundary.top + 100, 50, 50), 85, 95, 100, 200));
		
		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 1200, Boundary.top + 250, 100, 50), 250, 290, 150, 200));

		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(125,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 300, Boundary.top + 550, 150, 50), 265, 285, 15, 110));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 500, Boundary.top + 950, 100, 50), 260, 280, 19, 200));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 650, Boundary.top + 850, 50, 150), 355, 10, 19, 30));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 150, Boundary.top + 350, 50, 200), 355, 10, 119, 200));
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 150, Boundary.top + 350, 50, 200), 355, 10, 119, 200));

		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(125,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(125,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[3].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Background_SFX.push_back(BackgroundSFX(sf::Vector2f(Boundary.left + 750, Boundary.top + 750), 750, "auto repair shop", 100));

	}
	if(design == 3)
	{
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(600,500), sf::Vector2f(750,550), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(700,200), sf::Vector2f(750,500), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(850,200), sf::Vector2f(900,300), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(900,250), sf::Vector2f(1050,300), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1000,300), sf::Vector2f(1050,500), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(850,500), sf::Vector2f(1050,550), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(600,650), sf::Vector2f(650,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(600,1400), sf::Vector2f(1250,1450), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1000,550), sf::Vector2f(1050,1100), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1000,1200), sf::Vector2f(1050,1400), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1150,1050), sf::Vector2f(1200,1250), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1150,1250), sf::Vector2f(1250,1300), Tall_Collisions_Sprite_Sheet));
		Tall_Collisions.push_back(buildWallOne(sf::Vector2f(1200,1300), sf::Vector2f(1250,1400), Tall_Collisions_Sprite_Sheet));

		Short_Collisions.push_back(buildBoxes(sf::Vector2f(900,300), sf::Vector2f(1000,500), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildLiquorShelf(sf::Vector2f(675,1025), Short_Collisions_Sprite_Sheet, 0));
		Short_Collisions.push_back(buildDiningTable(sf::Vector2f(800,700), sf::Vector2f(850,1400), Short_Collisions_Sprite_Sheet));
		Short_Collisions.push_back(buildBathroomSink(sf::Vector2f(1075,1375), Short_Collisions_Sprite_Sheet, 0));


		Floor_Tiles.push_back(buildFloorOne(sf::Vector2f(700,200), sf::Vector2f(900,300), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildFloorOne(sf::Vector2f(700,300), sf::Vector2f(1000,500), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildFloorOne(sf::Vector2f(600,500), sf::Vector2f(1000,1400), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildFloorOne(sf::Vector2f(1000,1050), sf::Vector2f(1200,1400), Floor_Tiles_Sprite_Sheet));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,775), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,875), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,975), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,1075), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,1175), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,1275), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildDiningChair(sf::Vector2f(875,1375), Floor_Tiles_Sprite_Sheet, 180));
		Floor_Tiles.push_back(buildToilet(sf::Vector2f(1175,1325), Floor_Tiles_Sprite_Sheet, 180));

		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left, Boundary.top, 600, 1500)));
		Flee_Boxes.push_back(HashVector(sf::FloatRect(Boundary.left + 1250, Boundary.top, 250, 1500)));

		Hostile_NPC_Spawn_Vector = HashVector(sf::FloatRect(650,550,350,150));

		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(650,550,350,150)));
		Assassin_Hash_Vectors.push_back(HashVector(sf::FloatRect(1050,1300,150,50)));

		std::vector<HashVector> Temp;
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 850, Boundary.top + 850, 50, 50), 185, 195, 115, 210));
		
		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 850, Boundary.top + 1350, 50, 50), 165, 195, 115, 220));
		
		Passive_NPCs.push_back(PassiveNPC(generateCivilianBodySpriteTextRect(), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Temp.clear();
		Temp.push_back(HashVector(sf::FloatRect(Boundary.left + 750, Boundary.top + 700, 50, 700), 353, 7, 15, 110));
		
		Passive_NPCs.push_back(PassiveNPC(sf::IntRect(125,200,25,100), &Character_Sprite_Sheet, sf::Vector2f(Temp[0].getVector()), /*Null_Adj_List,*/ sf::FloatRect(Boundary.left - Boundary.width, Boundary.top - Boundary.height, Boundary.width * 3, Boundary.height * 3), Temp, Flee_Boxes));

		Background_SFX.push_back(BackgroundSFX(sf::Vector2f(Boundary.left + 800, Boundary.top + 825), 625, "bar", 70));

	}

	moveEverything();
}

void Grid::playBackgroundSFX(sf::Vector2f P_C_Position)
{
	for(unsigned int i = 0; i < Background_SFX.size(); i++)
	{
		Background_SFX[i].playSFX(P_C_Position);
	}
}

void Grid::stopBackgroundSFX()
{
	for(unsigned int i = 0; i < Background_SFX.size(); i++)
	{
		Background_SFX[i].stopSFX();
	}
}

sf::RectangleShape Grid::buildDinerFloor(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &Floor_Tiles_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Floor_Tiles_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,1000,1000,1000));
	
	return To_Return;
}


Grid::Grid()
{

}

sf::IntRect Grid::generateCivilianBodySpriteTextRect()
{
	unsigned int random_number = rand() % 3;

	if(random_number == 0)
	{
		return sf::IntRect(0,200,25,100);
	}
	if(random_number == 1)
	{
		return sf::IntRect(25,200,25,100);
	}
	if(random_number == 2)
	{
		return sf::IntRect(50,200,25,100);
	}
}

bool Grid::adjListCollisionDetection(sf::Vector2f Point_To_Test)
{
	if(shortCollisionsDetection(Point_To_Test))
		return true;
	if(tallCollisionsDetection(Point_To_Test))
		return true;

	if(Point_To_Test.y <= Boundary.top)
	{

		if(Point_To_Test.x >= Boundary.left + Boundary.width)
		{
			if(Northeast_Grid)
			{
				if(Northeast_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(Northeast_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
		else if(Point_To_Test.x <= Boundary.left)
		{
			if(Northwest_Grid)
			{
				if(Northwest_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(Northwest_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
		else
		{
			if(North_Grid)
			{
				if(North_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(North_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
	}	
	else if(Point_To_Test.y >= Boundary.top + Boundary.height)
	{
		if(Point_To_Test.x <= Boundary.left)
		{
			if(Southwest_Grid)
			{
				if(Southwest_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(Southwest_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
		else if(Point_To_Test.x >= Boundary.left + Boundary.width)
		{
			if(Southeast_Grid)
			{
				if(Southeast_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(Southeast_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
		else
		{
			if(South_Grid)
			{
				if(South_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(South_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
	}
	else
	{
		if(Point_To_Test.x <= Boundary.left)
		{
			if(West_Grid)
			{
				if(West_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(West_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
		if(Point_To_Test.x >= Boundary.left + Boundary.width)
		{
			if(East_Grid)
			{
				if(East_Grid->shortCollisionsDetection(Point_To_Test))
					return true;
				if(East_Grid->tallCollisionsDetection(Point_To_Test))
					return true;		
			}
		}
	}

	return false;
}

void Grid::restartAllCivPocketWatches()
{
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].restartPocketWatch();
	}
}

void Grid::pauseAllCivClocks()
{
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].pauseDefaultClock();
	}
}

void Grid::resumeAllCivClocks()
{
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].resumeDefaultClock();
		Passive_NPCs[i].resumeAggroClock();
		Passive_NPCs[i].resumePocketWatch();
	}
}

void Grid::buildAdjList()
{
	sf::FloatRect Adj_List_Boundary;
	Adj_List_Boundary.left = Boundary.left - Boundary.width;
	Adj_List_Boundary.top = Boundary.top - Boundary.height;
	Adj_List_Boundary.width = Boundary.width * 3;
	Adj_List_Boundary.height = Boundary.height * 3;

	Adjacency_List.resize((Adj_List_Boundary.height / 50) * (Adj_List_Boundary.width / 50));

	
	sf::Vector2f Point_To_Test(Adj_List_Boundary.left + 25, Adj_List_Boundary.top + 25);

	unsigned int dijkstras_nodes_built = 0;

	while(Point_To_Test.y < (Adj_List_Boundary.top + Adj_List_Boundary.height))
	{
		Point_To_Test.x = Adj_List_Boundary.left + 25;

		while(Point_To_Test.x < (Adj_List_Boundary.left + Adj_List_Boundary.width))
		{
			if(!adjListCollisionDetection(Point_To_Test))
			{
				//check upper node
				if(Point_To_Test.y - 50 > Adj_List_Boundary.top)
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x, Point_To_Test.y - 50)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built - (Adj_List_Boundary.width / 50)),10));
					}
				}
				
				//check lower node
				if(Point_To_Test.y + 50 < Adj_List_Boundary.top + Adj_List_Boundary.height)
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x, Point_To_Test.y + 50)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built + (Adj_List_Boundary.width / 50)),10));
					}
				}

				//check left node
				if(Point_To_Test.x - 50 > Adj_List_Boundary.left)
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x - 50, Point_To_Test.y)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built - 1),10));
					}
				}

				//check right node
				if(Point_To_Test.x + 50 < Adj_List_Boundary.left + Adj_List_Boundary.width)
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x + 50, Point_To_Test.y)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built + 1),10));
					}
				}

				//check upper right
				if((Point_To_Test.x + 50 < Adj_List_Boundary.left + Adj_List_Boundary.width) && (Point_To_Test.y - 50 > Adj_List_Boundary.top))
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x + 50, Point_To_Test.y - 50)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built + 1 - (Adj_List_Boundary.width / 50)),14));
					}
				}
				//check lower right
				if((Point_To_Test.x + 50 < Adj_List_Boundary.left + Adj_List_Boundary.width) && (Point_To_Test.y + 50 < Adj_List_Boundary.top + Adj_List_Boundary.height))
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x + 50, Point_To_Test.y + 50)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built + 1 + (Adj_List_Boundary.width / 50)),14));
					}
				}
				//check lower left
				if((Point_To_Test.x - 50 > Adj_List_Boundary.left) && (Point_To_Test.y + 50 < Adj_List_Boundary.top + Adj_List_Boundary.height))
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x - 50, Point_To_Test.y + 50)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built - 1 + (Adj_List_Boundary.width / 50)),14));
					}
				}
				//check upper left
				if((Point_To_Test.x - 50 > Adj_List_Boundary.left) && (Point_To_Test.y - 50 > Adj_List_Boundary.top))
				{
					if(!adjListCollisionDetection(sf::Vector2f(Point_To_Test.x - 50, Point_To_Test.y - 50)))
					{
						Adjacency_List[dijkstras_nodes_built].push_back(Dijkstras::neighbor((dijkstras_nodes_built - 1 - (Adj_List_Boundary.width / 50)),14));
					}
				}
			}

			dijkstras_nodes_built++;
			Point_To_Test.x += 50;
		}

		Point_To_Test.y += 50;
	}

}

void Grid::setPassiveNPCsAdjLists()
{
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].setAdjList(&Adjacency_List);
	}
}

void Grid::moveEverything()
{

		for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
		{
			Tall_Collisions[i].move(Boundary.left, Boundary.top);
		}
		for(unsigned int i = 0; i < Short_Collisions.size(); i++)
		{
			Short_Collisions[i].move(Boundary.left, Boundary.top);
		}
		for(unsigned int i = 0; i < Floor_Tiles.size(); i++)
		{
			Floor_Tiles[i].move(Boundary.left, Boundary.top);
		}
		for(unsigned int i = 0; i < Assassin_Hash_Vectors.size(); i++)
		{
			Assassin_Hash_Vectors[i].moveBoundary(Boundary.left, Boundary.top);
		}
		Hostile_NPC_Spawn_Vector.moveBoundary(Boundary.left, Boundary.top);
}

void Grid::drawEverything(sf::RenderWindow &Window)
{
	for(unsigned int i = 0; i < Floor_Tiles.size(); i++)
	{
		Window.draw(Floor_Tiles[i]);
	}
	for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
	{
		Window.draw(Tall_Collisions[i]);
	}
	for(unsigned int i = 0; i < Short_Collisions.size(); i++)
	{
		Window.draw(Short_Collisions[i]);
	}
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Window.draw(Passive_NPCs[i].getLeftFootSprite());
		Window.draw(Passive_NPCs[i].getRightFootSprite());
		Window.draw(Passive_NPCs[i].getBodySprite());
		Window.draw(Passive_NPCs[i].getHeadSprite());
	}

}

//void Grid::setPassiveNPCsAdjLists(std::vector<std::vector<Dijkstras::neighbor> >* Adj_List)
//{
//	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
//	{
//		Passive_NPCs[i].setAdjList(Adj_List);
//	}
//}

void Grid::restartAggroClocks()
{
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].restartAggroClock();
	}	
}

void Grid::passiveNPCsScripting()
{
	if(Passive_NPCs.size() > 0)
	{
		Passive_NPCs[passive_npcs_iterator].chooseScript();
	}
}

void Grid::incrementPassiveNPCIterators()
{
	passive_npcs_iterator++;
	if(passive_npcs_iterator == Passive_NPCs.size())
	{
		passive_npcs_iterator = 0;
	}	
}

void Grid::updateCharacterSprites()
{
	//Passive_NPCs[passive_npcs_iterator].updateCharacterSprite();
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].updateCharacterSprite();
	}
}

void Grid::moveCharacterSprites(sf::Time Frame_Time)
{
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].movement(Frame_Time);
		Passive_NPCs[i].determineRotation();
		Passive_NPCs[i].updateCharacterSprite();
	}
}

void Grid::determinePassiveNPCsRotations()
{
	//Passive_NPCs[passive_npcs_iterator].determineRotation();
	for(unsigned int i = 0; i < Passive_NPCs.size(); i++)
	{
		Passive_NPCs[i].determineRotation();
	}
}

bool Grid::shortCollisionsDetection(sf::Vector2f Point)
{
	for(unsigned int i = 0; i < Short_Collisions.size(); i++)
	{
		if(Short_Collisions[i].getGlobalBounds().contains(Point))
		{
			return true;
		}
	}

	return false;
}

bool Grid::tallCollisionsDetection(sf::Vector2f Point)
{
	for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
	{
		if(Tall_Collisions[i].getGlobalBounds().contains(Point))
		{
			return true;
		}
	}

	return false;
}

bool Grid::lineOfSight(sf::Vector2f A, sf::Vector2f B)
{
	for(unsigned int i = 0; i < Tall_Collisions.size(); i++)
	{
		if(lineLineIntersection(A, B, sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left, Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left + Tall_Collisions[i].getGlobalBounds().width, Tall_Collisions[i].getGlobalBounds().top)))
		{
			return false;
		}
		if(lineLineIntersection(A, B, sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left + Tall_Collisions[i].getGlobalBounds().width, Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left + Tall_Collisions[i].getGlobalBounds().width, Tall_Collisions[i].getGlobalBounds().top + Tall_Collisions[i].getGlobalBounds().height)))
		{
			return false;
		}
		if(lineLineIntersection(A, B, sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left + Tall_Collisions[i].getGlobalBounds().width, Tall_Collisions[i].getGlobalBounds().top + Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left, Tall_Collisions[i].getGlobalBounds().top + Tall_Collisions[i].getGlobalBounds().height)))
		{
			return false;
		}
		if(lineLineIntersection(A, B, sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left, Tall_Collisions[i].getGlobalBounds().top + Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Tall_Collisions[i].getGlobalBounds().left, Tall_Collisions[i].getGlobalBounds().top)))
		{
			return false;
		}
	}
	if(North_Grid)
	{
		for(unsigned int i = 0; i < North_Grid->Tall_Collisions.size(); i++)
		{
			if(North_Grid->lineLineIntersection(A, B, sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left, North_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left + North_Grid->Tall_Collisions[i].getGlobalBounds().width, North_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(North_Grid->lineLineIntersection(A, B, sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left + North_Grid->Tall_Collisions[i].getGlobalBounds().width, North_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left + North_Grid->Tall_Collisions[i].getGlobalBounds().width, North_Grid->Tall_Collisions[i].getGlobalBounds().top + North_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(North_Grid->lineLineIntersection(A, B, sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left + North_Grid->Tall_Collisions[i].getGlobalBounds().width, North_Grid->Tall_Collisions[i].getGlobalBounds().top + North_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left, North_Grid->Tall_Collisions[i].getGlobalBounds().top + North_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(North_Grid->lineLineIntersection(A, B, sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left, North_Grid->Tall_Collisions[i].getGlobalBounds().top + North_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(North_Grid->Tall_Collisions[i].getGlobalBounds().left, North_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	if(Northeast_Grid)
	{
		for(unsigned int i = 0; i < Northeast_Grid->Tall_Collisions.size(); i++)
		{
			if(Northeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(Northeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Northeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Northeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Northeast_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Northeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Northeast_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	if(East_Grid)
	{
		for(unsigned int i = 0; i < East_Grid->Tall_Collisions.size(); i++)
		{
			if(East_Grid->lineLineIntersection(A, B, sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left, East_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left + East_Grid->Tall_Collisions[i].getGlobalBounds().width, East_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(East_Grid->lineLineIntersection(A, B, sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left + East_Grid->Tall_Collisions[i].getGlobalBounds().width, East_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left + East_Grid->Tall_Collisions[i].getGlobalBounds().width, East_Grid->Tall_Collisions[i].getGlobalBounds().top + East_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(East_Grid->lineLineIntersection(A, B, sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left + East_Grid->Tall_Collisions[i].getGlobalBounds().width, East_Grid->Tall_Collisions[i].getGlobalBounds().top + East_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left, East_Grid->Tall_Collisions[i].getGlobalBounds().top + East_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(East_Grid->lineLineIntersection(A, B, sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left, East_Grid->Tall_Collisions[i].getGlobalBounds().top + East_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(East_Grid->Tall_Collisions[i].getGlobalBounds().left, East_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	if(Southeast_Grid)
	{
		for(unsigned int i = 0; i < Southeast_Grid->Tall_Collisions.size(); i++)
		{
			if(Southeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(Southeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Southeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().width, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Southeast_Grid->lineLineIntersection(A, B, sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top + Southeast_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Southeast_Grid->Tall_Collisions[i].getGlobalBounds().left, Southeast_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	if(South_Grid)
	{
		for(unsigned int i = 0; i < South_Grid->Tall_Collisions.size(); i++)
		{
			if(South_Grid->lineLineIntersection(A, B, sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left, South_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left + South_Grid->Tall_Collisions[i].getGlobalBounds().width, South_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(South_Grid->lineLineIntersection(A, B, sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left + South_Grid->Tall_Collisions[i].getGlobalBounds().width, South_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left + South_Grid->Tall_Collisions[i].getGlobalBounds().width, South_Grid->Tall_Collisions[i].getGlobalBounds().top + South_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(South_Grid->lineLineIntersection(A, B, sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left + South_Grid->Tall_Collisions[i].getGlobalBounds().width, South_Grid->Tall_Collisions[i].getGlobalBounds().top + South_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left, South_Grid->Tall_Collisions[i].getGlobalBounds().top + South_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(South_Grid->lineLineIntersection(A, B, sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left, South_Grid->Tall_Collisions[i].getGlobalBounds().top + South_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(South_Grid->Tall_Collisions[i].getGlobalBounds().left, South_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	if(Southwest_Grid)
	{
		for(unsigned int i = 0; i < Southwest_Grid->Tall_Collisions.size(); i++)
		{
			if(Southwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(Southwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Southwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Southwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Southwest_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Southwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Southwest_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	if(West_Grid)
	{
		for(unsigned int i = 0; i < West_Grid->Tall_Collisions.size(); i++)
		{
			if(West_Grid->lineLineIntersection(A, B, sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left, West_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left + West_Grid->Tall_Collisions[i].getGlobalBounds().width, West_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(West_Grid->lineLineIntersection(A, B, sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left + West_Grid->Tall_Collisions[i].getGlobalBounds().width, West_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left + West_Grid->Tall_Collisions[i].getGlobalBounds().width, West_Grid->Tall_Collisions[i].getGlobalBounds().top + West_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(West_Grid->lineLineIntersection(A, B, sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left + West_Grid->Tall_Collisions[i].getGlobalBounds().width, West_Grid->Tall_Collisions[i].getGlobalBounds().top + West_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left, West_Grid->Tall_Collisions[i].getGlobalBounds().top + West_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(West_Grid->lineLineIntersection(A, B, sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left, West_Grid->Tall_Collisions[i].getGlobalBounds().top + West_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(West_Grid->Tall_Collisions[i].getGlobalBounds().left, West_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	if(Northwest_Grid)
	{
		for(unsigned int i = 0; i < Northwest_Grid->Tall_Collisions.size(); i++)
		{
			if(Northwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
			if(Northwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top), sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Northwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().width, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().height)))
			{
				return false;
			}
			if(Northwest_Grid->lineLineIntersection(A, B, sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top + Northwest_Grid->Tall_Collisions[i].getGlobalBounds().height), sf::Vector2f(Northwest_Grid->Tall_Collisions[i].getGlobalBounds().left, Northwest_Grid->Tall_Collisions[i].getGlobalBounds().top)))
			{
				return false;
			}
		}
	}
	return true;
}

float Grid::max(float A, float B){if(A > B){return A;}else{return B;}}

float Grid::min(float A, float B){if(A < B){return A;}else{return B;}}

bool Grid::lineLineIntersection(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Vector2f D)
{
	boost::geometry::model::segment<boost::geometry::model::d2::point_xy<double>> AB( boost::geometry::model::d2::point_xy<double>(A.x, A.y), boost::geometry::model::d2::point_xy<double>(B.x, B.y) );
	boost::geometry::model::segment<boost::geometry::model::d2::point_xy<double>> CD( boost::geometry::model::d2::point_xy<double>(C.x, C.y), boost::geometry::model::d2::point_xy<double>(D.x, D.y) );

	boost::geometry:
	if(boost::geometry::intersects(AB, CD))
	{
		return true;
	}

	return false;
}

bool Grid::isNPCContainedInFleeBoxes(sf::Vector2f Point)
{
	for(unsigned int i = 0; i < Flee_Boxes.size(); i++)
	{
		if(Flee_Boxes[i].getBoundary().contains(Point))
		{
			return true;
		}
	}

	return false;
}

sf::RectangleShape Grid::buildAlleyFloor(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &Floor_Tiles_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Floor_Tiles_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,0,1000,1000));

	return To_Return;
}

sf::RectangleShape Grid::buildWallOne(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &Tall_Collisions_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Tall_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,0,500,500));

	return To_Return;
}

sf::RectangleShape Grid::buildFryers(sf::Vector2f Position, sf::Texture &Short_Collisions_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,150));
	To_Return.setOrigin(25,75);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(50,0,50,150));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildGrill(sf::Vector2f Position, sf::Texture &Short_Collisions_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,150));
	To_Return.setOrigin(25,75);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,0,50,150));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildExpoTable(sf::Vector2f Position, sf::Texture &Short_Collisions_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,200));
	To_Return.setOrigin(25,100);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(100,0,50,200));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildBathroomSink(sf::Vector2f Position, sf::Texture &Short_Collisions_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,50));
	To_Return.setOrigin(25,25);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,150,50,50));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildDiningTable(sf::Vector2f Top_Left, sf::Vector2f Bottom_Right, sf::Texture &Short_Collisions_Sprite_Sheet)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(50,150,50,50));

	return To_Return;
}

sf::RectangleShape Grid::buildToilet(sf::Vector2f Position, sf::Texture &Floor_Tiles_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,50));
	To_Return.setOrigin(25,25);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Floor_Tiles_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(1000,50,50,50));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildDiningChair(sf::Vector2f Position, sf::Texture &Floor_Tiles_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,50));
	To_Return.setOrigin(25,25);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Floor_Tiles_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(1000,0,50,50));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildDiningBooth(sf::Vector2f Position, sf::Texture &Floor_Tiles_Sprite_Sheet, float rotation)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,150));
	To_Return.setOrigin(25,75);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Floor_Tiles_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(1000,100,50,150));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildCashRegister(sf::Vector2f Position,
										   sf::Texture &Short_Collisions_Sprite_Sheet,
										   float rotation
										   )
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,50));
	To_Return.setOrigin(25,25);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(50,200,50,50));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildGroceryShelves(sf::Vector2f Position,
											 sf::Texture &Tall_Collisions_Sprite_Sheet,
											 float rotation
											 )
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(150,1000));
	To_Return.setOrigin(75,500);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Tall_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,500,150,1000));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildToolTable(sf::Vector2f Position,
										sf::Texture &Short_Collisions_Sprite_Sheet,
										float rotation
										)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,150));
	To_Return.setOrigin(25,75);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,250,50,150));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildCar(sf::Vector2f Position,
								  sf::Texture &Short_Collisions_Sprite_Sheet,
								  float rotation
								  )
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(200,400));
	To_Return.setOrigin(100,200);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	unsigned int random_number = rand() % 3;
	To_Return.setTextureRect(sf::IntRect(0,400 + (random_number * 400),200,400));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildCounter(sf::Vector2f Top_Left,
										   sf::Vector2f Bottom_Right,
										   sf::Texture &Short_Collisions_Sprite_Sheet
										   )
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,200,50,50));

	return To_Return;
}

sf::RectangleShape Grid::buildBoxes(sf::Vector2f Top_Left,
									sf::Vector2f Bottom_Right,
									sf::Texture &Short_Collisions_Sprite_Sheet
									)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(50,250,100,150));

	return To_Return;
}

sf::RectangleShape Grid::buildLiquorShelf(sf::Vector2f Position,
										  sf::Texture &Short_Collisions_Sprite_Sheet,
										  float rotation
										  )
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(50,350));
	To_Return.setOrigin(25,175);
	To_Return.setPosition(Position);
	To_Return.setTexture(&Short_Collisions_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(150,0,50,350));
	To_Return.setRotation(rotation);

	return To_Return;
}

sf::RectangleShape Grid::buildFloorZero(sf::Vector2f Top_Left,
										sf::Vector2f Bottom_Right,
										sf::Texture &Floor_Tiles_Sprite_Sheet
										)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Floor_Tiles_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,2000,1000,1000));

	return To_Return;
}

sf::RectangleShape Grid::buildFloorOne(sf::Vector2f Top_Left,
										sf::Vector2f Bottom_Right,
										sf::Texture &Floor_Tiles_Sprite_Sheet
										)
{
	sf::RectangleShape To_Return;

	To_Return.setSize(sf::Vector2f(Bottom_Right.x - Top_Left.x, Bottom_Right.y - Top_Left.y));
	To_Return.setPosition(Top_Left);
	To_Return.setTexture(&Floor_Tiles_Sprite_Sheet);
	To_Return.setTextureRect(sf::IntRect(0,3000,1000,1000));

	return To_Return;
}