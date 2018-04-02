#ifndef SHADERSOURCEDATA
#define SHADERSOURCEDATA

#include <string>

struct ShaderSourceData
{
    std::string vertexSource;
    std::string tessellationControlSource;
    std::string tessellationEvaluationSource;
    std::string geometrySource;
    std::string fragmentSource;

    bool hasVertexSource;
    bool hasTessellationControlSource;
    bool hasTessellationEvaluationSource;
    bool hasGeometrySource;
    bool hasFragmentSource;
};

#endif // SHADERSOURCEDATA

