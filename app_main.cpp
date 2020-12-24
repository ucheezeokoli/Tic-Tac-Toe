#include <iostream>
#include <math.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

// Store the width and height of the window
int width = 640, height = 640;

int redraw = 0;
bool single_player = false;

float my;
float mx;

float my_y;
float my_x;

int count = -1;
int sp_count = 0;

bool TL, TM, TR, ML, MM, MR, BL, BM, BR = false;
bool disp_TLX, disp_TMX, disp_TRX, disp_MLX, disp_MMX, disp_MRX, disp_BLX, disp_BMX, disp_BRX,
	disp_TLO, disp_TMO, disp_TRO, disp_MLO, disp_MMO, disp_MRO, disp_BLO, disp_BMO, disp_BRO = false;

float TLX_x, TLX_y, TLO_x, TLO_y,
	TMX_x, TMX_y, TMO_x, TMO_y,
	TRX_x, TRX_y, TRO_x, TRO_y,
	MLX_x, MLX_y, MLO_x, MLO_y,
	MMX_x, MMX_y, MMO_x, MMO_y,
	MRX_x, MRX_y, MRO_x, MRO_y,
	BLX_x, BLX_y, BLO_x, BLO_y,
	BMX_x, BMX_y, BMO_x, BMO_y,
	BRX_x, BRX_y, BRO_x, BRO_y;

void botPlayer()
{
	//TOP LEFT
		if (mx > -1 && mx < -0.35 && my > 0.35 && my < 1 && TL == false)
		{
			cout << "TL was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				TLX_x = -0.9;
				TLX_y = 0.9;
				disp_TLX = true;
			}
			else
			{
				TLO_x = -0.7;
				TLO_y = 0.7;
				disp_TLO = true;
			}

			TL = true;
		}
		else if (mx > -1 && mx < -0.35 && my > 0.35 && my < 1 && TL == true)
		{
			cout << "location unavailable" << endl;
		}

		//TOP MIDDLE
		if (mx > -0.35 && mx < 0.35 && my > 0.35 && my < 1 && TM == false)
		{
			cout << "TM was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				TMX_x = -0.25;
				TMX_y = 0.9;
				disp_TMX = true;
			}
			else
			{
				TMO_x = -0.05;
				TMO_y = 0.7;
				disp_TMO = true;
			}

			TM = true;
		}
		else if (mx > -0.35 && mx < 0.35 && my > 0.35 && my < 1 && TM == true)
		{
			cout << "location unavailable" << endl;
		}

		//TOP RIGHT
		if (mx > 0.35 && mx < 1 && my > 0.35 && my < 1 && TR == false)
		{
			cout << "TR was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				TRX_x = 0.45;
				TRX_y = 0.9;
				disp_TRX = true;
			}
			else
			{
				TRO_x = 0.65;
				TRO_y = 0.7;
				disp_TRO = true;
			}

			TR = true;
		}
		else if (mx > 0.35 && mx < 1 && my > 0.35 && my < 1 && TR == true)
		{
			cout << "Location unavailable" << endl;
		}

		//MIDDLE LEFT
		if (mx > -1 && mx < -0.35 && my > -0.35 && my < 0.35 && ML == false)
		{
			cout << "ML was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				MLX_x = -0.9;
				MLX_y = 0.25;
				disp_MLX = true;
			}
			else
			{
				MLO_x = -0.7;
				MLO_y = 0.05;
				disp_MLO = true;
			}

			ML = true;
		}
		else if (mx > -1 && mx < -0.35 && my > -0.35 && my < 0.35 && ML == true)
		{
			cout << "location unavailable" << endl;
		}

		//MIDDLE MIDDLE
		if (mx > -0.35 && mx < 0.35 && my > -0.35 && my < 0.35 && MM == false)
		{
			cout << "MM was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				MMX_x = -0.25;
				MMX_y = 0.25;
				disp_MMX = true;
			}
			else
			{
				MMO_x = -0.05;
				MMO_y = 0.05;
				disp_MMO = true;
			}

			MM = true;
		}
		else if (mx > -0.35 && mx < 0.35 && my > -0.35 && my < 0.35 && MM == true)
		{
			cout << "location unavailable" << endl;
		}

		//MIDDLE RIGHT
		if (mx > 0.35 && mx < 1 && my > -0.35 && my < 0.35 && MR == false)
		{
			cout << "MR was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				MRX_x = 0.45;
				MRX_y = 0.25;
				disp_MRX = true;
			}
			else
			{
				MRO_x = 0.65;
				MRO_y = 0.05;
				disp_MRO = true;
			}

			MR = true;
		}
		else if (mx > 0.35 && mx < 1 && my > -0.35 && my < 0.35 && MR == true)
		{
			cout << "Location unavailable" << endl;
		}

		//BOTTOM LEFT
		if (mx > -1 && mx < -0.35 && my > -1 && my < -0.35 && BL == false)
		{
			cout << "BL was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				BLX_x = -0.9;
				BLX_y = -0.45;
				disp_BLX = true;
			}
			else
			{
				BLO_x = -0.7;
				BLO_y = -0.65;
				disp_BLO = true;
			}

			BL = true;
		}
		else if (mx > -1 && mx < -0.35 && my > -1 && my < -0.35 && BL == true)
		{
			cout << "location unavailable" << endl;
		}

		//BOTTOM MIDDLE
		if (mx > -0.35 && mx < 0.35 && my > -1 && my < -0.35 && BM == false)
		{
			cout << "BM was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				BMX_x = -0.25;
				BMX_y = -0.45;
				disp_BMX = true;
			}
			else
			{
				BMO_x = -0.05;
				BMO_y = -0.65;
				disp_BMO = true;
			}
			BM = true;
		}
		else if (mx > -0.35 && mx < 0.35 && my > -1 && my < -0.35 && BM == true)
		{
			cout << "location unavailable" << endl;
		}

		//BOTTOM RIGHT
		if (mx > 0.35 && mx < 1 && my > -1 && my < -0.35 && BR == false)
		{
			cout << "BR was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				BRX_x = 0.45;
				BRX_y = -0.45;
				disp_BRX = true;
			}
			else
			{
				BRO_x = 0.65;
				BRO_y = -0.65;
				disp_BRO = true;
			}

			BR = true;
		}
		else if (mx > 0.35 && mx < 1 && my > -1 && my < -0.35 && BR == true)
		{
			cout << "Location unavailable" << endl;
		}
	if (redraw == 0)
	{
		glutPostRedisplay();
	}
}

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Your code here...

	if (single_player && sp_count % 2 != 0)
	{
		mx = 2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f;
		my = 2.0f * ((float)rand() / (float)RAND_MAX) - 1.0f;
		cout << mx << " " << my << endl;
		// sp_count++;
		botPlayer();
	}

	//VERTICLE LINES
	glPointSize(10);
	glColor3f(0, 1, 0);

	glBegin(GL_LINES);

	glVertex2f(-0.35, 1);
	glVertex2f(-0.35, -1);

	glEnd();

	glBegin(GL_LINES);

	glVertex2f(0.35, 1);
	glVertex2f(0.35, -1);

	glEnd();

	//HORIZONTAL LINES
	glBegin(GL_LINES);

	glVertex2f(-1, 0.35);
	glVertex2f(1, 0.35);

	glEnd();

	glBegin(GL_LINES);

	glVertex2f(-1, -0.35);
	glVertex2f(1, -0.35);

	glEnd();

	if (disp_TLX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(TLX_x, TLX_y);
		glVertex2f(TLX_x + 0.5, TLX_y - 0.5);

		glVertex2f(TLX_x, TLX_y - 0.5);
		glVertex2f(TLX_x + 0.5, TLX_y);

		glEnd();
	}

	if (disp_TLO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + TLO_x, sin(theta) * 0.25 + TLO_y);
		}

		glEnd();
	}

	if (disp_TMX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(TMX_x, TMX_y);
		glVertex2f(TMX_x + 0.5, TMX_y - 0.5);

		glVertex2f(TMX_x, TMX_y - 0.5);
		glVertex2f(TMX_x + 0.5, TMX_y);

		glEnd();
	}

	if (disp_TMO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + TMO_x, sin(theta) * 0.25 + TMO_y);
		}

		glEnd();
	}

	if (disp_TRX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(TRX_x, TRX_y);
		glVertex2f(TRX_x + 0.5, TRX_y - 0.5);

		glVertex2f(TRX_x, TRX_y - 0.5);
		glVertex2f(TRX_x + 0.5, TRX_y);

		glEnd();
	}

	if (disp_TRO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + TRO_x, sin(theta) * 0.25 + TRO_y);
		}

		glEnd();
	}

	if (disp_MLX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(MLX_x, MLX_y);
		glVertex2f(MLX_x + 0.5, MLX_y - 0.5);

		glVertex2f(MLX_x, MLX_y - 0.5);
		glVertex2f(MLX_x + 0.5, MLX_y);

		glEnd();
	}

	if (disp_MLO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + MLO_x, sin(theta) * 0.25 + MLO_y);
		}

		glEnd();
	}

	if (disp_MMX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(MMX_x, MMX_y);
		glVertex2f(MMX_x + 0.5, MMX_y - 0.5);

		glVertex2f(MMX_x, MMX_y - 0.5);
		glVertex2f(MMX_x + 0.5, MMX_y);

		glEnd();
	}

	if (disp_MMO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + MMO_x, sin(theta) * 0.25 + MMO_y);
		}

		glEnd();
	}

	if (disp_MRX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(MRX_x, MRX_y);
		glVertex2f(MRX_x + 0.5, MRX_y - 0.5);

		glVertex2f(MRX_x, MRX_y - 0.5);
		glVertex2f(MRX_x + 0.5, MRX_y);

		glEnd();
	}

	if (disp_MRO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + MRO_x, sin(theta) * 0.25 + MRO_y);
		}

		glEnd();
	}

	if (disp_BLX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(BLX_x, BLX_y);
		glVertex2f(BLX_x + 0.5, BLX_y - 0.5);

		glVertex2f(BLX_x, BLX_y - 0.5);
		glVertex2f(BLX_x + 0.5, BLX_y);

		glEnd();
	}

	if (disp_BLO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + BLO_x, sin(theta) * 0.25 + BLO_y);
		}

		glEnd();
	}

	if (disp_BMX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(BMX_x, BMX_y);
		glVertex2f(BMX_x + 0.5, BMX_y - 0.5);

		glVertex2f(BMX_x, BMX_y - 0.5);
		glVertex2f(BMX_x + 0.5, BMX_y);

		glEnd();
	}

	if (disp_BMO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + BMO_x, sin(theta) * 0.25 + BMO_y);
		}

		glEnd();
	}

	if (disp_BRX)
	{
		glColor3f(1, 0, 0);

		glBegin(GL_LINES);

		glVertex2f(BRX_x, BRX_y);
		glVertex2f(BRX_x + 0.5, BRX_y - 0.5);

		glVertex2f(BRX_x, BRX_y - 0.5);
		glVertex2f(BRX_x + 0.5, BRX_y);

		glEnd();
	}

	if (disp_BRO)
	{
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);

		float theta = 0;
		float inc = M_PI / 10000; //you will get 2 times as many points as the denominator

		for (theta; theta <= 2 * M_PI; theta += inc)
		{
			glVertex2f(cos(theta) * 0.25 + BRO_x, sin(theta) * 0.25 + BRO_y);
		}

		glEnd();
	}

	

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();

	if ((disp_TLX && disp_TMX && disp_TRX) ||
		(disp_TLX && disp_MLX && disp_BLX) ||
		(disp_TLX && disp_MMX && disp_BRX) ||
		(disp_TMX && disp_MMX && disp_BMX) ||
		(disp_TRX && disp_MRX && disp_BRX) ||
		(disp_TRX && disp_MMX && disp_BLX) ||
		(disp_MLX && disp_MMX && disp_MRX) ||
		(disp_BLX && disp_BMX && disp_BRX))
	{
		cout << "Player 1 is the winner!" << endl;
		// redraw = 1;
		sleep(5);
		exit(0);
	}

	if ((disp_TLO && disp_TMO && disp_TRO) ||
		(disp_TLO && disp_MLO && disp_BLO) ||
		(disp_TLO && disp_MMO && disp_BRO) ||
		(disp_TMO && disp_MMO && disp_BMO) ||
		(disp_TRO && disp_MRO && disp_BRO) ||
		(disp_TRO && disp_MMO && disp_BLO) ||
		(disp_MLO && disp_MMO && disp_MRO) ||
		(disp_BLO && disp_BMO && disp_BRO))
	{
		cout << "Player 2 is the winner!" << endl;
		// redraw = 1;
		sleep(5);
		exit(0);
	}
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments:
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float &x, float &y)
{
	x = (2.0f * (x / float(width))) - 1.0f;
	y = 1.0f - (2.0f * (y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h)
{
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h)
	{
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin) * scale;
		winXmax = center + (appXmax - center) * scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else
	{
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin) * scale;
		winYmax = center + (appYmax - center) * scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}

//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments:
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y)
{
	// Convert from Window to Scene coordinates
	mx = (float)x;
	my = (float)y;

	windowToScene(mx, my);

	// Your code here...

	// bool play = true;

	if (s == 0)
	{
		//TOP LEFT
		if (mx > -1 && mx < -0.35 && my > 0.35 && my < 1 && TL == false)
		{
			cout << "TL was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				TLX_x = -0.9;
				TLX_y = 0.9;
				disp_TLX = true;
			}
			else
			{
				TLO_x = -0.7;
				TLO_y = 0.7;
				disp_TLO = true;
			}

			TL = true;
		}
		else if (mx > -1 && mx < -0.35 && my > 0.35 && my < 1 && TL == true)
		{
			cout << "location unavailable" << endl;
		}

		//TOP MIDDLE
		if (mx > -0.35 && mx < 0.35 && my > 0.35 && my < 1 && TM == false)
		{
			cout << "TM was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				TMX_x = -0.25;
				TMX_y = 0.9;
				disp_TMX = true;
			}
			else
			{
				TMO_x = -0.05;
				TMO_y = 0.7;
				disp_TMO = true;
			}

			TM = true;
		}
		else if (mx > -0.35 && mx < 0.35 && my > 0.35 && my < 1 && TM == true)
		{
			cout << "location unavailable" << endl;
		}

		//TOP RIGHT
		if (mx > 0.35 && mx < 1 && my > 0.35 && my < 1 && TR == false)
		{
			cout << "TR was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				TRX_x = 0.45;
				TRX_y = 0.9;
				disp_TRX = true;
			}
			else
			{
				TRO_x = 0.65;
				TRO_y = 0.7;
				disp_TRO = true;
			}

			TR = true;
		}
		else if (mx > 0.35 && mx < 1 && my > 0.35 && my < 1 && TR == true)
		{
			cout << "Location unavailable" << endl;
		}

		//MIDDLE LEFT
		if (mx > -1 && mx < -0.35 && my > -0.35 && my < 0.35 && ML == false)
		{
			cout << "ML was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				MLX_x = -0.9;
				MLX_y = 0.25;
				disp_MLX = true;
			}
			else
			{
				MLO_x = -0.7;
				MLO_y = 0.05;
				disp_MLO = true;
			}

			ML = true;
		}
		else if (mx > -1 && mx < -0.35 && my > -0.35 && my < 0.35 && ML == true)
		{
			cout << "location unavailable" << endl;
		}

		//MIDDLE MIDDLE
		if (mx > -0.35 && mx < 0.35 && my > -0.35 && my < 0.35 && MM == false)
		{
			cout << "MM was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				MMX_x = -0.25;
				MMX_y = 0.25;
				disp_MMX = true;
			}
			else
			{
				MMO_x = -0.05;
				MMO_y = 0.05;
				disp_MMO = true;
			}

			MM = true;
		}
		else if (mx > -0.35 && mx < 0.35 && my > -0.35 && my < 0.35 && MM == true)
		{
			cout << "location unavailable" << endl;
		}

		//MIDDLE RIGHT
		if (mx > 0.35 && mx < 1 && my > -0.35 && my < 0.35 && MR == false)
		{
			cout << "MR was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				MRX_x = 0.45;
				MRX_y = 0.25;
				disp_MRX = true;
			}
			else
			{
				MRO_x = 0.65;
				MRO_y = 0.05;
				disp_MRO = true;
			}

			MR = true;
		}
		else if (mx > 0.35 && mx < 1 && my > -0.35 && my < 0.35 && MR == true)
		{
			cout << "Location unavailable" << endl;
		}

		//BOTTOM LEFT
		if (mx > -1 && mx < -0.35 && my > -1 && my < -0.35 && BL == false)
		{
			cout << "BL was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				BLX_x = -0.9;
				BLX_y = -0.45;
				disp_BLX = true;
			}
			else
			{
				BLO_x = -0.7;
				BLO_y = -0.65;
				disp_BLO = true;
			}

			BL = true;
		}
		else if (mx > -1 && mx < -0.35 && my > -1 && my < -0.35 && BL == true)
		{
			cout << "location unavailable" << endl;
		}

		//BOTTOM MIDDLE
		if (mx > -0.35 && mx < 0.35 && my > -1 && my < -0.35 && BM == false)
		{
			cout << "BM was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				BMX_x = -0.25;
				BMX_y = -0.45;
				disp_BMX = true;
			}
			else
			{
				BMO_x = -0.05;
				BMO_y = -0.65;
				disp_BMO = true;
			}
			BM = true;
		}
		else if (mx > -0.35 && mx < 0.35 && my > -1 && my < -0.35 && BM == true)
		{
			cout << "location unavailable" << endl;
		}

		//BOTTOM RIGHT
		if (mx > 0.35 && mx < 1 && my > -1 && my < -0.35 && BR == false)
		{
			cout << "BR was clicked" << endl;
			count++;
			sp_count++;
			if (count % 2 == 0)
			{
				BRX_x = 0.45;
				BRX_y = -0.45;
				disp_BRX = true;
			}
			else
			{
				BRO_x = 0.65;
				BRO_y = -0.65;
				disp_BRO = true;
			}

			BR = true;
		}
		else if (mx > 0.35 && mx < 1 && my > -1 && my < -0.35 && BR == true)
		{
			cout << "Location unavailable" << endl;
		}
	}

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	if (redraw == 0)
	{
		glutPostRedisplay();
	}
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments:
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y)
{
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// Your code here...

	// Again, we redraw the scene
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments:
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y)
{
	// Define what should happen for a given key press
	switch (key)
	{
		// Escape was pressed. Quit the program
	case 27: //ASCII VALUE FOR ESC
		exit(0);
		break;
		// More cases here if you need...
	case 'w':
		my_y += 0.1;
		// cout << "Will move up" << endl;
		break;

	case 'a':
		my_x -= 0.1;
		// cout << "Will move left" << endl;
		break;

	case 's':
		my_y -= 0.1;
		// cout << "Will move down" << endl;
		break;

	case 'd':
		my_x += 0.1;
		// cout << "Will move right" << endl;
		break;
		// case 'f':
		// 	single_player = true;
		// 	cout << "f was pressed" << endl;
		// 	break;
	}
	// After all the state changes, redraw the scene
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	cout << "Lets Play Tic Tac Toe!" << endl;
	cout << "Press 1 to play against bot or press 2 begin a 2 player game" << endl;

	int input;
	cin >> input;

	bool game = true;
	if (input == 1)
	{
		single_player = true;
		cout << "Lets Begin!" << endl;
		game = false;
	}
	else if (input == 2)
	{
		cout << "Lets Begin!" << endl;
		game = false;
	}
	else
	{
		cout << "Invalid entry" << endl;
		cout << "Try Again";
		exit(0);
	}

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	// Start with a slightly smaller window (bug in macOS Catalina)
	glutInitWindowSize(width - 1, height - 1);

	// Create the window
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	// Set callback for drawing the scene
	
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);

	// Resize your window to the desired size (bug in macOS Catalina)
	glutReshapeWindow(width, height);

	// Start the main loop
	glutMainLoop();
}
