#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"

class Cylinder : public Shape {
public:
	Cylinder() {
	};
	~Cylinder() {};



	void draw() {
		Shape shape;
		glBegin(GL_TRIANGLES);

		std::vector<Point> top = getTopPoints(m_segmentsX, m_segmentsY);
		std::vector<Point> bottom = getBottomPoints(m_segmentsX, m_segmentsY);

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
		//glColor3f(1.0, 0.0, 0.0);
		glVertex3f(top[m_segmentsX][0], top[m_segmentsX][1], top[m_segmentsX][2]);
		glVertex3f(0, .5, 0);
		glVertex3f(top[1][0], top[1][1], top[1][2]);

		glVertex3f(bottom[m_segmentsX][0], bottom[m_segmentsX][1], bottom[m_segmentsX][2]);
		glVertex3f(bottom[0][0], bottom[0][1], bottom[0][2]);
		glVertex3f(bottom[1][0], bottom[1][1], bottom[1][2]);
		

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


		glEnd();
	};

	void drawNormal() {

		std::vector<Point> top = getTopPoints(m_segmentsX,m_segmentsY);
		std::vector<Point> bottom = getBottomPoints(m_segmentsX, m_segmentsY);

		glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		//double r, t, z;
		
		//double dy = 1.0/m_segmentsY;
		/*double dy2 = dy1;
		double dy3 = 0;
		*/

		/*for (int i = 1; i < top.size() + 1; i++) {
			for (int j = 0; j < m_segmentsY; j++) {
				double x1 = top[i][0];
				double y1 = top[i][1];
				double z1 = top[i][2] + j*dy;
				r = sqrt(SQR(x1) + SQR(y1));
				t = atan(y1/x1) ;
				glVertex3f(x1, z1, y1);
				glVertex3f(r*cos(t), z1, r*sin(t));

			}
		} */
		for (int i = 1; i <= m_segmentsX; i++) {
			double dy1 = 1.0/m_segmentsY;
			double dy2 = dy1;
			double dy3 = 0;
			for (int j = 0; j < m_segmentsY; j++){
				std::vector<Vector> CPvector;
				double x1 = top[i][0];
				double y1 = top[i][1];
				double z1 = top[i][2];
				double x2 = top[i+1][0];
				double y2 = top[i+1][1];
				double z2 = top[i+1][2];
				//std::cout<<"Y1, y2: "<<y1<<", "<<y2<<std::endl;

				CPvector.push_back(Vector(x1, y1-dy3, z1));
				CPvector.push_back(Vector(x2, y2-dy3, z2));
				CPvector.push_back(Vector(x2, y2-dy2, z2));
				CPvector.push_back(Vector(x1, y1-dy2, z1));

				Vector v1 = cross(CPvector[1],CPvector[3]);
				double v1x = v1[0];
				double v1y = v1[1];
				double v1z = v1[2];
				Vector v2 = cross(CPvector[1],CPvector[2]);
				double v2x = v2[0];
				double v2y = v2[1];
				double v2z = v2[2];
				Vector v3 = cross(CPvector[2], CPvector[1]);
				double v3x = v3[0];
				double v3y = v3[1];
				double v3z = v3[2];
				//std::cout<<"v1x, v2x, v3x: "<<v1x<<", "<<v2x<<", "<<v3x<<std::endl;
				Vector v4 = cross(CPvector[4], CPvector[5]);
				double v4x = v3[0];
				double v4y = v3[1];
				double v4z = v3[2];
				for (int h = 4; h > 0; h--){
					CPvector.pop_back();
				}
				glVertex3f(1 + v1x, 1 + v1z, 1 + v1y);
				glVertex3f(x1, y1-dy3, z1);
				//std::cout<<"x1, y1-dy3, z1: "<<x1<<", "<<y1-dy3<<", "<<z1<<std::endl;
				//glVertex3f(2.0*v1x, 2.0*v1y, 2.0*v1z);
				//std::cout<<"v1x, v1y, v1z: "<<v1x<<", "<<v1y<<", "<<v1z<<std::endl;

				//glVertex3f(x2, y2-dy3, z2);
				//glVertex3f(1.5*v2x, 1.5*v2y, 1.5*v2z);

				//glVertex3f(x2, y2-dy2, z2);
				//glVertex3f(1.5*v3x, 1.5*v3y, 1.5*v3z);

				//glVertex3f(x1, y1-dy3, z1);
				//glVertex3f(v3x, v3y, v3z);

				//glVertex3f(x1, y1-dy2, z1);
				//glVertex3f(1.5*v4x, 1.5*v4y, 1.5*v4z);

				//glVertex3f(x2, y2-dy2, z2);
				//glVertex3f(v3x, v3y, v3z);

				dy2 += dy1;
				dy3 += dy1;
			}
		}
	
		glEnd();
	};


protected:

inline Vector cross(const Vector& u, const Vector& v) {
	Vector t(u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]);
	return t;
};

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

	/*

	std::vector<Point> * getSidePoints(int m_segmentsX, int m_segmentsY, std::vector<Point> top_points){
		std::vector<Point> *sides = new std::vector<Point>[m_segmentsY];
	 

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
*/

};
#endif
