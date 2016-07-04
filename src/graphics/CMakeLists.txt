add_library(graphics shaderManager/Shader.cpp shaderManager/Shader.h
        shaderManager/ShaderProgram.cpp shaderManager/ShaderProgram.h
        buffers/VertexBuffer.cpp buffers/VertexBuffer.h
        buffers/VertexArray.cpp buffers/VertexArray.h
        buffers/IndexBuffer.cpp buffers/IndexBuffer.h
        VertLineRenderer.cpp VertLineRenderer.h
        texturing/Texture.cpp texturing/Texture.h
        models/Mesh.cpp models/Mesh.h
        models/Model.cpp models/Model.h
        Transform.h Camera.h
        buffers/UniformBuffer.cpp buffers/UniformBuffer.h
        buffers/UBOPrimitive.cpp buffers/UBOPrimitive.h
        buffers/UniformData.h
        buffers/UBOStruct.cpp buffers/UBOStruct.h
        buffers/UBOStructArray.cpp buffers/UBOStructArray.h
        buffers/UBOPrimitiveArray.cpp buffers/UBOPrimitiveArray.h
        buffers/UBOData.h)
target_link_libraries(graphics ${ext_libraries} util)
