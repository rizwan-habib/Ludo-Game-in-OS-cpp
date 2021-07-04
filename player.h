// Rizwan Habib 	I190603
//Talha				I192049
//CS-G
//Submitted to Sir faisal Cheema


#include <iostream>
#include<time.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>	
#include<algorithm>
#include<sys/wait.h>
#include<semaphore.h>
#include <unistd.h>
using namespace std;

//structure for token
struct token{
	int value,x,y;//shows the x,y position and it's respective value
	bool open; //shows the state of token
	bool home;
	bool stop;
	bool win;
    char sym;
    token(){
        value=-1;
        x=0;
        y=0;
		stop=0;
		win=0;
		open=0;
		sym='!';
    }    
	token(int v,int x1,int y1,bool o,bool s,bool w,char sy){
		value=v;
        x=x1;
        y=y1;
		stop=s;
		win=w;
		open=o;
		sym=sy;
	}
	
};

///
// structure of player
//	each player will have tokens ranging from 1-4 
///
struct player{
    
	//attributes
    token *tok;
	int hitRate;
	int withoutsixturns;
	bool is_win;
	bool inGame;
	//constructor
	player(){
		
		hitRate=1;
		is_win=0;
		inGame=1;
		withoutsixturns=0;
	}
	//parameterised constructor
	player(char symbol,int noOftokens ){
		
        tok = new token [noOftokens];
        for (int i=0;i<noOftokens;i++)
        {
            tok[i].sym=symbol;
        }
        
		hitRate=1;
		is_win=0;
		inGame=1;
		withoutsixturns=0;
	}
};
