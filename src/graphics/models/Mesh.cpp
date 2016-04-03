//
// Created by lejonmcgowan on 3/28/16.
//

#include "Mesh.h"

Mesh::Mesh()
{

    vao.addBuffer(0, new VertexBuffer("vertex", 3), new IndexBuffer());
    vao.addBuffer(1, new VertexBuffer("normal", 3));
    vao.addBuffer(2, new VertexBuffer("texcoords", 2));
    vao.addBuffer(3, new VertexBuffer("tangent", 3));
    vao.addBuffer(4, new VertexBuffer("bitangent", 3));
}


void Mesh::draw(ShaderProgram &shaderProgram)
{
    for (auto texture: textures)
    {
        texture->setTexUniform(shaderProgram);
    }

    // Draw mesh
    vao.bind();
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);
    vao.unbind();

    // Always good practice to set everything back to defaults once configured.
    for (auto texture: textures)
    {
        glActiveTexture(GL_TEXTURE0 + texture->getTexNum());
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void Mesh::init(GLenum drawType)
{
    for (auto texture: textures)
        texture->init();

    vao.generate(drawType);
    numIndices = (int) vao.getIBOByName("vertex")->getBufferSize();
}

//utility add functinons to populte mesh data
void Mesh::addVertex(glm::vec3 vertex)
{
    vao.getVBOByName("vertex")->addData(vertex);
}

void Mesh::addIndex(GLuint index)
{
    vao.getIBOByName("vertex")->addData(index);
}

void Mesh::addUV(glm::vec2 uv)
{
    vao.getVBOByName("texcoord")->addData(uv);
}

void Mesh::addTangent(glm::vec3 tangent)
{
    vao.getVBOByName("tangent")->addData(tangent);
}

void Mesh::addBinormal(glm::vec3 binormal)
{
    vao.getVBOByName("binormal")->addData(binormal);
}

void Mesh::addVertices(vector<glm::vec3> vertices)
{
    for (auto vertex: vertices)
        addVertex(vertex);
}

void Mesh::addIndices(vector<GLuint> indices)
{
    for (auto index: indices)
        addIndex(index);
}

void Mesh::addUVs(vector<glm::vec2> uvs)
{
    for (auto uv: uvs)
        addUV(uv);
}

void Mesh::addTangents(vector<glm::vec3> tangents)
{
    for (auto tangent: tangents)
        addTangent(tangent);
}

void Mesh::addBinormals(vector<glm::vec3> binormals)
{
    for (auto binormal: binormals)
        addBinormal(binormal);
}

void Mesh::addTexture(Texture &texture)
{
    textures.push_back(std::make_shared<Texture>(texture));
}

