#pragma once
#include "Sprite.h"
#include <vector>


	struct [[nodiscard]] SpriteMesh
	{
        QString name;
		int nSprites;
		std::vector<Sprite> sprites;
	};


//    void LoadSpriteMesh(QTextStream& stream,SpriteMesh& spriteMesh);

//    void SaveSpriteMesh(QTextStream& stream,SpriteMesh& spriteMesh);
