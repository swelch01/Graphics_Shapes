all:
	g++ -Wall -Wextra Assignment1.cpp -L ~/Desktop/Comp175/glui-2.36/src/lib -I ~/Desktop/Comp175/glui-2.36/src/include -framework OpenGL -lglui -framework GLUT -o a1