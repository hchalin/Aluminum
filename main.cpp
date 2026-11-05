#include "AluminumAppDelegate.h"

int main() {
    NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();
    AluminumAppDelegate appDelegate;
    NS::Application* app = NS::Application::sharedApplication();
    app->setDelegate(&appDelegate);
    app->run();
    pool->release();
    return 0;
}
