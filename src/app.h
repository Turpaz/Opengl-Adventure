#include "include.h"

using Shader = graphics::Shader;

class App
{
public:
	Window window;
	engine::Input Input;

	float delta = 0;
	const int fixedFPS = 60;
	bool printFpsEverySecond = true;
	int fps = 0;
private:
	tools::Timer deltaTimer;
	tools::Timer fixedDeltaTimer;
	tools::Timer secondsTimer;
	int frames = 0;
public:
	App() {}
	App(int w = 960, int h = 540, const char* n = __FILE__)
	{
		window = Window(w, h, n);
		Input = engine::Input(this->window.window());
		Primitives::initPrimitives();
		Camera camera(window);

		Shader StandardLit("res/shaders/defaultVert.glsl", "res/shaders/defaultFrag.glsl");

		this->OnCreate();
	}

	void update()
	{
		glClearColor(0.2f, 0.2f, 0.3f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Delte Time things & FPS things
		this->delta = (float)this->deltaTimer.deltaTime();
		this->frames++;

		// Called every second
		if (this->secondsTimer.time() >= 1)
		{
			this->fps = this->frames;
			this->frames = 0;
			this->secondsTimer.reset();

			this->SecondsUpdate(this->Input);

			if (this->printFpsEverySecond)
				printf("FPS: %d\n", this->fps);
		}

		// Called every 1/60 of a second (60 FPS)
		if (this->fixedDeltaTimer.time() >= (1.f / this->fixedFPS))
		{
			this->fixedDeltaTimer.reset();

			this->FixedUpdate(this->Input);
		}

		// Call Update
		this->Update(this->delta, this->Input);

		// Input updates
		if (Input.mouseDown(MouseKeys::lmb))
			Input.setMouseMode(MouseModes::disabled);
		if (Input.pressed(Keys::Esc))
			Input.setMouseMode(MouseModes::normal);

		// Draw all things
		this->draw();

		if (Input.getMouseMode() == MouseModes::disabled)
			glfwSetCursorPos(this->window.window(), (this->window.width() / 2), (this->window.height() / 2));
		
		// Update
		glfwSwapBuffers(this->window.window());
		glfwPollEvents();
	}

	void draw()
	{

	}

	static void OnCreate();
	static void Update(const float delta, engine::Input& Input);
	static void FixedUpdate(engine::Input& Input);
	static void SecondsUpdate(engine::Input& Input);
};