#ifndef FORMAS_H
#define FORMAS_H 

#include <cmath>
#include "formas.h"
#include <GL/glut.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/glu.h>
#include "textura.h"
#include "stb_image.h"
//#include "fonteluz.h"


class Formas {
private:
public:
    Formas();
    static void esferaNuvem();
    static void estrelaObstaculo();
    static void estrelaPersonagem();
    //void desenhaLuz();

};

#endif // FORMAS_H