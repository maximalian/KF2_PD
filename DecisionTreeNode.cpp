#include "DecisionTreeNode.h"

int DecisionTreeNode::getPlayer1Score()
{
	return player1Score;
}
int DecisionTreeNode::getPlayer2Score()
{
	return player2Score;
}

vector<int> DecisionTreeNode::getData()
{
	return data;
}

void DecisionTreeNode::setPlayer1Score(int score)
{
	this->player1Score = score;
}

void DecisionTreeNode::setPlayer2Score(int score)
{
	this->player2Score = score;
}


int DecisionTreeNode::getChosenButtonID()
{
	return chosenButtonID;
}

void DecisionTreeNode::setChosenButtonID(int ID)
{
	chosenButtonID = ID;
}

void DecisionTreeNode::setData(vector<int> newData)
{
	if (data.size()>0) {
		data.clear();
	}
	for (int i = 0;i<newData.size();i++) {
		data.push_back(newData.at(i));
	}
}

int DecisionTreeNode::getChildsCount()
{
	return childs.size();
}

void DecisionTreeNode::addChild(DecisionTreeNode* newChild)
{
	childs.push_back(newChild);
}

DecisionTreeNode* DecisionTreeNode::getChild(int ID)
{
	return childs.at(ID);
}

void DecisionTreeNode::deleteTree(DecisionTreeNode* tree)
{
	if (tree == nullptr) return;
	for (int i = 0;i<tree->getChildsCount();i++) {
		if (tree->getChild(i)) {
			deleteTree(tree->getChild(i));
		}
	}
	tree->childs.clear();
	tree = nullptr;
	
}

bool DecisionTreeNode::hasChilds() {
	return !childs.empty();
}

DecisionTreeNode::~DecisionTreeNode()
{
}
