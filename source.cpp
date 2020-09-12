#include "source.hpp" 

//it is drawing facis of a cube 

int Square::edge = 12; //length of side of cube

Square::Square(Display * m_display, Window & m_window,
		XEvent & m_event, GC & m_gc,  int xx, int yy)
{
//	int edge = 7; //length of side of cube interesting pics	
	axis s_point(xx, yy, 0);	
	//top horizontal line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x, s_point.m_a_y, 
		  s_point.m_a_x + edge, s_point.m_a_y );	
	//right vertical line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x + edge, s_point.m_a_y, 
		  s_point.m_a_x + edge , s_point.m_a_y + edge );	
	//left vertical line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x, s_point.m_a_y, 
		  s_point.m_a_x , s_point.m_a_y + edge );	
	//down horizontal line
	XSetForeground(m_display, m_gc, green_col.pixel);			
	XDrawLine(m_display, m_window, m_gc,
		  s_point.m_a_x, s_point.m_a_y + edge, 
		  s_point.m_a_x + edge, s_point.m_a_y+ edge);	
}

Human::Human(Display * disp, Window & wind,
      XEvent & event, GC & gc, int x, int y)
{
	//int edge = 7; //need be change for scaling
	//head
/*	Square cuedgeic00(disp, wind, event, gc, x+edge+(edge/2), y-edge);	

	//edgeody and hand
	Square cuedgeic11(disp, wind, event, gc, x, y);
	Square cuedgeic12(disp, wind, event, gc, x + edge, y);
	Square cuedgeic13(disp, wind, event, gc, x + 2*edge, y);
	Square cuedgeic14(disp, wind, event, gc, x + 3*edge, y);
	
	Square cuedgeic21(disp, wind, event, gc, x, y+edge);
	Square cuedgeic22(disp, wind, event, gc, x + edge, y+ edge);
	Square cuedgeic23(disp, wind, event, gc, x + 2*edge, y + edge);
	Square cuedgeic24(disp, wind, event, gc, x + 3*edge, y + edge );
	
	Square cuedgeic31(disp, wind, event, gc, x, y+2*edge);
	Square cuedgeic32(disp, wind, event, gc, x + edge, y + 2* edge);
	Square cuedgeic33(disp, wind, event, gc, x + 2*edge, y+2* edge);
	Square cuedgeic34(disp, wind, event, gc, x + 3*edge, y+2* edge);
	
	//foot
	Square cuedgeic41(disp, wind, event, gc, x+edge, y+ 3*edge );
	Square cuedgeic42(disp, wind, event, gc, x+2*edge , y+ 3*edge);

	Square cuedgeic51(disp, wind, event, gc, x + edge, y+4*edge);
	Square cuedgeic52(disp, wind, event, gc, x + 2*edge, y+4*edge);

	Square cuedgeic61(disp, wind, event, gc, x + edge, y+5*edge);
	Square cuedgeic62(disp, wind, event, gc, x + 2*edge, y+5*edge);
*/	
	Square(disp, wind, event, gc, x+edge+(edge/2), y-edge);	

	//edgeody and hand
	Square(disp, wind, event, gc, x, y);
	Square(disp, wind, event, gc, x + edge, y);
	Square(disp, wind, event, gc, x + 2*edge, y);
	Square(disp, wind, event, gc, x + 3*edge, y);
	
	Square(disp, wind, event, gc, x, y+edge);
	Square(disp, wind, event, gc, x + edge, y+ edge);
	Square(disp, wind, event, gc, x + 2*edge, y + edge);
	Square(disp, wind, event, gc, x + 3*edge, y + edge );
	
	Square(disp, wind, event, gc, x, y+2*edge);
	Square(disp, wind, event, gc, x + edge, y + 2* edge);
	Square(disp, wind, event, gc, x + 2*edge, y+2* edge);
	Square(disp, wind, event, gc, x + 3*edge, y+2* edge);
	
	//foot
	Square(disp, wind, event, gc, x+edge, y+ 3*edge );
	Square(disp, wind, event, gc, x+2*edge , y+ 3*edge);

	Square(disp, wind, event, gc, x + edge, y+4*edge);
	Square(disp, wind, event, gc, x + 2*edge, y+4*edge);

	Square(disp, wind, event, gc, x + edge, y+5*edge);
	Square(disp, wind, event, gc, x + 2*edge, y+5*edge);
}





