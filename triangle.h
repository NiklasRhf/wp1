#include <ostream>
// triangle.h

// An die notwendigen Includes denken...

// struct: coords
struct coords {
	coords() : first(), second() {};
	coords(const float _Val1, const float _Val2)
		: first(_Val1), second(_Val2) {};

	float first;
	float second;
};

// class: triangle 
static const int anzTriangleCoords = 3;

class triangle {
	friend	std::ostream& operator<<(std::ostream &os, const triangle &_Val);
	friend class triangleContainer;

	coords *_pCoords[anzTriangleCoords];

protected:
	const coords& getCoords(int _Idx) const;

public:
	triangle();
	triangle(const coords &_Val1, const coords &_Val2, const coords &_Val3);
	triangle(const triangle& _Val);
	~triangle();

	triangle& operator=(const triangle &_Other);
	bool setCoords(int _Idx, const coords &_Val);
};

// class: triangleContainer
static const int maxTriangles = 100;

class triangleContainer
{
	friend std::ostream& operator<<(std::ostream &os, const triangleContainer &_Val);

	int _length{ 0 };
	triangle *_pTriangleField[maxTriangles];

protected:
	const triangle& getTriangle(int _Idx) const;

public:
	triangleContainer(int _Val);
	triangleContainer(const triangleContainer &_Val);
	~triangleContainer();

	triangleContainer& operator=(const triangleContainer &_other);
	int length() const;
	bool addTriangle(const triangle &_Val);
	bool changeTriangle(int _Idx, const triangle &_val);
};

// Prototyping für die Ausgabe-Funktionen
std::ostream& operator<<(std::ostream &os, const coords &_Val);
std::ostream& operator<<(std::ostream &os, const triangle &_Val);
std::ostream& operator<<(std::ostream &os, const triangleContainer &_Val);
