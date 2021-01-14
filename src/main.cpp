#include <iostream>
#include <thread>
#include <chrono>

#include "SystemManager.h"

#include "TestSystem.h"
#include "GraphicsSystem.h"

using namespace std::chrono_literals;

int main()
{
	std::cout << "Hello World" << std::endl;

	SystemManager Manager = SystemManager();

	System* TestSys1 = new TestSystem();
	System* TestSys2 = new TestSystem2();

	System* GraphicsSys = new GraphicsSystem();

	Manager.AddSystem(TestSys1);
	Manager.AddSystem(TestSys2);
	Manager.AddSystem(GraphicsSys);

	std::this_thread::sleep_for(0s);

	Mesh* TestMesh = new Mesh;

	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	TestMesh->Verts = vertices;
	TestMesh->VertCount = 9;

	Command TestCommand;

	TestCommand.CommandT = Command_MeshLoad;
	TestCommand.Data = TestMesh;

	((GraphicsSystem*)GraphicsSys)->CommandQueue.push(TestCommand);
	std::this_thread::sleep_for(15s);

	Manager.RemoveSystem(TestSys1);
	Manager.RemoveSystem(TestSys2);
	Manager.RemoveSystem(GraphicsSys);

	return 0;
}