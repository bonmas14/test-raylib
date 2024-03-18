/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Logo Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

static int logoPositionX = 0;
static int logoPositionY = 0;

static int lettersCount = 0;

static int state = 0;              // Logo animation states
static float alpha = 1.0f;         // Useful for fading

//----------------------------------------------------------------------------------
// Logo Screen Functions Definition
//----------------------------------------------------------------------------------

void InitLogoScreen(void)
{
    finishScreen = 0;
    framesCounter = 0;
    lettersCount = 0;

    logoPositionX = GetScreenWidth()/2 - 8;
    logoPositionY = GetScreenHeight()/2 - 8;

    state = 0;
    alpha = 1.0f;
}

void UpdateLogoScreen(void)
{
	framesCounter++;

	if (lettersCount < 20)
	{
		lettersCount = (framesCounter * framesCounter) / (10 * 60);
	}
	else 
	{
		if (framesCounter < 30)
			return;

		alpha -= 0.08f;

		if (alpha <= 0.0f)
		{
			alpha = 0.0f;
			finishScreen = 1;
		}
	}
}

void DrawLogoScreen(void)
{
	DrawText(TextSubtext("bonmas technologies", 0, lettersCount),
		GetScreenWidth() / 2 - MeasureText(TextSubtext("bonmas technologies", 0, lettersCount), 50) / 2,
		GetScreenHeight() / 2 - 25, 50, 
		Fade(WHITE, alpha));
}

void UnloadLogoScreen(void)
{
}

int FinishLogoScreen(void)
{
    return finishScreen;
}
