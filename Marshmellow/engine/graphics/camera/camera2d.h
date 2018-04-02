#ifndef CAMERA2D_H
#define CAMERA2D_H

#include "camera.h"

class Camera2D : public Camera
{
public:
    Camera2D( float width, float height );
    virtual ~Camera2D();

    virtual float getAspectRatio() const override;
    virtual glm::mat4 getProjectionMatrix() const override;
    virtual glm::mat4 getViewMatrix() const override;

    float getHeight() const;
    float getWidth() const;

    void setHeight( float h );
    void setWidth( float w );
    void setViewport( float l, float r, float b, float t );

    void setPosition( const glm::vec2& pos );
    glm::vec2 getPosition() const;

private:
    float m_aspectRatio;
    float m_height;
    float m_width;
    float m_l, m_r, m_b, m_t;
    mutable glm::mat4 m_viewMatrix;
    mutable glm::mat4 m_projectionMatrix;
    glm::vec2 m_position;
};

#endif // CAMERA2D_H
