// Helper classes for RGO shuffle.

#ifndef BUCKET_H
#define BUCKET_H

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "../V2Province.h"

#include "newParser.h"

class Bucket : commonItems::parser
{
public:
	Bucket(std::istream& theStream);
	bool match(const std::string& provClimate, const std::string& provTerrain);
	void shuffle(std::default_random_engine& shuffler);
	void addProvince(V2Province* prov) { provinces.push_back(prov); };

private:
	std::string name;
	std::vector<std::string> climates = {};
	std::vector<std::string> terrains = {};
	double fraction = 0.0;
	bool wildClimate = false;
	bool wildTerrain = false;
	std::vector<V2Province*> provinces;
};

#endif // BUCKET_H
