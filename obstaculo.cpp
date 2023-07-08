#include "obstaculo.h"
#include "formas.h"
#include <GL/glut.h>
#include <glm/glm.hpp>

Obstaculo::Obstaculo(float x) {
    posicao = glm::vec3(x, rand() % 2 == 0 ? 0.5 : 4.5, 0);
    velocidade = 3;
    largura = 0.5;
}


bool Obstaculo::isOutFrente() {
    return posicao.x < 0 - largura;
}

bool Obstaculo::isOutTras() {
    return posicao.x > 6 + largura;
}
void Obstaculo::move(float tempo) {
    posicao.x = posicao.x - velocidade * tempo;
    //instanciaLuz.setLuzPos(glm::vec3(posicao.x, posicao.y, 0));
}

void Obstaculo::respawnFrente() {
    posicao.x = 6 + largura;
    posicao.y = 1 + rand() % 10;
}

void Obstaculo::respawnTras() {
    posicao.x = 0 - largura -1 ;
    posicao.y =1 + rand() % 10;
}

void Obstaculo::desenha() {
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(posicao.x, posicao.y, 0);
    glScalef(largura, largura, 1);
    Formas::estrelaObstaculo();
    glPopMatrix();
}

glm::vec3 Obstaculo::getPosicao() const {
    return posicao;
}

float Obstaculo::getTamanho() const {
    return largura;
}