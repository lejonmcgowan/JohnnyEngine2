//
// Created by lejonmcgowan on 3/28/16.
//

#include "Model.h"

Model::Model(string const &path)
{
    this->loadModel(path);
}

void Model::draw(ShaderProgram &shaderProgram)
{
    for (auto mesh: meshes)
        mesh.draw(shaderProgram);
}

void Model::loadModel(string path)
{
    // Read file via ASSIMP
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(path,
                                             aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    // Check for errors
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
    {
        cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
        return;
    }
    // Retrieve the directory path of the filepath
    directory = path.substr(0, path.find_last_of('/'));
    cout << directory << std::endl;
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
        auto normal = assimpMesh->mNormals[i];
        auto binormal = assimpMesh->mBitangents[i];
        bool hasTexcoord = (bool) assimpMesh->mTextureCoords[0];

        mesh.addVertex(glm::vec3(vertex.x, vertex.y, vertex.z));
        mesh.addTangent(glm::vec3(normal.x, normal.y, normal.z));
        mesh.addBinormal(glm::vec3(binormal.x, binormal.y, binormal.z));
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
    vector<Texture> textures;
    for (GLuint i = 0; i < mat->GetTextureCount(type); i++)
    {
        //assimps special string structure. has a char buffer you can access directly
        aiString str;
        mat->GetTexture(type, i, &str);
        std::string path(std::string(str.data));
        auto texture = Texture::getTextureByPath(path);
        //if not in texturemap, make new texture
        if (texture == nullptr)
        {
            texture = std::make_shared<Texture>(baseName + std::to_string(i + 1), GL_TEXTURE_2D, path);
        }
        mesh.addTexture(*texture);
    }
}