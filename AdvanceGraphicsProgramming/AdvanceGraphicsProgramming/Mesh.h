#ifndef MESH_H
#define MESH_H

// EXTERNAL INCLUDES
#include "glm/gtc/matrix_transform.hpp"
#include "glad/glad.h"
#include "glm/glm.hpp"

// SYSTEM INCLUDES
#include <vector>
#include <string>

// PROJECT INCLUDES
#include "Shader.h"

#define MAX_BONE_INFLUENCE 4

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
    int BoneIDs[MAX_BONE_INFLUENCE];
    float Weights[MAX_BONE_INFLUENCE];
};

struct Texture
{
    unsigned int ID = 0;
    std::string Type;
    std::string Path;
};

class Mesh
{
public: // ACCESSABLE VARIABLE DECLARATIONS
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    std::vector<Texture> Textures;
    unsigned int VAO;

private: // MEMBER VARIABLE DECLARATIONS
    unsigned int _VBO;
    unsigned int _EBO;

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    ~Mesh();

public: // DOERS
    void Draw(Shader& shader);
    void setupMesh();
};
#endif // !MESH_H