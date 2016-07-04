//
// Created by lejonmcgowan on 8/11/15.
//

#ifndef TESTPROJECT2_TRANSFORM_H
#define TESTPROJECT2_TRANSFORM_H

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
class Transform
{
private:
    friend class Camera;
    glm::vec3 translation;
    glm::quat internalRot;
    glm::vec3 rotation;
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

    glm::mat4 transform;
    bool updateTransform;

    void updateQuat()
    {
        internalRot = glm::quat(rotation);
    }

    glm::vec3 &getMutableRotation()
    {
        return rotation;
    }

    glm::vec3 &getMutableTranslation()
    {
        return translation;
    }

    glm::vec3 &getMutableScale()
    {
        return scale;
    }

public:
    const glm::mat4 &getTransformMatrix()
    {
        if (updateTransform)
        {
            glm::quat currentRotation = glm::quat(rotation);
            if (std::abs(glm::dot(internalRot, currentRotation) < 0.001))
                updateQuat();
            transform = glm::mat4();
            transform *= glm::translate(glm::mat4(), translation);
            transform *= glm::toMat4(internalRot);
            transform *= glm::scale(glm::mat4(), scale);

            updateTransform = false;
        }
        return transform;
    };

    const glm::vec3 &getRotation()
    {
        return rotation;
    }

    void rotateTo(glm::vec3 rotation)
    {
        updateTransform = true;
        this->rotation = rotation;
        updateQuat();
    }

    const glm::vec3 &getTranslation()
    {
        return translation;
    }

    void translateTo(glm::vec3 translation)
    {
        updateTransform = true;
        this->translation = translation;
    }

    const glm::vec3 &getScale()
    {
        return scale;
    }

    void scaleTo(glm::vec3 scale)
    {
        updateTransform = true;
        this->scale = scale;
    }

    void scaleTo(float scale)
    {
        updateTransform = true;
        this->scale = glm::vec3(scale, scale, scale);
    }

    void scaleBy(float factor)
    {
        updateTransform = true;
        this->scale *= factor;
    }

    void scaleBy(glm::vec3 factor)
    {
        updateTransform = true;
        this->scale += factor;
    }

    void scaleIncreaseBy(float factor)
    {
        updateTransform = true;
        scale.x += factor;
        scale.y += factor;
        scale.z += factor;
    }

    void scaleIncreaseBy(glm::vec3 factor)
    {
        updateTransform = true;
        scale.x += factor.x;
        scale.y += factor.y;
        scale.z += factor.z;
    }

    void translateBy(glm::vec3 factor)
    {
        updateTransform = true;
        this->translation += factor;
    }

    void rotateBy(glm::vec3 factor)
    {
        updateTransform = true;
        rotation.x += factor.x;
        rotation.y += factor.y;
        rotation.z += factor.z;
        updateQuat();
    }

    void reset()
    {
        updateTransform = true;
        scale = glm::vec3(1.0f, 1.0f, 1.0f);
        translation = glm::vec3();
        rotation = glm::vec3();
        updateQuat();
    }
};


#endif //TESTPROJECT2_TRANSFORM_H
