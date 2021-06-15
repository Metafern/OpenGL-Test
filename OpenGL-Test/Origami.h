#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Paper {

public:
	Paper();
	
	int divisions;
	int rows;
	int columns;
	int total;

	std::vector<GLfloat> vertexMap;
	std::vector<GLuint> indicesMap;
	void makePoints();
	void makeTriangles();
	std::vector<GLfloat> getMap();
};