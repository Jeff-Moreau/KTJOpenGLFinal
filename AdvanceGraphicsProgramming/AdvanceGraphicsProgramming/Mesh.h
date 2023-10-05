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

using namespace std;

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
    string Type;
    string Path;
};

class Mesh
{
public: // ACCESSABLE VARIABLE DECLARATIONS
    vector<Vertex> Vertices;
    vector<unsigned int> Indices;
    vector<Texture> Textures;
    unsigned int VAO;

private: // MEMBER VARIABLE DECLARATIONS
    unsigned int _VBO;
    unsigned int _EBO;

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    ~Mesh();

public: // DOERS
    void Draw(Shader& shader);
    void setupMesh();
};
#endif // !MESH_H