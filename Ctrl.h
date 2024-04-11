#pragma once
#include "Buttn.h"
#include "Member.h"
#include "Player.h"
#include "Cell.h"
#include <vector>
#include <fstream>
#include "DecisionTreeNode.h"
#include <msclr/marshal_cppstd.h>
#include <ctime>

using namespace System::Drawing;
using namespace System;
using System::String;

using std::vector;

class Ctrl
{
private:
	vector<Player*> players; // Spēlētāju vektors.
	vector<Buttn*> buttons; // Pogu vektors.
	vector<Cell*> cells; // Šūnu vektors.
	int cellCount; // Šūnu skaits.
	int buttonCount; // Pogu skaits.
	float memberMaxSize; // Maksimālais biedra izmērs.
	float memberMinSize; // Minimālais biedra izmērs.
	elementSize controlAreaSize; // Kontroles laukuma izmēri.
	elementSize buttonSize; // Pogas izmēri.
	elementSize cellSize; // Šūnas izmēri.
	float getMembersMaxSize(); // Funkcija, kas aprēķina maksimālo biedra izmēru.
	float btnSizeKoef; // Pogu izmēra koeficients.
	float playerIndicatorSize = 0; // Spēlētāja indikatora izmērs.
	bool playerWin = false; // Būleanais mainīgais, kas norāda, vai spēlētājs ir uzvarējis.
	int AIVisionStrength = 3; // Mākslīgā intelekta redzes spēks.
	string currentPlayerName; // Spēlētāja vārds, kurš veic gājienu.
	int currentButtonID{}; // ID poga, kas tika noklikšķināta.
	int AIAlgorithmNodesVisited; // Apmeklētie mezgli algoritma darbības laikā.
	int MiniMaxNodesVisited = 0; // Apmeklētie mezgli Minimax algoritma darbības laikā.
	int AlphaBetaNodesVisited = 0; // Apmeklētie mezgli AlphaBeta algoritma darbības laikā.
	clock_t startAI{}, endAI{}; // Laika indikatori algoritma darbības laikam.
	int AITimeTaken{}; // Laiks, kas pavadīts ar datora.
	std::vector<int> originalCellValues; // Sākotnējie šūnu vērtību dati.
	bool isAIPlayerTurn = false; // Būleanais mainīgais, kas norāda, vai tagad ir datora gājiens.

public:
	//----
	Ctrl(int controlAreaWidth, int controlAreaHeight, int cellsCount, float btnSizeKoef, float cellMinSize); // Konstruktors ar parametriem.
	Ctrl(); // Noklusētais konstruktors.
	~Ctrl(); // Destruktors.
	//----
	void DrawControl(Graphics^ grp); // Funkcija, kas zīmē vadības elementus.
	void DrawPlayer1Status(Graphics^ grp, float grpW, float grpH); // Funkcija, kas zīmē spēlētāja 1 statusu.
	void DrawPlayer2Status(Graphics^ grp, float grpW, float grpH); // Funkcija, kas zīmē spēlētāja 2 statusu.
	void RecalculateSizes(int controlAreaWidth, int controlAreaHeight); // Funkcija, kas pārskaita izmērus.
	float GetControlAreaMinWidth(); // Funkcija, kas atgriež minimālo kontroles laukuma platumu.
	void checkCursorLocation(int mouseX, int mouseY, bool player2IsHuman); // Funkcija, kas pārbauda kursora atrašanās vietu.
	int getPlayerScore(int playerID); // Funkcija, kas atgriež spēlētāja rezultātu.
	void setPlayerScore(int playerID, int score); // Funkcija, kas iestata spēlētāja rezultātu.
	bool getmakingMoveStatus(int playerID); // Funkcija, kas atgriež informāciju par gājiena veikšanas statusu.
	void setMakingMoveStatus(int playerID, bool isMakingMove); // Funkcija, kas iestata gājiena veikšanas statusu.
	float getPlayerIndicatorSize(); // Funkcija, kas atgriež spēlētāja indikatora izmēru.
	void setPlayerIndicatorSize(float newSize); // Funkcija, kas iestata spēlētāja indikatora izmēru.
	bool playerHasWin(); // Funkcija, kas nosaka, vai spēlētājam ir uzvara.
	int getButtonsCount(); // Funkcija, kas atgriež pogu skaitu.
	void recalculateButtonsValues(); // Funkcija, kas pārrēķina pogu vērtības.
	//-----
	void createDecisionTree(); // Funkcija, kas veido lēmumu koku.
	DecisionTreeNode* Ctrl::addNode(DecisionTreeNode* parent, vector<int> data, int player1Score, int player2Score, int depth, int max_depth, bool AIMakingMoveTime); // Funkcija, kas pievieno mezglu lēmumu koka struktūrā.
	DecisionTreeNode* decisionTree = new DecisionTreeNode; // Lēmumu koka saknes mezgls.
	//-----
	void setAIVisionStrength(int VisionStrength); // Funkcija, kas iestata mākslīgā intelekta redzes spēku.
	int getAIVisionStrength(); // Funkcija, kas atgriež mākslīgā intelekta redzes spēku.
	int MiniMax(DecisionTreeNode* node, int player1Score, int player2Score, int depth, int max_depth, bool maximizingPlayer); // Šī funkcija veic Minimax algoritmu, lai noteiktu labāko gājienu, izmantojot dotā mezgla informāciju.
	int AlphaBeta(DecisionTreeNode* node, int player1Score, int player2Score, int depth, int max_depth, int alpha, int beta, bool maximizingPlayer);
	int CellHNF(); // Šī funkcija aprēķina heuristisko novērtējuma funkciju, pamatojoties uz dotā mezgla informāciju.
	void makeAIMove(bool AIAlgorithmMiniMax, int AIVisionStrength); // Funkcija, kas veic datora gājienu, izmantojot inteliģences algoritmu.
	int chooseBestMove(bool AIAlgorithmMiniMax, int AIVisionStrength); // Funkcija, kas izvēlas labāko gājiena variantu datoram, pamatojoties uz norādīto inteliģences algoritmu un redzes spēku.
	void executeMove(int buttonID); // Funkcija, kas veic gājienu, izmantojot norādīto pogas ID.
	//-----
	void writeRoundResultsToFile(const std::string& player1Name, const std::string& player2Name, bool AIAlgorithmMiniMax, int AIVisionStrength, int player1Score, int player2Score); // Funkcija, kas ieraksta kārtas rezultātus failā, norādot spēlētāju vārdus, izmantoto inteliģences algoritmu, redzes spēku un rezultātus.
	void writeMoveToFile(const std::string& playerName, int buttonID, int scoreBeforeMove, int scoreAfterMove, int AITime, int AIAlgorithmNodesVisited, int currentPlayerNumber); // Funkcija, kas ieraksta gājiena datus failā, norādot spēlētāja vārdu, pogas ID, rezultātu pirms un pēc gājiena, laiku, kāds tika patērēts datoram, apmeklēto mezglu skaitu inteliģences algoritmu procesā un pašreizējo spēlētāja numuru.
	void clearRoundMovesFile(); // Funkcija, kas notīra informāciju par gājieniem failā.
};