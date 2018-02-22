#ifndef SHADERFILEREPOSITORY_H
#define SHADERFILEREPOSITORY_H

#include "shaderrepository.h"
#include "shadersourcedata.h"

class ShaderFileRepository : public ShaderRepository
{
public:
    ShaderFileRepository();
    void loadVertexShader( std::ifstream & );
    void loadTessellationControlShader( std::ifstream & );
    void loadTessellationEvaluationShader( std::ifstream & );
    void loadGeometryShader( std::ifstream & );
    void loadFragmentShader( std::ifstream & );
    virtual std::vector<ShaderSourceData> getShaderSourceData() override;

private:

    ShaderSourceData m_data;
};

#endif // SHADERFILEREPOSITORY_H
