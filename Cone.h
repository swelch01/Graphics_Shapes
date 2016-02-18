#ifndef COHE_H
#define CONE_H

#include "Shape.h"
#include <iostream>


class Cone : public Shape {
public:
	Cone() {

	};

	~Cone() {};

	void draw() {
		Shape shape;
		Point tip = Point(0, .5, 0);
		std::vector<Point> peak = getPeak(m_segmentsX, m_segmentsY);
		std::vector<Point> rest = getRest(m_segmentsX, m_segmentsY);


		glBegin(GL_TRIANGLES);
		double x1 = tip[0];
		double y1 = tip[1];
		double z1 = tip[2]; 


		//draw peak

		for (int i = 0; i < peak.size() - 1; i++) {
			double x2 = peak[i][0];
			double y2 = peak[i][1];
			double z2 = peak[i][2];
			double x3 = peak[i+1][0];
			double y3 = peak[i+1][1];
			double z3 = peak[i+1][2];

			glVertex3f(x1, y1, z1);
			glVertex3f(x2, y2, z2);
			glVertex3f(x3, y3, z3);
		}

		glVertex3f(x1, y1, z1);
		glVertex3f(peak[0][0], peak[0][1], peak[0][2]);
		glVertex3f(peak[peak.size()-1][0], peak[peak.size()-1][1], peak[peak.size()-1][2]);



		//draw rest

		for (int j = 0; j < m_segmentsX - 1; j++){
			for (int k = 0; k < (m_segmentsY-1); k++) { 
				int index = j*m_segmentsY + k;
				double x1 = rest[index][0];
				double y1 = rest[index][1];
				double z1 = rest[index][2];
				double x2 = rest[index+1][0];
				double y2 = rest[index+1][1];
				double z2 = rest[index+1][2];
				double x3 = rest[index+m_segmentsY][0];
				double y3 = rest[index+m_segmentsY][1];
				double z3 = rest[index+m_segmentsY][2];
				double x4 = rest[index+m_segmentsY + 1][0];
				double y4 = rest[index+m_segmentsY + 1][1];
				double z4 = rest[index+m_segmentsY + 1][2];

			    glVertex3f(x1, y1, z1);
				glVertex3f(x3, y3, z3);
				glVertex3f(x4, y4, z4);

				glVertex3f(x1, y1, z1);
				glVertex3f(x2, y2, z2);
				glVertex3f(x4, y4, z4);
			}
		}
		for (int i = 0; i < m_segmentsY - 1; i++) {
			glVertex3f(rest[(m_segmentsX-1)*m_segmentsY + i][0], rest[(m_segmentsX-1)*m_segmentsY + i][1], rest[(m_segmentsX-1)*m_segmentsY + i][2]);
			glVertex3f(rest[i][0], rest[i][1], rest[i][2]);
			glVertex3f(rest[i+1][0], rest[i+1][1], rest[i+1][2]);

			glVertex3f(rest[(m_segmentsX-1)*m_segmentsY + i][0], rest[(m_segmentsX-1)*m_segmentsY + i][1], rest[(m_segmentsX-1)*m_segmentsY + i][2]);
			glVertex3f(rest[(m_segmentsX-1)*m_segmentsY + 1 +i][0], rest[(m_segmentsX-1)*m_segmentsY + 1 + i][1], rest[(m_segmentsX -1)*m_segmentsY + 1 + i][2]);
			glVertex3f(rest[i+1][0], rest[i+1][1], rest[i+1][2]);

		}

		glEnd();
	};
	void drawNormal() {
	};

protected:
	
	std::vector<Point> getPeak(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> peak;
		double r = .5/m_segmentsY;
		double x, y, z;
		for (int i = 0; i < m_segmentsX; i++) {
			x = r * cos(2.0 * PI * i / m_segmentsX);
			y = r * sin(2.0 * PI * i / m_segmentsX);
			z = .5 - 1.0/m_segmentsY;
			peak.push_back(Point(x, z, y));
		}
		return peak;
	}

	std::vector<Point> getRest(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> rest;// = new std::vector<Point>;
		double r, x, y, z;

		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY; j++) {
				r = (j+1.0)/2.0/m_segmentsY;
				x = r * cos(2.0 * PI * i / m_segmentsX);
				y = r * sin(2.0 * PI * i / m_segmentsX);
				z = .5 - (j+1.0)/m_segmentsY;
				rest.push_back(Point(x, z, y));
			}
		}
		/*
		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY - 1; j++) {
				r = (j+1.0)/2.0/m_segmentsY;
				x = r * cos(2.0 * PI * i / m_segmentsX);
				y = r * sin(2.0 * PI * i / m_segmentsX);
				z = .5 - (j+1.0)/m_segmentsY;
				rest.push_back(Point(x, z, y));
			}
		}
*/

		/*
		r = .5/m_segmentsY;
		for (int i = 0; i < m_segmentsX; i++) {
			x = r * cos(2.0 * PI * i / m_segmentsX);
			y = r * sin(2.0 * PI * i / m_segmentsX);
			z = .5 - 1.0/m_segmentsY;
			rest.push_back(Point(x, z, y));
		}
		*/
		return rest;


	}

};

#endif
