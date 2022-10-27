#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H


#include "Render.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;



class TextRenderer
{
public:
	TextRenderer();
	~TextRenderer();
	
	static FT_Library ft;
	static FT_Face face;
	static FT_GlyphSlot g;
	static GLint uniform_tex;
	static GLint attribute_coord;
	static void init();
	static void renderText(const char*, float, float, float, float);
	
};