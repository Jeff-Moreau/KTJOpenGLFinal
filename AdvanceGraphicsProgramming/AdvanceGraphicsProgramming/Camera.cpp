#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : _Front(glm::vec3(0.0f, 0.0f, -1.0f)), _MovementSpeed(SPEED), _MouseSensitivity(SENSITIVITY), _Zoom(ZOOM)
{
    // MEMBER VARIABLE INSTANTIATION
    _Position = position;
    _WorldUp = up;
    _Yaw = yaw;
    _Pitch = pitch;

    UpdateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : _Front(glm::vec3(0.0f, 0.0f, -1.0f)), _MovementSpeed(SPEED), _MouseSensitivity(SENSITIVITY), _Zoom(ZOOM)
{
    // MEMBER VARIABLE INSTANTIATION
    _Position = glm::vec3(posX, posY, posZ);
    _WorldUp = glm::vec3(upX, upY, upZ);
    _Yaw = yaw;
    _Pitch = pitch;

    UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(_Position, _Position + _Front, _Up);
}

float Camera::GetZoom()
{
    return _Zoom;
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    // LOCAL VARIABLE DECLARATIONS
    float velocity = _MovementSpeed * deltaTime;

    if (direction == FORWARD)
    {
        _Position += _Front * velocity;
    }

    if (direction == BACKWARD)
    {
        _Position -= _Front * velocity;
    }

    if (direction == LEFT)
    {
        _Position -= _Right * velocity;
    }

    if (direction == RIGHT)
    {
        _Position += _Right * velocity;
    }
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= _MouseSensitivity;
    yoffset *= _MouseSensitivity;

    _Yaw += xoffset;
    _Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (_Pitch > 89.0f)
        {
            _Pitch = 89.0f;
        }

        if (_Pitch < -89.0f)
        {
            _Pitch = -89.0f;
        }
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    UpdateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    _Zoom -= (float)yoffset;

    if (_Zoom < 1.0f)
    {
        _Zoom = 1.0f;
    }

    if (_Zoom > 45.0f)
    {
        _Zoom = 45.0f;
    }
}

void Camera::UpdateCameraVectors()
{
    // calculate the new Front vector
    // LOCAL VARIABLE DECLARATIONS
    glm::vec3 front;

    front.x = cos(glm::radians(_Yaw)) * cos(glm::radians(_Pitch));
    front.y = sin(glm::radians(_Pitch));
    front.z = sin(glm::radians(_Yaw)) * cos(glm::radians(_Pitch));
    _Front = glm::normalize(front);

    // also re-calculate the Right and Up vector
    _Right = glm::normalize(glm::cross(_Front, _WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    _Up = glm::normalize(glm::cross(_Right, _Front));
}