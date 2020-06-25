#include "AnimationClip.h"
#include <QTextStream>

QTextStream& operator>>(QTextStream &stream, bool &b)
{
  char value;
  stream >> value;
  b = (value == '1');
  return stream;
}

QTextStream& operator<<(QTextStream &stream, bool &b)
{
  char value = b? '1' : '0';
  stream << value;
  return stream;
}

void LoadAnimationClip(QTextStream& stream,AnimationClip& animClip)
{
    stream>>animClip.name;
    stream>>animClip.isLooping;
    stream>>animClip.nRepetition;
    stream>>animClip.playTime;
    stream>>animClip.playRate;
    stream>>animClip.nAnimSamples;
    animClip.animSamples.reserve(animClip.nAnimSamples);
    for(int i = 0; i < animClip.nAnimSamples; i++)
    {
        LoadAnimSample(stream,animClip.animSamples[i]);
    }
}

void SaveAnimationClip(QTextStream& stream,AnimationClip& animClip)
{
     stream<<animClip.name<<endl;
     stream<<animClip.isLooping<<endl;
     stream<<animClip.nRepetition<<endl;
     stream<<animClip.playTime<<endl;
     stream<<animClip.playRate<<endl;
     stream<<animClip.nAnimSamples<<endl;
     for(int i = 0; i < animClip.nAnimSamples; i++)
     {
         SaveAnimSample(stream,animClip.animSamples[i]);
     }
}
