#include "triangle.h"
// triangle.cpp


std::ostream& operator<<(std::ostream& os, const coords& _Val)
{
	os << "(" << _Val.first << "|" << _Val.second << ")";
	return os;
}

std::ostream& operator<<(std::ostream& os, const triangle& _Val)
{
	os << "[" << _Val.getCoords(0) << " " << _Val.getCoords(1) << " " << _Val.getCoords(2) << "]";
	return os;
}

std::ostream& operator<<(std::ostream& os, const triangleContainer& _Val)
{
	for (int i = 0; i < _Val.length(); ++i)
	{
		os << *_Val._pTriangleField[i] << "\n";
	}

	return os;
}

// class: triangle
triangle::triangle() : _pCoords() 
{
	for (int i = 0; i < anzTriangleCoords; i++) 
	{
		this->_pCoords[i] = NULL;
	}
}

triangle::triangle(const coords& _Val1, const coords& _Val2, const coords& _Val3) : _pCoords() {
	setCoords(0, _Val1);
	setCoords(1, _Val2);
	setCoords(2, _Val3);
}

triangle::triangle(const triangle& _Val) : _pCoords()
{
	setCoords(0, _Val.getCoords(0));
	setCoords(1, _Val.getCoords(1));
	setCoords(2, _Val.getCoords(2));
}

triangle::~triangle()
{
	delete[] * this->_pCoords;
}

triangle& triangle::operator=(const triangle& _Other)
{
	for (int i = 0; i < anzTriangleCoords; i++)
	{
		this->_pCoords[i] = new coords(_Other._pCoords[i]->first, _Other._pCoords[i]->second);
	}

	return *this;
}

bool triangle::setCoords(int _Idx, const coords& _Val)
{
	if (_Idx >= 0 && _Idx < anzTriangleCoords)
	{
		this->_pCoords[_Idx] = new coords(_Val.first, _Val.second);
		return true;
	}
	
	return false;
}

const coords& triangle::getCoords(int _Idx) const
{
	return *this->_pCoords[_Idx];
}

// class: triangleContainer
triangleContainer::triangleContainer(int _Val) : _pTriangleField()
{
	this->_length = _Val;

	for (int i = 0; i < maxTriangles; i++)
	{
		this->_pTriangleField[i] = NULL;
	}
}

triangleContainer::~triangleContainer()
{
	delete[] * this->_pTriangleField;
}

triangleContainer::triangleContainer(const triangleContainer& _Other) : _pTriangleField()
{
	this->_length = _Other._length;

	for (int i = 0; i < _length; i++)
	{
		this->_pTriangleField[i] = new triangle(_Other.getTriangle(i));
	}

	for (int i = _length; i < maxTriangles; i++)
	{
		this->_pTriangleField[i] = NULL;
	}
}

triangleContainer& triangleContainer::operator=(const triangleContainer& _Other)
{
	this->_length = _Other._length;

	for (int i = 0; i < _length; i++)
	{
		this->_pTriangleField[i] = new triangle(_Other.getTriangle(i));
	}

	for (int i = _length; i < maxTriangles; i++)
	{
		this->_pTriangleField[i] = NULL;
	}

	return *this;
}

int triangleContainer::length() const
{
	return this->_length;
}

bool triangleContainer::addTriangle(const triangle& _Val)
{
	for (int i = 0; i < _length; i++)
	{
		if (this->_pTriangleField[i] == nullptr)
		{
			this->_pTriangleField[i] = new triangle(_Val);
			return true;
		}
	}
	
	return false;
}

bool triangleContainer::changeTriangle(int _Idx, const triangle& _val)
{
	if (_pTriangleField[_Idx] == nullptr)
	{
		return false;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (!_pTriangleField[_Idx]->setCoords(i, _val.getCoords(i)))
		{
			return false;
		}
	}

	return true;
}

const triangle& triangleContainer::getTriangle(int idx) const
{
	return *(this->_pTriangleField[idx]);
}