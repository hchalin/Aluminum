//
// Created by Hayden Chalin on 11/3/26.
//

#include "KinetisAppDelegate.h"
#include "KinetisViewDelegate.h"



KinetisAppDelegate::~KinetisAppDelegate() {
}

/**
 *      This function gets called automatically, and acts as the applicaitons constructor
 */
void KinetisAppDelegate::applicationDidFinishLaunching(NS::Notification *pNotification) {

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
    _view->setClearColor(MTL::ClearColor::Make(0.0, 0.5, 0.5, 1.0));
    _view->setColorPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB);

    //* create and assign view delegate to view
    _viewDelegate = std::make_unique<KinetisViewDelegate>(_device.get());
    _view->setDelegate( _viewDelegate.get() );

    _window->setContentView( _view.get());
    _window->setTitle(NS::String::string("Kinetis - A Metal based physics engine.", NS::UTF8StringEncoding));

    _window->makeKeyAndOrderFront(nullptr);

    NS::Application* pApp = reinterpret_cast<NS::Application*>(pNotification->object());
    pApp->activateIgnoringOtherApps(true);

}

void KinetisAppDelegate::applicationWillFinishLaunching(NS::Notification *pNotification) {
    NS::Application* pApp = reinterpret_cast< NS::Application* >( pNotification->object() );
    pApp->setActivationPolicy( NS::ActivationPolicy::ActivationPolicyRegular );
}
bool KinetisAppDelegate::applicationShouldTerminateAfterLastWindowClosed(NS::Application *pSender) {
    return true;
}


