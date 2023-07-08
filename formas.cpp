#include "formas.h"
#define TEXTURA_PERSONAGEM_ARQ "texturas/Personagem.jpg"
#define TEXTURA_O_ARQ "texturas/obstaculos.jpg"

Formas::Formas() {
   
}

void Formas::esferaNuvem() {
    float pi = 3.14;
        for(int i = 0; i < 36; i++) {
            float theta1 = i * 2.0 * pi / 36;
            float theta2 = (i + 1) * 2.0 * pi / 36;

            glBegin(GL_QUAD_STRIP);
            for (int j = 0; j <= 50; j++) {
                float phi = j * pi / 50;
                float x, y, z;

                // Cálculo das coordenadas x, y, z do ponto
                x =  cos(theta2) * sin(phi);
                y =  sin(theta2) * sin(phi);
                z =  cos(phi);
                glVertex3f(x, y, z);

                x =  cos(theta1) * sin(phi);
                y =  sin(theta1) * sin(phi);
                z =  cos(phi);
                glVertex3f(x, y, z);
            }
            glEnd();
        }
    }


void Formas::estrelaPersonagem() {
    Textura instanciaTexturaPersonagem;
    unsigned int texturaPersonagemId = instanciaTexturaPersonagem.carregaTextura(TEXTURA_PERSONAGEM_ARQ);
    glBindTexture(GL_TEXTURE_2D, texturaPersonagemId); //ativando a textura
    
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.25, 0.5);//A
    glVertex3f(0,0,0.25);
    glTexCoord2f(0.25,1);//B
    glVertex3f(0,1,0);
    glTexCoord2f(0.5,1);//C
    glVertex3f(0.25,0.25,0);
    glTexCoord2f(0.5, 0.5);//D
    glVertex3f(1, 0, 0);
    glTexCoord2f(0.5, 0);//E
    glVertex3f(0.25,-0.25,0);
    glTexCoord2f(0.25, 0);//F
    glVertex3f(0, -1, 0);
    glTexCoord2f(0, 0);//G
    glVertex3f(-0.25, -0.25, 0);
    glTexCoord2f(0, 0.5);//H
    glVertex3f(-1, 0, 0);
    glTexCoord2f(0, 1);//I
    glVertex3f(-0.25, 0.25, 0);
    glTexCoord2f(0.25, 1);//B
    glVertex3f(0, 1, 0);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.75, 0.5);//J
    glVertex3f(0, 0, -0.25);
    glTexCoord2f(0.75, 1);//K
    glVertex3f(0, 1, 0);
    glTexCoord2f(1, 1);//L
    glVertex3f(0.25, 0.25, 0);
    glTexCoord2f(1, 0.5);//M
    glVertex3f(1, 0, 0);
    glTexCoord2f(1, 0);//N
    glVertex3f(0.25, -0.25, 0);
    glTexCoord2f(0.75, 0);//O
    glVertex3f(0, -1, 0);
    glTexCoord2f(0.5, 0);//E
    glVertex3f(-0.25, -0.25, 0);
    glTexCoord2f(0.5, 0.5);//D
    glVertex3f(-1, 0, 0);
    glTexCoord2f(0.5, 1);//C
    glVertex3f(-0.25, 0.25, 0);
    glTexCoord2f(0.75, 1);//K
    glVertex3f(0, 1, 0);
    glEnd();
 }

void Formas::estrelaObstaculo() {
    Textura instanciaTexturaObstaculo;
    unsigned int texturaObstaculoId = instanciaTexturaObstaculo.carregaTextura(TEXTURA_O_ARQ);
    glBindTexture(GL_TEXTURE_2D, texturaObstaculoId); //ativando a textura
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.25, 0.5);//A
    glVertex3f(0, 0, 0.25);
    glTexCoord2f(0.25, 1);//B
    glVertex3f(0, 1, 0);
    glTexCoord2f(0.5, 1);//C
    glVertex3f(0.25, 0.25, 0);
    glTexCoord2f(0.5, 0.5);//D
    glVertex3f(1, 0, 0);
    glTexCoord2f(0.5, 0);//E
    glVertex3f(0.25, -0.25, 0);
    glTexCoord2f(0.25, 0);//F
    glVertex3f(0, -1, 0);
    glTexCoord2f(0, 0);//G
    glVertex3f(-0.25, -0.25, 0);
    glTexCoord2f(0, 0.5);//H
    glVertex3f(-1, 0, 0);
    glTexCoord2f(0, 1);//I
    glVertex3f(-0.25, 0.25, 0);
    glTexCoord2f(0.25, 1);//B
    glVertex3f(0, 1, 0);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.75, 0.5);//J
    glVertex3f(0, 0, -0.25);
    glTexCoord2f(0.75, 1);//K
    glVertex3f(0, 1, 0);
    glTexCoord2f(1, 1);//L
    glVertex3f(0.25, 0.25, 0);
    glTexCoord2f(1, 0.5);//M
    glVertex3f(1, 0, 0);
    glTexCoord2f(1, 0);//N
    glVertex3f(0.25, -0.25, 0);
    glTexCoord2f(0.75, 0);//O
    glVertex3f(0, -1, 0);
    glTexCoord2f(0.5, 0);//E
    glVertex3f(-0.25, -0.25, 0);
    glTexCoord2f(0.5, 0.5);//D
    glVertex3f(-1, 0, 0);
    glTexCoord2f(0.5, 1);//C
    glVertex3f(-0.25, 0.25, 0);
    glTexCoord2f(0.75, 1);//K
    glVertex3f(0, 1, 0);
    glEnd();
}
