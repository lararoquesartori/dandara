#ifndef FONTELUZPERSONAGEM_H
#define FONTELUZPERSONAGEM_H

#include <glm/glm.hpp>
#include <GL/glut.h>
#include <GL/gl.h>
#include "personagem.h"

class FonteLuzPersonagem {
private:
   // Personagem instanciaPersonagem;
    glm::vec3 luzPos;
    glm::vec3 luzAmb;
    glm::vec3 luzDiff;
    glm::vec3 luzSpec;
public:
    FonteLuzPersonagem();
    const glm::vec3& getLuzPos() const;
    const glm::vec3& getLuzAmb() const;
    const glm::vec3& getLuzDiff() const;
    const glm::vec3& getLuzSpec() const;
    void setLuzPos(const glm::vec3& newLuzPos);
    void setLuzAmb(const glm::vec3& newLuzAmb);
    void setLuzDiff(const glm::vec3& newLuzDiff);
    void setLuzSpec(const glm::vec3& newLuzSpec);
    glm::vec3 iluminacao(glm::vec3 P, glm::vec3 camPos, glm::vec3 matAmb, glm::vec3 matDiff, glm::vec3 matSpec, float matShine, glm::vec3 n);
    void desenha();
};

#endif // FONTELUZPERSONAGEM_H
