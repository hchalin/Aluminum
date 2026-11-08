//
// Created by Hayden Chalin on 11/3/26.
//

#pragma once

#include <AppKit/AppKit.hpp>
#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>
#include <memory>

#include "AluminumViewDelegate.h"

class AluminumAppDelegate : public NS::ApplicationDelegate {
public:
    virtual ~AluminumAppDelegate();
    void applicationDidFinishLaunching(NS::Notification *pNotification) override;
    void applicationWillFinishLaunching(NS::Notification *pNotification) override;
    bool applicationShouldTerminateAfterLastWindowClosed(NS::Application *pSender) override;
private:
    NS::SharedPtr<NS::Window> _window;
    NS::SharedPtr<MTK::View> _view;
    NS::SharedPtr<MTL::Device> _device;
    std::unique_ptr<AluminumViewDelegate> _viewDelegate;
};