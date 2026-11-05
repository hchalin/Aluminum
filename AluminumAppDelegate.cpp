//
// Created by Hayden Chalin on 11/3/26.
//

#include "AluminumAppDelegate.h"
#include "AluminumViewDelegate.h"



AluminumAppDelegate::~AluminumAppDelegate() {
    _pView->release();
    _pWindow->release();
    _pDevice->release();
    delete _pViewDelegate;
}

/**
 *      This function gets called automatically, and acts as the applicaitons constructor
 */
void AluminumAppDelegate::applicationDidFinishLaunching(NS::Notification *pNotification) {

    //* Define the frame size
    CGRect frame = {.origin = {100.0, 100.0}, .size = {1024, 1024}};

     //*  Create window
    _pWindow = NS::Window::alloc()->init(
        frame,
        NS::WindowStyleMaskClosable|NS::WindowStyleMaskTitled,
        NS::BackingStoreBuffered,
        false);
    //* Create Device
    _pDevice = MTL::CreateSystemDefaultDevice();

    //* Create base Metal View, set clear color, and pixel format
    _pView = MTK::View::alloc()->init(frame, _pDevice);
    _pView->setClearColor(MTL::ClearColor::Make(0.0, 1.0, 0.0, 1.0));
    _pView->setColorPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB);

    //* create and assign view delegate to view
    _pViewDelegate = new AluminumViewDelegate(_pDevice);
    _pView->setDelegate( _pViewDelegate );

    _pWindow->setContentView( _pView );
    _pWindow->setTitle(NS::String::string("Aluminum - A Metal based physics engine.", NS::UTF8StringEncoding));

    _pWindow->makeKeyAndOrderFront(nullptr);

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


