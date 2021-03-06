#pragma once
#include "decorator.h"

class SkinDecorator :
	public Decorator
{
public:
	SkinDecorator(void);
	virtual ~SkinDecorator(void);

	virtual void DrawButtonBackground(short int x, short int y, short int w, short int h, bool bSel);
	virtual void DrawDialogFrame(short int x, short int y, short int w, short int h);
	virtual void PrintText(short int x, short int y, short int maxX, const char* text, byte fontSize, colorSets whichColors);
	virtual void DrawProgress(short int x, short int y, short int w, short int h, short int percent);
	virtual void PrintTextLeft(short int x, short int y, short int maxX, const char* text, byte fontSize, colorSets whichArea);
	virtual void DrawColoredButon(short int x, short int y, short int w, short int h, word fillColor);
	virtual void DrawInfoFrame(short int  x, short int  y, short int  w, short int  h);

private:

	void DrawCorner(short int x, short int y, word colour, byte direction);
};
