#include "Ctrl.h"
#include <stack>
#include <fstream>
#include "DecisionTreeNode.h"

#pragma region CtrlClass
// Šis ir Ctrl klases konstruktors, kas tiek izmantots, lai inicializētu jaunu Ctrl objektu.
Ctrl::Ctrl(int controlAreaWidth, int controlAreaHeight, int cellsCount, float btnSizeKoef, float cellMinSize)
{
	this->memberMinSize = cellMinSize;
	this->controlAreaSize.H = controlAreaHeight;
	this->controlAreaSize.W = controlAreaWidth;
	this->cellCount = cellsCount;
	this->buttonCount = cellsCount - 1;
	this->btnSizeKoef = btnSizeKoef;

	// Iegūst maksimālo dalībnieku (spēlētāju un pogu) izmēru.
	memberMaxSize = getMembersMaxSize();

	// Izveido atrašanās vietu (kursoru) elementiem.
	location cursor{ 0,0 };

	// Uzstāda noklusējuma krāsu.
	Color defaultColor = Color::FromArgb(255, 255, 255);

	// Izveido spēles šūnas un pogas.
	for (int i = 0; i < cellsCount; i++) {
		// Izveido jaunu šūnu un iestata tās izmērus, atrašanās vietu, krāsu, vērtību un identifikatoru.
		Cell* cell = new Cell;
		cell->setSize(memberMaxSize);
		cell->setLocation(cursor.X, cursor.Y);
		cell->setColor(defaultColor.ToArgb());
		cell->setValue(1 + rand() % 9);
		cell->setID(i);
		cells.push_back(cell);

		// Pārvietojas uz nākamo atrašanās vietu šūnas labajā pusē.
		cursor.X += memberMaxSize * 2;
	}

	for (int i = 0; i < cellsCount; i++) {
		originalCellValues.push_back(cells.at(i)->getValue());
	}

	// Izveido pogas un piesaista tām šūnas.
	for (int i = 0; i < buttonCount; i++) {
		// Izveido jaunu pogu un iestata tās izmērus, atrašanās vietu, krāsu un identifikatoru.
		Buttn* button = new Buttn;
		button->setSize(memberMaxSize * btnSizeKoef);
		button->setLocation(cursor.X, cursor.Y);
		button->setColor(defaultColor.ToArgb());
		button->setID(i);

		// Piesaista pogai šūnas pāri.
		controlledCellsID cellsID{ i, i + 1 };
		button->setCellsID(cellsID);

		// Iestata pogas vērtību atkarībā no piesaistīto šūnu vērtību summas.
		int buttonValue{};
		if (this->cells.at(cellsID.ID1)->getValue() + this->cells.at(cellsID.ID2)->getValue() > 7) {
			buttonValue = 1;
		}
		else if (this->cells.at(cellsID.ID1)->getValue() + this->cells.at(cellsID.ID2)->getValue() < 7) {
			buttonValue = -1;
		}
		else {
			buttonValue = 2;
		}
		button->setPointsForCellsMerge(buttonValue);

		// Pievieno pogu vektorā.
		buttons.push_back(button);

		// Pārvietojas uz nākamo atrašanās vietu pogas labajā pusē.
		cursor.X += memberMaxSize * 2;
	}

	// Izveido divus spēlētājus un pievieno tos spēlei.
	for (int i = 0; i < 2; i++) {
		Player* player = new Player;
		players.push_back(player);
	}
}
Ctrl::Ctrl()
{
}
// Destruktors, kas tiek izsaukts, kad objekts tiek iznīcināts.
// Katrs spēlētājs, poga un šūna tiek atbrīvota, izmantojot atbrīvošanas operatoru delete.
Ctrl::~Ctrl()
{
	// Atbrīvo atmiņu, kas piešķirta spēlētājiem.
	for (int i = 0; i < players.size(); i++) {
		delete players.at(i);
	}
	// Atbrīvo atmiņu, kas piešķirta pogām.
	for (int i = 0; i < buttons.size(); i++) {
		delete buttons.at(i);
	}
	// Atbrīvo atmiņu, kas piešķirta šūnām.
	for (int i = 0; i < cells.size(); i++) {
		delete cells.at(i);
	}
}
// Šī funkcija atgriež norādītā spēlētāja rezultātu.
int Ctrl::getPlayerScore(int playerID)
{
	return players.at(playerID)->getScore();
}

// Šī funkcija iestata norādītā spēlētāja rezultātu.
void Ctrl::setPlayerScore(int playerID, int score)
{
	players.at(playerID)->setScore(score);
}

// Šī funkcija atgriež norādītā spēlētāja gājiena stāvokli (vai viņš ir pa gājienu).
bool Ctrl::getmakingMoveStatus(int playerID)
{
	return players.at(playerID)->getStatus();
}

// Šī funkcija iestata norādītā spēlētāja gājiena stāvokli.
void Ctrl::setMakingMoveStatus(int playerID, bool isMakingMove)
{
	players.at(playerID)->setStatus(isMakingMove);
}

// Šī funkcija atgriež spēlētāju indikatora izmēru.
float Ctrl::getPlayerIndicatorSize()
{
	return playerIndicatorSize;
}

// Šī funkcija iestata spēlētāju indikatora izmēru.
void Ctrl::setPlayerIndicatorSize(float newSize)
{
	this->playerIndicatorSize = newSize;
}

// Šī funkcija nosaka, vai spēlētājam ir uzvarējis, pārbaudot, vai ir vairāk nekā viena šūna.
bool Ctrl::playerHasWin()
{
	return cells.size() > 1 ? false : true;
}

// Šī funkcija atgriež pogu skaitu, kas ir kontrolējamās klases objektā.
int Ctrl::getButtonsCount()
{
	return buttons.size();
}
// Šī funkcija pārbauda, vai peles kursora atrašanās vieta atrodas uz kādas no pogām.
// Ja peles kursors ir uz kādas pogas, funkcija veic attiecīgas darbības.
void Ctrl::checkCursorLocation(int mouseX, int mouseY, bool player2IsHuman)
{
	for (int i = 0; i < buttons.size(); i++) {
		// Ja peles klikšķis bija uz pogas, nevis ārpus tās.
		if (sqrt(pow((mouseX - buttons.at(i)->getLocation().X), 2) + pow((mouseY - buttons.at(i)->getLocation().Y), 2)) <= buttons.at(i)->getSize() / 2) {

			// Noskaidro pašreizējo spēlētāju
			currentPlayerName = players.at(0)->getStatus() ? "Player1" : "Player2";

			// Noskaidro pašreizējo spēlētāju numuru
			int currentPlayerNumber = players.at(0)->getStatus() ? 1 : 2;
			// Izsauc writeMoveToFile, padodot informāciju par pašreizējo spēlētāju
			currentButtonID = buttons.at(i)->getID();
			if (player2IsHuman && currentPlayerNumber == 1) {
				int currentPlayer1ScoreBeforeMove = players.at(0)->getScore();
				int currentPlayer1ScoreAfterMove = currentPlayer1ScoreBeforeMove + buttons.at(i)->getPointsForCellsMerge();
				writeMoveToFile(currentPlayerName, currentButtonID, currentPlayer1ScoreBeforeMove, currentPlayer1ScoreAfterMove, AITimeTaken, AIAlgorithmNodesVisited, currentPlayerNumber);
			}
			else if (player2IsHuman && currentPlayerNumber == 2) {
				int currentPlayer2ScoreBeforeMove = players.at(1)->getScore();
				int currentPlayer2ScoreAfterMove = currentPlayer2ScoreBeforeMove + buttons.at(i)->getPointsForCellsMerge();
				writeMoveToFile(currentPlayerName, currentButtonID, currentPlayer2ScoreBeforeMove, currentPlayer2ScoreAfterMove, AITimeTaken, AIAlgorithmNodesVisited, currentPlayerNumber);
			}


			// Pogas noklikšķināšanas gadījumā notiek krāsas maiņa.
			// Krāsas maiņa nav aktivizēta.
			// Color col = Color::FromArgb(255, 0, 0);
			// buttons.at(i)->setColor(col.ToArgb());

			// Spēlētāju rezultātu mainīšana atkarībā no pogas punktiem.
			for (int j = 0; j < players.size(); j++)
			{
				if (players.at(j)->getStatus()) {
					players.at(j)->setScore(players.at(j)->getScore() + buttons.at(i)->getPointsForCellsMerge());
					break;
				}
			}

			// Šūnu pārkārtošana pēc pogas klikšķa.
			for (int j = i; j < cells.size() - 1; j++) {
				if (j == i) {
					// Jaunas šūnas vērtības noteikšana, balstoties uz apvienošanas summu.
					int localCellsMergeSum = cells.at(j)->getValue() + cells.at(j + 1)->getValue();
					if (localCellsMergeSum > 7) {
						localCellsMergeSum = 1;
					}
					else if (localCellsMergeSum < 7) {
						localCellsMergeSum = 3;
					}
					else {
						localCellsMergeSum = 2;
					}
					cells.at(j)->setValue(localCellsMergeSum);
				}
				else {
					cells.at(j)->setValue(cells.at(j + 1)->getValue());
				}
			}
			cells.erase(cells.end() - 1);
			// Pēdējās pogas dzēšana.
			buttons.erase(buttons.end() - 1);
			// Piešķiršana jaunām šūnām pogu ID.
			for (int j = 0; j < buttons.size(); j++) {
				buttons.at(j)->setCellsID(controlledCellsID{ j,j + 1 });
			}
			// Pārkalkulē pogu vērtības.
			recalculateButtonsValues();
			// Spēlētāju maiņa.
			for (int j = 0; j < players.size(); j++) {
				if (players.at(j)->getStatus()) {
					players.at(j)->setStatus(false);
				}
				else {
					players.at(j)->setStatus(true);
				}
			}
			this->cellCount = cells.size();
			this->buttonCount = buttons.size();
			if (players.at(1)->getStatus()) {
				// Sāk taimeri, lai noteiktu gājiena ilgumu
				startAI = clock();
			}
			break;
		}
	}
}

#pragma endregion
#pragma region Visual
// Šī funkcija aprēķina maksimālo iespējamo dalībnieku (spēlētāju un pogu) izmēru
float Ctrl::getMembersMaxSize()
{
	float maxH = controlAreaSize.H - 2;
	float maxW = (controlAreaSize.W - 2) / (cellCount + buttonCount);
	maxH = maxH <= maxW ? maxH : maxW;
	return maxH;
}

// Šī funkcija pārrēķina pogu vērtības, pamatojoties uz to piesaistītajām šūnām.
void Ctrl::recalculateButtonsValues()
{
	for (int i = 0; i < buttons.size(); i++) {
		int buttonValue{};
		// Noteiktās šūnas ID tiek izmantotas, lai iegūtu šo šūnu vērtības un aprēķinātu pogas vērtību.
		int cellValueSum = cells.at(buttons.at(i)->getCellsID().ID1)->getValue() + cells.at(buttons.at(i)->getCellsID().ID2)->getValue();

		// Nosaka pogas vērtību atkarībā no šūnu vērtību summas.
		if (cellValueSum > 7) {
			buttonValue = 1;
		}
		else if (cellValueSum < 7) {
			buttonValue = -1;
		}
		else {
			buttonValue = 2;
		}

		// Iestata jauno pogas vērtību, izmantojot setPointsForCellsMerge metodi.
		buttons.at(i)->setPointsForCellsMerge(buttonValue);
	}
}

// Šī funkcija ir atbildīga par visu kontroles elementu (šūnas un pogas) zīmēšanu uz norādītajas Graphics objektu.
void Ctrl::DrawControl(Graphics^ grp)
{
	// Iegūst jauno maksimālo dalībnieku (spēlētāju un pogu) izmēru.
	this->memberMaxSize = getMembersMaxSize();

	// Uzstāda zīmēšanas līnijas un plātnes krāsu.
	Pen pen(Color::Black, 2);
	SolidBrush brush(Color::Transparent);

	// Zīmē šūnas un pogas.
	for (int i = 0; i < cells.size(); i++) {
		// Iegūst šūnas atrašanās vietu un izmēru.
		location loc = cells.at(i)->getLocation();
		float size = cells.at(i)->getSize();

		// Zīmē taisnstūra kontūru un aizpilda to ar norādīto krāsu.
		grp->DrawRectangle(% pen, (float)loc.X - size / 2, (float)loc.Y - size / 2, memberMaxSize, memberMaxSize);
		brush.Color = Color::FromArgb(cells.at(i)->getColor());
		grp->FillRectangle(% brush, (float)loc.X - size / 2, (float)loc.Y - size / 2, memberMaxSize, memberMaxSize);

		// Zīmē šūnas vērtību tekstu.
		String^ str = cells.at(i)->getValue().ToString();
		Font drawFont("Arial", size / 2);
		brush.Color = Color::Black;
		grp->DrawString(str, % drawFont, % brush, (float)cells.at(i)->getLocation().X - drawFont.Size / 2, (float)cells.at(i)->getLocation().Y - drawFont.GetHeight() / 2);
	}

	// Zīmē pogas.
	for (int i = 0; i < buttons.size(); i++) {
		// Iegūst pogas atrašanās vietu un izmēru.
		location loc = buttons.at(i)->getLocation();
		float size = buttons.at(i)->getSize();

		// Zīmē elipses kontūru un aizpilda to ar norādīto krāsu.
		grp->DrawEllipse(% pen, (float)loc.X - size / 2, (float)loc.Y - size / 2, memberMaxSize * btnSizeKoef, memberMaxSize * btnSizeKoef);
		brush.Color = Color::FromArgb(buttons.at(i)->getColor());
		grp->FillEllipse(% brush, (float)loc.X - size / 2, (float)loc.Y - size / 2, memberMaxSize * btnSizeKoef, memberMaxSize * btnSizeKoef);

		// Zīmē pogas vērtību tekstu.
		//String^ str = buttons.at(i)->getPointsForCellsMerge().ToString();
		//Font drawFont("Arial", size / 2);
		//brush.Color = Color::Black;
		//grp->DrawString(str, % drawFont, % brush, (float)buttons.at(i)->getLocation().X - drawFont.Size / 2, (float)buttons.at(i)->getLocation().Y - drawFont.GetHeight() / 2);
	}
}


// Šī funkcija zīmē spēlētāja 1 statusa indikatoru uz norādītajā Graphics objekta.
void Ctrl::DrawPlayer1Status(Graphics^ grp, float grpW, float grpH)
{
	// Uzstāda zīmēšanas līnijas un plātnes krāsu.
	Pen pen(Color::Black, 2);
	SolidBrush brush(Color::Transparent);

	// Nosaka spēlētāja 1 stāvokli un atbilstoši tam izvēlas krāsu.
	if (players.at(0)->getStatus()) {
		brush.Color = Color::FromArgb(0, 200, 0);
	}
	else {
		brush.Color = Color::FromArgb(200, 0, 0);
	}

	// Zīmē apli ar izvēlēto krāsu, lai parādītu spēlētāja 1 stāvokli.
	grp->DrawEllipse(% pen, grpW - playerIndicatorSize - pen.Width, float(0), playerIndicatorSize, playerIndicatorSize);
	grp->FillEllipse(% brush, grpW - playerIndicatorSize - pen.Width, float(0), playerIndicatorSize, playerIndicatorSize);
}

// Šī funkcija zīmē spēlētāja 2 statusa indikatoru uz norādītajā Graphics objekta.
void Ctrl::DrawPlayer2Status(Graphics^ grp, float grpW, float grpH)
{
	// Uzstāda zīmēšanas līnijas un plātnes krāsu.
	Pen pen(Color::Black, 2);
	SolidBrush brush(Color::Transparent);

	// Nosaka spēlētāja 2 stāvokli un atbilstoši tam izvēlas krāsu.
	if (players.at(1)->getStatus()) {
		brush.Color = Color::FromArgb(0, 200, 0);
	}
	else {
		brush.Color = Color::FromArgb(200, 0, 0);
	}

	// Zīmē apli ar izvēlēto krāsu, lai parādītu spēlētāja 2 stāvokli.
	grp->DrawEllipse(% pen, grpW - playerIndicatorSize - pen.Width, float(0), playerIndicatorSize, playerIndicatorSize);
	grp->FillEllipse(% brush, grpW - playerIndicatorSize - pen.Width, float(0), playerIndicatorSize, playerIndicatorSize);
}


// Šī funkcija pārrēķina elementu izmērus un atrašanās vietas atbilstoši norādītajiem kontrolējamā laukuma izmēriem.
void Ctrl::RecalculateSizes(int controlAreaWidth, int controlAreaHeight)
{
	// Atjauno kontrolējamā laukuma izmērus.
	controlAreaSize.W = controlAreaWidth;
	controlAreaSize.H = controlAreaHeight;

	// Aprēķina jauno maksimālo dalībnieku (spēlētāju un pogu) izmēru.
	memberMaxSize = getMembersMaxSize();

	// Izveido atrašanās vietu (kursoru) elementiem.
	location cursor{ 0,0 };

	// Atjaunina šūnu izmērus un atrašanās vietas.
	cursor.X = controlAreaSize.W / 2 - (memberMaxSize * (cellCount + buttonCount)) / 2 + memberMaxSize / 2;
	cursor.Y = controlAreaSize.H / 2;
	for (int i = 0; i < cells.size(); i++) {
		cells.at(i)->setSize(memberMaxSize);
		cells.at(i)->setLocation(cursor.X, cursor.Y);
		cursor.X += memberMaxSize * 2;
	}

	// Atjaunina pogu izmērus un atrašanās vietas.
	cursor.X = controlAreaSize.W / 2 - (memberMaxSize * (cellCount + buttonCount)) / 2 + memberMaxSize / 2 + memberMaxSize;
	cursor.Y = controlAreaSize.H / 2;
	for (int i = 0; i < buttons.size(); i++) {
		buttons.at(i)->setSize(memberMaxSize * btnSizeKoef);
		buttons.at(i)->setLocation(cursor.X, cursor.Y);
		cursor.X += memberMaxSize * 2;
	}
}
// Šī funkcija aprēķina minimālo kontroles laukuma platumu, ņemot vērā šūnas un pogas skaitu un minimālo šūnas izmēru.
float Ctrl::GetControlAreaMinWidth()
{
	return (float)(cellCount + buttonCount) * memberMinSize;
}

#pragma endregion
#pragma region Tree
// Šī funkcija ir atbildīga par lēmumu koka izveidi datora gājiena algoritmā.
// Tā sākumā notīra esošo lēmumu koku, tad sagatavo sākotnējās datu vērtības no pašreizējām šūnām.
// Pēc tam tā izsauc funkciju, lai pievienotu mezglus lēmumu koka struktūrai, izmantojot rekursiju.
void Ctrl::createDecisionTree()
{
	// Notīra esošo lēmumu koku.
	decisionTree->deleteTree(decisionTree);

	// Sagatavo sākotnējās datu vērtības no pašreizējām šūnām.
	vector<int> startData;
	for (int i = 0; i < cells.size(); i++) {
		startData.push_back(cells.at(i)->getValue());
	}

	// Iestata sākotnējās datu vērtības un spēlētāju rezultātus lēmumu koka saknē.
	decisionTree->setData(startData);
	decisionTree->setPlayer1Score(getPlayerScore(0));
	decisionTree->setPlayer2Score(getPlayerScore(1));

	// Izsauc funkciju, lai pievienotu mezglus lēmumu koka struktūrai, izmantojot rekursiju.
	decisionTree = addNode(decisionTree, startData, getPlayerScore(0), getPlayerScore(1), 0, AIVisionStrength, true);
}


// Šī funkcija ir atbildīga par jauna mezgla pievienošanu lēmumu koka struktūrai.
// Tā veido jaunus mezglus, analizējot esošo datu vektoru un spēlētāju rezultātus.
// Katrs jaunais mezgls tiek pievienots kā priekštecējs mezgls.
// Rekursīvi tiek izveidoti visi iespējamie turpmākie gājieni, līdz sasniegts maksimālais dziļums vai ir palicis viens vai mazāk elementu datu vektorā.
// Kad izveidoti visi iespējamie gājieni, funkcija atgriež priekštecējo mezglu.
DecisionTreeNode* Ctrl::addNode(DecisionTreeNode* parent, vector<int> data, int player1Score, int player2Score, int depth, int max_depth, bool AIMakingMoveTime) {
	if (depth > max_depth || data.size() <= 1) {
		return parent;
	}
	int newPlayer1Score = player1Score, newPlayer2Score = player2Score;
	for (int i = 0; i < data.size() - 1; i++) {
		vector<int> childData;
		int chosenButtonID = -1;
		for (int j = 0; j < data.size() - 1; j++) {
			if (i == j) {
				chosenButtonID = i;
				if (data.at(j) + data.at(j + 1) > 7) {
					childData.push_back(1);
					if (AIMakingMoveTime) {
						newPlayer2Score = player2Score + 1;
					}
					else {
						newPlayer1Score = player1Score + 1;
					}
				}
				else if (data.at(j) + data.at(j + 1) == 7) {
					childData.push_back(2);
					if (AIMakingMoveTime) {
						newPlayer2Score = player2Score + 2;
					}
					else {
						newPlayer1Score = player1Score + 2;
					}
				}
				else if (data.at(j) + data.at(j + 1) < 7) {
					childData.push_back(3);
					if (AIMakingMoveTime) {
						newPlayer2Score = player2Score - 1;
					}
					else {
						newPlayer1Score = player1Score - 1;
					}
				}
				j++;
			}
			else {
				if (j < data.size() - 1) {
					childData.push_back(data.at(j));
				}
			}
			if (j == data.size() - 2) {
				childData.push_back(data.at(data.size() - 1));
			}
		}
		if (childData.size() < data.size()) {
			DecisionTreeNode* child = new DecisionTreeNode;
			child->setData(childData);
			child->setChosenButtonID(chosenButtonID);
			child->setPlayer1Score(newPlayer1Score);
			child->setPlayer2Score(newPlayer2Score);
			parent->addChild(child);
			bool AIMoveNextTime = AIMakingMoveTime ? false : true;
			addNode(child, childData, newPlayer1Score, newPlayer2Score, depth + 1, max_depth, AIMoveNextTime);
		}
	}
	return parent;
}

#pragma endregion
#pragma region AI
// Šī funkcija uzstāda Māksimālo redzamības dziļumu (AIVisionStrength) uz norādīto vērtību.
void Ctrl::setAIVisionStrength(int VisionStrength)
{
	AIVisionStrength = VisionStrength;
}

// Šī funkcija atgriež Māksimālo redzamības dziļumu (AIVisionStrength).
int Ctrl::getAIVisionStrength()
{
	return AIVisionStrength;
}


// Šī funkcija veic heuristisko novērtējumu, lai noteiktu mezgla vērtību lēmumu koka algoritmā.
// Tā atjauno pogu vērtības, iegūst spēlētāju pašreizējās punktu vērtības un nosaka mezgla vērtību, ņemot vērā pogu vērtības.
int Ctrl::CellHNF() {
	// Atjauno pogu vērtības, izmantojot funkciju recalculateButtonsValues().
	recalculateButtonsValues();

	// Skaita pogas ar atšķirīgām vērtībām.
	int numButtonsGiving1 = 0;
	int numButtonsGivingMinus1 = 0;
	int numButtonsGiving2 = 0;

	for (int i = 0; i < buttons.size(); ++i) {
		int buttonValue = buttons[i]->getPointsForCellsMerge();
		if (buttonValue == 1) {
			numButtonsGiving1++;
		}
		else if (buttonValue == -1) {
			numButtonsGivingMinus1++;
		}
		else if (buttonValue == 2) {
			numButtonsGiving2++;
		}
	}

	// Ja ir pogas ar vērtību 2, atgriež 2.
	if (numButtonsGiving2 > 0) {
		return 2;
	}
	// Ja pogu ar vērtību 1 ir vairāk nekā ar vērtību -1, atgriež 1.
	else if (numButtonsGiving1 > numButtonsGivingMinus1) {
		return 1;
	}
	// Ja pogu ar vērtību -1 ir vairāk nekā ar vērtību 1, atgriež -1.
	else if (numButtonsGiving1 < numButtonsGivingMinus1) {
		return -1;
	}
	// Ja pogas ar vērtību 1 un -1 ir vienāds skaits, atgriež 0.
	else {
		return 0;
	}
}

// Šī funkcija veic MiniMax algoritmu, lai noteiktu labāko gājiena vērtību spēles koka lēmumu mezglos.
// Tas izmanto rekursīvu pieeju, lai izvērtētu visus iespējamos gājienus un atrastu optimālo gājienu.
int Ctrl::MiniMax(DecisionTreeNode* node, int player1Score, int player2Score, int depth, int max_depth, bool maximizingPlayer) {

	MiniMaxNodesVisited++;

	// Ja sasniegts maksimālais dziļums vai nav pecteču vai neviena, atgriež šūnas vērtību, izmantojot CellHNF funkciju.
	if (depth == max_depth || node->getChildsCount() == 0) {
		return CellHNF();
	}

	if (maximizingPlayer) {
		int maxEval = INT_MIN;
		// Pārskata visus šūnas pectečus un atrod maksimālo vērtību, izsaucot rekursīvi MiniMax funkciju.
		for (int j = 0; j < node->getChildsCount(); j++) {
			DecisionTreeNode* child = node->getChild(j);
			if (child) {
				int eval = MiniMax(child, child->getPlayer1Score(), child->getPlayer2Score(), depth + 1, max_depth, false);
				maxEval = max(maxEval, eval);
			}
		}
		return maxEval;
	}
	else {
		int minEval = INT_MAX;
		// Pārskata visus šūnas pectečus un atrod minimālo vērtību, izsaucot rekursīvi MiniMax funkciju.
		for (int j = 0; j < node->getChildsCount(); j++) {
			DecisionTreeNode* child = node->getChild(j);
			if (child) {
				int eval = MiniMax(child, child->getPlayer1Score(), child->getPlayer2Score(), depth + 1, max_depth, true);
				minEval = min(minEval, eval);
			}
		}
		return minEval;
	}
}

// Šī funkcija veic alfa-beta algoritmu, lai noteiktu labāko gājiena vērtību spēles koka lēmumu mezglos.
// Tas izmanto rekursīvu pieeju, lai izvērtētu visus iespējamos gājienus un atrastu optimālo gājienu.
int Ctrl::AlphaBeta(DecisionTreeNode* node, int player1Score, int player2Score, int depth, int max_depth, int alpha, int beta, bool maximizingPlayer) {
	AlphaBetaNodesVisited++;

	// Ja sasniegts maksimālais dziļums vai nav pecteču vai neviena, atgriež šūnas vērtību, izmantojot CellHNF funkciju.
	if (depth == max_depth || node->getChildsCount() == 0) {
		return CellHNF();
	}

	if (maximizingPlayer) {
		int maxEval = INT_MIN;
		// Pārskata visus šūnas pectečus un atrod maksimālo vērtību, izsaucot rekursīvi AlphaBeta funkciju.
		for (int j = 0; j < node->getChildsCount(); j++) {
			DecisionTreeNode* child = node->getChild(j);
			if (child) {
				int eval = AlphaBeta(child, child->getPlayer1Score(), child->getPlayer2Score(), depth + 1, max_depth, alpha, beta, false);
				maxEval = max(maxEval, eval);
				alpha = max(alpha, eval);
				if (beta >= alpha) break; // Cuts off the search if beta >= alpha, hence beta cutoff
			}
		}
		return maxEval;
	}
	else {
		int minEval = INT_MAX;
		// Pārskata visus šūnas pectečus un atrod minimālo vērtību, izsaucot rekursīvi AlphaBeta funkciju.
		for (int j = 0; j < node->getChildsCount(); j++) {
			DecisionTreeNode* child = node->getChild(j);
			if (child) {
				int eval = AlphaBeta(child, child->getPlayer1Score(), child->getPlayer2Score(), depth + 1, max_depth, alpha, beta, true);
				minEval = min(minEval, eval);
				beta = min(beta, eval);
				if (beta <= alpha) break; // Cuts off the search if beta <= alpha, hence alpha cutoff
			}
		}
		return minEval;
	}
}


// Šī funkcija ir atbildīga par datora gājiena veikšanu spēles laukumā, izmantojot datora inteliģences algoritmu.
// Tā iegūst informāciju par datora redzes spēku (cik dziļi skatīties nākotnē) un izmanto algoritmu, lai noteiktu labāko gājiena variantu.
void Ctrl::makeAIMove(bool AIAlgorithmMiniMax, int AIVisionStrength) {
	startAI = clock();
	// Iestata karodziņu, ka tagad dators veic gājienu
	isAIPlayerTurn = true;


	// Iestata redzes spēku AI
	this->AIVisionStrength = AIVisionStrength - 1;

	// Skaitītājs apmeklēto algoritma mezglu skaitam
	AIAlgorithmNodesVisited = 0;

	// Pārbauda, vai šobrīd dators veic gājienu
	if (getmakingMoveStatus(1)) {
		// Izveido lēmumu koka struktūru
		createDecisionTree();

		// Izvēlas labāko gājiena variantu, izmantojot MiniMax vai AlphaBeta algoritmu
		int bestButtonID = chooseBestMove(AIAlgorithmMiniMax, AIVisionStrength);

		// Pabeidz taimeri
		endAI = clock();
		AITimeTaken = double(endAI - startAI) / CLOCKS_PER_SEC * 1000;
		writeMoveToFile("AI", bestButtonID, players.at(1)->getScore(), players.at(1)->getScore() + buttons.at(bestButtonID)->getPointsForCellsMerge(), AITimeTaken, AIAlgorithmNodesVisited, 2);
		// Ja atrasts piemērots gājiens, to izpilda
		if (bestButtonID != -1) {
			executeMove(bestButtonID);
		}
	}
}


// Šī funkcija izvēlas labāko gājiena variantu, izmantojot MiniMax vai AlphaBeta algoritmu, atkarībā no norādītās izvēles.
// Pēc tam meklē vislabāko iespējamo gājiena vērtību un atgriež atbilstošo pogas identifikatoru.
int Ctrl::chooseBestMove(bool AIAlgorithmMiniMax, int AIVisionStrength) {
	// Izvēlas labāko gājiena variantu, izmantojot MiniMax vai AlphaBeta algoritmu
	int bestScore = AIAlgorithmMiniMax ? MiniMax(decisionTree, getPlayerScore(0), getPlayerScore(1), 0, AIVisionStrength, true) :
		AlphaBeta(decisionTree, getPlayerScore(0), getPlayerScore(1), 0, AIVisionStrength, INT_MIN, INT_MAX, true);

	AIAlgorithmNodesVisited = AIAlgorithmMiniMax ? MiniMaxNodesVisited : AlphaBetaNodesVisited;

	// Inicializē mainīgos labākā gājiena informācijas saglabāšanai
	int bestButtonID = -1;
	int currentBestValue = INT_MIN;

	// Pārskata pieejamās pogas un izvēlas labāko gājienu
	for (int i = 0; i < buttons.size(); i++) {
		int buttonValue = buttons.at(i)->getPointsForCellsMerge();
		if (buttonValue >= bestScore && (buttonValue >= currentBestValue || bestButtonID == -1)) {
			currentBestValue = buttonValue;
			bestButtonID = i;
		}
	}

	return bestButtonID;
}


// Šī funkcija izpilda gājienu, norādot pogas identifikatoru.
// Saņemot pogas identifikatoru, funkcija iegūst attiecīgās pogas koordinātas un pēc tam veic gājienu.
void Ctrl::executeMove(int buttonID) {
	// Iegūst pogas koordinātas
	int buttonX = buttons.at(buttonID)->getLocation().X;
	int buttonY = buttons.at(buttonID)->getLocation().Y;

	// Veic gājienu
	checkCursorLocation(buttonX, buttonY, false);
}

#pragma endregion
#pragma region FileResult
// Šī funkcija ieraksta informāciju par veikto gājienu failā "round_results.txt".
// Tā iegūst spēlētāja vārdu, pogas identifikatoru, rezultātu pirms un pēc gājiena, laiku, ko pavada AI, apmeklētos AI algoritma mezglus un pašreizējās šūnu vērtības.
void Ctrl::writeMoveToFile(const std::string& playerName, int buttonID, int scoreBeforeMove, int scoreAfterMove, int AITime, int AIAlgorithmNodesVisited, int currentPlayerNumber) {
	std::ofstream file("round_results.txt", std::ios_base::app); // Atveram failu, lai pievienotu datus
	if (file.is_open()) {
		file << "" << std::endl;
		// Ierakstam informāciju par gājienu failā
		file << "Move made by " << playerName << std::endl;
		file << "Score " << playerName << ": ";
		// Ierakstām iepriekšējo un jauno spēlētāja rezultātu
		file << scoreBeforeMove << " -> " << scoreAfterMove << std::endl;
		file << "Button ID chosen: " << buttonID << std::endl;

		// Saņemam šūnu vērtības šai pogai
		int cellValue1 = cells.at(buttonID)->getValue();
		int cellValue2 = cells.at(buttonID + 1)->getValue();

		// Ierakstām šūnu vērtības failā
		file << "Cell values: " << cellValue1 << "+" << cellValue2 << std::endl;

		if (currentPlayerNumber == 2 && isAIPlayerTurn) {
			file << "Time taken by AI: " << AITime << std::endl;
			file << "AI Algorithm Nodes Visited: " << AIAlgorithmNodesVisited << std::endl;
		}
		// Ierakstām pašreizējo šūnu vērtību virkni
		file << "Current cell values: ";
		for (int i = 0; i < cells.size(); ++i) {
			file << cells[i]->getValue() << " ";
		}
		file << std::endl;
		file.close(); // Aizveram failu
	}
}

// Šī funkcija papildina Ctrl klasi ar funkciju, kas notīra informāciju par gājieniem.
void Ctrl::clearRoundMovesFile() {
	ofstream file("round_results.txt", ios::trunc); // Atver failu rakstīšanas režīmā, notīra esošo saturu
	if (file.is_open()) {
		file.close();
	}
}

// Šī funkcija ieraksta kārtas rezultātus failā "round_results.txt".
// Tā saņem spēlētāju vārdus, AI algoritma veidu, redzes stiprumu, spēlētāju rezultātus un ieraksta tos failā.
void Ctrl::writeRoundResultsToFile(const std::string& player1Name, const std::string& player2Name, bool AIAlgorithmMiniMax, int AIVisionStrength, int player1Score, int player2Score) {
	std::ofstream file("round_results.txt", std::ios::app); // Atdalītājs starp gājieniem un rezultātiem
	if (file.is_open()) {
		file << "---------------------------------------------" << std::endl; // Atdalītājs starp gājieniem un rezultātiem
		file << "Player 1: " << player1Name << ", Score: " << player1Score << std::endl;

		if (isAIPlayerTurn) {
			file << "Player 2: AI, Score: " << player2Score << std::endl;
			file << "AI Algorithm: " << (AIAlgorithmMiniMax ? "MiniMax" : "AlphaBeta") << std::endl;
			file << "AI Vision Strength: " << AIVisionStrength << std::endl;
		}
		else {
			// Ja otrs spēlētājs nav AI, ierakstām viņa vārdu
			file << "Player 2: " << player2Name << ", Score: " << player2Score << std::endl;
		}

		// Noteiksim uzvarētāju
		std::string winner = (player1Score > player2Score) ? player1Name : ((player1Score < player2Score) ? player2Name : "Draw");
		file << "Winner: " << winner << std::endl;

		// Ierakstām oriģinālo skaitļu virkni
		file << "Original cell values: ";
		for (int i = 0; i < originalCellValues.size(); ++i) {
			file << originalCellValues[i] << " ";
		}
		file << std::endl;

		file.close(); // Aizveram failu
	}
}
#pragma endregion