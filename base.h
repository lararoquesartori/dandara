#ifndef BASE_H
#define BASE_H

#include <glm/glm.hpp>


class Base {
private:
    glm::vec2 posicao;
    glm::vec3 corBase;
    float distanciaEntreBases;
    float altura;
public:
    Base(float x, float y);
    bool isOutFrente();
    bool isOutTras();
    void move(float tamanho);
    void respawnFrente();
    void respawnTras();
    void desenha();
};

#endif // BASE_H