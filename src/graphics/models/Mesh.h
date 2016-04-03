//
// Created by lejonmcgowan on 3/28/16.
//

#ifndef OGLSIMPLEENGINE_MESH_H
#define OGLSIMPLEENGINE_MESH_H

// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
// GL Includes
#define GLM_FORCE_RADIANS

#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h> // Contains all the necessery OpenGL includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//my includes

#include <src/graphics/shaderManager/Shader.h>
#include <src/graphics/texturing/Texture.h>
#include <src/graphics/buffers/VertexArray.h>

class Mesh
{
public:
    /*  Mesh Data  */
    vector<std::shared_ptr<Texture>> textures;
    GLuint VAO;

    /*  Functions  */
    Mesh();

    void draw(ShaderProgram &shaderProgram);

    void init(GLenum drawType = GL_STATIC_DRAW);

    void addVertex(glm::vec3 vertex);

    void addIndex(GLuint index);

    void addUV(glm::vec2 uv);

    void addTangent(glm::vec3 tangent);

    void addBinormal(glm::vec3 binormal);

    void addVertices(vector<glm::vec3> vertex);

    void addIndices(vector<GLuint> index);

    void addUVs(vector<glm::vec2> uv);

    void addTangents(vector<glm::vec3> tangent);

    void addBinormals(vector<glm::vec3> binormal);

    void addTexture(Texture &texture);


private:
    VertexArray vao;
    int numIndices;
};

#endif //OGLSIMPLEENGINE_MESH_H
