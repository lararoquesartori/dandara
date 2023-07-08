#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <glm/glm.hpp>
//#include <cstdlib>
//#include "fonteluzObstaculo.h"

class Obstaculo {
private:
   // FonteLuzObstaculo instanciaLuz;
    glm::vec3 posicao;
    glm::vec2 cor;
    float largura;
    float velocidade;
public:
    Obstaculo();
    Obstaculo(float x);
    bool isOutFrente();
    bool isOutTras();
    void move(float tempo);
    void respawnFrente();
    void respawnTras();
    void desenha();
    glm::vec3 getPosicao() const;
    float getTamanho() const;
};

#endif // OBSTACULO_H