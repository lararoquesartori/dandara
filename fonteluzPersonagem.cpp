#include "fonteluzPersonagem.h"


FonteLuzPersonagem::FonteLuzPersonagem() {
    luzPos = glm::vec3(0, 0, 0);// instanciaPersonagem.getPosicao();
    luzAmb = glm::vec3(0.1, 0.1, 0.1);
    luzDiff = glm::vec3(1, 1, 1);
    luzSpec = glm::vec3(1, 1, 1);
}

const glm::vec3& FonteLuzPersonagem::getLuzPos() const {
    return luzPos;
}

const glm::vec3& FonteLuzPersonagem::getLuzAmb() const {
    return luzAmb;
}

const glm::vec3& FonteLuzPersonagem::getLuzDiff() const {
    return luzDiff;
}

const glm::vec3& FonteLuzPersonagem::getLuzSpec() const {
    return luzSpec;
}

void FonteLuzPersonagem::setLuzPos(const glm::vec3& newLuzPos) {
    luzPos = newLuzPos;
}

void FonteLuzPersonagem::setLuzAmb(const glm::vec3& newLuzAmb) {
    luzAmb = newLuzAmb;
}

void FonteLuzPersonagem::setLuzDiff(const glm::vec3& newLuzDiff) {
    luzDiff = newLuzDiff;
}

void FonteLuzPersonagem::setLuzSpec(const glm::vec3& newLuzSpec) {
    luzSpec = newLuzSpec;
}

glm::vec3 FonteLuzPersonagem::iluminacao(glm::vec3 P, glm::vec3 camPos, glm::vec3 matAmb, glm::vec3 matDiff, glm::vec3 matSpec, float matShine, glm::vec3 n) {
    glm::vec3 amb = luzAmb * matAmb;

    glm::vec3 l = glm::vec3(luzPos) - P;
    l = glm::normalize(l);
    n = glm::normalize(n);
    glm::vec3 dif = luzDiff * matDiff * glm::max(0.0f, glm::dot(l, n));

    glm::vec3 v = glm::vec3(camPos) - P;
    v = glm::normalize(v);
    glm::vec3 r = 2 * glm::dot(n, l) * n - l;
    glm::vec3 esp = luzSpec * matSpec * (float)(pow(glm::max(0.0f, glm::dot(v, r)), matShine));

    return amb + dif + esp;
}

void FonteLuzPersonagem::desenha() {
    glPointSize(10);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    glVertex3f(luzPos.x, luzPos.y, luzPos.z);
    glEnd();
}