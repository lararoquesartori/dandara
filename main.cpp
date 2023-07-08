#include <GL/glut.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>
#include <glm/ext.hpp>
#include <GL/glu.h>


#include "base.h"
#include "obstaculo.h"
#include "personagem.h"

using namespace std;

//variaveis globais da janela
int larguraJanela = 640;
int alturaJanela = 360;
float aspctRatio;

//variáveis globais relacionadas a câmera
glm::vec4 camPos(6, 6, 1, 1);//posição inicial da câmera
bool      camMove = true;//liga/desliga movimentação da câmera
bool      showEixos = true;
unsigned int texLuaId; //identificador da textura do chão


// Variáveis globais
float frameRate = 100;
Personagem personagem;

Obstaculo obstaculo1(5);
Obstaculo obstaculo2(9);
Obstaculo obstaculo3(10);

vector<Obstaculo> obstaculos;

float y = 4.5;
Base base1(1, y);
Base base2(2, y);
Base base3(3, y);
Base base4(4, y);
Base base5(5, y);
Base base6(6, y);
Base base7(7, y);

vector<Base> bases;

// Função com configurações iniciais da aplicação
void inicio() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //glEnable(GL_DEPTH_TEST);          //habilitando a remoção de faces que estejam atrás de outras (ocultas)


    obstaculos.push_back(obstaculo1);
    obstaculos.push_back(obstaculo2);
    obstaculos.push_back(obstaculo3);

    bases.push_back(base1);
    bases.push_back(base2);
    bases.push_back(base3);
    bases.push_back(base4);
    bases.push_back(base5);
    bases.push_back(base6);
    bases.push_back(base7);
}

void teclado(unsigned char tecla, int x, int y) {
    if (tecla == 'd') {
        glPushMatrix();
        personagem.mudarBase(0.0, 2.25);

        personagem.anguloRotacao += 180.0;
        if (personagem.anguloRotacao <= 360.0) {
            personagem.anguloRotacao -= 360.0;
        }

        glPopMatrix();
        for (unsigned int i = 0; i < 7; i++) {
            bases[i].move(0.5);
            if (bases[i].isOutFrente()) bases[i].respawnFrente();
        }
        for (unsigned int i = 0; i < obstaculos.size(); i++) {
            obstaculos[i].move(0.5);
            if (obstaculos[i].isOutFrente()) obstaculos[i].respawnFrente();
        }
    }

    if (tecla == 'a') {
        glPushMatrix();
        personagem.mudarBase(0.0, 2.25);

        personagem.anguloRotacao += 180.0;
        if (personagem.anguloRotacao <= 360.0) {
            personagem.anguloRotacao -= 360.0;
        }

        glPopMatrix();
        for (unsigned int i = 0; i < 7; i++) {
            bases[i].move(-0.5);
            if (bases[i].isOutTras()) bases[i].respawnTras();
        }
        for (unsigned int i = 0; i < obstaculos.size(); i++) {
            obstaculos[i].move(-0.5);
            if (obstaculos[i].isOutTras()) obstaculos[i].respawnTras();
        }
    }
}

void timer(int v) {
    glutTimerFunc(1000.0 / frameRate, timer, 0);
    for (unsigned int i = 0; i < obstaculos.size(); i++) {
        obstaculos[i].move(1.0 / frameRate);
        if (obstaculos[i].isOutFrente()) obstaculos[i].respawnFrente();
    }

    glutPostRedisplay();
}

void desenha() {
    glViewport(0, 0, larguraJanela, alturaJanela);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definição da área do sistema de coordenadas do mundo 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 6, 0, 4, 0, 10);
    //gluPerspective(50, larguraJanela/alturaJanela, 0.1, 3000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (unsigned int i = 0; i < 6; i++) bases[i].desenha();
    for (unsigned int j = 0; j < 3; j++) obstaculos[j].desenha();
    personagem.desenha();

    for (unsigned int j = 0; j < 3; j++) {
        obstaculos[j].desenha();
        if (personagem.verificarColisao(obstaculos[j])) {
            // Colisão detectada, interrompe o jogo
            cout << "Voce perdeu!" << endl;
            exit(0);
        }
    }
    //definindo o posicionamento da câmera
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glm::mat4 matrizProjecao = glm::perspective(glm::radians(45.0f),               //ângulo de abertura do frustum
        (float)larguraJanela / alturaJanela, //aspect ratio do plano de projeção
        1.0f, 100.0f);                     //near e far (limites na profundidade do volume de visualização)
    glMultMatrixf(glm::value_ptr(matrizProjecao));
   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glm::mat4 matrizCamera = glm::lookAt(glm::vec3(camPos), //eye = posição da câmera
        glm::vec3(0, 6, 0),  //at  = para onde a câmera aponta
        glm::vec3(0, 1, 0)); //up  = para onde o topo da câmera aponta
    glMultMatrixf(glm::value_ptr(matrizCamera)); //criada a matriz usando GLM, deve-se enviá-la para OpenGL

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(larguraJanela, alturaJanela);
    glutCreateWindow("Transformacoes Geometricas 2D - OpenGL Classico");

    inicio();

    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glutTimerFunc(1000.0 / frameRate, timer, 0);

    glutMainLoop();

    return 0;
}
