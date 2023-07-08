#include "base.h"
#include "formas.h"
#include <cstdlib>
#include <GL/glut.h>

Base::Base(float x, float y) {
    posicao = glm::vec2(x, y);
    corBase = glm::vec3(0.1, 0.1, 0.1);
    distanciaEntreBases = 0.000000000001;
}

bool Base::isOutFrente() {
    return posicao.x < 0 - distanciaEntreBases;
}

bool Base::isOutTras() {
    return posicao.x > 6 + distanciaEntreBases;
}

void Base::move(float tamanho) {
    posicao.x = posicao.x - tamanho;
}

void Base::respawnFrente() {
        posicao.x = 6 + distanciaEntreBases + 1;
}

void Base::respawnTras() {
    posicao.x = 0 - distanciaEntreBases - 1;
}

void Base::desenha() {

    //base superior
    glPushMatrix();
    glTranslatef(posicao.x - 0.25, posicao.y - 0.5, 0);
    glColor3f(corBase.r, corBase.g, corBase.b);
    Formas::esferaNuvem();
    glPopMatrix();

    //base infeiror
    glPushMatrix();
    glTranslatef(posicao.x, posicao.y - 4.70, 0);
    Formas::esferaNuvem();
    glPopMatrix();
}