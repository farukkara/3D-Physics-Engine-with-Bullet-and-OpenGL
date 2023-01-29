#include "PhysicsEngine.h"
#include "RigidBody.h"
#include "Scene.h"
#include "Renderer.h"

int main(int argc, char* argv[]) {
    // Initialize the physics engine
    PhysicsEngine physics;
    physics.init();

    // Create a scene and add some rigid bodies to it
    Scene scene;
    scene.addRigidBody(std::make_unique<RigidBody>(1.0f, glm::vec3(0.0f, 0.0f, 0.0f)));
    scene.addRigidBody(std::make_unique<RigidBody>(2.0f, glm::vec3(1.0f, 0.0f, 0.0f)));

    // Create a renderer and initialize it
    Renderer renderer;
    renderer.init();

    while (!renderer.shouldClose()) {
        // Update the physics simulation
        physics.update(scene, renderer.getDeltaTime());

        // Render the scene
        renderer.render(scene);

        // Handle input and window events
        renderer.pollEvents();
    }

    // Clean up
    renderer.cleanup();

    return 0;
}
