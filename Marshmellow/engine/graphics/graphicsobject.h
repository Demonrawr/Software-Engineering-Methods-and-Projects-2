#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include "glm/glm.hpp"

class GraphicsObject
{
public:
    GraphicsObject();
    ~GraphicsObject();

    enum class CULL_FACE { CULL_FRONT, CULL_BACK, CULL_BOTH };
    enum class POLYGON_MODE { POINT, LINE, FILL };
    enum class TEXTURE_FORMAT { TEX_1D, TEX_2D, TEX_3D };
    enum class BLEND_MODE { ZERO,
                            ONE,
                            SRC_COLOR,
                            ONE_MINUS_SRC_COLOR,
                            DST_COLOR,
                            ONE_MINUS_DST_COLOR,
                            SRC_ALPHA,
                            ONE_MINUS_SRC_ALPHA,
                            DST_ALPHA,
                            ONE_MINUS_DST_ALPHA,
                            CONSTANT_COLOR,
                            ONE_MINUS_CONSTANT_COLOR,
                            CONSTANT_ALPHA,
                            ONE_MINUS_CONSTANT_ALPHA,
                            ALPHA_SATURATE,
                            SRC1_COLOR,
                            ONE_MINUS_SRC1_COLOR,
                            SRC1_ALPHA,
                            ONE_MINUS_SRC1_ALPHA };

    static void checkError();

    void setClearColor(float r, float g, float b, float a);
    void clearColorBuffer();
    void clearDepthBuffer();
    void cullFace( CULL_FACE c );

    void disableBlend();
    void disableCullFace();
    void disableDepth();
    void disableDepthMask();
    void disableMultisample();

    void enableBlend();
    void enableCullFace();
    void enableDepth();
    void enableDepthMask();
    void enableMultisample();

    void setBlendMode( BLEND_MODE src, BLEND_MODE dst );
    int blendModeToEnum( BLEND_MODE b );

    glm::ivec2 getScreenDimensions();

    void resize( int w, int h );

    void setLineWidth( float f );
    void setPolygonMode( POLYGON_MODE m );

    void printGLVersionInfo();

private:

    void initializeGLEW();

    int m_screenWidth;
    int m_screenHeight;
};

#endif // GRAPHICSOBJECT_H
