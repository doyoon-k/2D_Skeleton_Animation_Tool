#include "SpriteMesh.h"
#include <QTextStream>

void LoadSpriteMesh(QTextStream& stream,SpriteMesh& spriteMesh)
{
    stream>>spriteMesh.nSprites;
    stream>>spriteMesh.name;
    spriteMesh.sprites.resize(spriteMesh.nSprites);
    for(int i = 0; i < spriteMesh.nSprites; i++)
    {
        LoadSprite(stream,spriteMesh.sprites[i]);
    }
}

void SaveSpriteMesh(QTextStream& stream,SpriteMesh& spriteMesh)
{
    stream<<spriteMesh.nSprites<<endl;
    stream<<spriteMesh.name<<endl;
    for(int i = 0; i < spriteMesh.nSprites; i++)
    {
        SaveSprite(stream,spriteMesh.sprites[i]);
    }
}
