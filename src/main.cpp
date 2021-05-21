#include "include.h"

#pragma region primitives
#pragma region Quad
std::vector<Vertex> QuadVerts =
{
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)}
};

std::vector<GLuint> QuadTris =
{
	0, 1, 2,
	0, 2, 3
};
#pragma endregion Quad
#pragma region Cube
std::vector<Vertex> CubeVerts =
{
	Vertex{glm::vec3(-1.f, -1.f,  1.f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},// Down Face
	Vertex{glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.f, -1.f, -1.f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) },
	Vertex{ glm::vec3(1.f, -1.f,  1.f) , glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{glm::vec3(-1.f, 1.f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) }, // Up Face
	Vertex{ glm::vec3(-1.f, 1.f, -1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(1.f, 1.f, -1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(1.f, 1.f, 1.f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{glm::vec3(1.f,  1.f, -1.f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) }, // Right Face
	Vertex{ glm::vec3(1.f,  1.f,  1.f) , glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(1.f, -1.f, -1.f) , glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(1.f, -1.f, 1.f) , glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{glm::vec3(-1.f,  1.f,  1.f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) }, // Left Face
	Vertex{ glm::vec3(-1.f,  1.f, -1.f) , glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(-1.f, -1.f,  1.f) , glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-1.f, -1.f, -1.f) , glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{glm::vec3(1.f,  1.f, -1.f),  glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },// Front Face
	Vertex{ glm::vec3(-1.f,  1.f, -1.f) , glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(1.f, -1.f, -1.f) , glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(-1.f, -1.f, -1.f) , glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)},

	Vertex{glm::vec3(-1.f,  1.f,  1.f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f) }, // Back Face
	Vertex{ glm::vec3(1.f,  1.f,  1.f) , glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3(-1.f, -1.f,  1.f) , glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3(1.f, -1.f,  1.f) , glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

std::vector<GLuint> CubeTris =
{
	0, 2, 1, // Down Face
	0, 3, 2,

	4, 5, 6, // Up Face
	4, 6, 7,

	8, 10, 9, // Right Face
	10, 11, 9,

	12, 14, 13, // Left Face
	14, 15, 13,

	16, 17, 18, // Front Face
	17, 19, 18,

	20, 21, 22, // Back Face
	21, 23, 22
};
#pragma endregion Cube
#pragma endregion primitives

int main(int argc, char** argv)
{
	Window window(960, 540, __FILE__);
	Input Input(window.window());

#pragma region textures_for_primitives
	std::vector<Texture> QuadTexs
	{
		Texture("res/textures/planks.png", "diffuse"),
		Texture("res/textures/planksSpec.png", "specular")
	};

	std::vector<Texture> CubeTexs
	{
		Texture("res/textures/planks.png", "diffuse"),
		Texture("res/textures/planksSpec.png", "specular")
	};
#pragma endregion textures_for_primitives
	
	Shader defaultShader("res/shaders/defaultVert.glsl", "res/shaders/defaultFrag.glsl");
	Mesh quad(QuadVerts, QuadTris, CubeTexs);
	Mesh cube(CubeVerts, CubeTris, CubeTexs);

	Entity quad0(quad);
	Entity cube0(cube);
	cube0.transform.scale /= 5.f;
	cube0.transform.position.y = 1.f;
	quad0.transform.position.x = 2.f;
	quad0.transform.rotation.z = 90.f;

	Light light0(defaultShader, POINT_LIGHT_TYPE, { 0.5f, 0.5f, 0.5f });

	// loop variables BEG
	tools::Timer deltaTimer;
	tools::Timer fixedDeltaTimer;
	tools::Timer secondsTimer;
	float delta = 0;

	const int fixedFPS = 60;
	int fps = 0;
	int frames = 0;
	// loop variables END

	// camera movement
	float camSpeed = 1.f;
	float sensitivity = 1.f;

	// Camera
	Camera camera(window, { 0.f, 1.f, 2.f });

	cube0.mainCamera = &camera;
	cube0.mainShader = &defaultShader;
	quad0.mainCamera = &camera;
	quad0.mainShader = &defaultShader;


	while (!window.closed())
	{
#if 1
		glClearColor(0.2f, 0.2f, 0.3f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Delte Time things & FPS things
		delta = (float)deltaTimer.deltaTime(); // set delteTime
		frames++; // add frame to FPS counter

		// Called every second
		if (secondsTimer.time() >= 1)
		{
			fps = frames;
			frames = 0;
			secondsTimer.reset();
			// TODO: Call App::SecondsUpdate()
			printf("FPS: %d\n", fps);
		}

		// Called every 1/60 of a second (60 FPS)
		if (fixedDeltaTimer.time() >= (1.f / fixedFPS))
		{
			fixedDeltaTimer.reset();
			// TODO: Call App::FixedUpdate()
		}
#endif

		// Things To Do / App::Update()

		glm::vec3 dir = glm::vec3(0.f);

		// Forward, Backward & Left, Right
		if (Input.pressed(Keys::W))
			dir += camera.transform.forward();
		if (Input.pressed(Keys::A))
			dir += -camera.transform.right();
		if (Input.pressed(Keys::S))
			dir += -camera.transform.forward();
		if (Input.pressed(Keys::D))
			dir += camera.transform.right();

		// Up & Down
		if (Input.pressed(Keys::Space))
			dir += camera.transform.up();
		if (Input.pressed(Keys::LeftShift))
			dir += -camera.transform.up();

		// Sprint / Walk
		if (Input.pressed(Keys::LeftCtrl))
			camSpeed = 4.f;
		else if (Input.released(Keys::LeftCtrl))
			camSpeed = 1.f;
		
		// Apply dir
		camera.transform.position += camSpeed * normalized(dir) * delta;
		
		// Mouse Input Look Around
		if (Input.getMouseMode() == MouseModes::disabled)
		{
			glm::vec2 mousePos = Input.mousePosition();
			camera.transform.rotation += glm::vec3(sensitivity * (mousePos.y - (window.height() / 2)) / window.height(), sensitivity * (mousePos.x - (window.width() / 2)) / window.width(), 0.f);
			// Clamp the camera
			if (glm::degrees(camera.transform.rotation.x) > 85.f)
				camera.transform.rotation.x = glm::radians(85.f);
			if (glm::degrees(camera.transform.rotation.x) < -85.f)
				camera.transform.rotation.x = glm::radians(-85.f);
		}

		// _________________________________________
		if (Input.pressed(Keys::H))
			quad0.transform.rotation.y += 20.0f * delta;
		if (Input.pressed(Keys::J))
			quad0.transform.rotation.y -= 20.0f * delta;
		// _________________________________________

		// End Things To Do / App::Update()

		// Input updates
		if (Input.mouseDown(MouseKeys::lmb))
			Input.setMouseMode(MouseModes::disabled);
		if (Input.pressed(Keys::Esc))
			Input.setMouseMode(MouseModes::normal);

		if (Input.getMouseMode() == MouseModes::disabled)
			glfwSetCursorPos(window.window(), (window.width() / 2), (window.height() / 2));


		// Draw
		light0.render();

		quad0.render(defaultShader, camera);
		cube0.render(defaultShader, camera);

		// Update
		glfwSwapBuffers(window.window());
		glfwPollEvents();
		//window.update(); // TODO
	}

	return 0;
}