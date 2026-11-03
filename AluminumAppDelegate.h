//
// Created by Hayden Chalin on 11/3/26.
//

#include <Metal/Metal.hpp>
#include <AppKit/AppKit.hpp>
#include <MetalKit/MetalKit.hpp>

#pragma once


class AluminumAppDelegate : NS::ApplicationDelegate {
    virtual ~AluminumAppDelegate();
    void applicationDidFinishLaunching(NS::Notification *pNotification) override;
    void applicationWillFinishLaunching(NS::Notification *pNotification) override;
    bool applicationShouldTerminateAfterLastWindowClosed(class NS::Application *pSender) override;
};