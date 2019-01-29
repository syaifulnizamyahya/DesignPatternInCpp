// AbstractFactoryPattern.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Renderer
{
public:
	virtual ~Renderer() {};
	virtual void RenderIt() = 0;
};

class OpenGLRenderer : public Renderer
{
	void RenderIt() {
		std::cout << "OpenGL render \n";
	}
};

class DirectXRenderer : public Renderer
{
	void RenderIt() {
		std::cout << "DirectX render \n";
	}
};

#include <string>

class RendererFactory
{
public:
	Renderer *createRenderer(const std::string& type)
	{
		if (type == "opengl")
			return new OpenGLRenderer();
		else if (type == "directx")
			return new DirectXRenderer();
		else return NULL;
	}
};


int main()
{
	RendererFactory *factory = new RendererFactory();
	factory->createRenderer("opengl")->RenderIt();
	factory->createRenderer("directx")->RenderIt();

	cin.get();
	return 0;
}