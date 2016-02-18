#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"
#include <iostream>


class Cube : public Shape {
public:
	Cube() {};
	~Cube() {};

	/*void setSegments(int x, int y) {
	}*/
	
	void draw() {
		
		Shape shape;
		//int m_segmentsX = 3;//shape.getxseg();
		//int m_segmentsY = 3;//shape.getyseg();
	 	//std::vector<Point> vertexList = shape.pointVector;
	 	//std::vector<std::vector<Point> > face;

		std::vector<Point> *face = new std::vector<Point>[6];
		face = getPoints(m_segmentsX,m_segmentsY);


		glBegin(GL_TRIANGLES);
		double a, b, c, d;
		a = 0;
		b = a + 1;
		c = a + m_segmentsY + 1;
		d = c + 1;
		//std::cout<<"num segx*segy: "<<m_segmentsX*m_segmentsY<<std::endl;
		
			for (int k = 0; k < m_segmentsX*m_segmentsY; k++) {
				//if not on edge (use y segments to calculate)
				//std::cout<<"a, b, c, d:"<<a<<", "<<b<<", "<<d<<", "<<std::endl;
				double *v1 = new double[4];
				double *v2 = new double[4];
				double *v3 = new double[4];
				double *v4 = new double[4];


				for(int m = 0; m < 6; m++){

					//std::cout<<"m: "<<m<<std::endl;
					face[m][a].unpack(v1);
					face[m][b].unpack(v2);
					face[m][c].unpack(v3);
					face[m][d].unpack(v4);
					//std::cout<<"unpack done"<<std::endl;
					double x1 = v1[0];//face[0][a].at(0);

					double y1 = v1[1];//face[0][a].at(1);
					double z1 = v1[2];//face[0][a].at(2);
					double x2 = v2[0];//face[0][b].at(0);
					double y2 = v2[1];//face[0][b].at(1);
					double z2 = v2[2];//face[0][b].at(2);
					double x3 = v3[0];//face[0][c].at(0);
					double y3 = v3[1];//face[0][c].at(1);
					double z3 = v3[2];//face[0][c].at(2);
					double x4 = v4[0];//face[0][d].at(0);
					double y4 = v4[1];//face[0][d].at(1);
					double z4 = v4[2];//face[0][d].at(2);
					//std::cout<<x1<<", "<<y1<<", "<<z1<<", "<<x2<<", "<<y2<<", "<<z2<<", "<<x3<<", "<<y3<<", "<<z3<<", "<<x4<<", "<<y4<<", "<<z4<<std::endl;

					//setNormal(x1, y1, z1, x2, y2, z2, x3, y3, z3);
					//glNormal3f(x1, y1, z1); do we need this??
					glVertex3f(x1, y1, z1);
					glVertex3f(x2, y2, z2);
					glVertex3f(x3, y3, z3);
					//std::cout<<"first triange"<<std::endl;

					//setNormal(x2, y2, z2, x3, y3, z3, x4, y4, z4);

					glVertex3f(x2, y2, z2);
					glVertex3f(x3, y3, z3);
					glVertex3f(x4, y4, z4);
					//std::cout<<"second triangle"<<std::endl;

				}

				if ((k+1) % m_segmentsY == 0) {
					//std::cout<<"a"<<std::endl;
					a += 2;
					b += 2;
					c += 2;
					d += 2;
				} else {
					//std::cout<<"b"<<std::endl;
					a++;
					b++;
					c++;
					d++;
				}
				//std::cout<<"k: "<<k<<std::endl;

			}
		

		glEnd();
	};


	void drawNormal() {

		std::vector<Point> *face = new std::vector<Point>[6];
		glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);

		face = getPoints(m_segmentsX,m_segmentsY);

		
		for (int i = 0; i < 6; i++){
			for(int j = 0; j < ((m_segmentsX+1)*(m_segmentsY+1)); j++){
				//for(int k = 0; k < m_segmentsY; k++ )
				//	std::cout << "i j k : "<< i << " "<< j << " " << k << std::endl;
				switch (i) {
					case 0:
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]);
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]-0.1);
						break;
					case 1:
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]);
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]+0.1);
						break;
					case 2:
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]);
						glVertex3f(face[i][j][0], face[i][j][1]-0.1, face[i][j][2]);
						break;
					case 3:
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]);
						glVertex3f(face[i][j][0], face[i][j][1]+0.1, face[i][j][2]);
						break;
					case 4:
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]);
						glVertex3f(face[i][j][0]-0.1, face[i][j][1], face[i][j][2]);
						break;
					case 5: 
						glVertex3f(face[i][j][0], face[i][j][1], face[i][j][2]);
						glVertex3f(face[i][j][0]+0.1, face[i][j][1], face[i][j][2]);
						break;

				}
			}
		}
		

		glVertex3f(0, 0, 0); glVertex3f(1.0, 0, 0);
		glVertex3f(0, 0, 0); glVertex3f(0.0, 1.0, 0);
		glVertex3f(0, 0, 0); glVertex3f(0, 0, 1.0);
		glEnd();

		glEnd();

	};


protected:
	std::vector<Point> * getPoints(int m_segmentsX, int m_segmentsY){
		std::vector<Point> *face = new std::vector<Point>[6];
	 	
		//std::cout << m_segmentsX<< std::endl;
		double dx = 1.0/m_segmentsX;
		double dy = 1.0/m_segmentsY;
		double dz = 1.0/m_segmentsX;


		//double dz = 1/m_segmentsX;
		double x  = -.5;
		double y  = -.5;
		double z  = -.5;
		int index = 0;

		for (int i = 0; i <= m_segmentsX; i++) {
			y = -.5;
			for (int j = 0; j <= m_segmentsY; j++) {

				(face[0]).push_back(Point(x, y, -0.5));
				(face[1]).push_back(Point(x, y,  0.5));
				(face[2]).push_back(Point(x, -0.5, y));
				(face[3]).push_back(Point(x,  0.5, y));
				(face[4]).push_back(Point(-0.5, y, x));
				(face[5]).push_back(Point( 0.5, y, x));

				index ++;
				//std::cout<<"y "<<y<<std::endl;
				y += dy;
			}
			x += dx;
		}
		return face;
	};

	//std::vector<Point> face[6];




};







#endif
