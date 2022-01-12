/*#include "include.h"

int main(int argc, char** argv)
{
	Window window(960, 540, __FILE__);
	engine::Input Input(window.window());
	Primitives::initPrimitives();
	
	Shader defaultShader("res/shaders/defaultVert.glsl", "res/shaders/defaultFrag.glsl");

	Entity quad0(Primitives::Quad);
	Entity cube0(Primitives::Pyramid);
	Entity lightMesh0(Primitives::Cube);
	lightMesh0.transform.scale /= 25.f;
	cube0.transform.scale /= 5.f;
	cube0.transform.position.y = 1.f;
	quad0.transform.position.x = 1.f;
	quad0.transform.rotation.z = 90.f;

	Light light0(defaultShader, POINT_LIGHT_TYPE, { 0.5f, 1.2f, 0.5f });
	light0.intensity = 2.f;
	Light light1(defaultShader, AMBIENT_LIGHT_TYPE);
	light0.ambient = 0.2f;

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
		{
			cube0.mesh.vertices = Primitives::Cube.vertices;
			cube0.mesh.indices = Primitives::Cube.indices;
			cube0.mesh.updateVertices();
		}
		if (Input.pressed(Keys::J))
		{
			cube0.mesh.vertices = Primitives::Pyramid.vertices;
			cube0.mesh.indices = Primitives::Pyramid.indices;
			cube0.mesh.updateVertices();
		}
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

		lightMesh0.transform.position = light0.transform.position;
		lightMesh0.transform.rotation = light0.transform.rotation;
		lightMesh0.render(defaultShader, camera);

		quad0.render();
		cube0.render();

		// Update
		glfwSwapBuffers(window.window());
		glfwPollEvents();
		//window.update(); // TODO
	}

	return 0;
}*/

#include "app.h"
#include "engine/primitives.h"

App app;
Primitives Primitive(1);
//Primitives Primitives::s_Instance;

int main()
{
	app = App(960, 540, __FILE__);
	Primitive = Primitives();

	while (!app.closed())
	{
		app.update();
	}
}

Entity quad0;
Entity cube0;

void App::OnCreate()
{
	quad0 = Entity((Mesh&)Primitive.Quad());
	cube0 = Entity((Mesh&)Primitive.Cube());
}

void App::Update(float delta, engine::Input& Input)
{
	quad0.render(app.StandardLit, app.camera);
	cube0.render(app.StandardLit, app.camera);
}

void App::FixedUpdate(engine::Input& Input)
{

}

void App::SecondsUpdate(engine::Input& Input)
{

}