/*
Dijkstras class declaration.
All members give NPC's capability of pathfinding; this is nested in NonPlayableCharacter class.
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> 
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>

class Dijkstras
{
public:

	double max_weight; 

	struct neighbor {
		int target;
		double weight;
		neighbor(int arg_target, double arg_weight) : target(arg_target), weight(arg_weight) { }
	};
	 
	Dijkstras();

	void DijkstraComputePaths(int, const std::vector<std::vector<neighbor> >&, std::vector<double>&, std::vector<int>&);

	std::list<int> DijkstraGetShortestPathTo(int, const std::vector<int>&);
};