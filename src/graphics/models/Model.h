//
// Created by lejonmcgowan on 3/28/16.
//

#ifndef OGLSIMPLEENGINE_MODEL_H
#define OGLSIMPLEENGINE_MODEL_H

// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.h"

GLint TextureFromFile(const char *path, string directory, bool gamma = false);

class Model
{
public:
    /*  Model Data */
    vector<Texture> textures_loaded;    // Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    vector<Mesh> meshes;
    string directory;

    /*  Functions   */
    Model(const string &path);

    void render(ShaderProgram &shader);

    void init();

private:
    /*  Functions   */
    void loadModel(string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *assimpMesh, const aiScene *scene);
    void loadMaterialTextures(Mesh &mesh, aiMaterial *mat, aiTextureType type, string typeName);

};

#endif //OGLSIMPLEENGINE_MODEL_H
