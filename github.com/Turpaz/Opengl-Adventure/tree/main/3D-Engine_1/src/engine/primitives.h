#pragma once

#include "mesh.h"

using namespace graphics;

namespace PrimitivesProps
{
	// Quad
	const std::vector<Vertex> QuadVerts =
	{
		Vertex{ glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
		Vertex{ glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) }
	};

	const std::vector<GLuint> QuadTris =
	{
		0, 1, 2,
		0, 2, 3
	};

	// Cube
	const std::vector<Vertex> CubeVerts =
	{
		Vertex{glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},// Down Face
		Vertex{glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
		Vertex{ glm::vec3(1.f, -1.f,  1.f) , glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{glm::vec3(-1.f, 1.f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) }, // Up Face
		Vertex{ glm::vec3(-1.f, 1.f, -1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
		Vertex{ glm::vec3(1.f, 1.f, -1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{ glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{ glm::vec3(1.f,  1.f,  1.f) , glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)}, // Right Face
		Vertex{glm::vec3(1.f,  1.f, -1.f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(1.f, -1.f, -1.f) , glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{ glm::vec3(1.f, -1.f, 1.f) , glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{ glm::vec3(-1.f,  1.f, -1.f) , glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)}, // Left Face
		Vertex{glm::vec3(-1.f,  1.f,  1.f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(-1.f, -1.f,  1.f) , glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{ glm::vec3(-1.f, -1.f, -1.f) , glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{ glm::vec3(-1.f,  1.f, -1.f) , glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)}, // Front Face
		Vertex{glm::vec3(1.f,  1.f, -1.f),  glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(1.f, -1.f, -1.f) , glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{ glm::vec3(-1.f, -1.f, -1.f) , glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

		Vertex{ glm::vec3(1.f,  1.f,  1.f) , glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)}, // Back Face
		Vertex{glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(-1.f, -1.f,  1.f) , glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
		Vertex{ glm::vec3(1.f, -1.f,  1.f) , glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
	};

	const std::vector<GLuint> CubeTris =
	{
		0, 2, 1, // Down Face
		0, 3, 2,

		4, 5, 6, // Up Face
		4, 6, 7,

		8, 9, 10, // Right Face
		8, 10, 11,

		12, 13, 14, // Left Face
		12, 14, 15,

		16, 18, 17, // Front Face
		16, 19, 18,

		20, 22, 21, // Back Face
		20, 23, 22
	};

	// Triangle
	const std::vector<Vertex> TriangleVerts =
	{
		Vertex{ glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
	};

	const std::vector<GLuint> TriangleTris =
	{
		0, 1, 2
	};

	// Pyramid
	const std::vector<Vertex> PyramidVerts =
	{
		Vertex{ glm::vec3(-1.0f, -0.5f,  1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) }, // Base
		Vertex{ glm::vec3(-1.0f, -0.5f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(1.0f, -0.5f, -1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
		Vertex{ glm::vec3(1.0f, -0.5f,  1.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) },

		Vertex{ glm::vec3(1.0f, -0.5f,  1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) }, // Right
		Vertex{ glm::vec3(1.0f, -0.5f, -1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f) },

		Vertex{ glm::vec3(-1.0f, -0.5f,  1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) }, // Left
		Vertex{ glm::vec3(-1.0f, -0.5f, -1.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f) },

		Vertex{ glm::vec3(-1.0f, -0.5f, -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) }, // Front
		Vertex{ glm::vec3(1.0f, -0.5f, -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f) },

		Vertex{ glm::vec3(-1.0f, -0.5f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) }, // Back
		Vertex{ glm::vec3(1.0f, -0.5f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.5f, 1.0f) },
	};

	const std::vector<GLuint> PyramidTris =
	{
		0, 2, 1, // Base
		0, 3, 2,

		4, 6, 5, // Right

		7, 8, 9, // Left

		10, 11, 12, // Front

		13, 15, 14, // Back
	};

	// Sphere // TODO: actually make them
	const std::vector<Vertex> SphereVerts =
	{
		Vertex{ glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) }, // Base
		Vertex{ glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f) },
		Vertex{ glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f) },
		Vertex{ glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) },

		Vertex{ glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) }, // Right
		Vertex{ glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.5f, 1.0f) },

		Vertex{ glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) }, // Left
		Vertex{ glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.5f, 1.0f) },

		Vertex{ glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) }, // Front
		Vertex{ glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.5f, 1.0f) },

		Vertex{ glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f) }, // Back
		Vertex{ glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f) },
		Vertex{ glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.5f, 1.0f) },
	};

	const std::vector<GLuint> SphereTris =
	{
		0, 2, 1, // Base
		0, 3, 2,

		4, 6, 5, // Right

		7, 8, 9, // Left

		10, 11, 12, // Front

		13, 15, 14, // Back
	};
}

/*namespace Primitives
{
	extern const Mesh Quad;
	extern const Mesh Cube;
	extern const Mesh Triangle;
	extern const Mesh Pyramid;
	extern const Mesh Sphere;

	const std::vector<Texture> Texs
	{
		Texture("res/textures/planks.png", DIFFUSE_TEXTURE_TYPE),
		Texture("res/textures/planksSpec.png", SPECULAR_TEXTURE_TYPE)
	};

	const Mesh Quad(PrimitivesProps::QuadVerts, PrimitivesProps::QuadTris, Texs);
	const Mesh Cube(PrimitivesProps::CubeVerts, PrimitivesProps::CubeTris, Texs);
	const Mesh Triangle(PrimitivesProps::TriangleVerts, PrimitivesProps::TriangleTris, Texs);
	const Mesh Pyramid(PrimitivesProps::PyramidVerts, PrimitivesProps::PyramidTris, Texs);
	const Mesh Sphere(PrimitivesProps::SphereVerts, PrimitivesProps::SphereTris, Texs);

	inline void initPrimitives()
	{
		const std::vector<Texture> Texs
		{
			Texture("res/textures/planks.png", DIFFUSE_TEXTURE_TYPE),
			Texture("res/textures/planksSpec.png", SPECULAR_TEXTURE_TYPE)
		};

		Mesh Quad(PrimitivesProps::QuadVerts, PrimitivesProps::QuadTris, Texs);
		Mesh Cube(PrimitivesProps::CubeVerts, PrimitivesProps::CubeTris, Texs);
		Mesh Triangle(PrimitivesProps::TriangleVerts, PrimitivesProps::TriangleTris, Texs);
		Mesh Pyramid(PrimitivesProps::PyramidVerts, PrimitivesProps::PyramidTris, Texs);
		Mesh Sphere(PrimitivesProps::SphereVerts, PrimitivesProps::SphereTris, Texs);
	}
}*/

/*class Primitives
{
public:
	static Primitives& Get()
	{
		return s_Instance;
	}

	static Mesh Quad() { return Get().IQuad; }
	static Mesh Cube() { return Get().ICube; }
	static Mesh Triangle() { return Get().ITriangle; }
	static Mesh Pyramid() { return Get().IPyramid; }
	static Mesh Sphere() { return Get().ISphere; }

	static void init()
	{
		Get().IQuad = Mesh(PrimitivesProps::QuadVerts, PrimitivesProps::QuadTris);
		Get().ICube = Mesh(PrimitivesProps::CubeVerts, PrimitivesProps::CubeTris);
		Get().ITriangle = Mesh(PrimitivesProps::TriangleVerts, PrimitivesProps::TriangleTris);
		Get().IPyramid = Mesh(PrimitivesProps::PyramidVerts, PrimitivesProps::PyramidTris);
		Get().ISphere = Mesh(PrimitivesProps::SphereVerts, PrimitivesProps::SphereTris);
	}
private:
	Mesh IQuad = Mesh(1);
	Mesh ICube = Mesh(1);
	Mesh ITriangle = Mesh(1);
	Mesh IPyramid = Mesh(1);
	Mesh ISphere = Mesh(1);

	static Primitives s_Instance;
private:
	Primitives() {}
};*/

class Primitives
{
private:
	Mesh IQuad = Mesh(1);
	Mesh ICube = Mesh(1);
	Mesh ITriangle = Mesh(1);
	Mesh IPyramid = Mesh(1);
	Mesh ISphere = Mesh(1);
public:
	Primitives(int dontinit) {}
	Primitives()
	{
		IQuad = Mesh(PrimitivesProps::QuadVerts, PrimitivesProps::QuadTris);
		ICube = Mesh(PrimitivesProps::CubeVerts, PrimitivesProps::CubeTris);
		ITriangle = Mesh(PrimitivesProps::TriangleVerts, PrimitivesProps::TriangleTris);
		IPyramid = Mesh(PrimitivesProps::PyramidVerts, PrimitivesProps::PyramidTris);
		ISphere = Mesh(PrimitivesProps::SphereVerts, PrimitivesProps::SphereTris);
	}

	Mesh Quad() { return IQuad; }
	Mesh Cube() { return ICube; }
	Mesh Triangle() { return ITriangle; }
	Mesh Pyramid() { return IPyramid; }
	Mesh Sphere() { return ISphere; }
};