#ifndef TEXTURA_H
#define TEXTURA_H
#include "formas.h"
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/glut.h>


class Textura{
public:
	Textura();
	unsigned int carregaTextura(const char fileName[]);
};

#endif // TEXTURA_H

