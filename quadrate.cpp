#include "quadrate.hpp" 

Fenster::Fenster(){
	m_display = XOpenDisplay(NULL);
	m_screen = DefaultScreen(m_display);
	m_window = XCreateSimpleWindow( m_display,
					RootWindow(m_display, m_screen ), 
					10, 10, 500, 300, 1,
					BlackPixel(m_display, m_screen), 
					WhitePixel(m_display, m_screen));
	XSelectInput(m_display, m_window, ExposureMask | KeyPressMask);
	XMapWindow(m_display, m_window);

	colormap = DefaultColormap(m_display,0);	
	XParseColor(m_display, colormap, yellow_bits, &yellow_col);
	XAllocColor(m_display, colormap, &yellow_col);
	XParseColor(m_display, colormap, blue_bits, &blue_col);
	XAllocColor(m_display, colormap, &blue_col);
	XParseColor(m_display, colormap, green_bits, &green_col);
	XAllocColor(m_display, colormap, &green_col);
	XParseColor(m_display, colormap, red_bits, &red_col);
	XAllocColor(m_display, colormap, &red_col);

	if (NULL == this->getDisplay() ) {
		fprintf(stderr, "Cannot open display...\n");
		exit(1);
	}
	
	m_gc = XCreateGC(m_display, m_window, 0, NULL);
	int b =5 ; //origin value, start point for Cartesian Axis  
	while(1){
	//	for (int b = 0; b < 34; ++b){		
		XNextEvent(m_display, &m_event);	
		if (m_event.type == Expose){
		CartesianAxis origin(m_display, m_window, m_event,
			             m_gc, b+100, b+110, b+200 ); //obj
		
		Square one_cubic(m_display, m_window, m_event, m_gc,
				 b+220, b + 50); //(b+ x,b+ y)(x,y) start pointforcube

		
		Human mard(m_display, m_window, m_event, m_gc, 
				 b + 200, b +100);

	}
		if (KeyPress == m_event.type){
			break;		
		}
	}
}

Fenster::~Fenster(){
	XFreeGC(m_display, m_gc);
	XDestroyWindow(m_display, m_window);
	XCloseDisplay(m_display);
}
	
Display *& Fenster :: setDisplay(){
		return m_display; 	
}

Display * Fenster:: getDisplay(){
	return m_display;
}

Window & Fenster::getWindow(){}
XEvent & Fenster:: getEvent(){}
	
CartesianAxis::CartesianAxis(Display * disp, Window wind, 
		     XEvent evend, GC gc, int x, int y, int z)
{
	m_display = disp;	
	m_window = wind;
	m_event = evend;
	m_gc = gc;
	int xx = x;
	int yy = y;
	int zz = z;

	s_point = new axis(xx, yy, zz); //you can change this value
			//for 3 axis and for circle
	
       	    XDrawArc(m_display, m_window, m_gc,
		    s_point-> m_a_x-10, s_point->m_a_y - 10,
		 			20, 20, 10*54, 64*330);
	  
	    XSetForeground(m_display, m_gc, yellow_col.pixel);
	
	    XSetForeground(m_display, m_gc, yellow_col.pixel);
	    XDrawLine(m_display, m_window, m_gc, 
			 s_point->m_a_x, s_point->m_a_y,
			 s_point->m_a_x, s_point->m_a_y - 50);

	
	    XSetForeground(m_display, m_gc, red_col.pixel);
	    XDrawLine(m_display, m_window, m_gc, 
			 s_point->m_a_x, s_point->m_a_y,
			 s_point->m_a_x - 50, s_point->m_a_y + 50);

	    XSetForeground(m_display, m_gc, blue_col.pixel);
	    XDrawLine(m_display, m_window, m_gc, 
			 s_point->m_a_x, s_point->m_a_y,
			 s_point->m_a_x + 50, s_point->m_a_y);
}

CartesianAxis::~CartesianAxis()
{
	delete	s_point;		
	s_point = NULL;	
}

