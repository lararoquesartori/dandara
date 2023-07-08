#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <glm/glm.hpp>
#include "obstaculo.h"
//#include "fonteluzPersonagem.h"

class Personagem {
private:
    //FonteLuzPersonagem instanciaLuz;
    glm::vec3 posicao;
    glm::vec3 corPersonagem;
    float tamanho;
public:
    Personagem();
    float anguloRotacao;
    void desenha();
    bool mudarBase(float a, float b);
    bool verificarColisao(const Obstaculo& obstaculo) const;

    glm::vec3 getPosicao() const;
    float getTamanho() const;
};

#endif // PERSONAGEM_H