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

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0.25);
    glVertex3f(0.25, 0.25, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(-0.25, 0.25, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(-0.25, -0.25, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0.25, -0.25, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0.25, 0.25, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, -0.25);
    glVertex3f(0.25, 0.25, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(-0.25, 0.25, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(-0.25, -0.25, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0.25, -0.25, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0.25, 0.25, 0);
    glEnd();
    glPopMatrix();



    /*
    //carregando as texturas que serão utilizadas
        glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0, 0.25);//v[0]
        glVertex3f(0.25, 0.25, 0);//v[6]
        glVertex3f(0, 1, 0);//v[4]
        glVertex3f(-0.25, 0.25, 0);//v
        glVertex3f(-1, 0, 0);
        glVertex3f(-0.25, -0.25, 0);
        glVertex3f(0, -1, 0);
        glVertex3f(0.25, -0.25, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0.25, 0.25, 0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0, 0, -0.25);
        glVertex3f(0.25, 0.25, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(-0.25, 0.25, 0);
        glVertex3f(-1, 0, 0);
        glVertex3f(-0.25, -0.25, 0);
        glVertex3f(0, -1, 0);
        glVertex3f(0.25, -0.25, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0.25, 0.25, 0);
        glEnd();
        glPopMatrix();
        
     
       
        glm::vec3 verticePos[10];
        glm::vec2 texturePos[15];

        //todas as posições dos vértices do cubo
        verticePos[0] = glm::vec3(0, 0, 0.25);
        verticePos[1] = glm::vec3(0, 0, -0.25);
        verticePos[2] = glm::vec3(1, 0, 0);
        verticePos[3] = glm::vec3(-1, 0, 0);
        verticePos[4] = glm::vec3(0, 1, 0);
        verticePos[5] = glm::vec3(0, -1, 0);
        verticePos[6] = glm::vec3(0.25, 0.25, 0);
        verticePos[7] = glm::vec3(0.25, -0.25, 0);
        verticePos[8] = glm::vec3(-0.25, 0.25, 0);
        verticePos[9] = glm::vec3(-0.25, -0.25, 0);

        //todas as posições da textura que serão utilizadas para mapear nos vértices do cubo
        texturePos[0] = glm::vec2(0.00, 0.0);
        texturePos[1] = glm::vec2(0.25, 0.0);
        texturePos[2] = glm::vec2(0.50, 0.0);
        texturePos[3] = glm::vec2(0.75, 0.0);
        texturePos[4] = glm::vec2(1.00, 0.0);
        texturePos[5] = glm::vec2(0.00, 0.5);
        texturePos[6] = glm::vec2(0.25, 0.5);
        texturePos[7] = glm::vec2(0.50, 0.5);
        texturePos[8] = glm::vec2(0.75, 0.5);
        texturePos[9] = glm::vec2(1.00, 0.5);
        texturePos[10] = glm::vec2(0.00, 1.0);
        texturePos[11] = glm::vec2(0.25, 1.0);
        texturePos[12] = glm::vec2(0.50, 1.0);
        texturePos[13] = glm::vec2(0.75, 1.0);
        texturePos[14] = glm::vec2(1.00, 1.0);

        int facesVert[16][3];
        int facesTex[16][3];



        //FAZEEEERRRRR
        //Cada face conecta 3 vértices. Anotando os índices do vetor verticePos que cada face conecta.
        facesVert[0][0] = 0; facesVert[0][1] = 4; facesVert[0][2] = 6; 
        facesVert[1][0] = 0; facesVert[1][1] = 4; facesVert[1][2] = 8; 
        facesVert[2][0] = 0; facesVert[2][1] = 3; facesVert[2][2] = 8; 
        facesVert[3][0] = 0; facesVert[3][1] = 3; facesVert[3][2] = 9; 
        facesVert[4][0] = 0; facesVert[4][1] = 5; facesVert[4][2] = 9; 
        facesVert[5][0] = 0; facesVert[5][1] = 5; facesVert[5][2] = 7;
        facesVert[6][0] = 0; facesVert[6][1] = 2; facesVert[6][2] = 7;
        facesVert[7][0] = 0; facesVert[7][1] = 2; facesVert[7][2] = 6;
        facesVert[8][0] = 1; facesVert[8][1] = 4; facesVert[8][2] = 6;
        facesVert[9][0] = 1; facesVert[9][1] = 4; facesVert[9][2] = 8;
        facesVert[10][0] = 1; facesVert[10][1] = 3; facesVert[10][2] = 8;
        facesVert[11][0] = 1; facesVert[11][1] = 3; facesVert[11][2] = 9;
        facesVert[12][0] = 1; facesVert[12][1] = 5; facesVert[12][2] = 9;
        facesVert[13][0] = 1; facesVert[13][1] = 5; facesVert[13][2] = 7;
        facesVert[14][0] = 1; facesVert[14][1] = 2; facesVert[14][2] = 7;
        facesVert[15][0] = 1; facesVert[15][1] = 2; facesVert[15][2] = 6;



        //Cada face precisa de 3 coordenadas de textura. Anotando os índices do vetor texturaPos que cada face irá precisar.
        facesVert[0][0] = 6; facesVert[0][1] = 11; facesVert[0][2] = 12;
        facesVert[1][0] = 6; facesVert[1][1] = 11; facesVert[1][2] = 10;
        facesVert[2][0] = 6; facesVert[2][1] = 5; facesVert[2][2] = 10;
        facesVert[3][0] = 6; facesVert[3][1] = 5; facesVert[3][2] = 0;
        facesVert[4][0] = 6; facesVert[4][1] = 1; facesVert[4][2] = 0;
        facesVert[5][0] = 6; facesVert[5][1] = 1; facesVert[5][2] = 2;
        facesVert[6][0] = 6; facesVert[6][1] = 7; facesVert[6][2] = 2;
        facesVert[7][0] = 6; facesVert[7][1] = 7; facesVert[7][2] = 12;
        facesVert[8][0] = 8; facesVert[8][1] = 13; facesVert[8][2] = 14;
        facesVert[9][0] = 8; facesVert[9][1] = 13; facesVert[9][2] = 12;
        facesVert[10][0] = 8; facesVert[10][1] = 7; facesVert[10][2] = 12;
        facesVert[11][0] = 8; facesVert[11][1] = 7; facesVert[11][2] = 2;
        facesVert[12][0] = 8; facesVert[12][1] = 3; facesVert[12][2] = 2;
        facesVert[13][0] = 8; facesVert[13][1] = 3; facesVert[13][2] = 4;
        facesVert[14][0] = 8; facesVert[14][1] = 9; facesVert[14][2] = 4;
        facesVert[15][0] = 8; facesVert[15][1] = 9; facesVert[15][2] = 14;


        //desenhando o cubo com a textura
        glBindTexture(GL_TEXTURE_2D, texturaPersonagemId); //ativando a textura
        glBegin(GL_TRIANGLE_FAN);                       //todas as faces são triangulos
        for (int i = 0; i < 16; i++) {            //desenhe um total de 16 faces
            for (int v = 0; v < 3; v++) {        //passando por cada um dos 3 vértices de cada face
                glTexCoord2f(texturePos[facesTex[i][v]].s, texturePos[facesTex[i][v]].t); //coordenada de textura localizada no índice armazenado naquela face
                glVertex3f(verticePos[facesVert[i][v]].x, verticePos[facesVert[i][v]].y, verticePos[facesVert[i][v]].z); //coordenada do vértice localizada no índice armazenado naquela face
            }
        }
        glEnd();
        glBindTexture(GL_TEXTURE_2D, 0); //após terminar o desenho do objeto, desativa a textura   
*/}

void Formas::estrelaTextura() {

    Textura instanciaTextura;
    unsigned int texturaPersonagemId = instanciaTextura.carregaTextura(TEXTURA_PERSONAGEM_ARQ);
    glBindTexture(GL_TEXTURE_2D, texturaPersonagemId); //ativando a textura
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(-1, -1);
    glTexCoord2f(0, 1);
    glVertex2f(-1, 1);
    glTexCoord2f(1, 1);
    glVertex2f(1, 1);
    glTexCoord2f(1, 0);
    glVertex2f(1, -1);
    glEnd();
 }

void Formas::estrelaTextura2() {
    Textura instanciaTextura2;
    unsigned int texturaPersonagemId2 = instanciaTextura2.carregaTextura(TEXTURA_O_ARQ);
    glBindTexture(GL_TEXTURE_2D, texturaPersonagemId2); //ativando a textura
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(-1, -1);
    glTexCoord2f(0, 1);
    glVertex2f(-1, 1);
    glTexCoord2f(1, 1);
    glVertex2f(1, 1);
    glTexCoord2f(1, 0);
    glVertex2f(1, -1);
    glEnd();
}






void Formas::estrelaObstaculo() {
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0.25);
    glVertex3f(0.25, 0.25, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(-0.25, 0.25, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(-0.25, -0.25, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0.25, -0.25, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0.25, 0.25, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, -0.25);
    glVertex3f(0.25, 0.25, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(-0.25, 0.25, 0);
    glVertex3f(-1, 0, 0);
    glVertex3f(-0.25, -0.25, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0.25, -0.25, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0.25, 0.25, 0);
    glEnd();
    glPopMatrix();
}