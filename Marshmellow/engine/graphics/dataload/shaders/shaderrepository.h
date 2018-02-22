#ifndef SHADERREPOSITORY
#define SHADERREPOSITORY

#include <vector>

struct ShaderSourceData;

class ShaderRepository
{
public:
    virtual std::vector<ShaderSourceData> getShaderSourceData() = 0;
};

#endif // SHADERREPOSITORY

