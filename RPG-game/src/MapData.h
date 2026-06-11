#pragma once
#include <string>

struct MapData {
	int version;

	std::string tilesheet = "";
	std::string name = "";

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleX = 0;
	int scaleY = 0;

	int mapWidth = 0;
	int mapHeight = 0;

	int dataLength = 6;
	int* data = nullptr;
};