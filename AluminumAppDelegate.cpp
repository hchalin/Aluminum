//
// Created by Hayden Chalin on 11/3/26.
//

#include "AluminumAppDelegate.h"
#include "AluminumViewDelegate.h"



AluminumAppDelegate::~AluminumAppDelegate() {
    delete _pViewDelegate;
}

/**
 *      This function gets called automatically, and acts as the applicaitons constructor
 */
void AluminumAppDelegate::applicationDidFinishLaunching(NS::Notification *pNotification) {

    //* Define the frame size
    CGRect frame = {.origin = {100.0, 100.0}, .size = {1024, 1024}};

     //*  Create window
    NS::Window* _pWindow = NS::Window::alloc()->init(
        frame,
        NS::WindowStyleMaskClosable|NS::WindowStyleMaskTitled,
        NS::BackingStoreBuffered,
        false);
    _window = NS::TransferPtr(_pWindow);

    //* Create Device
    _device = NS::TransferPtr(MTL::CreateSystemDefaultDevice());

    //* Create base Metal View, set clear color, and pixel format
    _view = NS::TransferPtr(MTK::View::alloc()->init(frame, _device.get()));
    _view->setClearColor(MTL::ClearColor::Make(0.0, 1.0, 0.0, 1.0));
    _view->setColorPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB);

    //* create and assign view delegate to view
    _viewDelegate = std::make_unique<AluminumViewDelegate>(_device.get());
    _view->setDelegate( _viewDelegate.get() );

    _window->setContentView( _view.get());
    _window->setTitle(NS::String::string("Aluminum - A Metal based physics engine.", NS::UTF8StringEncoding));

    _window->makeKeyAndOrderFront(nullptr);

    NS::Application* pApp = reinterpret_cast<NS::Application*>(pNotification->object());
    pApp->activateIgnoringOtherApps(true);

}

void AluminumAppDelegate::applicationWillFinishLaunching(NS::Notification *pNotification) {
    // NS::Menu* pMenu = createMenuBar();
    NS::Application* pApp = reinterpret_cast< NS::Application* >( pNotification->object() );
    // pApp->setMainMenu( pMenu );
    pApp->setActivationPolicy( NS::ActivationPolicy::ActivationPolicyRegular );
}
bool AluminumAppDelegate::applicationShouldTerminateAfterLastWindowClosed(NS::Application *pSender) {
    return true;
}


