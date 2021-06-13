#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Paper {

public:
	Paper();
	
	int divisions;
	std::vector<GLfloat> vertexMap;
	std::vector<GLuint> indicesMap;
	void makePoints();
	void makeTriangles();
	std::vector<GLfloat> getMap();
};