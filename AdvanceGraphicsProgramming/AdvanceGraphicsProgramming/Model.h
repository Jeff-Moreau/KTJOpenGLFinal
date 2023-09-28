#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <learnopengl/mesh.h>
#include <learnopengl/shader.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

class Model
{
public:
    vector<Texture> AllTexturesLoaded;
    vector<Mesh> Meshes;
    std::string Location;
    bool GammaCorrection;

public:
    Model(std::string const &path, bool gamma = false);

public:
    void Draw(Shader& shader);

private:
    void LoadModel(std::string const &path);
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
    vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};

unsigned int TextureFromFile(const char* path, const string& directory, bool gamma);
#endif // !MODEL_H