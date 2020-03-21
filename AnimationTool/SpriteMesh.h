#pragma once
#include "Sprite.h"
#include <vector>


	struct [[nodiscard]] SpriteMesh
	{
		const char* name;
		int nSprites;
		std::vector<Sprite> sprites;
	};
