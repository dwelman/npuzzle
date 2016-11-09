#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <ctime>
#include <sys/time.h>
#include <chrono>
#include <cmath>
#include <regex>
#include <Node.class.h>

using namespace std;

//TOOP - Tiles out of place
enum Heuristic
{
	MANHATTAN = 1,
	EUCLIDIAN,
	TOOP
};

static Heuristic	usedHeuristic;

vector<string>	readFile(string fileName);

Node			*makeInitialNode(vector<string> fileContents, int heuristic);

Node			*makeFinalNode(int size, int h);

void			solveLoop(Node *initialNode, Node *finalNode);

Node			*generateRandomPuzzle(int heuristic);