//
// Created by lejonmcgowan on 3/28/16.
//

#include "Model.h"

Model::Model(const string &path)
{
    this->loadModel(FileUtils::getFullPath(path));
}

void Model::render(ShaderProgram &shaderProgram)
{
    for (auto &mesh: meshes)
        mesh.render(shaderProgram);
}

void Model::loadModel(string modelFile)
{
    this->baseDir = modelFile.substr(0, modelFile.rfind("/") + 1);;
    // Read file via ASSIMP
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(modelFile,
                                             aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    // Check for errors
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
    {
        cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
        return;
    }
    // Process ASSIMP's root node recursively
    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    // Process each mesh located at the current node
    for (GLuint i = 0; i < node->mNumMeshes; i++)
    {
        // The node object only contains indices to index the actual objects in the scene.
        // The scene contains all the data, node is just to keep stuff organized (like relations between nodes).
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        this->meshes.push_back(this->processMesh(mesh, scene));
    }
    // After we've processed all of the meshes (if any) we then recursively process each of the children nodes
    for (GLuint i = 0; i < node->mNumChildren; i++)
    {
        this->processNode(node->mChildren[i], scene);
    }

}

Mesh Model::processMesh(aiMesh *assimpMesh, const aiScene *scene)
{
    Mesh mesh;
    // Walk through each of the mesh's vertices
    for (GLuint i = 0; i < assimpMesh->mNumVertices; i++)
    {
        auto vertex = assimpMesh->mVertices[i];
        mesh.addVertex(glm::vec3(vertex.x, vertex.y, vertex.z));
        if (assimpMesh->mNormals)
        {
            auto normal = assimpMesh->mNormals[i];
            mesh.addTangent(glm::vec3(normal.x, normal.y, normal.z));
        }
        if (assimpMesh->mBitangents)
        {
            auto binormal = assimpMesh->mBitangents[i];
            mesh.addBinormal(glm::vec3(binormal.x, binormal.y, binormal.z));
        }
        bool hasTexcoord = (bool) assimpMesh->mTextureCoords[0];

        // Texture Coordinates
        if (hasTexcoord) // Does the mesh contain texture coordinates?
        {
            auto texCoord = assimpMesh->mTextureCoords[0][i];
            mesh.addUV(glm::vec2(texCoord.x, texCoord.y));
        }
    }
    // Now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
    for (GLuint i = 0; i < assimpMesh->mNumFaces; i++)
    {
        aiFace face = assimpMesh->mFaces[i];
        // Retrieve all indices of the face and store them in the indices vector
        for (GLuint j = 0; j < face.mNumIndices; j++)
        {
            mesh.addIndex(face.mIndices[j]);
        }
    }
    // Process materials
    if (assimpMesh->mMaterialIndex >= 0)
    {
        aiMaterial *material = scene->mMaterials[assimpMesh->mMaterialIndex];
        // We assume a convention for sampler names in the shaders. Each diffuse texture should be named
        // as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER.
        // Same applies to other texture as the following list summarizes:
        // Diffuse: texture_diffuseN
        // Specular: texture_specularN
        // Normal: texture_normalN

        // 1. Diffuse maps
        loadMaterialTextures(mesh, material, aiTextureType_DIFFUSE, "diffuseTexture");
        // 2. Specular maps
        loadMaterialTextures(mesh, material, aiTextureType_SPECULAR, "specularTexture");
        // 3. Normal maps
        loadMaterialTextures(mesh, material, aiTextureType_HEIGHT, "normalTexture");
        // 4. Height maps
        loadMaterialTextures(mesh, material, aiTextureType_AMBIENT, "heightTexture");
    }

    // Return a mesh object created from the extracted mesh data
    return mesh;
}

void Model::loadMaterialTextures(Mesh &mesh, aiMaterial *mat, aiTextureType type, string baseName)
{
    for (GLuint i = 0; i < mat->GetTextureCount(type); i++)
    {
        //assimps special string structure. has a char buffer you can access directly
        aiString str;
        mat->GetTexture(type, i, &str);
        std::string file(std::string(str.data));
        file = baseDir + file;
        auto texture = Texture::getTextureByPath(file);
        //if not in texturemap, make new texture
        if (texture == nullptr)
        {
            texture = Texture::makeTexture(baseName + std::to_string(i + 1), GL_TEXTURE_2D, file);
        }
        mesh.addTexture(texture);
    }
}

void Model::init()
{
    for (Mesh &mesh: meshes)
        mesh.init();
}