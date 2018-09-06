cmake_minimum_required(VERSION 3.12)
project(CG)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_STANDARD 14)

include_directories(deprecated)
include_directories(shared)
include_directories(shared/windows)
include_directories(shared/windows/include)
include_directories(shared/windows/include/GL)
include_directories(shared/windows/include/png)
include_directories(shared/windows/include/zlib)
include_directories(src)

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

add_executable(CG
#        deprecated/glcShader.cpp
#        deprecated/glcShader.h
#        deprecated/glcWavefrontObject.cpp
#        deprecated/glcWavefrontObject.h
#        deprecated/glm.cpp
#        deprecated/glm.h
#        #deprecated/phong.cpp
#        deprecated/textfile.cpp
#        deprecated/textfile.h
#        shared/windows/include/GL/freeglut.h
#        shared/windows/include/GL/freeglut_ext.h
#        shared/windows/include/GL/freeglut_std.h
#        shared/windows/include/GL/glew.h
#        shared/windows/include/GL/glui.h
#        shared/windows/include/GL/glui_old.h
#        shared/windows/include/GL/glut.h
#        shared/windows/include/GL/glutf90.h
#        shared/windows/include/png/png.h
#        shared/windows/include/png/pngconf.h
#        shared/windows/include/zlib/crc32.h
#        shared/windows/include/zlib/crypt.h
#        shared/windows/include/zlib/deflate.h
#        shared/windows/include/zlib/infback9.h
#        shared/windows/include/zlib/inffast.h
#        shared/windows/include/zlib/inffix9.h
#        shared/windows/include/zlib/inffixed.h
#        shared/windows/include/zlib/inflate.h
#        shared/windows/include/zlib/inflate9.h
#        shared/windows/include/zlib/inftree9.h
#        shared/windows/include/zlib/inftrees.h
#        shared/windows/include/zlib/ioapi.h
#        shared/windows/include/zlib/iowin32.h
#        shared/windows/include/zlib/trees.h
#        shared/windows/include/zlib/unzip.h
#        shared/windows/include/zlib/zconf.h
#        shared/windows/include/zlib/zconf.in.h
#        shared/windows/include/zlib/zip.h
#        shared/windows/include/zlib/zlib.h
#        shared/windows/include/zlib/zutil.h
#        shared/glcFPSViewer.cpp
#        shared/glcFPSViewer.h
#        shared/glcMouse.cpp
#        shared/glcMouse.h
#        shared/glcPoint.cpp
#        shared/glcPoint.h
#        shared/glcShader.cpp
#        shared/glcShader.h
#        shared/glcSound.cpp
#        shared/glcSound.h
#        shared/glcText.cpp
#        shared/glcText.h
#        shared/glcTexture.cpp
#        shared/glcTexture.h
#        shared/glcWavefrontObject.cpp
#        shared/glcWavefrontObject.h
#        src/3DView.cpp
#        src/antialiasing.cpp
#        src/lighting.cpp
#        src/lightingAttenuation.cpp
#        src/lightingTwoLight.cpp
#        src/mouseKeyboard.cpp
#        #src/objViewer.cpp
#        #src/objViewerTextured.cpp
#        src/openglVersion.cpp
#        #src/phong.cpp
#        src/polygonTwoSide.cpp
        src/projection.cpp
        src/quad.cpp
#        src/quadColor.cpp
#        src/quadColorReshape.cpp
#        src/quadTransform.cpp
#        src/quadTransformMatrices.cpp
#        src/rayTracer.cpp
#        src/rayTracer.h
#        src/rayTracing.cpp
#        src/rayTracingSceneReader.cpp
#        src/rayTracingSceneReader.h
#        #src/shaderExample.cpp
#        src/shading.cpp
#        src/shadow.cpp
#        src/SpotlightExample.cpp
#        src/TextureMapping.cpp
#        src/triangleAnimation.cpp
#        src/viewport.cpp
#        src/zbufferBackface.cpp
        )


#add_executable(CG quad.cpp)