#ifndef GAMEOBJECT_
#define GAMEOBJECT_
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#ifdef __cplusplus
extern "C"
#endif
using namespace std;

class GameObject {
public:
	virtual void update() =0;
	virtual void render() =0;
	virtual ~GameObject() {};
};

#endif