#ifndef HYPERBOLOID_H
#define HYPERBOLOID_H

#include "Shape.h"

class Hyperboloid : public Shape {
public:
	Hyperboloid() {};
	~Hyperboloid() {};

	void draw() {
		Shape shape;


		glBegin(GL_TRIANGLES);

		std::vector<Point> top = getTopPoints(m_segmentsX, m_segmentsY);
		std::vector<Point> bottom = getBottomPoints(m_segmentsX, m_segmentsY);
		std::vector<Point> points = getSidePoints(m_segmentsX, m_segmentsY);


		for (int i = 1; i < m_segmentsX; i++) {
			double x1 = top[i][0];
			double y1 = top[i][1];
			double z1 = top[i][2];
			double x2 = top[i+1][0];
			double y2 = top[i+1][1];
			double z2 = top[i+1][2];
			double x3 = bottom[i][0];
			double y3 = bottom[i][1];
			double z3 = bottom[i][2];
			double x4 = bottom[i+1][0];
			double y4 = bottom[i+1][1];
			double z4 = bottom[i+1][2];

			glVertex3f(x1, y1, z1);
			glVertex3f(x2, y2, z2);
			glVertex3f(0, .5, 0);

			glVertex3f(x3, y3, z3);
			glVertex3f(x4, y4, z4);
			glVertex3f(0, -.5, 0);

		}
		//
		glVertex3f(top[m_segmentsX][0], top[m_segmentsX][1], top[m_segmentsX][2]);
		glVertex3f(0, .5, 0);
		glVertex3f(top[1][0], top[1][1], top[1][2]);

		glVertex3f(bottom[m_segmentsX][0], bottom[m_segmentsX][1], bottom[m_segmentsX][2]);
		glVertex3f(bottom[0][0], bottom[0][1], bottom[0][2]);
		glVertex3f(bottom[1][0], bottom[1][1], bottom[1][2]);


		for (int j = 0; j < m_segmentsX - 1; j++){
			for (int k = 0; k < (m_segmentsY-1); k++) { 
				int index = j*m_segmentsY + k;
				double x1 = points[index][0];
				double y1 = points[index][1];
				double z1 = points[index][2];
				double x2 = points[index+1][0];
				double y2 = points[index+1][1];
				double z2 = points[index+1][2];
				double x3 = points[index+m_segmentsY][0];
				double y3 = points[index+m_segmentsY][1];
				double z3 = points[index+m_segmentsY][2];
				double x4 = points[index+m_segmentsY + 1][0];
				double y4 = points[index+m_segmentsY + 1][1];
				double z4 = points[index+m_segmentsY + 1][2];

			    glVertex3f(x1, y1, z1);
				glVertex3f(x3, y3, z3);
				glVertex3f(x4, y4, z4);

				glVertex3f(x1, y1, z1);
				glVertex3f(x2, y2, z2);
				glVertex3f(x4, y4, z4);
			}
		}
		for (int i = 0; i < m_segmentsY - 1; i++) {
			glVertex3f(points[(m_segmentsX-1)*m_segmentsY + i][0], points[(m_segmentsX-1)*m_segmentsY + i][1], points[(m_segmentsX-1)*m_segmentsY + i][2]);
			glVertex3f(points[i][0], points[i][1], points[i][2]);
			glVertex3f(points[i+1][0], points[i+1][1], points[i+1][2]);

			glVertex3f(points[(m_segmentsX-1)*m_segmentsY + i][0], points[(m_segmentsX-1)*m_segmentsY + i][1], points[(m_segmentsX-1)*m_segmentsY + i][2]);
			glVertex3f(points[(m_segmentsX-1)*m_segmentsY + 1 +i][0], points[(m_segmentsX-1)*m_segmentsY + 1 + i][1], points[(m_segmentsX -1)*m_segmentsY + 1 + i][2]);
			glVertex3f(points[i+1][0], points[i+1][1], points[i+1][2]);

		}

		for (int i = 0; i < m_segmentsX - 1; i++){
			glVertex3f(bottom[i + 1][0], bottom[i + 1][1], bottom[i + 1][2]);
			glVertex3f(points[i*m_segmentsY + m_segmentsY - 1][0],
					   points[i*m_segmentsY + m_segmentsY - 1][1],
					   points[i*m_segmentsY + m_segmentsY - 1][2]);
			glVertex3f(bottom[i + 2][0], bottom[i + 2][1], bottom[i +2][2]);

			
			glVertex3f(points[i*m_segmentsY + m_segmentsY - 1][0],
					   points[i*m_segmentsY + m_segmentsY - 1][1],
					   points[i*m_segmentsY + m_segmentsY - 1][2]);
			glVertex3f(points[i*m_segmentsY + m_segmentsY 
											+ m_segmentsY - 1][0],
				       points[i*m_segmentsY + m_segmentsY 
				       						+ m_segmentsY - 1][1],
				       points[i*m_segmentsY + m_segmentsY 
				       						+ m_segmentsY - 1][2]);
			glVertex3f(bottom[i + 2][0], bottom[i + 2][1], bottom[i +2][2]);
		}
		glVertex3f(bottom[m_segmentsX][0], bottom[m_segmentsX][1], bottom[m_segmentsX][2]);
		glVertex3f(points[(m_segmentsX-1)*m_segmentsY + m_segmentsY - 1][0],
				   points[(m_segmentsX-1)*m_segmentsY + m_segmentsY - 1][1],
				   points[(m_segmentsX-1)*m_segmentsY + m_segmentsY - 1][2]);
		glVertex3f(bottom[1][0], bottom[1][1], bottom[1][2]);
			
		glVertex3f(points[(m_segmentsX-1)*m_segmentsY + m_segmentsY - 1][0],
				   points[(m_segmentsX-1)*m_segmentsY + m_segmentsY - 1][1],
				   points[(m_segmentsX-1)*m_segmentsY + m_segmentsY - 1][2]);
		glVertex3f(points[m_segmentsY - 1][0],
		 	       points[m_segmentsY - 1][1],
		 	       points[m_segmentsY - 1][2]);
		glVertex3f(bottom[1][0], bottom[1][1], bottom[1][2]);


/*
		for (int i = 1; i <= m_segmentsX; i++) {
			double dy1 = 1.0/m_segmentsY;
			double dy2 = dy1;
			double dy3 = 0;
			for (int j = 0; j < m_segmentsY; j++){
				double x1 = top[i][0];
				double y1 = top[i][1];
				double z1 = top[i][2];
				double x2 = top[i+1][0];
				double y2 = top[i+1][1];
				double z2 = top[i+1][2];

				glVertex3f(x1, y1-dy3, z1);
				glVertex3f(x2, y2-dy3, z2);
				glVertex3f(x2, y2-dy2, z2);

				glVertex3f(x1, y1-dy3, z1);
				glVertex3f(x1, y1-dy2, z1);
				glVertex3f(x2, y2-dy2, z2);

				dy2 += dy1;
				dy3 += dy1;
			}
		}
*/

		glEnd();
	};

	void drawNormal() {

	


	};


protected:


	std::vector<Point> getTopPoints(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> top;// = new std::vector<Point>;
		double r = .5;
		double z = .5;
		double x, y;
		top.push_back(Point(0, .5, 0));
		for (int i = 0; i <= m_segmentsX; i++) {
			x = r * cos(2*PI*i/m_segmentsX);
			y = r * sin(2*PI*i/m_segmentsX);
			top.push_back(Point(x, z, y));
		}
		return top;

	}

	std::vector<Point> getBottomPoints(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> bottom;// = new std::vector<Point>;
		double r = .5;
		double z = -.5;
		double x, y;
		bottom.push_back(Point(0, -.5, 0));
		for (int i = 0; i < m_segmentsX; i++) {
			x = r * cos(2*PI*i/m_segmentsX);
			y = r * sin(2*PI*i/m_segmentsX);
			bottom.push_back(Point(x, z, y));
		}
		return bottom;
	}

	// returns vector of side points in order top to bottom and then around ... does that make sense
	std::vector<Point> getSidePoints(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> points;
		double r, x, y, z, theta;
		double a, b; 

		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY; j++) {
				z = 0.5 - (j + 0.0) / m_segmentsY;
				r = SQR(.5) + SQR(z);
				theta = 2.0 * PI * i / m_segmentsX;
				x = r * cos(theta);
				y = r * sin(theta);
				points.push_back(Point(x, z, y));
			}
		}
		return points;
	}
};

#endif
