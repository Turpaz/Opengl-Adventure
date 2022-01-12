#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <math.h>

#include "tools/timer.h"
#include "tools/maths_tweaks.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "engine/input.h"

#include "engine/entity.h"
#include "engine/light.h"
#include "engine/mesh.h"

#include "graphics/window.h"
#include "graphics/camera.h"
#include "graphics/shader/shader.h"
#include "graphics/texture/texture.h"

#include "__O's/VBO.h"
#include "__O's/EBO.h"
#include "__O's/VAO.h"

using namespace graphics;