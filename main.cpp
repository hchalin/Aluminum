#include "KinetisAppDelegate.h"

int main() {
    NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();
    KinetisAppDelegate appDelegate;
    NS::Application* app = NS::Application::sharedApplication();
    app->setDelegate(&appDelegate);
    app->run();
    pool->release();
    return 0;
}
