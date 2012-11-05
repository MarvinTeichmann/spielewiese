#include <game/Game.h>
#include <game/Debug.h>
#include <game/Font.h>
#include <Bitmap.h>
#include <string.h>
#include <RLEBitmap.h>


#include <stdio.h>
#include <string.h>

extern const RLEBitmap testbild;


void Init(struct Gamestate*);
void OnEnter(struct Gamestate* state);
void OnLeave(struct Gamestate* state);
void Update(uint32_t);
void Draw(Bitmap *);

Gamestate InitState = { Init, OnEnter, OnLeave, Update, Draw };
Game* TheGame = &(Game) {&InitState};

void Init(struct Gamestate* state)
{
}

void OnEnter(struct Gamestate* state)
{
}

void OnLeave(struct Gamestate* state)
{
}

void Update(uint32_t a)
{
}

void Draw(Bitmap *b)
{
	ClearBitmap(b);
	DrawRLEBitmap(b, &testbild, 25, 25);
	DrawFilledCircle(b, 10, 10, 25, RGB(255,0,0));


}
