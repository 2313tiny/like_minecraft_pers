
#ifndef SOURCE_HPP
#define SOURCE_HPP

#include<X11/Xlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include"quadrate.hpp"


class Square {//: private axis  {
private:
	Colormap colormap;
	XColor green_col;
	const char green_bits[8]= "#00FF00";
public:
	static int edge; //length of side of cube

protected:
	int m_x_begin; //start point for x
	int m_y_begin; //start point for y
	
public:
	Square(){}
	Square(Display * disp, Window & wind,
		XEvent & evend, GC & gc, int x, int y);
	Square(const Square & ){}
	virtual ~Square(){}
};

class Human : private Square
{
public:
	Human(){}
	Human(Display * disp, Window & wind,
		XEvent & evend, GC & gc, int x, int y);
	virtual ~Human(){}	
};

 
#endif //SOURCE_HPP
