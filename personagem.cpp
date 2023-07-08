#include "personagem.h"
#include "formas.h"
#include <GL/glut.h>
#include <glm/glm.hpp>
//#include "fonteluz.h"

Personagem::Personagem() {
    posicao = glm::vec3(3, 0.75, 0);
    corPersonagem = glm::vec3(1, 1, 0);
    tamanho = 0.2;
    anguloRotacao = 0.0;
   // fonteLuz.setLuzPos(glm::vec3(posicao.x+1, posicao.y, 0)); // Configura a posição da fonte de luz
}

bool Personagem::mudarBase(float a, float b) {
    if (posicao.y == 0.75) {
        posicao.x = posicao.x + a;
        posicao.y = posicao.y + b;
       // instanciaLuz.setLuzPos(glm::vec3(posicao.x, posicao.y, 0));
    }
    else {
        posicao.x = posicao.x + a;
        posicao.y = posicao.y - b;
       // instanciaLuz.setLuzPos(glm::vec3(posicao.x, posicao.y, 0));
    }
    //fonteLuz.setLuzPos(glm::vec3(posicao.x+1, posicao.y, 0));
    return true;
}

glm::vec3 Personagem::getPosicao() const {
    return posicao;
}

float Personagem::getTamanho() const {
    return tamanho;
}

void Personagem::desenha() {
    glPushMatrix();
    glTranslatef(posicao.x, posicao.y, 0);
    glRotatef(anguloRotacao, 0.0, 0.0, 1.0);
    glTranslatef(-tamanho / 1.0f, -tamanho / 1.0f, 0);
    glScalef(tamanho, tamanho, 1);
        
    // Calcular iluminação de Phong
    //glm::vec3 corIluminada = fonteLuz.iluminacao(glm::vec3(posicao.x+1, posicao.y, 0), glm::vec3(1, 2.5, 0), corPersonagem, corPersonagem, corPersonagem, 32, glm::vec3(0, 0, 1));

    // Aplicar cor iluminada
    //glColor3f(corIluminada.r, corIluminada.g, corIluminada.b);

    // Desenhar personagem
    Formas::estrelaPersonagem();

    glPopMatrix();
}

bool Personagem::verificarColisao(const Obstaculo& obstaculo) const {
    glm::vec2 posicaoObstaculo = obstaculo.getPosicao();
    float tamanhoObstaculo = obstaculo.getTamanho();

    // Verificar colisão horizontal
    bool colisaoHorizontal = posicao.x + tamanho >= posicaoObstaculo.x &&
        posicaoObstaculo.x + tamanhoObstaculo >= posicao.x;

    // Verificar colisão vertical
    bool colisaoVertical = posicao.y + tamanho >= posicaoObstaculo.y &&
        posicaoObstaculo.y + tamanhoObstaculo >= posicao.y;

    return colisaoHorizontal && colisaoVertical;
}
