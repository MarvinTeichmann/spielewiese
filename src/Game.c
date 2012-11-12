#include <game/Game.h>
#include <game/Debug.h>
#include <game/Font.h>
#include <Bitmap.h>
#include <string.h>
#include <RLEBitmap.h>


#include <stdio.h>
#include <string.h>

extern const RLEBitmap testbild;

snes_button_state_t state;


void Init(struct Gamestate*);
void OnEnter(struct Gamestate* state);
void OnLeave(struct Gamestate* state);
void Update(uint32_t);
void Draw(Bitmap *);

void spider_move();

Gamestate InitState = { Init, OnEnter, OnLeave, Update, Draw };
Game* TheGame = &(Game) {&InitState};




uint16_t spider_x;
uint16_t spider_y;
uint16_t spider_delay;
uint16_t button_delay;


uint16_t spider_dir;



void Init(struct Gamestate* state)
{
	spider_dir = 0;
	spider_x = 10;
	spider_y = 10;
	spider_delay = 0;

}

void OnEnter(struct Gamestate* state)
{
}

void OnLeave(struct Gamestate* state)
{
}

void Update(uint32_t a)
{
	spider_delay += a;
	button_delay += a;

	if(spider_delay >= 4){
		spider_move();
		spider_delay = 0;
	}

	state = GetControllerState1();

	if(button_delay >= 10){ 
		if(state.buttons.A) spider_dir = spider_dir >= 11? 0: spider_dir+1;
		if(state.buttons.B) spider_dir = spider_dir <= 0? 11:spider_dir-1;
		button_delay = 0;;
	}


	if(spider_x >= 321) spider_x = 1;
	if(spider_x <= 0) spider_x = 320;
	if(spider_y >= 197) spider_y = 1;
	if(spider_y <= 0) spider_y = 196;
	

}

void spider_move(){
	switch(spider_dir){

	case 0:
		{
			spider_x +=3;
			break;
		}
	case 1:
		{
			spider_x +=2;
			spider_y +=1;
			break;
		}
	case 2:
		{
			spider_x +=1;
			spider_y +=2;
			break;
		}	
	case 3:
		{
			spider_y +=3;
			break;
		}	
	case 4:
		{
			spider_x -=1;
			spider_y +=2;
			break;
		}	
	case 5:
		{
			spider_x -=2;
			spider_y +=1;
			break;
		}	
	case 6:
		{
			spider_x -=3;
			break;
		}
	case 7:
		{
			spider_x -=2;
			spider_y -=1;
			break;
		}
	
	case 8:
		{
			spider_x -=1;
			spider_y -=2;
			break;
		}

	case 9:
		{
			spider_y -=3;
			break;
		}
	

	case 10:
		{
			spider_y -=2;
			spider_x +=1;
			break;
		}


	case 11:
		{
			spider_y -=1;
			spider_x += 2;
			break;
		}		
	}



}

void Draw(Bitmap *b)
{
	ClearBitmap(b);
	DrawRLEBitmap(b, &testbild, spider_x, spider_y);
	//DrawFilledCircle(b, 50, 50, 15, RGB(255,0,0));
	//DrawRectangle(b, 150,150,20,30, RGB(255,0,0));
	


}
