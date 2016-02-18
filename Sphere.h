#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
	Sphere() {};
	~Sphere() {};

	void draw() {
		Shape shape;

		Point top = Point(0, .5, 0);
		Point bottom = Point(0, -.5, 0);
		std::vector<Point> top_points = getTopPoints(m_segmentsX, m_segmentsY);
		std::vector<Point> bottom_points = getBottomPoints(m_segmentsX, m_segmentsY);
		std::vector<Point> points = getSidePoints(m_segmentsX, m_segmentsY);

		glBegin(GL_TRIANGLES);
		for (int i = 1; i < m_segmentsX; i++) {
			double x1 = top_points[i][0];
			double y1 = top_points[i][1];
			double z1 = top_points[i][2];
			double x2 = top_points[i+1][0];
			double y2 = top_points[i+1][1];
			double z2 = top_points[i+1][2];
			double x3 = bottom_points[i][0];
			double y3 = bottom_points[i][1];
			double z3 = bottom_points[i][2];
			double x4 = bottom_points[i+1][0];
			double y4 = bottom_points[i+1][1];
			double z4 = bottom_points[i+1][2];

			glVertex3f(x1, y1, z1);
			glVertex3f(x2, y2, z2);
			glVertex3f(0, .5, 0);

			glVertex3f(x3, y3, z3);
			glVertex3f(x4, y4, z4);
			glVertex3f(0, -.5, 0);

		}
		//glColor3f(1.0, 0.0, 0.0);
		glVertex3f(top_points[m_segmentsX][0], top_points[m_segmentsX][1], top_points[m_segmentsX][2]);
		glVertex3f(0, .5, 0);
		glVertex3f(top_points[1][0], top_points[1][1], top_points[1][2]);

		//glColor3f(1.0, 0.0, 0.0);
		glVertex3f(bottom_points[m_segmentsX][0], bottom_points[m_segmentsX][1], bottom_points[m_segmentsX][2]);
		glVertex3f(0, -0.5, 0);
		//glVertex3f(bottom_points[0][0], bottom_points[0][1], bottom_points[0][2]);
		glVertex3f(bottom_points[1][0], bottom_points[1][1], bottom_points[1][2]);
		
		
		// glVertex3f(bottom_points[m_segmentsX + 1][0], bottom_points[m_segmentsX+1][1], bottom_points[m_segmentsX+1][2]);
		// glVertex3f(bottom_points[0][0], bottom_points[0][1], bottom_points[0][2]);
		// glVertex3f(bottom_points[1][0], bottom_points[1][1], bottom_points[1][2]);
		

		
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


		glEnd();


	};

	void drawNormal() {
	};

protected:

	// returns vector of points for the top ring (to make the top part of the sphere)
	std::vector<Point> getTopPoints(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> top;// = new std::vector<Point>;
		double x, y, z, theta;
		double phi = PI / m_segmentsY;
		double r = .5;
		for (int i = 0; i <= m_segmentsX; i++) {
			theta = 2.0 * PI * i / m_segmentsX;
			x = r * cos(theta) * sin(phi);
			y = r * sin(theta) * sin(phi);
			z = r * cos(phi);
			top.push_back(Point(x, z, y));
		}

		return top;

	}


	// returns vector of points for the bottom ring 
	std::vector<Point> getBottomPoints(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> bottom;// = new std::vector<Point>;
		double x, y, z, theta;
		double phi = PI - (PI / m_segmentsY);
		double r = .5;
		for (int i = 0; i <= m_segmentsX; i++) {
			theta = 2.0 * PI * i / m_segmentsX;
			x = r * cos(theta) * sin(phi);
			y = r * sin(theta) * sin(phi);
			z = r * cos(phi);
			bottom.push_back(Point(x, z, y));
		}

		return bottom;
	}


	// returns vector of side points in order top to bottom and then around ... does that make sense
	std::vector<Point> getSidePoints(int m_segmentsX, int m_segmentsY) {
		std::vector<Point> points;
		double x, y, z, theta, phi;
		double r = .5;
		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY; j++) {
				theta = 2.0 * PI * i / m_segmentsX;
				phi = PI * j / m_segmentsY;
				x = r * cos(theta) * sin(phi);
				y = r * sin(theta) * sin(phi);
				z = r * cos(phi);
				points.push_back(Point(x, z, y));
			}
		}
		return points;
	}
};

#endif
