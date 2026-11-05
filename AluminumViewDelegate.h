//
// Created by Hayden Chalin on 11/3/26.
//

#pragma once
#include "MetalKit/MTKView.hpp"


class AluminumViewDelegate : public MTK::ViewDelegate {
public:
    AluminumViewDelegate(MTL::Device* pDevice);
    virtual ~AluminumViewDelegate() override;
    virtual void drawableSizeWillChange(class MTK::View *pView, CGSize size) override;
    virtual void drawInMTKView(class MTK::View *pView) override;
private:
    class Renderer* _pRenderer;
};
