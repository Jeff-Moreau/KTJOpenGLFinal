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
#include "Shader.h"
#include "GraphicsManager.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace SDLFramework;

class Model
{
public:
    vector<Texture> AllTexturesLoaded;
    vector<Mesh> Meshes;
    std::string Location;
    bool GammaCorrection;

private:
    glm::vec3 _Position;
    float _XPos;
    float _YPos;
    float _ZPos;

public:
    Model(std::string const &path, bool gamma = false);

public:
    void Draw(Shader& shader);
    void SetPosition(glm::vec3 position);
    void SetRotation(float angle, glm::vec3 axis);
    void SetPerspective(float fov);
    glm::vec3 GetPosition();

private:
    void LoadModel(std::string const &path);
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
    vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};

unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);
#endif // !MODEL_H