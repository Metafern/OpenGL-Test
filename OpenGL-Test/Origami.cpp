#include "Origami.h"

using namespace std;

Paper::Paper() {
	divisions = 4;

}

void Paper::makePoints() {

	float x = 0;
	float y = 0;
	float z = 0;

	int total = divisions * divisions + divisions - 1;
	int r = 0;

	for (int i = 0; i < total; i++) {
		vertexMap.push_back(x);
		vertexMap.push_back(y);
		vertexMap.push_back(z);

		
		if (x >= divisions - r) {
			x = x + 0.5 - divisions;
			y += sqrt(3) / 2;

			r = (r + 1) % 2;
		}
		else {
			x++;
		}
	}
}

void Paper::makeTriangles() {
	int p1 = 0;
	int p2;
	int p3;
	int rows = 3;

	for (int r = 0; r < rows; r++) {
		for (int i = 0; i < divisions - r % 2; i++) {
			p2 = p1 + 1;
			p3 = p2 + divisions;

			indicesMap.push_back(p1);
			indicesMap.push_back(p2);
			indicesMap.push_back(p3);
			printf("%d %d %d\n", p1, p2, p3);

			p1++;
		}
		p1++;
	}
}

std::vector<GLfloat> Paper::getMap() {
	vector<GLfloat> vertices;

	for (int i = 0; i < vertexMap.size(); i+=3) {

		float p1 = 1.0f / divisions * vertexMap[i] - 0.5;
		float p2 = 1.0f / divisions * vertexMap[i + 1] - 0.5;
		float p3 = 0;

		//points
		vertices.push_back(p1);
		vertices.push_back(p2);
		vertices.push_back(p3);

		//color 0.8f, 0.3f, 0.02f
		vertices.push_back(0.8f);
		vertices.push_back(0.3f);
		vertices.push_back(0.02f);
	}

	return vertices;
}
