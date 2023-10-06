#ifndef MODEL_H
#define MODEL_H

// EXTERNAL INCLUDES
#include "glm/gtc/matrix_transform.hpp"
#include "assimp/postprocess.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "glm/glm.hpp"
#include "glad/glad.h"

// SYSTEM INCLUDES
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

// PROJECT INCLUDES
#include "GraphicsManager.h"
#include "stb_image.h"
#include "Shader.h"
#include "Mesh.h"

using namespace SDLFramework;

class Model
{
public: // ACCESSABLE VARIABLE DECLARATIONS
    std::vector<Texture> AllTexturesLoaded;
    std::vector<Mesh> Meshes;
    std::string Location;
    bool GammaCorrection;

private: // MEMBER VARIABLE DECLARATIONS
    glm::vec3 _Position;
    float _XPos;
    float _YPos;
    float _ZPos;

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
    Model(std::string const &path, bool gamma = false);
    ~Model();

public: // GETTERS
    glm::vec3 GetPosition();

public: // SETTERS
    void SetPosition(glm::vec3 position);
    void SetRotation(float angle, glm::vec3 axis);
    void SetPerspective(float fov);

public: // DOERS
    void Draw(Shader& shader);

private: // DOERS
    void LoadModel(std::string const &path);
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
    unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);
};
#endif // !MODEL_H